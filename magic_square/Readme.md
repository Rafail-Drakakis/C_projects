Magic Square
The magic_square program is a command-line tool that can be used to generate and check magic squares. A magic square is a square matrix in which the sum of every row, column, and diagonal is the same.

Requirements
To use the magic_square program, you will need:

A C compiler (such as GCC)
The stdio.h, string.h, and stdlib.h libraries
Usage
To use the magic_square program, open a terminal window and navigate to the directory containing the program. Then, compile the program using the following command:

gcc magic_square.c -o magic_square
Once the program is compiled, you can use it to generate or check magic squares by running the following command:

./magic_square <flag>
The magic_square program accepts two flags:

-create: Generates a magic square of a specified size.
-check: Checks if a square matrix is a magic square.

-create Flag
To generate a magic square, use the -create flag followed by the desired size of the square. For example, to generate a 3x3 magic square, run the following command:

./magic_square -create 3
The program will output the generated magic square to the console in the following format:

3
8 1 6
3 5 7
4 9 2
The first line of the output indicates the size of the square. The remaining lines contain the matrix elements, with each row of the matrix separated by a new line, and each element in a row separated by a space.

-check Flag
To check if a matrix is a magic square, use the -check flag followed by the matrix size and the matrix elements. For example, to check if the following 3x3 matrix is a magic square:

8 1 6
3 5 7
4 9 2
Run the following command:

./magic_square -check
3
8 1 6
3 5 7
4 9 2
The program will output the results of the check, indicating whether each row, column, and diagonal in the matrix sums to the same value. The program will also indicate whether the matrix contains unique elements and whether it is a magic square.

Testing
The magic_square program comes with a test script that can be used to test the functionality of the program. The script can be found in the test.sh file in the project directory.

To run the script, open a terminal window and navigate to the project directory. Then, run the following command:
make.
The script will run several test cases to ensure that the program is functioning correctly. The output of the test script will indicate whether each test passed or failed.

License
This project is licensed under the MIT License.
