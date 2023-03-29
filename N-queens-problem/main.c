
#include <stdio.h>
//Print all possible solutions to N–Queens problem
#define N 9
struct queen{
    int row;
    int col;
};
int is_safe(struct queen* queens,int row, int col, int size);

int main() {
    struct queen queen_table[N];
    for(int i=0;i<N;i++){
        queen_table[i].col=-1;
        queen_table[i].row=-1;
    }

    for(int row=0;row<N;){

        for(int c=0;c<N;c++) {

            if (is_safe(queen_table, row, c, N) == 1) {
                queen_table[row].row = row;
                queen_table[row].col = c;
                row++;
                break;
            }
            else {

            }

        }
    }

    printf("Hello, World!\n");

    return 0;
}
int is_safe(struct queen* queens,int row, int col, int size){
    for(int i=0;i<row;i++){
        //sprawdz  kolumny
        if(col==queens[i].col ){
            return 0;
        }
        //sprawdz diagonalna '\'
        for(int c=queens[i].col, r=queens[i].row;c<size && r<size;c++,r++) {
            if (r == row && c == col) {
                return 0;
            }
        }
        //sprawdz diagonalna /
        for(int c=queens[i].col, r=queens[i].row;c>0 && r<size;c--,r++){
            if(r==row && c==col){
                return 0;
            }
        }
    }
    return 1;
}
