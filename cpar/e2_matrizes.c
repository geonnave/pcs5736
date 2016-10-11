/* --- Arquivo : e2_matrizes.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_e2_matrizes.h"  /* typedef's */
#include "vgp_e2_matrizes.h"   /* global privada*/
#include "vsl_e2_matrizes.h"   /* shared local  */
#include "partask_e2_matrizes.h"
#define _MAX_THREADS_ 100
#define get_mi_id() get_mi_id(_cpar_id_thread_)
pthread_t **_cpar_tid_;
int *_cpar_task_nthreads_;
extern int *_cpar_sec_parbegin_ ;
extern int *_cpar_count_bar_ ;
extern int *_cpar_count_end_bar_ ;
extern int *_cpar_end_barrier_;
int _cpar_id_task_;
extern int _cpar_num_tasks_;

extern int *_cpar_task_wait_flag_;

extern pthread_mutex_t *_cpar_create_task_flag_;

extern pthread_mutex_t _cpar_mutex_create_thread_ ;

extern pthread_mutex_t *_cpar_mutex_task_flag_ ;

extern pthread_mutex_t *_cpar_mutex_parbegin_ ;

extern pthread_mutex_t *_cpar_mutex_ ;

extern pthread_mutex_t *_cpar_mutex2_ ;

extern pthread_mutex_t *_cpar_mutex3_ ;

extern pthread_mutex_t *_cpar_mutex_bar_ ;

gl_priv *glbpriv;

extern int id_thread_global_next;

typedef struct {unsigned long int tid;int id_thread;struct type_next_id_thread *next;} type_next_id_thread;

typedef struct {unsigned long int tid;int id_thread;type_next_id_thread *next_id_thread;}type_list_id_thread;

extern type_list_id_thread list_thread[1000];

#include "cob_e2_matrizes.h"
#include <stdio.h>
#define N 100
   double a[N][N];

   double b[N][N];

   double c[N][N];

   double d[N][N];

   double a_b[N][N];

   double c_d[N][N];

   double res[N][N];

