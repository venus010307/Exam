#include <stdio.h>
#include <ctype.h>  

#define MAX_LENGTH 1000  


void capitalizeSentence(char *sentence) {
    while (*sentence) {
        *sentence = toupper(*sentence);  
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char sentence[MAX_LENGTH];

   
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    
    if (fgets(sentence, MAX_LENGTH, inputFile) != NULL) {
        
        capitalizeSentence(sentence);

        
        fputs(sentence, outputFile);
    } else {
        printf("Error reading from input file\n");
    }

    
    fclose(inputFile);
    fclose(outputFile);

    printf("The sentence has been capitalized and written to output.txt\n");

    return 0;
}
