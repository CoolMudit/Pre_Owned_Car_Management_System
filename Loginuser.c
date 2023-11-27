
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


