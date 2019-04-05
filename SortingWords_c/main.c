/*
Implement function sort_words that sorts an array of words that contain lowercase
characters from english alphabet, in descending order, and is efficient with respect to time used.

For example, the array { "cherry", "orange", "apple" } should,
after sorting, become { "orange", "cherry", "apple" }.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cstring_cmp(const void *a, const void *b) {
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ib, *ia);
}

void sort_words(char *words[], int count){
    qsort(words, count, sizeof(char *), cstring_cmp);
}

#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };

    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif
