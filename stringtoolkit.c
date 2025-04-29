#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stringtoolkit.h"

void to_uppercase(char str[]) {
    for (int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}

void to_lowercase(char str[]) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int count_vowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void sort_strings(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

void reverse_words(char str[]) {
    char temp[1000];
    int len = strlen(str), word_start = 0, word_end = 0, i = 0, j = 0;
    char words[100][100];
    int word_count = 0;

    while (sscanf(str + i, "%s", words[word_count]) == 1) {
        i += strlen(words[word_count]) + 1;
        word_count++;
    }

    temp[0] = '\0';
    for (int k = word_count - 1; k >= 0; k--) {
        strcat(temp, words[k]);
        if (k > 0)
            strcat(temp, " ");
    }
    strcpy(str, temp);
}
