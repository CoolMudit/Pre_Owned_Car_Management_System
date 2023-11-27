
void interface()
{ int ch;

    printf("Welcome to Pre Owned Car Management System\n");
   
    while(1)
    {
     printf("Press 1 to create user account\nPress 2 to login into user account\nPress 3 to login into Admin account\nPress 0 to exit the system\n");
    
    
    scanf("%d",&ch);
    fflush(stdin);
    if(ch==1)
    {
     
      createacc();
     
     }
    
    else if(ch==2)
    {
       
    loginuser();            
       
    }
    else if(ch==3)
    {
     loginadmin();
    }
    else if(ch==0)
    {
        break;
    }
       
    
    
    

    }


}
