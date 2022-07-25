#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "7segment.h"
#include "my_util.h"

void seven_segment_display(char *str, int len)
{
    int i = 0, j = 0, number = 0;
    //int output_order[7] = {2, 3, 1, 4, 5, 0, 6};
    int digit_map[][7] = {
        {1, 0, 1, 1, 1, 1, 1}, //0
        {0, 0, 0, 0, 1, 0, 1}, //1
        {1, 1, 1, 0, 1, 1, 0}, //2
        {1, 1, 1, 0, 1, 0, 1}, //3
        {0, 1, 0, 1, 1, 0, 1}, //4
        {1, 1, 1, 1, 0, 0, 1}, //5
        {1, 1, 1, 1, 0, 1, 1}, //6
        {0, 0, 1, 0, 1, 0, 1}, //7
        {1, 1, 1, 1, 1, 1, 1}, //8
        {1, 1, 1, 1, 1, 0, 1}, //9
    };

    char *segment_part_str  = malloc(sizeof(char)*4);
    char *segment_line1     = malloc(sizeof(char)*MAX_NUMBER_LEN*5);
    char *segment_line2     = malloc(sizeof(char)*MAX_NUMBER_LEN*5);
    char *segment_line3     = malloc(sizeof(char)*MAX_NUMBER_LEN*5);

    memset(segment_part_str, 0, sizeof(char)*4);
    memset(segment_line1, 0, sizeof(char)*MAX_NUMBER_LEN*5);
    memset(segment_line2, 0, sizeof(char)*MAX_NUMBER_LEN*5);
    memset(segment_line3, 0, sizeof(char)*MAX_NUMBER_LEN*5);

    for ( i = 0; i < len; i ++ ) {
        number = str[i] - '0';

        print_segment_part(2, digit_map[number][2], segment_part_str);
        strcat(segment_line1, segment_part_str);

        print_segment_part(3, digit_map[number][3], segment_part_str);
        strcat(segment_line2, segment_part_str);
        print_segment_part(1, digit_map[number][1], segment_part_str);
        strcat(segment_line2, segment_part_str);
        print_segment_part(4, digit_map[number][4], segment_part_str);
        strcat(segment_line2, segment_part_str);

        print_segment_part(5, digit_map[number][5], segment_part_str);
        strcat(segment_line3, segment_part_str);
        print_segment_part(0, digit_map[number][0], segment_part_str);
        strcat(segment_line3, segment_part_str);
        print_segment_part(6, digit_map[number][6], segment_part_str);
        strcat(segment_line3, segment_part_str);
    }

    printf("%s\n", segment_line1);
    printf("%s\n", segment_line2);
    printf("%s\n", segment_line3);

    free(segment_part_str);
    free(segment_line1);
    free(segment_line2);
    free(segment_line3);

    return;
}

void print_segment_part(int segment, int is_show, char *segment_part_str)
{
    switch ( segment ) {
    case 0: 
    case 1:
        if ( is_show ) strncpy(segment_part_str, "__", 4);
        else           strncpy(segment_part_str, "  ", 4);
        break;
    case 2:
        if ( is_show ) strncpy(segment_part_str, " __ ", 4);
        else           strncpy(segment_part_str, "    ", 4);
        break;
    case 4:
        if ( is_show ) strncpy(segment_part_str, "|", 4);
        else           strncpy(segment_part_str, " ", 4);
        break;
    case 3:
    case 5:
    case 6:
        if ( is_show ) strncpy(segment_part_str, "|", 4);
        else           strncpy(segment_part_str, " ", 4);
        break;
    default:
        strncpy(segment_part_str, "   ", 4);
    }

    return;
}

int main()
{
    char number_str[MAX_NUMBER_LEN];

    while ( scanf("%s", number_str) ) {
        seven_segment_display(number_str, strlen(number_str));
    }

    return 0;
}
