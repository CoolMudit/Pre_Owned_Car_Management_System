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


void databasedisplay()
{

    FILE *carbrand = fopen("carbrand.txt", "r");
    FILE *carname = fopen("carname.txt", "r");
    FILE *caryear = fopen("caryear.txt", "r");
    FILE *carfuel = fopen("carfuel.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");
    FILE *carCP = fopen("carCP.txt", "r");
    FILE *carLP = fopen("carLP.txt", "r");

    while (fgets(cb, sizeof(cb), carbrand) && fgets(cn, sizeof(cn), carname) && fgets(cy, sizeof(cy), caryear) && fgets(cf, sizeof(cf), carfuel) && fgets(crn, sizeof(crn), carregnum) && fgets(ccost, sizeof(ccost), carCP) && fgets(clist, sizeof(clist), carLP))

    {
        printf("Car name: %s\nCar brand: %s\nYear of manufacture: %s\nFuel type: %s\nRegistration Number: %s\nCostPrice: %s\nList Price: %s", cn, cb, cy, cf, crn, ccost, clist);
    }

    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}
