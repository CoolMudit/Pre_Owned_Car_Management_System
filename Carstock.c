
void carstock()
{

    printf("Enter the brand of car:\n");
    gets(arr.cbrand);                                          //using gets instead of scanf because of multiword string 
  
    printf("Enter the name of car:\n");
    gets(arr.cname);

    printf("Enter the manufacture year of car:\n");
    gets(arr.cyear);

    printf("Enter the fuel type of car:\n");
    gets(arr.cfuel);

    printf("Enter the registration number of car:\n");
    gets(arr.cregnum);

    printf("Enter the Cost Price of car:\n");
    gets(arr.cCP);

    printf("Enter the List Price of car:\n");
    gets(arr.cLP);

    database();   //calling database function in stock() to add the details in file
}  

