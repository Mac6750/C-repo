#include <stdio.h>
//#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int za_c=0;
int przed_c=0;
int pom_c=0;
int przep_c=0;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Given an array of integers nums, sort the array in ascending order and return it.

//You must solve the problem without using any built-in
//functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
int* sortArray(int* nums, int numsSize, int* returnSize);
int merge(int* tab,size_t size_a,size_t size_b);

int main() {
    int tabsize=1<<17  ;
    //printf("Hello, World!\n");
    //int tab[]={99,-3,-2,-1,-1,3,2,5};
   int tab[tabsize];
    for(int i=0;i<tabsize;i++) {
        unsigned int seed =879897+i;
        //int a=tabsize-i;
        int a=rand_r(&seed);
        tab[i]=a;
    }
    int*wsk=NULL;
    int size=0;
    time_t start,end;
    time(&start);
    wsk=sortArray(tab,tabsize,&size);
    time(&end);
    for(int i=0;i<tabsize;i++) {
           if(wsk[i]>wsk[i+1]){
               //printf( " wsk [ %d ]=%d",i,wsk[i]);
               //printf( " wsk [ %d ]=%d\n",i+1,wsk[i+1]);

              // puts("");
           }
        printf( " wsk [ %d ]=%d\n",i,wsk[i]);
       // printf( " wsk [ %d ]=%d\n",i+1,wsk[i+1]);

    }
    printf( "\n time %d",end-start);
    printf( "\n za %d",za_c);
    printf( "\n przed %d",przed_c);
    printf( "\n pom%d",pom_c);
    printf( "\n przep %d",przep_c);

    free(wsk);
    return 0;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    int *tab=malloc(numsSize*sizeof(int));

    if(tab==NULL){
        return 0;
    }
    *returnSize=numsSize;

    for(int i=0;i<numsSize;i+=4){
       int buf=0;
       tab[i]=nums[i];
       tab[i+1]=nums[i+1];
       tab[i+2]=nums[i+2];
       tab[i+3]=nums[i+3];

       if(tab[i]>tab[i+1]){
           buf=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=buf;
       }
        if(tab[i+2]>tab[i+3]){
            buf=tab[i+2];
            tab[i+2]=tab[i+3];
            tab[i+3]=buf;
        }

        if(tab[i]>tab[i+2]){
            buf=tab[i];
            tab[i]=tab[i+2];
            tab[i+2]=buf;
        }

        if(tab[i+1]>tab[i+3]){
            buf=tab[i+1];
            tab[i+1]=tab[i+3];
            tab[i+3]=buf;
        }

        if(tab[i+1]>tab[i+2]){
            buf=tab[i+1];
            tab[i+1]=tab[i+2];
            tab[i+2]=buf;
        }

    }

    int ind=0;
    for(int i=0;i*4+8<=numsSize;i++){
        int size=(i+1)*4;
        int pocz=i*4+4;
        //for(int k=0;k<numsSize;k++) {
        //    printf("tab_a [ %d ]=%d\n", k, tab[k]);
       // }
        merge(tab,size,4);

    }

    



    return tab;
}
int merge(int* tab,size_t size_a,size_t size_b){
    if(size_a<size_b){
        return -1;
    }
    int* tab_a=tab;
    int* tab_b=&tab_a[size_a];
    int min_ind=0;
    int max_ind=0;
    int buf[size_a];
    for(int i=0;i<size_a;i++){
        buf[i]=0;
    }

    //da sie wkleic pomiedzy, za ,przed
    //wklej za
    if(tab_b[0]>=tab_a[size_a-1]){
        //wklej_za();
      //  puts("za");
        za_c++;
        return 1;
    }
    //wklej przed
    else if(tab_b[size_b-1]<=tab_a[0]){
        //wkleJ_przed();
        memcpy(buf,tab_a,size_a*sizeof(int));
        memcpy(tab_a,tab_b,size_b*sizeof(int));
        memcpy(&tab_a[size_b],buf,size_a*sizeof(int));
        //puts("przed");
        przed_c++;
        return 1;
    }
    //wklej pomiedzy

    for(int i=1;i<size_a;i++) {
        if (tab_b[0] > tab_a[size_a - 1 - i]) {
            if (tab_b[size_b - 1 ] < tab_a[size_a - i]) {
                //wklej_pomiedzy();
                memcpy(buf, &tab_a[size_a - i], i  * sizeof(int));
                memcpy(&tab_a[size_a - i], tab_b, size_b * sizeof(int));
                memcpy(&tab_b[size_b - i], buf, i * sizeof(int));
                //puts("pomiedzy");
                pom_c++;
                return 1;
            } else {
                break;
            }
        }
    }
    przep_c++;

    //wklej z przeplotem
    int byl_kop=0;
    int count=0;
    //puts("z przeplotem");
    for(int j=0;j<size_b;j++){
        byl_kop=0;
        for(int i=1;i<size_a;i++){
            int b=tab_b[j];

            int a=tab_a[size_a-1-i];
            //int miej_porow=size-i+count-1;
            int miej_porow=size_a-i-1;
            if(tab_b[j]>=tab_a[miej_porow]){

                byl_kop=1;
               // printf("\nprzed\n");

                for(int k=0;k<size_a;k++) {
                //    printf("tab_a [ %d ]=%d\n", k, tab[k]);
                }
                for(int k=0;k<size_b;k++) {
                //    printf("tab_b [ %d ]=%d\n", k, tab_b[k]);
                }

                memcpy(buf,&tab_a[miej_porow+1],i*sizeof(int));
                memcpy(&tab_a[miej_porow+1],&tab_b[j],sizeof(int));
                memcpy(&tab_a[miej_porow+2],buf,i*sizeof(int));
               // printf("\npo\n");
                for(int k=0;k<size_a;k++) {
               //     printf("tab_a [ %d ]=%d\n", k, tab[k]);
                }

                for(int k=0;k<size_b;k++) {
                //        printf("tab_b [ %d ]=%d\n", k, tab_b[k]);
                }

                tab_a++;
                break;
             }
        }

        if(byl_kop==0){
            //printf("\nnie bylo - przed\n");
            /*for(int k=0;k<size;k++) {
                printf("tab_a [ %d ]=%d\n", k, tab_a[k]);
            }
            for(int k=0;k<size;k++) {
                printf("tab_b [ %d ]=%d\n", k, tab_b[k]);
            }
             */
            memcpy(buf,tab_a,size_a*sizeof(int));
            memcpy(tab_a,&tab_b[j],sizeof(int));
            memcpy(&tab_a[1],buf,size_a*sizeof(int));
           // printf("\npo\n");
            /*for(int k=0;k<size;k++) {
                printf("tab_a [ %d ]=%d\n", k, tab_a[k]);
            }

            for(int k=0;k<size;k++) {
                printf("tab_b [ %d ]=%d\n", k, tab_b[k]);
            }
           */
            tab_a++;

        }
    }

    return 0;
}