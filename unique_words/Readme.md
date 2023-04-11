This C program takes a text file as input, counts the number of words in it, and prints out each unique word and the number of times it appears in the file.

Usage
To run the program, compile it using a C compiler and run it with the text file you want to analyze as a command line argument:

make
./unique_words textfile.txt
The program will output a list of unique words in the file along with the number of times each word appears.

Limitations
The program only counts whitespace-separated words, and does not consider punctuation or special characters. Additionally, the program assumes that the file contains only text data and may produce unexpected results when given binary files or files with non-text data.

License
This project is licensed under the MIT License.
