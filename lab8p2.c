/* Lab8p2.c */
#include <stdio.h>
int main(void)
{
    char letter = 'D';
    int num = 19 ;
    float point = 26.09;
    char *pt_letter;
    int *pt_num;
    float *pt_point;

    pt_letter = &letter;
    pt_num = &num;
    pt_point = &point;

    printf("Address of letter = %p \n", pt_letter);
    printf("Address of num = %p \n", pt_num);
    printf("Address of point = %p \n", pt_point);

    return 0;
}