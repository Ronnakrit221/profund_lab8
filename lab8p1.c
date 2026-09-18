/* Lab8p1.c */
#include <stdio.h>
int main(void)
{
    int num1 = 113, num2;
    float price1 = 4.85;
    char hint1 = 'J', hint2;

    int *pt_num;
    float *pt_price;
    char *pt_hint;

    pt_num = &num1;
    pt_price = &price1;
    pt_hint = &hint1;

    num2 = *pt_num;
    hint2 = *pt_hint;

    printf("Variable num1 = %d \n", num2);
    printf("Variable price1 = %f \n", *pt_price);
    printf("Variable hint2 = %c \n", hint2);
    return 0;
} //main