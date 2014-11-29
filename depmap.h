#include <set>
#include <fstream>

class dependencyMap
{
   typedef std::set< std::string >              stringSet ;
   typedef std::map< std::string, stringSet >   dependencyContainerType ;

   dependencyContainerType m_typeDeps ;

   void collectAllDeps( stringSet & allDeps, const std::string & theTypeName )
   {
      auto & setOfDepsForThisType = m_typeDeps[ theTypeName ] ;

      for ( auto & oneDependentType : setOfDepsForThisType )
      {
         if ( m_typeDeps.count( oneDependentType ) )
         {
            collectAllDeps( allDeps, oneDependentType ) ;
         }
         else
         {
            allDeps.insert( setOfDepsForThisType.begin(), setOfDepsForThisType.end() ) ;
         }
      }
   }

   /**
      dump the dependency tree.
    */
   void dumpOne( const std::string t, stringSet & seen, const std::string & indent )
   {
      llvm::outs() << indent << t << " : " << "\n" ;
      const std::string moreindent = indent + "   " ;

      for ( auto & v : m_typeDeps[ t ] )
      {
#if 0
         if ( v == g_typeSuppressed )
         {
         }
         else 
#endif
            if ( seen.count( v ) )
         {
            llvm::outs() << moreindent << v << "\n" ;
         }
         else
         {
            seen.insert( v ) ;

            dumpOne( v, seen, moreindent ) ;
         }
      }
   }

public:
   /**
      A pair of types.  The type and something that it depends on.
    */
   void insertDependency( const std::string & theTypeName, const std::string & theTypeDep )
   {
      m_typeDeps[ theTypeName ].insert( theTypeDep ) ;
   }

   /**
      dump dependencies as a tree.
    */
   void dump( )
   {
      std::ifstream file ; // Will let destructor cleanup ifstream object.

#if 0
      if ( g_symbolfile )
      {
         file.open( g_symbolfile ) ;

         if ( file.is_open() )
         {
            std::string line ;

            while ( file >> line )
            {
               stringSet seen ;

               dumpOne( line, seen, "" ) ;
            }
         }
         else
         {
            cout << "Failed to process --symbolfile==" << g_symbolfile << "\n" ;
         }
      }
      else
#endif
      {
         /* didn't find a list of specific symbols of interest.  Dump all symbols */
         for ( auto & k : m_typeDeps )
         {
            stringSet seen ;

            dumpOne( k.first, seen, "" ) ;
         }
      }
   }

   /**
      Find all the dependencies of a type recursively and dump them for each type in flat fashion.
    */
   void dumpRecursiveDeps( )
   {
      for ( auto & k : m_typeDeps )
      {
         llvm::outs() << k.first << " : " ;

         stringSet s ;

         collectAllDeps( s, k.first ) ;

         const char * commaOrBlank = "" ;

         for ( auto & v : s )
         {
#if 0
            if ( g_typeSuppressed != v )
#endif
            {
               llvm::outs() << commaOrBlank << v ;

               commaOrBlank = ", " ;
            }
         }

         llvm::outs() << "\n" ;
      }
   }

   void dumpJustDeps( )
   {
      for ( auto & k : m_typeDeps )
      {
         for ( auto & v : m_typeDeps[ k.first ] )
         {
            llvm::outs() << v << "\n" ;
         }
      }
   }

   void dumpDirectDeps()
   {
      for ( auto & k : m_typeDeps )
      {
         llvm::outs() << k.first << " : " ;

         const char * commaOrBlank = "" ;

         for ( auto & v : m_typeDeps[ k.first ] )
         {
            llvm::outs() << commaOrBlank << v ;

            commaOrBlank = ", " ;
         }

         llvm::outs() << "\n" ;
      }
   }

   ~dependencyMap()
   {
      dump() ;

#if 0
      if ( g_out == &g_outFile )
      {
         g_outFile.close() ;
      }
#endif
   }
} ;

// bool g_quietDeps = true ;
