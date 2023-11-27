#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

char cb[20];
char cn[20];
char cy[20];
char cf[20];
char crn[20];
char ccost[20];
char clist[20];

char carb[20];
char carn[20];
char cary[20];
                
char user[20];  //charater array for user to take user input  
char name[20];
char pass[7];   //pin should be exactly of 6 digits
char passcheck[20];
char buff[20];
char mobnum[11];
char emailid[25];
char checkmail[25];
char address[20];
char aadhar[20];


char us[20];   //character arrays for user to validate
char em[25]; 
char pa[7];  

char adminus[20];    //character arrays for admin  to take user input
char adminpass[20]; 

char aduser[20];     //character arrays for admin to validate
char adpass[20]; 



char custemail[20];  //character array for billing 
char reg[20];        
char creg[20];
char billuser[20];
char details[40];
char  formattedTime[100];  //To get current date and time for billing


char userreg[20];   //array to be used to display the bill of the car 
char readbill[100];
static int c=0;



typedef struct PreOwnedCarManagementSystem
{
    char cbrand[20];
    char cname[20];
    char cyear[20];
    char cfuel[20];
    char cregnum[20];
    char cCP[20];
    char cLP[20];

} car;

car arr;



void DataBase()
{

    FILE *carbrand = fopen("carbrand.txt", "a");
    FILE *carname = fopen("carname.txt", "a");
    FILE *caryear = fopen("caryear.txt", "a");
    FILE *carfuel = fopen("carfuel.txt", "a");
    FILE *carregnum = fopen("carregnum.txt", "a");
    FILE *carCP = fopen("carCP.txt", "a");
    FILE *carLP = fopen("carLP.txt", "a");

    fprintf(carbrand, "%s\n", arr.cbrand);
    fprintf(carname, "%s\n", arr.cname);
    fprintf(caryear, "%s\n", arr.cyear);
    fprintf(carfuel, "%s\n", arr.cfuel);
    fprintf(carregnum, "%s\n", arr.cregnum);
    fprintf(carCP, "%s\n", arr.cCP);
    fprintf(carLP, "%s\n", arr.cLP);

    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}
