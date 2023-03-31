/*
Name: Mohamed Abdo Abdallah Ali Maklad
Email: mohamedabdo75200@gmail.com
Phone: 01551754160
Diploma: AMIT Embedded Systems Diploma
Group: D45 - Online
>>>>>>>>>>>>>>>>>>>(C Project)<<<<<<<<<<<<<<<<<<<<
*/
#include <stdio.h>
#include "functions.h"
int main()
{
    DataBaseInet();
    int select,ID;
    DB_Error Add;
    while(1)
    {
        printf("-------------------------\n");
        printf("|1|- shaw Database State|\n");
        printf("-------------------------\n");
        printf("|2|- Free Entries\t|\n");
        printf("-------------------------\n");
        printf("|3|- Full Entries\t|\n");
        printf("-------------------------\n");
        printf("|4|- Display Database\t|\n");
        printf("-------------------------\n");
        printf("|5|- Exist IDs list\t|\n");
        printf("-------------------------\n");
        printf("|6|- Display ID Date\t|\n");
        printf("-------------------------\n");
        printf("|7|- Delete Student\t|\n");
        printf("-------------------------\n");
        printf("|8|- Add Student\t|\n");
        printf("-------------------------\n");
        printf("|9|- Check Student State|\n");
        printf("-------------------------\n");
        printf("Enter Selection: ");
        scanf("%d",&select);
        printf("-------------------------\n");
        switch (select)
        {
            case 1:
                PrintDB_State(students);
                break;
            case 2:
                printf("free entries:%d\n",FreeEntries(students));
                break;
            case 3:
                printf("full entries:%d\n",FullEntries(students));
                break;
            case 4:
                PrintDataBase();
                break;
            case 5:
                PrintExistIDs();
                break;
            case 6:
                printf("Enter Student ID: ");
                scanf("%d",&ID);
                PrintDataBaseElement(ID);
                break;
            case 7:
                printf("Enter Student ID: ");
                scanf("%d",&ID);
                if (DeleteStudent(ID,students)==Successfully_Deleted)
                    printf("ID: %d >> Deleted Successfully\n",ID);
                if (DeleteStudent(ID,students)==Failed)
                    printf("Delete Failed\n");
                break;
            case 8:
                Add = AddStudent(students);
                if (Add == DBfull)
                    printf("Database is Full\n");
                if (Add == Successfully_Added)
                    printf("Student Successfully Added\n");
                if (Add == Error_Couese1_Grade)
                    printf("Student Error In Grade 1\n");
                if (Add == Error_Couese2_Grade)
                    printf("Student Error In Grade 2\n");
                if (Add == Error_Couese3_Grade)
                    printf("Student Error In Grade 3\n");
                break;
            case 9:
                printf("Enter Student ID: ");
                scanf("%d",&ID);
                if (CheckStudent_State(ID,students)==exist)
                    printf("Student Exist\n");
                else
                    printf("Student Not Exist\n");
                break;
            default:
                printf("Enter Valid Choice\n");
        }
    }

    return 0;
}
