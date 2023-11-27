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


void createacc()
{       int num;
    
    
        printf("Enter the name:\n");
        gets(name);
          
        printf("Enter your mobile number:\n");
        gets(mobnum);
        
        printf("Enter your permanent address\n");
        gets(address);
        
        printf("Enter your Aadhar number:\n");
        gets(aadhar);


        printf("Enter your email id:\n");
        gets(emailid);
    
        printf("Create your username:\n");
        gets(user);

        printf("Create your new password:\n");
        gets(pass);
        
        printf("Confirm password:\n");
        gets(passcheck);
         
       
        if(strcmp(pass,passcheck)==0)
        {
 
    
     // file created with name as username.txt 
   
     FILE *uaadhar=fopen("useraadhar.txt","a");
     FILE *email=fopen("useremail.txt","a");
     FILE *checkemail=fopen("checkemail.txt","w");
     FILE *usern=fopen("username.txt","a");
     FILE *password=fopen("pass.txt","a");

    sprintf(buff,"%s.txt",user);  
    FILE *n=fopen(buff,"a");  

    fprintf(n, "%s   ", name);
    fprintf(n, "%s   ", mobnum);  
    fprintf(n,"%s   ",address);              
    fprintf(n,"%s   ",aadhar);
    fprintf(n, "%s   ", emailid); 

    fprintf(usern,"%s\n",user);
    fprintf(uaadhar,"%s\n",aadhar);
    fprintf(password, "%s\n", pass);
    fprintf(email,"%s\n",emailid);
    fprintf(checkemail,"%s",emailid);


    fclose(n);
    fclose(usern);
    fclose(uaadhar);
    fclose(email);
    fclose(password);
    fclose(email);
    fclose(checkemail);
    
    FILE *mail=fopen("checkemail.txt","r");

       
     while(fgets(em,sizeof(em),mail))
     {  
        
        if(strcmp(em,emailid)==0)
        {
            printf("Account created successfully !...You are now registered with this email ! Press 1 to login into your account Press 0 to exit system\n");

        while(1)
        {   
       event:
         scanf("%d",&num);
         fflush(stdin);
            if(num==1)
            {
            loginuser();
            }
            else if(num==0)
            {
                printf("exiting system...");
                break;
            }
            else{
                printf("You entered wrong option Please try again...");
                goto event;
            }
        }
        fclose(mail);
        }
     }

        

   
    }
    
}
