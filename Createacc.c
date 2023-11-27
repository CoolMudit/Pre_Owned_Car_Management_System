
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
