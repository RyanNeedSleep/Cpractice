#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

void* routine(void* arg){
    
    int* ptr = arr + (*(int *)arg)*5;
    int* sum = malloc(sizeof(int));

    for (int i = 0; i < 5; i++){
        *sum += *(ptr + i);
    }
    
    return sum;
}


int main(int argc, char const *argv[])
{
    pthread_t worker[2];
    int* result;
    int sum = 0;

    for (int i = 0; i < 2; i++){
        int* index = malloc(sizeof(int));
        *index = i;
        pthread_create(&worker[i], NULL, &routine, index);
    }

    for (int i = 0; i < 2; i++){
        pthread_join(worker[i], (void **)&result);
        sum += *result;
    }

    printf("Total is: %d\n", sum);



    return 0;
}
