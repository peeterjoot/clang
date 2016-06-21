struct lz_mutex ;

void lz_mutex_lock( lz_mutex * ) ;
void lz_mutex_lock_extended( lz_mutex *, int ) ;

void foo()
{
   lz_mutex_lock( nullptr ) ;
}
