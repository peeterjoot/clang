struct lz_mutex ;

#define LZ_OP_ABORT_ON_ERROR 1
void lz_mutex_lock( lz_mutex * ) ;
void lz_mutex_lock_extended( lz_mutex *, int ) ;
void lz_mutex_unlock( lz_mutex * ) ;
void lz_mutex_unlock_extended( lz_mutex *, int ) ;
void lz_mutex_destroy( lz_mutex * ) ;
void lz_mutex_destroy_extended( lz_mutex *, int ) ;
void lz_mutex_consistent( lz_mutex * ) ;
void lz_mutex_consistent_extended( lz_mutex *, int ) ;
void lz_mutex_trylock( lz_mutex * ) ;
void lz_mutex_trylock_extended( lz_mutex *, int ) ;
void lz_cond_broadcast( lz_mutex * ) ;
void lz_cond_broadcast_extended( lz_mutex *, int ) ;
void lz_cond_destroy( lz_mutex * ) ;
void lz_cond_destroy_extended( lz_mutex *, int ) ;
void lz_cond_signal( lz_mutex * ) ;
void lz_cond_signal_extended( lz_mutex *, int ) ;
void lz_cond_wait( lz_mutex *, int ) ;
void lz_cond_wait_extended( lz_mutex *, int, int ) ;
void lz_cond_init( lz_mutex *, int ) ;
void lz_cond_init_extended( lz_mutex *, int, int ) ;
void lz_cond_timedwait( lz_mutex *, int, int ) ;
void lz_cond_timedwait_extended( lz_mutex *, int, int, int ) ;


void lz_mutex_lock_or_abort( lz_mutex * ) ;
void lz_mutex_unlock_or_abort( lz_mutex * ) ;
void lz_mutex_destroy_or_abort( lz_mutex * ) ;
void lz_mutex_consistent_or_abort( lz_mutex * ) ;
void lz_mutex_trylock_or_abort( lz_mutex * ) ;
void lz_cond_broadcast_or_abort( lz_mutex * ) ;
void lz_cond_destroy_or_abort( lz_mutex * ) ; 
void lz_cond_signal_or_abort( lz_mutex * ) ;
void lz_cond_wait_or_abort( lz_mutex *, int ) ; 
void lz_cond_init_or_abort( lz_mutex *, int ) ;
void lz_cond_timedwait_or_abort( lz_mutex *, int, int ) ;



void foo()
{
   lz_mutex_lock( nullptr ) ;
   lz_mutex_unlock( nullptr ) ;
   lz_mutex_destroy( nullptr ) ;
   lz_mutex_consistent( nullptr ) ;
   lz_mutex_trylock( nullptr ) ;
   lz_cond_broadcast( nullptr ) ;
   lz_cond_destroy( nullptr ) ;
   lz_cond_signal( nullptr ) ;
   lz_cond_wait( nullptr, 1 ) ;
   lz_cond_init( nullptr, 1 ) ;
   lz_cond_timedwait( nullptr, 1, 2 ) ;

   lz_mutex_lock_or_abort( nullptr ) ;
   lz_mutex_unlock_or_abort( nullptr ) ;
   lz_mutex_destroy_or_abort( nullptr ) ;
   lz_mutex_consistent_or_abort( nullptr ) ;
   lz_mutex_trylock_or_abort( nullptr ) ;
   lz_cond_broadcast_or_abort( nullptr ) ;
   lz_cond_destroy_or_abort( nullptr ) ;
   lz_cond_signal_or_abort( nullptr ) ;
   lz_cond_wait_or_abort( nullptr, 1 ) ;
   lz_cond_init_or_abort( nullptr, 1 ) ;
   lz_cond_timedwait_or_abort( nullptr, 1, 2 ) ;
}
