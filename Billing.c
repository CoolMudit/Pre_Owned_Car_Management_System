
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
