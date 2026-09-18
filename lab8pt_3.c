#include <stdio.h>

struct Address {
    char num[10];
    char road[30];
    char sub[30];
    char dis[30];
    char pro[30];
    char zip[10];
};

struct Contact {
    char land[20];
    char mobile[20];
    char fax[20];
};

struct Student {
    char name[50];
    int id;

    char programming;
    char physics;
    char calculus;
    char computer;

    struct Address address;
    struct Contact contact;
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
           g == 'D' || g == 'F')
            return g;

        printf("Grade must be A, B, C, D or F\n");
    }
}

int inputID(char text[]) {
    int id;
    char ch;

    while(1) {
        printf("%s", text);

        if(scanf("%d", &id) == 1)
            return id;

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

        (p+i)->programming = inputGrade("Programming");
        (p+i)->physics = inputGrade("Physics");
        (p+i)->calculus = inputGrade("Calculus");
        (p+i)->computer = inputGrade("Computer");

        printf("House Number: ");
        scanf("%9s", (p+i)->address.num);

        printf("Road: ");
        scanf(" %[^\n]", (p+i)->address.road);

        printf("Subdistrict: ");
        scanf(" %[^\n]", (p+i)->address.sub);

        printf("District: ");
        scanf(" %[^\n]", (p+i)->address.dis);

        printf("Province: ");
        scanf(" %[^\n]", (p+i)->address.pro);

        printf("ZIP: ");
        scanf("%9s", (p+i)->address.zip);

        printf("Landline: ");
        scanf("%19s", (p+i)->contact.land);

        printf("Mobile: ");
        scanf("%19s", (p+i)->contact.mobile);

        printf("Fax: ");
        scanf("%19s", (p+i)->contact.fax);
    }

    while(1) {

        id = inputID("\nSearch ID (0 exit): ");

        if(id == 0)
            break;

        found = 0;

        for(i = 0; i < 5; i++) {

            if((p+i)->id == id) {

                gpa = (
                    grade((p+i)->programming) +
                    grade((p+i)->physics) +
                    grade((p+i)->calculus) +
                    grade((p+i)->computer)
                ) / 4.0;

                printf("\nName: %s\n", (p+i)->name);
                printf("ID: %d\n", (p+i)->id);

                printf("Programming: %c\n", (p+i)->programming);
                printf("Physics: %c\n", (p+i)->physics);
                printf("Calculus: %c\n", (p+i)->calculus);
                printf("Computer: %c\n", (p+i)->computer);

                printf("GPA: %.2f\n", gpa);

                printf("Address: %s %s %s %s %s %s\n",
                    (p+i)->address.num,
                    (p+i)->address.road,
                    (p+i)->address.sub,
                    (p+i)->address.dis,
                    (p+i)->address.pro,
                    (p+i)->address.zip
                );

                printf("Landline: %s\n",
                    (p+i)->contact.land);

                printf("Mobile: %s\n",
                    (p+i)->contact.mobile);

                printf("Fax: %s\n",
                    (p+i)->contact.fax);

                found = 1;
            }
        }

        if(!found)
            printf("Search not found\n");
    }

    return 0;
}