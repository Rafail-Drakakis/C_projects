#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum direction {NONE, UP, DOWN, LEFT, RIGHT}; /*enumeration of all possible movement directions*/

enum boolean {F,T}; /*this is pretty redundant and was only done to experiment with the emun keyword*/

int input(); /*gets input from stdin in the form of a string if the input is not a positive integer, the program will terminate*/

void check_validity(int s1, int s2); /*checks the validity of the input the labyrinth using the given algorithm cannot be made on grid with individuals dimensions that are less than 3!*/

void up(int *i, int *j, char **lab); /*replaces X characters in the up direction*/

void down(int *i, int *j, char **lab); /*replaces X characters in the down direction*/

void left(int *i, int *j, char **lab); /*replaces X characters in the left direction*/

void right(int *i, int *j, char **lab); /*replaces X characters in the right direction*/

int roll(int b); /*generates a random number based on how many movement options we have*/

int movement(int *i, int *j, int N, int M, char **lab); /*evaluates movement options, makes a move, returns 1 if successful, 0 otherwise*/

void print(char **lab, int N, int M);

void dig(int i, int j, int N, int M, char **lab); /*receives a set of coordinates, copies them, evaluates movement options on a loop, will perform a random move, hands the new coordinates over to the next iteration of dig. When there no more movement options, the loop terminates and we return to the previous iteration of dig*/

char **create(int N, int M);

void free_mem(char **lab, int N);

void main(){
        char **lab;
        int N, M;

        N = input(); /*get size of the first dimension array[N][]*/

        M = input(); /*get size of the second dimension array[][M]*/

        check_validity(N,M); /*if validity check fails the program will terminate*/

        lab = create(N,M); /*creation of the labyrinth*/

        srand(time(NULL)); /*seeding of the random function using the time function*/

        dig(1,1,N,M,lab); /*first call to dig*/

        print(lab,N,M); /*print now excavated labyrinth*/

        free_mem(lab, N); /*free the memory allocated to the labyrinth*/
}

int input(){
        int size = 1; /*current input string size*/
        char *str = (char *) calloc(size,1); /*memory initialization*/
        enum boolean flag = F; /*F(alse) if there are no invalid characters*/
        int a;
        while(1){
                a = getc(stdin);
                if(a == EOF || a == ' ' || a == '\n') break;
                if(a < '0' || a > '9') flag = T;
                str[size-1] = a; /*placing the new character*/
                str = (char *) realloc(str, ++size); /*incrementing string size and allocating memory*/
                str[size-1] = '\0'; /*terminating the string*/
        }
        if(flag){/*check for invalid characters*/
                fprintf(stderr,"\nINVALID INPUT! USE POSITIVE INTEGERS ONLY!\n");
                exit(0);
        }
        a = atoi(str);
        free(str);
        return a;
}

void check_validity(int s1, int s2){
        if(s1 < 3 || s2 < 3){
                fprintf(stderr,"INVALID SIZE!\n");
                exit(0);
        }
}

void up(int *i, int *j, char **lab){
        lab[*i-1][*j] = ' ';
        lab[*i-2][*j] = ' ';
        *i = *i - 2;
}

void down(int *i, int *j, char **lab){
        lab[*i+1][*j] = ' ';
        lab[*i+2][*j] = ' ';
        *i = *i + 2;
}

void left(int *i, int *j, char **lab){
        lab[*i][*j-1] = ' ';
        lab[*i][*j-2] = ' ';
        *j = *j - 2;
}

void right(int *i, int *j, char **lab){
        lab[*i][*j+1] = ' ';
        lab[*i][*j+2] = ' ';
        *j = *j + 2;
}

int roll(int b){
        return rand()%b;
}

int movement(int *i, int *j, int N, int M, char **lab){
        enum direction moves[4] = {NONE,NONE,NONE,NONE}; /*array to store all valid movement options*/
        int options = 0, can_move_up, can_move_down, can_move_left, can_move_right;

        int s1 = N % 2 == 0 ? N-1 : N; /*s1 and s2 are here to prevent following bug in our algorithm*/
        int s2 = M % 2 == 0 ? M-1 : M; /*if N or M are even numbers, the bottom or the right side of the labyrinth, respectively, will be destroyed*/
        /*setting their values to the dimension size-1 prevents the algorithm from destroying the outer walls*/

        /*evaluating movement options in the following way*/
        /*if our index does not go out of bounds or hit an outer wall by moving in this direction*/
        /*and the two spaces in that direction are filled, then the movement is valid*/
        can_move_up = *i - 2 > 0 ? lab[*i-1][*j] == 'X' && lab[*i-2][*j] == 'X' : 0;
        can_move_down = *i + 2 < s1 ? lab[*i+1][*j] == 'X' && lab[*i+2][*j] == 'X' : 0;
        can_move_left = *j - 2 > 0 ? lab[*i][*j-1] == 'X' && lab[*i][*j-2] == 'X' : 0;
        can_move_right = *j + 2 < s2 ? lab[*i][*j+1] == 'X' && lab[*i][*j+2] == 'X' : 0;
        
        /*loading valid movement options to our array*/
        if(can_move_up) moves[options++] = UP;
        if(can_move_down) moves[options++] = DOWN;
        if(can_move_left) moves[options++] = LEFT;
        if(can_move_right) moves[options++] = RIGHT;
        
        /*if we have options*/
        /*instead of rolling a number that determines the move*/
        /*we roll for an index in our moves array and then move according to its contents*/
        /*this ensures that we only have to roll once to get our move*/
        if(options != 0){
                switch(moves[roll(options)]){
                        case UP:
                                up(i,j,lab);
                                break;
                        case DOWN:
                                down(i,j,lab);
                                break;
                        case LEFT:
                                left(i,j,lab);
                                break;
                        case RIGHT:
                                right(i,j,lab);
                                break;
                }
                return 1;
        }
        else
                return 0;
}

void print(char **lab, int N, int M){
        int i, j;
        for(i = 0; i < N; i++){
                for(j = 0; j < M; j++)
                        printf("%c",lab[i][j]);
                puts(" ");
        }
}

void dig(int i, int j, int N, int M, char **lab){
        int x = i, y = j; /*i,j are the coordinates the previous iteration of dig gave this one*/
        /*x,y are the coordinates of this iteration and will be reset every time we need to re-evaluate our movement options*/
        while(movement(&x,&y,N,M,lab)){
                dig(x, y, N, M, lab);
                x = i;
                y = j;
        }
}

char **create(int N, int M){
        char **lab = (char **) malloc(N * sizeof(char*));
        int i,j;
        for(i = 0; i < N; i++)
                lab[i] = malloc(M * sizeof(char));
        for(i = 0; i < N; i++)
                for(j = 0; j < M; j++)
                        lab[i][j] = 'X';
        lab[0][1] = ' ';
        lab[1][1] = ' ';
        return lab;
}

void free_mem(char **lab, int N){
        int i;
        for(i = 0; i < N; i++)
                free(lab[i]);
        free(lab);
}
