#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_plus(int colums);
int print_minus(int colums);

int main() {
    int ile_case;
    int buf=0;
    char str[10]={0};
    for(int i=0;i<10;i++){
        int c=getchar();
        if(c=='\n'||c==EOF){
            break;
        }
        str[i]=c;
    }

    ile_case=atoi(str);

    int a[ile_case];
    int b[ile_case];
    char string[10]={0};
    for(int i=0;i<ile_case;i++){

        for(int i=0;i<10;i++){
            int c=getchar();
            if(c=='\n'||c==EOF){
                break;
            }
            string[i]=c;
        }
        sscanf(string,"%d %d",&a[i],&b[i]);
        memset(string,0,10);
    }

    for(int acase=0;acase<ile_case;acase++){
        printf("Case #%d:\n",acase+1);
        for(int i=0;i<a[acase];i++) {

            if (i == 0) {
                printf("..");
                print_plus(b[acase]-1);
                printf("\n");
                printf("..");
                print_minus(b[acase]-1);
                printf("\n");

            }
            else if(i>0){
                print_plus(b[acase]);
                printf("\n");
                print_minus(b[acase]);
                printf("\n");
            }

        }
        print_plus(b[acase]);
        printf("\n");
    }

    return 0;
}

int print_plus(int colums){
    for(int i=0;i<colums;i++){
        printf("+-");
    }
    if(colums>0){
        printf("+");
    }
}

int print_minus(int colums){
    for(int i=0;i<colums;i++){
        printf("|.");
    }
    if(colums>0) {
        printf("|");
    }
}