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
    if (strcasecmp(word,"name")==0){
        for (int i=0;i<b;i++)
            printf("%s\n" , students[i].name);
    }
    else if (strcasecmp(word,"group number")==0) {
        for (int i=0;i<b;i++)
            printf("%d\n" , students[i].group_num);
    }
    else if (strcasecmp(word,"age")==0) {
        for (int i=0;i<b;i++)
            printf("%d\n" , students[i].age);
    }
    else if (strcasecmp(word,"average score")==0) {
        for (int i=0;i<b;i++)
            printf("%.2f\n" , students[i].avg);
    }
    else if (strcasecmp(word,"gender")==0) {
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
struct Student* sort_student_increase(int b , struct Student students[b] , char word[50]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    if (b <= 0) {
        printf("Array is empty\n");
        return students;
    }
    if (strcasecmp(word,"name")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (strcmp(students[j].name,students[j+1].name)>0) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"group number")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].group_num>students[j+1].group_num) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"age")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].age>students[j+1].age) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"average score")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].avg>students[j+1].avg) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"gender")==0) {
            for (int i=0;i<b-1;i++) {
                for (int j=0 ;j< b-i-1;j++) {
                    if (strcmp(students[j].gender,students[j+1].gender)>0) {
                        struct Student temp =students[j];
                        students[j] = students[j+1];
                        students[j+1] = temp;
                    }
                }
            }
        printf("Successful sort\n");
        }
    else
        printf("Try again!\n");
    return students;

}
struct Student* sort_student_decrease(int b , struct Student students[b] , char word[50]) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    if (b <= 0) {
        printf("Array is empty\n");
        return students;
    }
    if (strcasecmp(word,"name")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (strcmp(students[j].name,students[j+1].name)<0) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"group number")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].group_num<students[j+1].group_num) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"age")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].age<students[j+1].age) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"average score")==0) {
        for (int i=0;i<b-1;i++) {
            for (int j=0 ;j< b-i-1;j++) {
                if (students[j].avg<students[j+1].avg) {
                    struct Student temp =students[j];
                    students[j] = students[j+1];
                    students[j+1] = temp;
                }
            }
        }
        printf("Successful sort\n");
    }
    else if (strcasecmp(word,"gender")==0) {
            for (int i=0;i<b-1;i++) {
                for (int j=0 ;j< b-i-1;j++) {
                    if (strcmp(students[j].gender,students[j+1].gender)<0) {
                        struct Student temp =students[j];
                        students[j] = students[j+1];
                        students[j+1] = temp;
                    }
                }
            }
        printf("Successful sort\n");
        }
    else
        printf("Try again!\n");
    return students;
}
struct Student* insert_students(int b , struct Student students[b] , int index ) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    if (b <= 0) {
        printf("Array is empty\n");
        return students;
    }
    if (index<0 || index>=b) {
        printf("Wrong index!\n");
        return students;
    }
    printf("Enter student to add : \n");
    getchar();
    struct Student *temp3 = calloc((b+1) , sizeof(*temp3));
    if (temp3==NULL) {
        printf("Memory allocation is failed\n");
        return students;
    }
    for (int i=0;i<index;i++) {
        temp3[i]=students[i];
    }
    printf("Name:");
    fgets(temp3[index].name , 50,stdin);
    temp3[index].name[strcspn( temp3[index].name,"\n")] = '\0';
    printf("Group Number:");
    scanf("%d" , &temp3[index].group_num);
    printf("Age:");
    scanf("%d" , &temp3[index].age);
    printf("Average score:");
    scanf("%f" , &temp3[index].avg);
    printf("Gender:");
    getchar();
    fgets(temp3[index].gender , 10,stdin);
    temp3[index].gender[strcspn( temp3[index].gender,"\n")] = '\0';
    for (int i=index;i<b;i++) {
        temp3[i+1]=students[i];
    }
    printf("Successful insert!\n");
    free(students);
    return temp3;
}
struct Student* delete_student(int b , struct Student students[b] , int index) {
    if (students == NULL) {
        printf("Array is NULL\n");
        return NULL;
    }
    if (b <= 0) {
        printf("Array is empty\n");
        return students;
    }
    if (index<0 || index>=b) {
        printf("Wrong index!\n");
        return students;
    }
    struct Student *temp4 = calloc((b-1) , sizeof(*temp4));
    if (temp4==NULL) {
        printf("Memory allocation is failed!\n");
        return students;
    }
    for (int i=0;i<index;i++) {
        temp4[i] = students[i];
    }
    for (int i=(index+1);i<b;i++) {
        temp4[i-1] = students[i];
    }
    printf("Successful delete!\n");
    free(students);
    return temp4;
}
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
int main() {
    printf("Running master");
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
