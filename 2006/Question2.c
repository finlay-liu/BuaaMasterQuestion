#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int grade;
} student;
student list[100];
int i = 0;

int compare (const void *a, const void *b)
{

    student *orderA = (student *)a;
    student *orderB = (student *)b;

    if ( orderB->grade != orderA->grade )
        return orderB->grade - orderA->grade;
    else
        return orderB->name - orderA->name;
}

int main ()
{

    int n;
	scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",&list[i].name);
		scanf("%d",&list[i].grade);
    }
    printf("AFTER sorting\n");

    qsort (list, n, sizeof(student), compare);

    for (i = 0; i < n; i++)
        printf ("student name = %s grade = %d \n", list[i].name, list[i].grade);
    return 0;
}