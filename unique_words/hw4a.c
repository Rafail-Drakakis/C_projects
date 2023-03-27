#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_words(FILE * file) {
    int words = 0;
    char counter;
    counter = getc(file);
    while (counter !=  EOF && counter != '\0' ) {
        if (counter == '\n' || counter == ' ' || counter == '\t' || counter == '\0') {
            words++;
        }
        counter = getc(file);
    }
    rewind(file);
    return words;
}

int word_appearences(char *word, char *all_words[], int size) {//counts how many times does the word appear
    int i, appearences = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(all_words[i], word) == 0) {
            appearences++;
        }
    }
    return appearences;
}

int first_occurence(char *word, char *all_words[], int size) {
    int i, pos = 0;
    for (i = 0; i<size; i++) {
        if (strcmp(all_words[i], word) == 0) {
            pos = i;
            break;
        }
    }
    return pos;
}

int main(int argument_vector, char *argument_counter[]) {
    FILE * file;
    int i, j;
    char counter;
    file = fopen(argument_counter[1], "r");
    int words = count_words(file); //counts all words in text file
    char* all_words[words];    
    for (i = 0; i < words; i++) {
        counter = getc(file);
        all_words[i] = (char *)calloc(0,sizeof(char));
        j = 0;
        while (counter != ' ' && counter != '\n' && counter != '\t' && counter != '\0') {
            all_words[i] = realloc(all_words[i], strlen(all_words[i])+1); 
            all_words[i][j] = counter; 
            j++;
            counter = getc(file);
        }
    } 
    for (i = 0; i < words; i++) {
        if (first_occurence(all_words[i], all_words, words) == i) {
            printf("%s %d\n", all_words[i], word_appearences(all_words[i], all_words, words)); 
        }
    } 
    for (i = 0; i < words; i++){ 
        free(all_words[i]);
        }
    fclose(file);
    return 0;
}
