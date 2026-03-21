#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int savetofile(int b , struct Student students[b]) {
    FILE *f = fopen("students.txt" , "w");
    if (f==NULL) {
        printf("Memory allocation is failed!\n");
        return 1;
    }
    for (int i=0;i<b;i++) {
        fprintf(f,"%-3d| %-40s| %-14d| %-8d| %-13.2f| %-10s|\n",
            i+1,students[i].name,students[i].group_num,students[i].age,students[i].avg,students[i].gender);
    }
    fclose(f);
    return 0;
    }
void trim(char *str) {
    if (str == NULL)
        return;

    while (isspace((unsigned char)*str)) {
        str++;
    }
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
}
struct Student* loadFromFile(const char *filename, int *n) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Can not open your file!\n");
        return NULL;
    }

    char buffer[256];
    *n = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        (*n)++;
    }

    if (*n == 0) {
        fclose(f);
        return NULL;
    }

    struct Student *students = calloc(*n, sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation is failed!\n");
        fclose(f);
        return NULL;
    }

    rewind(f);

    for (int i = 0; i < *n; i++) {
        if (fgets(buffer, sizeof(buffer), f) == NULL) {
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) <= 1) {
            i--;
            continue;
        }
        char *token;
        char *saveptr;
        token = strtok_r(buffer, "|", &saveptr);
        token = strtok_r(NULL, "|", &saveptr);
        if (token) {
            trim(token);
            strncpy(students[i].name, token, sizeof(students[i].name) - 1);
            students[i].name[sizeof(students[i].name) - 1] = '\0';
        } else {
            students[i].name[0] = '\0';
        }
        token = strtok_r(NULL, "|", &saveptr);
        if (token) {
            trim(token);
            students[i].group_num = atoi(token);
        } else {
            students[i].group_num = 0;
        }
        token = strtok_r(NULL, "|", &saveptr);
        if (token) {
            trim(token);
            students[i].age = atoi(token);
        } else {
            students[i].age = 0;
        }
        token = strtok_r(NULL, "|", &saveptr);
        if (token) {
            trim(token);
            students[i].avg = atof(token);
        } else {
            students[i].avg = 0.0;
        }
        token = strtok_r(NULL, "|", &saveptr);
        if (token) {
            trim(token);
            strncpy(students[i].gender, token, sizeof(students[i].gender) - 1);
            students[i].gender[sizeof(students[i].gender) - 1] = '\0';
        } else {
            students[i].gender[0] = '\0';
        }
    }

    fclose(f);
    return students;
}
void add_students(int a , struct Student students[a]) {
    for (int i=0;i<a;i++) {
        printf("Name:");
        fgets(students[i].name , 50,stdin);
        students[i].name[strcspn( students[i].name,"\n")] = '\0';
        printf("Group Number:");
        scanf("%d" , &students[i].group_num);
        printf("Age:");
        scanf("%d" , &students[i].age);
        printf("Average score:");
        scanf("%f" , &students[i].avg);
        printf("Gender:");
        getchar();
        fgets(students[i].gender , 10,stdin);
        students[i].gender[strcspn( students[i].gender,"\n")] = '\0';
    }
}
void show_students (int b , struct Student students[b]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return;
    }
    if (b <= 0) {
        printf("No students to show\n");
        return;
    }
    printf("\n%-3s| %-40s| %-14s| %-8s| %-13s| %-10s| " , "N.", "Name" , "Group Number" ,"Age", "Average Score" , "Gender");
    printf("\n");
    for (int i=0;i<b;i++) {
        printf("%-3d| %-40s| %-14d| %-8d| %-13.2f| %-10s|\n",
          i+1,
          students[i].name,
          students[i].group_num,
          students[i].age,
          students[i].avg,
          students[i].gender
        );
    }
}