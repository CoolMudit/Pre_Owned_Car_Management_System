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


void loginuser()

{

     int n;
     FILE *usern=fopen("username.txt","r");
     FILE *password=fopen("pass.txt","r");
     int flag=0;int c=3;


        do
        {
         
        printf("Enter your username:\n");
        gets(user);
        
        printf("Enter password:\n");
        gets(pass);
        
        
        while(fgets(us,sizeof(us),usern) && fgets(pa,sizeof(pa),password) )
        {   
           
            if(strcmp(pa,pass)==0)
            {
                printf("Welcome %s\n",us);
                {
                    printf("Press 1 to visit menu\nPress 0 to logout\n");
                    scanf("%d",&n);
                    if(n==1)
                    {
                        selectusermenu();        //User menu page
                    }
                    else if(n==0)
                    {
                        break;
                    }
                }


            }
            else{
                c--;
                printf("You have entered wrong username or password try again!,You have only %d attempts left",c);
                flag=1;
               

            }


        }
        
        }while (flag==1 && c!=1);
       
     fclose(usern);
     fclose(password);
}