void *init_a (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *init_a (void * arg) 
{
int i, j;

   _cpar_arg_task_0_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=0;
   _cpar_arg_t_= (_cpar_arg_task_0_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      a_b[i][j] = 0;
      c_d[i][j] = 0;
      a[i][j] = (double)(i + j);
    }
  }

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *init_b (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *init_b (void * arg) 
{
int i, j;

   _cpar_arg_task_1_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=1;
   _cpar_arg_t_= (_cpar_arg_task_1_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      b[i][j] = i + 2*j;

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *init_c (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *init_c (void * arg) 
{
int i, j;

   _cpar_arg_task_2_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=2;
   _cpar_arg_t_= (_cpar_arg_task_2_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      c[i][j] = 2*i + 3*j;

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *init_d (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *init_d (void * arg) 
{
int i, j;

   _cpar_arg_task_3_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=3;
   _cpar_arg_t_= (_cpar_arg_task_3_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      d[i][j] = 2*i + j;

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *multiply_ab (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *multiply_ab (void * arg) 
{
int i, j, k;

   _cpar_arg_task_4_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=4;
   _cpar_arg_t_= (_cpar_arg_task_4_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      for(k = 0; k < N; k++)
        a_b[i][j] = a_b[i][j] + a[i][k]*b[k][j];

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *multiply_cd (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *multiply_cd (void * arg) 
{
int i, j, k;

   _cpar_arg_task_5_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=5;
   _cpar_arg_t_= (_cpar_arg_task_5_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      for(k = 0; k < N; k++)
        c_d[i][j] = c_d[i][j] + c[i][k]*d[k][j];

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void *sum_res (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *sum_res (void * arg) 
{
int i, j;

   _cpar_arg_task_6_ *_cpar_arg_t_;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=6;
   _cpar_arg_t_= (_cpar_arg_task_6_ *)arg;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
             };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = (N-1 - 0 + 1) / _cpar_numthreads_;
   if (((N-1 - 0 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 0 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= N-1)); i++) {
    for(j = 0; j < N; j++)
      res[i][j] = c_d[i][j] + c_d[i][j];
  }
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {


   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

main()
{
int i, j;


int _id_thread_,_i_;

int _cpar_id_thread_;
for (_i_=0;_i_<1000;_i_++)

   list_thread[_i_].id_thread = -1;

insert_id_thread();

_id_thread_=get_id_thread_gl();

  _cpar_arg_task_0_ *_cpar_arg_0_;

  _cpar_arg_task_1_ *_cpar_arg_1_;

  _cpar_arg_task_2_ *_cpar_arg_2_;

  _cpar_arg_task_3_ *_cpar_arg_3_;

  _cpar_arg_task_4_ *_cpar_arg_4_;

  _cpar_arg_task_5_ *_cpar_arg_5_;

  _cpar_arg_task_6_ *_cpar_arg_6_;

  _cpar_num_tasks_=7;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   printf(">>>begin main\n");

    
   init_create_task(0,1);

   sh_0=(shared_local_0 *) calloc(1,sizeof(shared_local_0));

   _cpar_arg_0_=(_cpar_arg_task_0_ *) calloc(1,sizeof(_cpar_arg_task_0_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_0_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_0_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[0][_cpar_id_thread_],NULL,init_a,(void *)&_cpar_arg_0_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[0]);

      _cpar_task_wait_flag_[0]=0;

    
   init_create_task(1,1);

   sh_1=(shared_local_1 *) calloc(1,sizeof(shared_local_1));

   _cpar_arg_1_=(_cpar_arg_task_1_ *) calloc(1,sizeof(_cpar_arg_task_1_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_1_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_1_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[1][_cpar_id_thread_],NULL,init_b,(void *)&_cpar_arg_1_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[1]);

      _cpar_task_wait_flag_[1]=0;

    
   init_create_task(2,1);

   sh_2=(shared_local_2 *) calloc(1,sizeof(shared_local_2));

   _cpar_arg_2_=(_cpar_arg_task_2_ *) calloc(1,sizeof(_cpar_arg_task_2_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_2_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_2_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[2][_cpar_id_thread_],NULL,init_c,(void *)&_cpar_arg_2_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[2]);

      _cpar_task_wait_flag_[2]=0;

    
   init_create_task(3,1);

   sh_3=(shared_local_3 *) calloc(1,sizeof(shared_local_3));

   _cpar_arg_3_=(_cpar_arg_task_3_ *) calloc(1,sizeof(_cpar_arg_task_3_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_3_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_3_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[3][_cpar_id_thread_],NULL,init_d,(void *)&_cpar_arg_3_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[3]);

      _cpar_task_wait_flag_[3]=0;

  wait_all();

    
   init_create_task(4,1);

   sh_4=(shared_local_4 *) calloc(1,sizeof(shared_local_4));

   _cpar_arg_4_=(_cpar_arg_task_4_ *) calloc(1,sizeof(_cpar_arg_task_4_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_4_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_4_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[4][_cpar_id_thread_],NULL,multiply_ab,(void *)&_cpar_arg_4_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[4]);

      _cpar_task_wait_flag_[4]=0;

    
   init_create_task(5,1);

   sh_5=(shared_local_5 *) calloc(1,sizeof(shared_local_5));

   _cpar_arg_5_=(_cpar_arg_task_5_ *) calloc(1,sizeof(_cpar_arg_task_5_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<1;_cpar_id_thread_++) {

      _cpar_arg_5_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_5_[_cpar_id_thread_].numthreads=1;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[5][_cpar_id_thread_],NULL,multiply_cd,(void *)&_cpar_arg_5_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[5]);

      _cpar_task_wait_flag_[5]=0;

  wait_all();

    
   init_create_task(6,4);

   sh_6=(shared_local_6 *) calloc(1,sizeof(shared_local_6));

   _cpar_arg_6_=(_cpar_arg_task_6_ *) calloc(4,sizeof(_cpar_arg_task_6_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<4;_cpar_id_thread_++) {

      _cpar_arg_6_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_6_[_cpar_id_thread_].numthreads=4;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[6][_cpar_id_thread_],NULL,sum_res,(void *)&_cpar_arg_6_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[6]);

      _cpar_task_wait_flag_[6]=0;

  wait_all();

  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      printf("%5.0lf ", res[i][j]);
    }
    printf("\n");
  }

  printf(">>>end main\n");
   wait_all();      /* --- rs307()  */
}

#include "cob_e2_matrizes"
