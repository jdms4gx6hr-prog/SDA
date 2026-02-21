#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
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
void change_struct(int k ,char ch[15], int b , struct Student students[b]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return;
    }
    if (b <= 0) {
        printf("No students to change\n");
        return;
    }
    if (k<0 || k>=b) {
        printf("Wrong index!\n");
        return;
    }
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
void search_struct(char word[15],int b , struct Student students[b]){
    if (students == NULL) {
        printf("Array is NULL\n");
        return;
    }
    if (b <= 0) {
        printf("No students to search\n");
        return;
    }
    if (strcmp(word,"name")==0 || strcmp(word,"Name")==0){
        for (int i=0;i<b;i++)
            printf("%s\n" , students[i].name);
    }
    else if (strcmp(word,"group number")==0 || strcmp(word,"Group number")==0) {
        for (int i=0;i<b;i++)
            printf("%d\n" , students[i].group_num);
    }
    else if (strcmp(word,"age")==0 || strcmp(word,"Age")==0 ) {
        for (int i=0;i<b;i++)
            printf("%d\n" , students[i].age);
    }
    else if (strcmp(word,"average score")==0 || strcmp(word,"Average score")==0) {
        for (int i=0;i<b;i++)
            printf("%.2f\n" , students[i].avg);
    }
    else if (strcmp(word,"gender")==0 || strcmp(word,"Gender")==0) {
        for (int i=0;i<b;i++)
            printf("%s\n" , students[i].gender);
    }
    else
        printf("Try again!\n");
}
struct Student* extend_array(int n , int b , struct Student students[b] ) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL ;
    }
    if (n<0)
        return students;
    printf("Enter new students:\n");
    struct Student *temp = calloc((b+n) , sizeof(*temp));
    if (temp == NULL) {
        printf("Array is NULL\n");
        return students ;
    }
    getchar();
    for (int i=0 ; i<(b+n);i++) {
        if (i<b)
            temp[i]=students[i];
        else{
            printf("Name:");
            fgets(temp[i].name , 50,stdin);
            temp[i].name[strcspn( temp[i].name,"\n")] = '\0';
            printf("Group Number:");
            scanf("%d" , &temp[i].group_num);
            printf("Age:");
            scanf("%d" , &temp[i].age);
            printf("Average score:");
            scanf("%f" , &temp[i].avg);
            printf("Gender:");
            getchar();
            fgets(temp[i].gender , 10,stdin);
            temp[i].gender[strcspn( temp[i].gender,"\n")] = '\0';
        }
    }
    free(students);
    return temp;
}
struct Student* append_array(int b , struct Student students[b]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    printf("Enter student to add to the end: \n");
    getchar();
    struct Student *temp1 = calloc((b+1) , sizeof(*temp1));
    if (temp1==NULL) {
        printf("Memory allocation is failed\n");
        return students;
    }
    for (int i=0;i<(b+1);i++) {
        if (i<b)
            temp1[i]=students[i];
        else {
            printf("Name:");
            fgets(temp1[i].name , 50,stdin);
            temp1[i].name[strcspn( temp1[i].name,"\n")] = '\0';
            printf("Group Number:");
            scanf("%d" , &temp1[i].group_num);
            printf("Age:");
            scanf("%d" , &temp1[i].age);
            printf("Average score:");
            scanf("%f" , &temp1[i].avg);
            printf("Gender:");
            getchar();
            fgets(temp1[i].gender , 10,stdin);
            temp1[i].gender[strcspn( temp1[i].gender,"\n")] = '\0';
        }
    }
    free(students);
    return temp1;
}
struct Student* delete_last(int b , struct Student students[b]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    if (b<=0) {
        free(students);
        printf("No students to delete");
        return students;
    }
    if (b == 1) {
        free(students);
        printf("Last student deleted. Array is now empty.\n");
        return NULL;
    }
    printf("Deleting last student: \n");
    struct Student *temp2 = calloc((b-1) ,sizeof(*temp2));
    if (temp2==NULL) {
        printf("Memory allocation is failed\n");
        return students;
    }
    for (int i=0 ; i<(b-1) ; i++)
        temp2[i] = students[i];
    printf("Successful delete!\n");
    free(students);
    return temp2;

}
void free_struct(int b , struct Student students[b]) {
    if (students!=NULL){
        free(students);
        printf("Successful cleaning\n");
    }
}
int main() {
    int n;
    printf("How many students to add?: ");
    scanf("%d" , &n);
    getchar();
    struct Student *students = calloc(n , sizeof(*students));
    while (1) {
        int choice;
        printf("Choose 1-9 to:\n"
               "1.Add students\n"
               "2.Show students\n"
               "3.Change\n"
               "4.Search\n"
               "5.Extend students\n"
               "6.Append student\n"
               "7.Delete last student\n"
               "8.Cleaning memory\n"
               "9.Exit\n");
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
                n += new;
                break;
            }
            case 6: {
                students = append_array(n , students);
                n += 1;
                break;
            }
            case 7: {
                students = delete_last(n , students);
                n--;
                break;
            }
            case 8: {
                free_struct( n , students);
                students = NULL;
                break;
            }
        }
        if (choice == 9)
            break;

    }
    return 0;
}
