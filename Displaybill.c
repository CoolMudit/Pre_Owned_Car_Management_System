
void displaybill()
{
     
      printf("Please enter the registration number of your car in order to display the bill of your car\n");
      gets(userreg);

      char filename[20];   // local variable 
   
      sprintf(filename,"%s.txt",userreg);
     
     FILE *bill=fopen(filename,"r"); 

     if(bill==NULL)
     {
        printf("Bill does not exist..Please contact the admin to generate the bill !\n");


     }
     else{

            while(fgets(readbill,sizeof(creg),bill)) 
            {
             printf("%s",readbill);

            }
     }
     fclose(bill);
}
