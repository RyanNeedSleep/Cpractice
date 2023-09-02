#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



void* roll(){
    int* result = (int *) malloc(sizeof(int));
    *result = rand() % 6 + 1;

    return result;
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    int* result1;
    int* result2;

    pthread_create(&t1, NULL, &roll, NULL);
    pthread_create(&t2, NULL, &roll, NULL);
    
    pthread_join(t1, (void ** )&result1);
    pthread_join(t2, (void ** )&result2);

    printf("Result 1 is: %d\n", *result1);
    printf("Result 2 is: %d\n", *result2);
    


    return 0;
}
