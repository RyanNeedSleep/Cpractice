#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    int* arr = (int *) malloc(sizeof(int)*10);
    for (int i = 0; i < 10; i++){
        arr[i] = i*i;
        printf("%d\n", arr[i]);
    }
    printf("the original address of arr is: %p\n", arr);

    arr = (int *)realloc(arr, sizeof(int)*20);

    for (int i = 0; i < 20; i++){
        if (i < 10){
            printf("%d\n", arr[i]);
        } else {
            arr[i] = i*i;
            printf("%d\n", arr[i]);
        }
    }
    printf("the re-allocated address of arr is: %p\n", arr);
    
    return 0;
}
