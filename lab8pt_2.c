#include <stdio.h>

struct Student {
    char name[50];
    int id;
    char phone[20];
    char pro, phy, cal, com;
};

float grade(char g) {
    if(g >= 'A' && g <= 'D')
        return 'E' - g;

    return 0;
}

char inputGrade(char subject[]) {
    char g;

    while(1) {
        printf("%s: ", subject);
        scanf(" %c", &g);

        if(g == 'A' || g == 'B' || g == 'C' ||
           g == 'D' || g == 'F') {
            return g;
        }

        printf("Grade must be A, B, C, D or F\n");
    }
}

int inputID(char text[]) {
    int id;
    char ch;

    while(1) {
        printf("%s", text);

        if(scanf("%d", &id) == 1) {
            return id;
        }

        printf("ID must be a number\n");

        while((ch = getchar()) != '\n' && ch != EOF);
    }
}

int main() {
    struct Student s[5], *p = s;
    int i, id, found;
    float gpa;

    for(i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", (p+i)->name);

        (p+i)->id = inputID("ID: ");

        printf("Phone: ");
        scanf("%19s", (p+i)->phone);

        (p+i)->pro = inputGrade("Programming");
        (p+i)->phy = inputGrade("Physics");
        (p+i)->cal = inputGrade("Calculus");
        (p+i)->com = inputGrade("Computer");
    }

    while(1) {
        id = inputID("\nSearch ID (0 exit): ");

        if(id == 0)
            break;

        found = 0;

        for(i = 0; i < 5; i++) {

            if((p+i)->id == id) {

                gpa = (
                    grade((p+i)->pro) +
                    grade((p+i)->phy) +
                    grade((p+i)->cal) +
                    grade((p+i)->com)
                ) / 4.0;

                printf("\nName: %s\n", (p+i)->name);
                printf("ID: %d\n", (p+i)->id);
                printf("Phone: %s\n", (p+i)->phone);

                printf("Programming: %c\n", (p+i)->pro);
                printf("Physics: %c\n", (p+i)->phy);
                printf("Calculus: %c\n", (p+i)->cal);
                printf("Computer: %c\n", (p+i)->com);

                printf("GPA: %.2f\n", gpa);

                found = 1;
            }
        }

        if(!found)
            printf("Search not found\n");
    }

    return 0;
}