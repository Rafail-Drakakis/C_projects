#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100

void checkMagicSquare(int N, int array[MAXN][MAXN]) {
    int sum, sum_check, i, j;
    sum_check = (N * (N * N + 1)) / 2;
    
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += array[i][j];
        }
        
        if (sum == sum_check) {
            printf("ROW %d YES\n", i + 1);
        } else {
            printf("ROW %d NO\n", i + 1);
        }
        
        printf("\n");
    }
    
    for (j = 0; j < N; j++) {
        sum = 0;
        for (i = 0; i < N; i++) {
            sum += array[i][j];
        }
        
        if (sum == sum_check) {
            printf("COLUMN %d YES\n", j + 1);
        } else {
            printf("COLUMN %d NO\n", j + 1);
        }
        
        printf("\n");
    }
    
    sum = 0;
    for (i = 0; i < N; i++) {
        sum += array[i][i];
    }
    
    if (sum == sum_check) {
        printf("DIAG1 YES\n");
    } else {
        printf("DIAG1 NO\n");
    }
    
    printf("\n");
    
    sum = 0;
    for (i = 0; i < N; i++) {
        sum += array[i][N - i - 1];
    }
    
    if (sum == sum_check) {
        printf("DIAG2 YES\n");
    } else {
        printf("DIAG2 NO\n");
    }
    
    int counter, temporary, unique = 0, magic = 0;
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            temporary = array[k][l];
            for (int i = 0; i < N; i++) {
                counter = 0;
                for (int j = 0; j < N; j++) {
                    if (array[i][j] > N * N) {
                        printf("UNIQUE NO\n");
                    }
                    if (array[i][j] == temporary) {
                        counter++;
                    }
                }
                
                if (counter == 1) {
                    unique++;
                }
            }
        }
    }
    
    if (unique == N * N) {
        magic++;
        printf("UNIQUE YES\n");
    } else {
        printf("UNIQUE NO\n");
    }
    
    if (magic == 1) {
        printf("MAGIC YES\n");
    } else {
        printf("MAGIC NO\n");
    }
}

void createMagicSquare(int N) {
    int array[MAXN][MAXN];
    int i, j, k;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            array[i][j] = 0;
        }
    }
    
    i = N - 1;
    j = N / 2;
    
    for (k = 1; k <= N * N; k++) {
        array[i][j] = k;
        int row = i;
        int column = j;
        i++;
        j++;
        
        if (i == N) {
            i = 0;
        }
        
        if (j == N) {
            j = 0;
        }
        
        if (!(array[i][j] == 0)) {
            i = row;
            j = column;
            i--;
        }
    }
    
    printf("%d\n", N);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", array[i][j]);
            
            if ((j + 1) % N == 0) {
                printf("\n");
            }
        }
    }
}

int main(int argument_count, char *argument_vector[]) {
    int N, i, j;
    int array[MAXN][MAXN];
    
    if (strcmp(argument_vector[1], "-check") == 0) {
        scanf("%d", &N);
        
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &array[i][j]);
            }
        }
        
        checkMagicSquare(N, array);
    }
    
    if (strcmp(argument_vector[1], "-create") == 0) {
        N = atoi(argument_vector[2]);
        createMagicSquare(N);
    }
    
    return 0;
}