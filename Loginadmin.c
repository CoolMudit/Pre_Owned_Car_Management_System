
void loginadmin()
{ int flag=0; 

    FILE *adusername=fopen("adminusername.txt","r");
    FILE *adpassword=fopen("adminpassword.txt","r");
   do
   {
   printf("Enter admin username:\n");
    scanf("%s",adminus);
    printf("Enter your admin password\n");
    scanf("%s",adminpass);

    while(fgets(aduser,sizeof(aduser),adusername) && fgets(adpass,sizeof(adpass),adpassword))
    {
        if(strcmp(adminus,aduser)==0 && strcmp(adminpass,adpass)==0)
        {
            printf("Welcome to Admin menu !\n");
            selectadminmenu();                   //Admin menu page
        }
        else{
            printf("Username or password is incorrect try again...");
            flag=1;
        }
    }
   } while (flag==1);
   
    
fclose(adusername);
fclose(adpassword);
    

}
