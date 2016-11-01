/* exemplo de uso de semaforos */
#include <stdio.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <semaphore.h>
#include <stdlib.h>
pthread_t rec_thread1;  //guarda info controle da receptor_thread
pthread_t rec_thread2;  //guarda info controle da receptor_thread
sem_t sem1;
int contador=0;
int fp_log;
int create_sem(sem_t *sem,int valor)
{     int erro;
      erro= sem_init(sem, 0, valor);      /* initialize semaforo to 1 - binary semaphore */
      return(erro);
}
int rem_sem(sem_t *sem)
{     int erro;
       erro=sem_destroy(sem); /* destroy semaphore */
      return(erro);
}
int lock(sem_t *sem)
{     int erro;
        sem_wait(sem);
      return(erro);
}
int unlock(sem_t *sem)
{     int erro;
        sem_post(sem);
      return(erro);
}

void *thread1(void *arg)
{     int i;
      printf("INICIA THREAD1\n");
      fflush(stdout);
      for(i=0;i<10000;i++){
        lock(&sem1);
        contador++;
        unlock(&sem1);
      }
}
void *thread2(void *arg)
{     int i;
      printf("INICIA THREAD2\n");
      fflush(stdout);
      for(i=0;i<10000;i++){
        lock(&sem1);
        contador++;
        unlock(&sem1);
      }
}
void main()
{
int rc;
       create_sem(&sem1, 1);      /* initialize mutex to 1 - binary semaphore */
       rc = pthread_create(&rec_thread1, NULL, thread1,(void *) &fp_log);
       if (rc!=0) {
           printf("req_connect(): cannot create requests_thread\n");
           exit(1);
       }
      rc = pthread_create(&rec_thread2, NULL, thread2,(void *) &fp_log);
       if (rc!=0) {
           printf("req_connect(): cannot create requests_thread\n");
           exit(1);
       }
       pthread_join(rec_thread1,NULL);
       pthread_join(rec_thread2,NULL);
       printf("APOS JOIN \n");
       rem_sem(&sem1); /* destroy semaphore */
       printf("CONTADOR=%d\n",contador);
       fflush(stdout);
       printf("FIM PROGRAMA\n");
       fflush(stdout);
}




