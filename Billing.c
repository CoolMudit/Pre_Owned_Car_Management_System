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




void billing()
{   

    FILE *email=fopen("useremail.txt","r");
    FILE *carregnum = fopen("carregnum.txt", "r");
 
    printf("Enter the aadhaar id of customer\n");
    gets(custemail);                       //validate the customer email id

    while(fgets(em,100,email))
    { 
        if(strcmp(em,custemail)==0)
        {
            printf("User is already registered\n");
            printf("Enter the username of the user:\n");
            gets(billuser);
            sprintf(buff,"%s.txt",billuser);  
            FILE *n=fopen(buff,"r");      

            printf("Please enter the registration number of car in order to proceed for billing\n");
            gets(reg);
            
             FILE *carregnum = fopen("carregnum.txt", "r");
              FILE *carbrand = fopen("carbrand.txt", "r");
               FILE *carname = fopen("carname.txt", "r");
                FILE *caryear = fopen("caryear.txt", "r");
                  FILE *carLP = fopen("carLP.txt", "r");
                   



            while(fgets(details,sizeof(details),n) && fgets(creg,sizeof(creg),carregnum) && fgets(cb, sizeof(cb), carbrand) && fgets(cn, sizeof(cn), carname) && fgets(cy, sizeof(cy), caryear) &&  fgets(clist, 100, carLP)) 
            {
                if(strcmp(creg,reg)==0)
                {   
                    char filename[20];   // local variable 
                    printf("Creating bill...");
                    sprintf(filename,"%s.txt",creg);
                    FILE *bill=fopen(filename,"a");   //billing file created
                    c++;

                    fprintf(bill,"--------Pre Owned Car Management Billing System--------");
                    gettime(); //calling gettime to get the current date and time for billing 

                    fprintf(bill,"---Bill created on %s---",formattedTime);
                    
                    fprintf(bill,"-------------User details-------------");
                    fprintf(bill,"Customer name                 Customer mobile number                 Customer Permanent Address                 Customer Aadhar number                  Customer email-id",n);
                    fprintf(bill,details);
                    fprintf(bill,"----------------------------------------------------");
                    fprintf(bill, "---Registration number of the vehicle:%s\n---", creg);
                    fprintf(bill, "---Brand of the vehicle:%s\n---", cb);
                    fprintf(bill, "---Name of the vehicle:%s\n---", cn);
                    fprintf(bill, "---Manufacture year of the vehicle:%s\n---", cy);
                    fprintf(bill, "---List Price of the vehicle:%s\n---", clist);
                    

                    char *endptr;                          //converting char array to floating type to calculate gst 
                    float flist=strtod(clist,&endptr);
                    float gst=flist*0.18;

                    fprintf(bill, "GST applicable @18%% %.2f\n", gst);

                    float totalamt=gst+flist;                          // total amt to be paid by customer 
                    fprintf(bill,"------------------------------------");
                    fprintf(bill,"Total amount to be paid:%.2f",totalamt);

                }
            }
            fclose(carregnum);           
            fclose(carbrand);
            fclose(carname);
            fclose(caryear);
            fclose(carLP);
            fclose(n);
        }
        else
        {

            printf("You are not a registered user.. Please register first as a user!");
            break;
    
            
        }
    }
        
}
