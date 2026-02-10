#include <stdio.h>
#include <string.h>

struct Student {
    char name[50] , gender[10];
    int group_num , age;
    float avg;
};

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
void change_struct(int k ,char ch[15], int b , struct Student students[b]) {
    int num,gr;
    float av;
    if (strcmp(ch,"name")==0){
        printf("Enter new name:");
        fgets(students[k].name,50,stdin);
        students[k].name[strcspn(  students[k].name,"\n")]='\0';
    }
    else if (strcmp(ch,"group number")==0) {
        printf("Enter new group number:");
        scanf("%d" , &gr);
        students[k].group_num = gr;
    }
    else if (strcmp(ch,"age")==0) {
        printf("Enter new age:");
        scanf("%d" , &num);
        students[k].age = num;
    }
    else if (strcmp(ch,"average score")==0) {
        printf("Enter new average score:");
        scanf("%f" , &av);
        students[k].avg = av;
    }
    else if (strcmp(ch,"gender")==0) {
        printf("Enter new gender:");
        fgets(students[k].gender,10,stdin);
        students[k].gender[strcspn(  students[k].gender,"\n")]='\0';
    }
    else
        printf("Try again!\n");
}
void search_struct(int k ,char word[15],int b , struct Student students[b]){
    if (strcmp(word,"name")==0){
        printf("%s\n" , students[k].name);
    }
    else if (strcmp(word,"group number")==0) {
        printf("%d\n" , students[k].group_num);
    }
    else if (strcmp(word,"age")==0) {
        printf("%d\n",students[k].age);
    }
    else if (strcmp(word,"average score")==0) {
        printf("%.2f\n" , students[k].avg);
    }
    else if (strcmp(word,"gender")==0) {
        printf("%s\n" , students[k].gender);
    }
    else
        printf("Try again!\n");
}

int main() {
    int n;
    printf("How many students to add?: ");
    scanf("%d" , &n);
    getchar();
    struct Student students[n];
    while (1) {
        int choice;
        printf("Choose 1-5 to:\n"
               "1.Add students\n"
               "2.Show students\n"
               "3.Change\n"
               "4.Search\n"
               "5.Exit\n");
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
                break;
            }
            case 4: {
                int ind;
                char srch[15];
                printf("Enter index for search:");
                scanf("%d" , &ind);
                if (ind>n) {
                    printf("Try valid index\n");
                    break;
                }
                getchar();
                printf("Enter field for search:");
                fgets(srch ,15,stdin);
                srch[strcspn(srch,"\n")]='\0';
                search_struct(ind-1,srch,n,students);
                break;
            }
        }
        if (choice==5)
            break;
    }
    return 0;
}
