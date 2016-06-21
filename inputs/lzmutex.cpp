struct lz_mutex ;

#define LZ_OP_ABORT_ON_ERROR 1
void lz_mutex_lock( lz_mutex * ) ;
void lz_mutex_lock_extended( lz_mutex *, int ) ;

void foo()
{
   lz_mutex_lock( nullptr ) ;
}
