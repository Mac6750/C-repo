#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int ile_case;
    int buf = 0;
    char str[10] = {0};
    for (int i = 0; i < 10; i++) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        str[i] = c;
    }

    ile_case = atoi(str);

    int color_input[ile_case][3][4];

    char string[100] = {0};

    for (int i = 0; i < ile_case; i++) {
        for (int j = 0; j < 3; j++) {

            for (int is = 0; is < 100; is++) {
                int c = getchar();
                if (c == '\n' || c == EOF) {
                    break;
                }
                string[is] = c;
            }

            sscanf(string, "%d %d %d %d", &color_input[i][j][0], &color_input[i][j][1], &color_input[i][j][2], &color_input[i][j][3]);
            memset(string, 0, 100);
        }

    }
    //gud
    int min_color[ile_case][4];
    int color_out[ile_case][4];
    for (int i = 0;i< ile_case ; i++){    // Set the first 6 elements in the array
        for(int k=0;k<4;k++){
            min_color[i][k] = color_input[i][0][k];
            color_out[i][k] = 0;
        }
    }



    for(int i=0;i<ile_case;i++) {
        printf("Case #%d: ",i+1);
        for (int j = 1; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                if(color_input[i][j][k]<min_color[i][k]){
                    min_color[i][k]=color_input[i][j][k];
                }
            }
            
        }

        int suma=0;
        for (int k = 0; k < 4; k++) {
            suma = suma + min_color[i][k];
        }

        if(suma<1000000){
            printf("IMPOSSIBLE\n");
            continue;
        }
        else{

            int max=1000000;
            int ile_zost=max;
            for (int k = 0; k < 4; k++) {
                if(k==3){
                    color_out[i][3]=ile_zost;
                    break;
                }
                if (min_color[i][k] >= ile_zost) {
                    color_out[i][k] = ile_zost;
                    break;
                } else {
                    color_out[i][k] = min_color[i][k];
                    ile_zost = ile_zost - color_out[i][k];
                }
            }
            printf("%d %d %d %d\n", color_out[i][0], color_out[i][1], color_out[i][2], color_out[i][3]);

        }
    }

    for(int i=0;i<ile_case;i++) {

    }

    return 0;
}
