#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define max_DB 10
/*----------------------------------*/
typedef struct student
{
    int id;
    int year;
} student;
/*----------------------------------*/
typedef struct course
{
    int id;
    char grad;
} course;
/*----------------------------------*/
typedef enum DB_Error
{
    DBfull,
    DBfree,
    Successfully_Added,
    Error_Couese1_Grade,
    Error_Couese2_Grade,
    Error_Couese3_Grade,
    Successfully_Deleted,
    Failed
} DB_Error;
/*----------------------------------*/
typedef enum state
{
    exist,
    not_exist
} state;
/*----------------------------------*/
struct DataBase
{
    student sudent;
    course course[3];
    state student_state;
} students[max_DB];

typedef struct DataBase DataBase;
/*----------------------------------*/
/*Functions Prototypes*/
DB_Error CheckDB(DataBase students[]);//done tested
char FreeEntries (DataBase students[]);//done tested
char FullEntries (DataBase students[]);//done tested
void PrintDB_State(DataBase students[]);//done tested
int git_free_entry(DataBase students[]);//done tested

DB_Error AddStudent(DataBase students[]);
DB_Error DeleteStudent(int stu_id,DataBase students[]);//done tested
state CheckStudent_State(int stu_id,DataBase students[]);//done tested

void DataBaseInet(void);//done tested
void PrintDataBase(void);//done tested
void PrintDataBaseElement(int i);//done tested
void PrintExistIDs(void);//done tested
#endif // FUNCTIONS_H_INCLUDED
