#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100
int main(int argument_count, char *argument_vector[] ) {
    int row,column,sum,sum_check,N,i,j,k,l,counter,temporary;
    int array[MAXN][MAXN];
    int unique = 0; 
    int magic = 0;
    if (strcmp(argument_vector[1], "-check")==0) {
        scanf("%d", &N);
        sum_check = (N*(N*N+1))/2;
        for (i = 0; i<N; i++) {
            for (j = 0; j<N; j++) {
                scanf("%d", &array[i][j]);
            }
        }
        for (i = 0; i<N; i++) {
            sum = 0;
            for (j = 0; j<N; j++) {
                sum = sum+array[i][j];
            }
            if (sum==sum_check) {
                printf("ROW %d YES\n", i+1);
            } else {
                printf("ROW %d NO\n", i+1);
            }
            printf("\n");
        }
        for (j = 0; j<N; j++) {
            sum = 0;
            for (i = 0; i<N; i++) {
                sum = sum+array[i][j];
            }
            if (sum==sum_check) {
                printf("COLUMN %d YES\n", j+1);
            } 
            else {
                printf("COLUMN %d NO\n", j+1);
            }
            printf("\n");
        }
        sum = 0;
        for (i = 0; i<N; i++) {
            sum = sum+array[i][i];
        }
        if (sum==sum_check) {
            printf("DIAG1 YES\n");
            } 
        else {
            printf("DIAG1 NO\n");
        }
        printf("\n");
        sum = 0;
        for (i = 0; i<N; i++) {
            sum = sum+array[i][N-i-1];
        }
        if (sum==sum_check) {
            printf("DIAG2 YES\n");
        } 
        else {
            printf("DIAG2 NO\n");
        }
        for(k=0; k<N; k++){
            for(l=0; l<N; l++){
                temporary = array[k][l];
                for(i=0; i<N; i++){
                    counter = 0;
                    for(j=0; j<N; j++){
                        if(array[i][j]>N*N){
                            printf("UNIQUE NO\n");
                        }
                        if(array[i][j]==temporary){
                            counter++;
                        }
                    }
                    if(counter==1){
                        unique++;
                    }
                }
            }
        }
        if(unique==N*N){
            magic++;
            printf("UNIQUE YES\n");
        }
        else{
            printf("UNIQUE NO\n");
        }
        if(magic==1){
            printf("MAGIC YES\n");
        }
        else{
            printf("MAGIC NO\n");
        }
    }
    if (strcmp(argument_vector[1], "-create") == 0) {
        N = atoi(argument_vector[2]);
        for (i = 0; i<N; i++) {
            for (j = 0; j<N; j++) {
                array[i][j] = 0;
            }
        }
        i = N-1;
        j = N/2;
        for (k = 1; k <= N*N; k++) {
            array[i][j] = k;
            row = i;
            column = j;
            i++;
            j++; 
            if (i==N) {
                i = 0;
            }
            if (j==N) {
                j = 0;
            }
            if (!(array[i][j] == 0)) {
                i = row;
                j = column;
                i--;
            }
        }
        printf("%d\n", N);
        for (i = 0; i<N; i++) {
            for (j = 0; j<N; j++) { 
                printf("%d ", array[i][j]);
                if ((j+1)%N==0) {
                    printf("\n");
                }
            }
        }  
    }
    return 0;
}
