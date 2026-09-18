/* Lab8p4.c */
#include <stdio.h>
int main(void)
{
    int i, offset, b[] = {10, 20, 30, 40};
    int *bPtr = b;

    printf("Array b printed with: \n","Array Subscript notation \n");
    for (i=0; i<=3; i++)
    printf("b[%d] = %d \n",i,b[i]);

    printf("Pointer/offset notation where\nthepointer is the array name\n");
    for (offset=0; offset<=3; offset++)
    printf("*(b+%d) = %d\n",offset, *(b+offset));

    printf("Pointer subscript notation\n");
    for (i=0; i<=3; i++)
    printf("bPtr[%d] = %d\n", i, bPtr[i]);

    printf("Pointer/offset notation\n");
    for (offset=0; offset<=3; offset++)
    printf("*(bPter+ %d) = %d\n", offset, *(bPtr+offset));
    return 0;
}