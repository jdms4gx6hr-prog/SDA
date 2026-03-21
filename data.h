//
// Created by user on 21.03.2026.
//

#ifndef SDA_DATA_H
#define SDA_DATA_H
struct Student {
    char name[50] , gender[10];
    int group_num , age;
    float avg;
};
int savetofile(int b, struct Student students[b]);
void trim(char *str);
struct Student* loadFromFile(const char *filename, int *n);
void add_students(int a , struct Student students[a]) ;
void show_students (int b , struct Student students[b]);

#endif //SDA_DATA_H