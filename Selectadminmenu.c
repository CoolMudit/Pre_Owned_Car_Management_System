
void selectadminmenu()
{
    int n;
    while (1)
    {
        printf("Press 1 to add a car\nPress 2 to display the full data of cars\nPress 3 to filter car by brand\nPress 4 to filter car by name\nPress 5 to filter car by year of manufacture\nPress 0 to logout from admin system\n");

        scanf("%d", &n);
        fflush(stdin);
        if (n == 1)
        {
            carstock();
            
        }

        else if (n == 2)
        {
            databasedisplay();
        }

        else if (n == 3)
        {

          
            printf("Enter the brand of car to be searched:\n");
            gets(carb);
            filterb(carb);
        }

        else if (n == 4)
        {
         
            printf("Enter the name of car to be searched:\n");
            gets(carn);

            filtern(carn);
        }
        else if (n == 5)
        {
            
            printf("Enter the manufacture year of car to be searched:\n");
            gets(cary);

            filtery(cary);
        }

        else if(n==6)
        {
           billing();
        }

        else if(n==0)
        {
            break;
        }
    }
}
