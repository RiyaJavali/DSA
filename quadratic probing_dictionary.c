#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct DictionaryEntry {
    char word[20];
};

struct DictionaryEntry dictionary[SIZE];

int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

void insert(char* word) {
    int index = hashFunction(word);
    int i = 1;
    while (strcmp(dictionary[index].word, "") != 0) {
        index = (index + i * i) % SIZE;
        i++;
    }
    strcpy(dictionary[index].word, word);
}

int search(char* word) {
    int index = hashFunction(word);
    int i = 1;
    while (strcmp(dictionary[index].word, "") != 0) {
        if (strcmp(dictionary[index].word, word) == 0) {
            return 1; // Word found
        }
        index = (index + i * i) % SIZE;
        i++;
    }
    return 0; // Word not found
}

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[20];
    while (fscanf(file, "%s", word) != EOF) {
        insert(word);
    }

    fclose(file);
}

int main() {
    // Initialize dictionary
    for (int i = 0; i < SIZE; i++) {
        strcpy(dictionary[i].word, "");
    }

    // Load dictionary from file
    const char* dictionaryFile = "dictionary.txt";
    loadDictionary(dictionaryFile);

    // Check if a word is valid
    char word[20];
    printf("Enter a word to check: ");
    scanf("%s", word);
    int isValid = search(word);

    // Display result
    if (isValid) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
    }

    return 0;
}
