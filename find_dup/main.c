
//Find the duplicate element in a limited range array
//
//
//Given a limited range array of size n containing elements between 1 and n-1 with one element repeating,
//find the duplicate number in it without using any extra space.

#include <stdio.h>
#include <stdbool.h>
int find_dup(int *array,size_t size);
int main() {
    int array[100];
    for (int i=0;i<100;i++){
        array[i]=i;
    }
    array[9]=83;
    int ret=find_dup(array,100);
    printf("%d\n",ret);
    return 0;
}
int find_dup(int *array,size_t size){
    bool vector[size];

    for (int i=0;i<size;i++){
        vector[i]=false;
    }

    for (int i=0;i<size;i++){
        int value=array[i];
        if(vector[value]==false){
            vector[value]=true;
        }
       else {
           return value;
       }
    }

    return -1;

}