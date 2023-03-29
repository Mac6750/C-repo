/*
 * https://github.com/bollwarm/DataStructuresAlgorithms
Find a pair with the given sum in an array
Google Translate Icon

        Given an unsorted integer array, find a pair with the given sum in it.

For example,
        Input:

nums = [8, 7, 2, 5, 3, 1]
target = 10

Output:

Pair found (8, 2)
or
        Pair found (7, 3)


Input:

nums = [5, 2, 6, 8, 1, 9]
target = 12

Output: Pair not found
 */

#include <stdio.h>
int find_pair(int* input_table, size_t input_size,int output_pairs[][2],size_t out_size,int target);
int main() {
    printf("Hello, World!\n");
    int int_table[]={1,2,3,4,78,989,11,2,3,4,6,8,9,0,1,2,3,4};
    size_t s_i=sizeof(int_table)/sizeof(int_table[0]);
    int out[9000][2]={0};
    size_t s_o=sizeof(out)/sizeof(out[0]);
    int target=10;
    printf("target is %d\n",target);
    int k=find_pair(int_table,s_i,out,s_o,target);
    if(k==0){
        printf("pair not found\n");
    }
    if(k>0) {
        printf("found %d pairs\n", k);
        for (int i = 0; i < k; i++) {
            int a=out[i][1];
            int b=out[i][2];
            printf("pair %d is %d and %d\n", i, a,b);
        }
    }
    return 0;
}
//brute force
//int find_pair(int* input_table, size_t input_size,int output_pairs[][2],size_t out_size,int target){
//    int k=0;
//    for  (int i=0;i<input_size;i++){
//        for  (int j=i;j<input_size;j++){
//            if(target==input_table[i]+input_table[j]){
//                output_pairs[k][1]=i;
//                output_pairs[k][2]=j;
//                k++;
//            }
//        }
//    }
//    return k;
//}

//less brute force
int find_pair(int* input_table, size_t input_size,int output_pairs[][2],size_t out_size,int target){
    int ln_size=0;
    int lesser_numbers[input_size];

    for  (int i=0;i<input_size;i++)
    {
        if(target>input_table[i])
        {
            lesser_numbers[ln_size]=input_table[i];
            ln_size++;
        }
    }

    if(ln_size<=0){
        return 0;
    }

    int k=0;
    for(int i=0;i<ln_size;i++)
    {
        for  (int j=i;j<ln_size;j++)
        {
            if(target==lesser_numbers[i]+lesser_numbers[j])
            {
                output_pairs[k][1]=lesser_numbers[i];
                output_pairs[k][2]=lesser_numbers[j];
                k++;
            }
        }
    }

    return k;
}

























