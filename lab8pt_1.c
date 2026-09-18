#include <stdio.h>

int main() {
    float a[10], *p = a, x;
    char c;
    int i, found;

    for(i = 0; i < 10; i++) {
        printf("Input %d : ",i+1);scanf("%f", p + i);
    }

    do {
        printf("Search: ");
        scanf("%f", &x);

        found = 0;

        for(i = 0; i < 10; i++) {
            if(*(p + i) == x) {
                printf("Position = %d Value = %.2f\n",
                       i + 1, *(p + i));
                found = 1;
            }
        }

        if(!found)
            printf("Cannot find the matched data\n");

        do {
            printf("Search again? Y/N: ");
            scanf(" %c", &c);

            if(c != 'Y' && c != 'y' &&
               c != 'N' && c != 'n') {
                printf("Esan can use only Y or N\n");
            }

        } while(c != 'Y' && c != 'y' &&
                c != 'N' && c != 'n');

    } while(c == 'Y' || c == 'y');

    return 0;
}