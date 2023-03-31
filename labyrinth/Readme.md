Random Labyrinth Generator
This is a C program that generates a random labyrinth using a recursive backtracking algorithm. The labyrinth is represented as a 2D character array where 'X' represents a wall and ' ' represents an empty space. The algorithm starts at a random point and randomly chooses a direction to move in. It then continues in that direction until it hits a dead end, at which point it backtracks to the last intersection and chooses a new direction.

Prerequisites
To run this program, you need a C compiler installed on your system.

Usage
Clone this repository to your local machine.
Open a terminal and navigate to the repository directory.
Compile the program using the following command:
gcc labyrinth.c -o labyrinth
Run the program using the following command:
./labyrinth

Follow the prompts to input the size of the labyrinth. The size must be a positive integer greater than or equal to 3.
The program will generate a random labyrinth and print it to the console.
Functions
1.input(): Gets input from stdin in the form of a string and returns it as an integer. If the input is not a positive integer, the program will terminate.
2.check_validity(int s1, int s2): Checks the validity of the input labyrinth using the given algorithm. The labyrinth cannot be made on a grid with individual dimensions that are less than 3. If the input is not valid, the program will terminate.
3.up(int *i, int *j, char **lab), down(int *i, int *j, char **lab), left(int *i, int *j, char **lab), right(int *i, int *j, char **lab). Replaces 'X' characters in the given direction with ' ' characters.
4.roll(int b) Generates a random number based on how many movement options we have.
5.movement(int *i, int *j, int N, int M, char **lab) Evaluates movement options, makes a move, returns 1 if successful, 0 otherwise.
6.print(char **lab, int N, int M) Prints the labyrinth to the console.
7.dig(int i, int j, int N, int M, char **lab) Receives a set of coordinates, evaluates movement options on a loop, performs a random move, hands the new coordinates over to the next iteration of dig. When there no more movement options, the loop terminates and we return to the previous iteration of dig.
8.create(int N, int M) Creates a new labyrinth array and initializes it with 'X' characters.
9.free_mem(char **lab, int N) Frees the memory allocated to the labyrinth.
