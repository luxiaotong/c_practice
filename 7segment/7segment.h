#ifndef SEGMENT_H
#define SEGMENT_H 1

#define MAX_NUMBER_LEN 16
#define MAX_SEGMENT_LEN 7

void seven_segment_display(char *str, int len);
void print_segment_part(int segment, int is_show, char *segment_part_str);

#endif
