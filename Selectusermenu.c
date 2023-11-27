
void selectusermenu()
{
   int n;
  
 while(1)
 {
    printf("Welcome to User menu!\n");
    printf("Press 1 to view full data of cars\nPress 2 to filter car by brand name\nPress 3 to filter car by car name\nPress 4 to filter car by year of manufacture\nPress 0 to quit\n");
    
    scanf("%d", &n);
        fflush(stdin);
        if (n == 1)
        {
            databasedisplay(); 
        }
        else if(n==2)
        {
             
            printf("Enter the brand of car to be searched:\n");
            gets(carb);
            filterb(carb);
        }

        else if(n==3)
        {
             
            printf("Enter the name of car to be searched:\n");
            gets(carn);

            filtern(carn);
        }
        else if(n==4)
        {
             
            printf("Enter the manufacture year of car to be searched:\n");
            gets(cary);

            filtery(cary);
        }

        else if(n==5)
        {
           displaybill();
        }

        else if(n==0)
        {
            break;
        }
      
}
}
