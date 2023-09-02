#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int count = 0;

pthread_mutex_t lock;



void* routine(){
   for (int i = 0; i < 1000000; i++){
      pthread_mutex_lock(&lock);
      count++;   
      pthread_mutex_unlock(&lock);
   }
   return NULL;
}


int main(int argc, char **argv){
    // pthread_t newthread;       
    // pthread_create(&newthread, NULL, myturn, NULL);
    // pthread_join(newthread, (void *)&result);
    pthread_mutex_init(&lock, NULL);
    pthread_t t1, t2;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    pthread_mutex_destroy(&lock);
    printf("Total count is: %d\n", count);

}