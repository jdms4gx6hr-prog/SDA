#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

int main() {
    int n;
    printf("How many students to add?: ");
    scanf("%d", &n);
    getchar();
    struct Student *students = calloc(n, sizeof(*students));

    while (1) {
        int choice;
        printf("Choose 1-6 to:\n"
               "1.Add students\n"
               "2.Show students\n"
               "3.Save into a file\n"
               "4.Read from a file\n"
               "5.Save current state for ending program\n"
               "6.Exit\n");
        scanf("%d" ,&choice);
        switch (choice) {
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
                if (savetofile(n,students)!=0)
                    printf("Your file was not saved!Try again!\n");
                else
                    printf("Your file was saved!\n");
                break;
            }
            case 4: {
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
            case 5: {
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
        if (choice == 6)
            break;
    }

        return 0;
    }

