#include "functions.h"
/*----------------------------------*/
DB_Error CheckDB(DataBase students[])
{
    for (int i=0;i<max_DB;i++)
    {
        if (students[i].student_state==not_exist)
        return DBfree;
    }
    return DBfull;
}
/*----------------------------------*/
char FreeEntries (DataBase students[])
{
    char Free_Entries=0;
    for (int i=0;i<max_DB;i++)
    {
        if (students[i].student_state==not_exist)
            Free_Entries++;
    }
        return Free_Entries;
}
/*----------------------------------*/
char FullEntries (DataBase students[])
{
    char Full_Entries=0;
    for (int i=0;i<max_DB;i++)
    {
        if (students[i].student_state==exist)
            Full_Entries++;
    }
        return Full_Entries;
}
/*----------------------------------*/
void PrintDB_State(DataBase students[])
{
    printf("free entries:%d\nfull entries:%d\n",FreeEntries(students),FullEntries(students));
}
/*----------------------------------*/
int git_free_entry(DataBase students[])
{
    int i;
    for (i=0;i<max_DB;i++)
        if (students[i].student_state==not_exist)
            return i;
}
/*----------------------------------*/
DB_Error AddStudent(DataBase students[])
{
    if(CheckDB(students)==DBfull)
        return DBfull;
    else
    {
        int i = git_free_entry(students);
        printf("student ID:");
        scanf("%d",&(students[i].sudent.id));
        printf("\nAcademic Year:");
        scanf("%d",&students[i].sudent.year);
        printf("\nCourse 1 ID:");
        scanf("%d",&students[i].course[0].id);
        printf("\nCourse 1 Grad (0-100%):");
        scanf("%d",&students[i].course[0].grad);
        if (students[i].course[0].grad >100 || students[i].course[0].grad < 0)
            return Error_Couese1_Grade;
        printf("\nCourse 2 ID:");
        scanf("%d",&students[i].course[1].id);
        printf("\nCourse 2 Grad (0-100%):");
        scanf("%d",&students[i].course[1].grad);
        if (students[i].course[1].grad >100 || students[i].course[1].grad < 0)
            return Error_Couese2_Grade;
        printf("\nCourse 3 ID:");
        scanf("%d",&students[i].course[2].id);
        printf("\nCourse 3 Grad (0-100%):");
        scanf("%d",&students[i].course[2].grad);
        if (students[i].course[2].grad >100 || students[i].course[2].grad < 0)
            return Error_Couese3_Grade;
        students[i].student_state=exist;
        return Successfully_Added;

    }
}
/*----------------------------------*/
DB_Error DeleteStudent(int stu_id,DataBase students[])
{
    int i;
    for (i=0;i<max_DB;i++)
    {
        if (stu_id == students[i].sudent.id)
        {
            students[i].student_state =not_exist;
            ;
        }
    }
    return Failed;
}
/*----------------------------------*/
state CheckStudent_State(int stu_id,DataBase students[])
{
    int i;
    for (i=0;i<max_DB;i++)
    {
        if (stu_id == students[i].sudent.id)
            return students[i].student_state;
    }
    return not_exist;
}
/*----------------------------------*/
void DataBaseInet(void)
{
    /*======                   (student 0)         ====== */
    students[0].sudent.id      =        1000;
    students[0].sudent.year    =        2023;
    students[0].course[0].id   =        3333;
    students[0].course[0].grad =        100;
    students[0].course[1].id   =        1111;
    students[0].course[1].grad =        90;
    students[0].course[2].id   =        2222;
    students[0].course[2].grad =        80;
    students[0].student_state  =        exist;
    /*======                   (student 1)         ====== */
    students[1].sudent.id      =        1001;
    students[1].sudent.year    =        2023;
    students[1].course[0].id   =        3333;
    students[1].course[0].grad =        88;
    students[1].course[1].id   =        1111;
    students[1].course[1].grad =        45;
    students[1].course[2].id   =        2222;
    students[1].course[2].grad =        55;
    students[1].student_state  =        exist;
    /*======                   (student 2)         ====== */
    students[2].sudent.id      =        1002;
    students[2].sudent.year    =        2023;
    students[2].course[0].id   =        3333;
    students[2].course[0].grad =        23;
    students[2].course[1].id   =        1111;
    students[2].course[1].grad =        78;
    students[2].course[2].id   =        2222;
    students[2].course[2].grad =        59;
    students[2].student_state  =        exist;
    /*======                   (student 3)         ====== */
    students[3].sudent.id      =        1003;
    students[3].sudent.year    =        2023;
    students[3].course[0].id   =        3333;
    students[3].course[0].grad =        65;
    students[3].course[1].id   =        1111;
    students[3].course[1].grad =        85;
    students[3].course[2].id   =        2222;
    students[3].course[2].grad =        56;
    students[3].student_state  =        exist;
    /*======                   (student 4)         ====== */
    students[4].sudent.id      =        1004;
    students[4].sudent.year    =        2022;
    students[4].course[0].id   =        3333;
    students[4].course[0].grad =        65;
    students[4].course[1].id   =        1111;
    students[4].course[1].grad =        68;
    students[4].course[2].id   =        2222;
    students[4].course[2].grad =        54;
    students[4].student_state  =        exist;
    /*======                   (student 5)         ====== */
    students[5].sudent.id      =        1005;
    students[5].sudent.year    =        2022;
    students[5].course[0].id   =        3333;
    students[5].course[0].grad =        54;
    students[5].course[1].id   =        1111;
    students[5].course[1].grad =        54;
    students[5].course[2].id   =        2222;
    students[5].course[2].grad =        54;
    students[5].student_state  =        exist;
    /*======                   (student 6)         ====== */
    students[6].sudent.id      =        1006;
    students[6].sudent.year    =        2022;
    students[6].course[0].id   =        3333;
    students[6].course[0].grad =        46;
    students[6].course[1].id   =        1111;
    students[6].course[1].grad =        92;
    students[6].course[2].id   =        2222;
    students[6].course[2].grad =        29;
    students[6].student_state  =        exist;
    /*======                   (student 7)         ====== */
    students[7].sudent.id      =        1007;
    students[7].sudent.year    =        2022;
    students[7].course[0].id   =        3333;
    students[7].course[0].grad =        94;
    students[7].course[1].id   =        1111;
    students[7].course[1].grad =        35;
    students[7].course[2].id   =        2222;
    students[7].course[2].grad =        56;
    students[7].student_state  =        not_exist;
    /*======                   (student 8)         ====== */
    students[8].sudent.id      =        1008;
    students[8].sudent.year    =        2022;
    students[8].course[0].id   =        3333;
    students[8].course[0].grad =        90;
    students[8].course[1].id   =        1111;
    students[8].course[1].grad =        80;
    students[8].course[2].id   =        2222;
    students[8].course[2].grad =        40;
    students[8].student_state  =        not_exist;
    /*======                   (student 9)         ====== */
    students[9].sudent.id      =        1009;
    students[9].sudent.year    =        2022;
    students[9].course[0].id   =        3333;
    students[9].course[0].grad =        50;
    students[9].course[1].id   =        1111;
    students[9].course[1].grad =        40;
    students[9].course[2].id   =        2222;
    students[9].course[2].grad =        60;
    students[9].student_state  =        not_exist;
    /*======                   (END)    ======     */
}
void PrintDataBaseElement(int i)
{
    printf("Student ID:%d\n",students[i].sudent.id);
    printf("Academic Year:%d\n",students[i].sudent.year);
    printf("Course 1 ID:%d\n",students[i].course[0].id);
    printf("Course 1 Grad:%d\n",students[i].course[0].grad);
    printf("Course 2 ID:%d\n",students[i].course[1].id );
    printf("Course 2 Grad:%d\n",students[i].course[1].grad);
    printf("Course 3 ID:%d\n",students[i].course[2].id);
    printf("Course 3 Grad:%d\n",students[i].course[2].grad);
    printf("===========================\n");
}
void PrintDataBase(void)
{
    int i;
    for (i=0;i<max_DB;i++)
    {
        if (students[i].student_state==exist)
        {
            PrintDataBaseElement(i);
        }
    }
}
void PrintExistIDs(void)
{

    int i;
    for (i=0;i<max_DB;i++)
    {
        if (students[i].student_state==exist)
        {
            printf("%d\n",students[i].sudent.id);
        }
    }
}
