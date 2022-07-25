#ifndef ANAGRAM_H
#define ANAGRAM_H 1

#define MAX_WORD_LEN 100
#define ASCII_LEN 128

static void qsort_anagram(char mid_word[][MAX_WORD_LEN], char word_arr[][MAX_WORD_LEN], int mid_left, int mid_right);
static void swap_mid_word(char mid_word[][MAX_WORD_LEN], int mid_left, int mid_right);
static void swap_word_arr(char word_arr[][MAX_WORD_LEN], int mid_left, int mid_right);

static void find_anagram(char mid_word[][MAX_WORD_LEN], char word_arr[][MAX_WORD_LEN], int len);

#endif
