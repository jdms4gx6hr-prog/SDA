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
void change_struct(int k, char ch[15], int b, struct Student students[b]) ;
void search_struct(char word[15],int b , struct Student students[b]);
struct Student* extend_array(int n , int b , struct Student students[b] );
struct Student* append_array(int b , struct Student students[b]);
struct Student* delete_last(int b , struct Student students[b]);
void free_struct(int b , struct Student students[b]);
struct Student* sort_student_increase(int b , struct Student students[b] , char word[50]);
struct Student* sort_student_decrease(int b , struct Student students[b] , char word[50]);
struct Student* insert_students(int b , struct Student students[b] , int index );
struct Student* delete_student(int b , struct Student students[b] , int index);
#endif //SDA_DATA_H