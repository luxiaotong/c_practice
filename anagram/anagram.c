#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "anagram.h"

void print_word(char mid_word[][MAX_WORD_LEN], int mid_left, int mid_right)
{
    int i = 0;
    for ( i = mid_left; i <= mid_right; i ++ ) {
        printf("%s ", mid_word[i]);
    }
    printf("\n");

    return;
}

static void qsort_anagram(char mid_word[][MAX_WORD_LEN], char word_arr[][MAX_WORD_LEN], int mid_left, int mid_right)
{
    if ( mid_right - mid_left < 1 ) return;

    int factor  = mid_left;
    int i       = mid_left;
    int j       = mid_right;
    char *tmp   = NULL;
    
    while (  i < j ) {
        while ( strcmp(mid_word[j], mid_word[factor]) >= 0 && i < j ) j --;
        while ( strcmp(mid_word[i], mid_word[factor]) <= 0 && i < j ) i ++;

        swap_mid_word(mid_word, i, j); 
        swap_mid_word(word_arr, i, j); 
    }

    swap_mid_word(mid_word, factor, j);
    swap_mid_word(word_arr, factor, j);

    qsort_anagram(mid_word, word_arr, mid_left, j - 1);
    qsort_anagram(mid_word, word_arr, j + 1, mid_right);

    return;
}

static void swap_mid_word(char mid_word[][MAX_WORD_LEN], int mid_left, int mid_right)
{
    char tmp[MAX_WORD_LEN];

    memcpy(tmp, mid_word[mid_right], sizeof(mid_word[mid_right]));
    memcpy(mid_word[mid_right], mid_word[mid_left], sizeof(mid_word[mid_left]));
    memcpy(mid_word[mid_left], tmp, sizeof(tmp));

    return;
}

static void swap_word_arr(char word_arr[][MAX_WORD_LEN], int mid_left, int mid_right)
{
    char tmp[MAX_WORD_LEN];

    memcpy(tmp, word_arr[mid_right], sizeof(word_arr[mid_right]));
    memcpy(word_arr[mid_right], word_arr[mid_left], sizeof(word_arr[mid_left]));
    memcpy(word_arr[mid_left], tmp, sizeof(tmp));

    return;
}
static void find_anagram(char mid_word[][MAX_WORD_LEN], char word_arr[][MAX_WORD_LEN], int len)
{
    int i = 0;
    int j = i + 1;

    while ( i < len && j < len ) {
        if ( strcmp(mid_word[i], mid_word[j]) == 0 ) {
            if ( j - i == 1 ) {
                printf("%s, %s", word_arr[i], word_arr[j]);
            } else {
                printf(", %s", word_arr[j]);
            } 
            j ++;
        } else {
            if ( j - i > 1 ) {
                printf("\n");
                i = j;
            } else {
                i ++;
            }
            j = i + 1;
        } 
    }

    return;
}


int main(void)
{
    FILE *fp;
    char word[MAX_WORD_LEN];
    char mid_word[100][MAX_WORD_LEN];
    char word_arr[100][MAX_WORD_LEN];
    char c;
    
    int ascii_arr[ASCII_LEN];
    int word_len;
    int i = 0, j = 0, k = 0;
    int ascii_code = 0;
    
    fp = fopen("word.txt","r");

    while ( (c = fscanf(fp, "%s", word)) != EOF ) {
        word_len = strlen(word); 
        for ( i = 0; i < word_len; i ++ ) {
            ascii_code = (int) word[i];
            ascii_arr[ascii_code] += 1; 
        }

        for ( i = 0, j = 0; i < ASCII_LEN; i ++ ) {
            if ( ascii_arr[i] != 0 ) {
                mid_word[k][j] = (char) i;
                mid_word[k][j+1] = (char) ascii_arr[i] + '0';
                j += 2;
            }
        }

        memset(ascii_arr, 0, sizeof(ascii_arr));
        memcpy(word_arr[k], word, sizeof(word));
        k ++;
    }

    //print_word(word_arr, 0, k);
    //print_word(mid_word, 0, k);
    qsort_anagram(mid_word, word_arr, 0, k-1);
    //print_word(mid_word, 0, k);
    //print_word(word_arr, 0, k);
    find_anagram(mid_word, word_arr, k);


    fclose(fp);

    return 0;
}
