#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct course
{
    char title[50];
    int sem;
    int credits;
};

typedef struct course *Course;

int main()
{

    Course c = (Course)malloc(3 * sizeof(struct course));

    for (int i = 0; i < 3; i++)
    {
        printf("Enter Title sem and credits\n");
        scanf("%s %d %d", &c[i].title, &c[i].sem, &c[i].credits);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Course Title : %s\n Semester : %d\n Course credits : %d\n", c[i].title, c[i].sem, c[i].credits);
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (c[i].sem == 3)
            sum += c[i].credits;
    }

    printf("The total number of credits in 3rd semester courses is : %d\n", sum);

    return 0;
}