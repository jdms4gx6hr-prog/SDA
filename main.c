#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

int main() {
    int n;
    printf("How many students to add?: ");
    scanf("%d" , &n);
    getchar();
    struct Student *students = calloc(n , sizeof(*students));
    while (1) {
        int choice;
        printf("Choose 1-16 to:\n"
               "1.Add students\n"
               "2.Show students\n"
               "3.Change\n"
               "4.Search\n"
               "5.Extend students\n"
               "6.Append student\n"
               "7.Delete last student\n"
               "8.Cleaning memory\n"
               "9.Sort students in ascending order\n"
               "10.Sort students in descending order\n"
               "11.Insert student\n"
               "12.Delete student\n"
               "13.Save into a file\n"
               "14.Read from a file\n"
               "15.Save current state for ending program\n"
               "16.Exit\n");
        scanf("%d" ,&choice);
        switch (choice){
            case 1: {
                getchar();
                add_students(n , students);
                break;
            }
            case 2: {
                show_students(n,students);
                break;
            }
            case 3: {
                int index;
                char field[15];
                printf("Enter index to change :");
                scanf("%d" , &index);
                if (index>n) {
                    printf("Try valid index\n");
                    break;
                }
                getchar();
                printf("Enter field to change:");
                fgets(field,15,stdin);
                field[strcspn(field,"\n")]='\0';
                change_struct(index-1,field,n,students);
                show_students(n,students);
                break;
            }
            case 4: {
                char srch[15];
                getchar();
                printf("Enter field for search:");
                fgets(srch ,15,stdin);
                srch[strcspn(srch,"\n")]='\0';
                search_struct(srch,n,students);
                break;
            }
            case 5: {
                int new;
                printf("Enter number of students for extending:");
                scanf("%d" , &new);
                students = extend_array(new , n , students);
                show_students(n,students);
                n += new;
                break;
            }
            case 6: {
                students = append_array(n , students);
                n += 1;
                show_students(n,students);
                break;
            }
            case 7: {
                students = delete_last(n , students);
                show_students(n,students);
                n-=1;
                break;
            }
            case 8: {
                free_struct( n , students);
                students = NULL;
                break;
            }
            case 9: {
                char field[50];
                printf("Enter field for sort:");
                getchar();
                fgets(field,50,stdin);
                field[strcspn(field,"\n")] = '\0';
                sort_student_increase(n,students,field);
                printf("\n");
                show_students(n,students);
                break;
            }
            case 10: {
                char field[50];
                printf("Enter field for sort:");
                getchar();
                fgets(field,50,stdin);
                field[strcspn(field,"\n")] = '\0';
                sort_student_decrease(n,students,field);
                printf("\n");
                show_students(n,students);
                break;
            }
            case 11: {
                int index;
                printf("Enter index for inserting:");
                scanf("%d" , &index);
                students = insert_students(n,students,index-1);
                n+=1;
                show_students(n,students);
                break;
            }
            case 12: {
                int index1;
                printf("Enter index to delete:");
                scanf("%d" , &index1);
                students = delete_student(n,students,index1-1);
                n-=1;
                show_students(n,students);
                break;
            }
            case 13: {
                if (savetofile(n,students)!=0)
                    printf("Your file was not saved!Try again!\n");
                else
                    printf("Your file was saved!\n");
                break;
            }
            case 14: {
                char filename[100];
                printf("Enter the name of your file:");
                getchar();
                fgets(filename , 100,stdin);
                filename[strcspn(filename,"\n")] = '\0';
                struct Student *loaded_students = loadFromFile(filename,&n);
                if (loaded_students==NULL) {
                    printf("Error\n");
                    break;
                }
                free(students);
                students = loaded_students;
                printf("There are %d students\n" , n);
                show_students(n , students);
                break;
            }
            case 15: {
                if (n>0 && students!=NULL) {
                    savetofile(n,students);
                    printf("Current student list is saved!\n");
                }
                else
                    printf("Nothing to save!");
                free(students);
                exit(0);
            }

        }
        if (choice == 16)
            break;
    }
    return 0;
}


