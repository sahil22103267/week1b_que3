#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void removeNonAlphanumeric(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char paragraph[10000];
    char word[MAX_WORD_LENGTH];
    WordFreq wordFreqs[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \t\n");
    while (token != NULL && wordCount < MAX_WORDS) {
        strcpy(word, token);
        toLowerCase(word);
        removeNonAlphanumeric(word);

        if (strlen(word) > 0) {
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(wordFreqs[i].word, word) == 0) {
                    wordFreqs[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordFreqs[wordCount].word, word);
                wordFreqs[wordCount].count = 1;
                wordCount++;
            }
        }

        token = strtok(NULL, " \t\n");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
    }

    return 0;
}
