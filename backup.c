#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

char user[20]; // charater array for user to take user input
char name[20];
char pass[7]; // pin should be exactly of 6 digits
char passcheck[20];
char buff[20];
char mobnum[11];
char emailid[25];
char checkmail[25];
char address[20];
char aadhar[20];

char us[20]; // character arrays for user to validate
char em[25];
char pa[7];

char adminus[20]; // character arrays for admin  to take user input
char adminpass[20];

char aduser[20]; // character arrays for admin to validate
char adpass[20];

char custemail[20]; // character array for billing
char reg[20];
char creg[20];
char billuser[20];
char details[40];
char formattedTime[100]; // To get current date and time for billing

char userreg[20]; // array to be used to display the bill of the car
char readbill[100];
static int c = 0;

void carstock();
void database();
void loginuser();
void createacc();
void interface();
void databasedisplay();
void filterb(char carb[]);
void filtern(char carn[]);
void filtery(char cary[]);
void selectusermenu();
void selectadminmenu();
void billing();
void displaybill();
void gettime();

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

void carstock()
{

    printf("Enter the brand of car:\n");
    gets(arr.cbrand); // using gets instead of scanf because of multiword string

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

    database(); // calling database function in stock() to add the details in file
}

void database()
{

    FILE *carbrand = fopen("carbrand.txt", "a");
    FILE *carname = fopen("carname.txt", "a");
    FILE *caryear = fopen("caryear.txt", "a");
    FILE *carfuel = fopen("carfuel.txt", "a");
    FILE *carregnum = fopen("carregnum.txt", "a");
    FILE *carCP = fopen("carCP.txt", "a");
    FILE *carLP = fopen("carLP.txt", "a");

    fprintf(carbrand, "%s\n", arr.cbrand);
    fprintf(carname, "%s\n", arr.cname);
    fprintf(caryear, "%s\n", arr.cyear);
    fprintf(carfuel, "%s\n", arr.cfuel);
    fprintf(carregnum, "%s\n", arr.cregnum);
    fprintf(carCP, "%s\n", arr.cCP);
    fprintf(carLP, "%s\n", arr.cLP);

    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}

void loginuser()

{

    int n;
    FILE *usern = fopen("username.txt", "r");
    FILE *password = fopen("pass.txt", "r");
    int flag = 0;
    int c = 3;

    do
    {

        printf("Enter your username:\n");
        gets(user);

        printf("Enter password:\n");
        gets(pass);

        while (fgets(us, sizeof(us), usern) && fgets(pa, sizeof(pa), password))
        {

            if (strcmp(pa, pass) == 0)
            {
                printf("Welcome %s\n", us);
                {
                    printf("Press 1 to visit menu\nPress 0 to logout\n");
                    scanf("%d", &n);
                    if (n == 1)
                    {
                        selectusermenu(); // User menu page
                    }
                    else if (n == 0)
                    {
                        break;
                    }
                }
            }
            else
            {
                c--;
                printf("You have entered wrong username or password try again!,You have only %d attempts left", c);
                flag = 1;
            }
        }

    } while (flag == 1 && c != 1);

    fclose(usern);
    fclose(password);
}

void loginadmin()
{
    int flag = 0;

    FILE *adusername = fopen("adminusername.txt", "r");
    FILE *adpassword = fopen("adminpassword.txt", "r");
    do
    {
        printf("Enter admin username:\n");
        scanf("%s", adminus);
        printf("Enter your admin password\n");
        scanf("%s", adminpass);

        while (fgets(aduser, sizeof(aduser), adusername) && fgets(adpass, sizeof(adpass), adpassword))
        {
            if (strcmp(adminus, aduser) == 0 && strcmp(adminpass, adpass) == 0)
            {
                printf("Welcome to Admin menu !\n");
                selectadminmenu(); // Admin menu page
            }
            else
            {
                printf("Username or password is incorrect try again...");
                flag = 1;
            }
        }
    } while (flag == 1);

    fclose(adusername);
    fclose(adpassword);
}

void createacc()
{
    int num;

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

    if (strcmp(pass, passcheck) == 0)
    {

        // file created with name as username.txt

        FILE *uaadhar = fopen("useraadhar.txt", "a");
        FILE *email = fopen("useremail.txt", "a");
        FILE *checkemail = fopen("checkemail.txt", "w");
        FILE *usern = fopen("username.txt", "a");
        FILE *password = fopen("pass.txt", "a");

        sprintf(buff, "%s.txt", user);
        FILE *n = fopen(buff, "a");

        fprintf(n, "%s   ", name);
        fprintf(n, "%s   ", mobnum);
        fprintf(n, "%s   ", address);
        fprintf(n, "%s   ", aadhar);
        fprintf(n, "%s   ", emailid);

        fprintf(usern, "%s\n", user);
        fprintf(uaadhar, "%s\n", aadhar);
        fprintf(password, "%s\n", pass);
        fprintf(email, "%s\n", emailid);
        fprintf(checkemail, "%s", emailid);

        fclose(n);
        fclose(usern);
        fclose(uaadhar);
        fclose(email);
        fclose(password);
        fclose(email);
        fclose(checkemail);

        FILE *mail = fopen("checkemail.txt", "r");

        while (fgets(em, sizeof(em), mail))
        {

            if (strcmp(em, emailid) == 0)
            {
                printf("Account created successfully !...You are now registered with this email ! Press 1 to login into your account Press 0 to exit system\n");

                while (1)
                {
                event:
                    scanf("%d", &num);
                    fflush(stdin);
                    if (num == 1)
                    {
                        loginuser();
                    }
                    else if (num == 0)
                    {
                        printf("exiting system...");
                        break;
                    }
                    else
                    {
                        printf("You entered wrong option Please try again...");
                        goto event;
                    }
                }
                fclose(mail);
            }
        }
    }
}

void interface()
{
    int ch;

    printf("Welcome to Pre Owned Car Management System\n");

    while (1)
    {
        printf("Press 1 to create user account\nPress 2 to login into user account\nPress 3 to login into Admin account\nPress 0 to exit the system\n");

        scanf("%d", &ch);
        fflush(stdin);
        if (ch == 1)
        {

            createacc();
        }

        else if (ch == 2)
        {

            loginuser();
        }
        else if (ch == 3)
        {
            loginadmin();
        }
        else if (ch == 0)
        {
            break;
        }
    }
}

void databasedisplay()
{

    FILE *carbrand = fopen("carbrand.txt", "r");
    FILE *carname = fopen("carname.txt", "r");
    FILE *caryear = fopen("caryear.txt", "r");
    FILE *carfuel = fopen("carfuel.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");
    FILE *carCP = fopen("carCP.txt", "r");
    FILE *carLP = fopen("carLP.txt", "r");

    while (fgets(cb, sizeof(cb), carbrand) && fgets(cn, sizeof(cn), carname) && fgets(cy, sizeof(cy), caryear) && fgets(cf, sizeof(cf), carfuel) && fgets(crn, sizeof(crn), carregnum) && fgets(ccost, sizeof(ccost), carCP) && fgets(clist, sizeof(clist), carLP))

    {
        printf("Car name: %s\nCar brand: %s\nYear of manufacture: %s\nFuel type: %s\nRegistration Number: %s\nCostPrice: %s\nList Price: %s", cn, cb, cy, cf, crn, ccost, clist);
    }

    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}

void filterb(char carb[])
{

    FILE *carbrand = fopen("carbrand.txt", "r");
    FILE *carname = fopen("carname.txt", "r");
    FILE *caryear = fopen("caryear.txt", "r");
    FILE *carfuel = fopen("carfuel.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");
    FILE *carCP = fopen("carCP.txt", "r");
    FILE *carLP = fopen("carLP.txt", "r");

    while (fgets(cb, 100, carbrand) && fgets(cn, 100, carname) && fgets(cy, 100, caryear) && fgets(cf, 100, carfuel) && fgets(crn, 100, carregnum) && fgets(ccost, 100, carCP) && fgets(clist, 100, carLP))

    {

        if (strlen(cb) - 1 == strlen(carb) && strcmp(cb, carb) == 1)
        {
            printf("Car brand: %s\nCar name: %s\nYear of manufacture: %s\nFuel type: %s\nRegistration Number: %s\nCostPrice: %s\nList Price: %s", cb, cn, cy, cf, crn, ccost, clist);
        }
    }
    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}

void filtern(char carn[])
{

    FILE *carbrand = fopen("carbrand.txt", "r");
    FILE *carname = fopen("carname.txt", "r");
    FILE *caryear = fopen("caryear.txt", "r");
    FILE *carfuel = fopen("carfuel.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");
    FILE *carCP = fopen("carCP.txt", "r");
    FILE *carLP = fopen("carLP.txt", "r");
    while (fgets(cb, 100, carbrand) && fgets(cn, 100, carname) && fgets(cy, 100, caryear) && fgets(cf, 100, carfuel) && fgets(crn, 100, carregnum) && fgets(ccost, 100, carCP) && fgets(clist, 100, carLP))

    {

        if (strlen(cn) - 1 == strlen(carn) && strcmp(cn, carn) == 1)
        {
            printf("Car name: %s\nCar brand: %s\nYear of manufacture: %s\nFuel type: %s\nRegistration Number: %s\nCostPrice: %s\nList Price: %s", cn, cb, cy, cf, crn, ccost, clist);
        }
    }
    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}

void filtery(char cary[])
{

    FILE *carbrand = fopen("carbrand.txt", "r");
    FILE *carname = fopen("carname.txt", "r");
    FILE *caryear = fopen("caryear.txt", "r");
    FILE *carfuel = fopen("carfuel.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");
    FILE *carCP = fopen("carCP.txt", "r");
    FILE *carLP = fopen("carLP.txt", "r");
    while (fgets(cb, 100, carbrand) && fgets(cn, 100, carname) && fgets(cy, 100, caryear) && fgets(cf, 100, carfuel) && fgets(crn, 100, carregnum) && fgets(ccost, 100, carCP) && fgets(clist, 100, carLP))

    {

        if (strlen(cy) - 1 == strlen(cary) && strcmp(cy, cary) == 1)
        {
            printf("Year of manufacture: %s\nCar name: %s\nCar brand: %s\nFuel type: %s\nRegistration Number: %s\nCostPrice: %s\nList Price: %s", cy, cn, cb, cf, crn, ccost, clist);
        }
    }
    fclose(carbrand);
    fclose(carname);
    fclose(caryear);
    fclose(carfuel);
    fclose(carregnum);
    fclose(carCP);
    fclose(carLP);
}

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

        else if (n == 6)
        {
            billing();
        }

        else if (n == 0)
        {
            break;
        }
    }
}

void selectusermenu()
{
    int n;

    while (1)
    {
        printf("Welcome to User menu!\n");
        printf("Press 1 to view full data of cars\nPress 2 to filter car by brand name\nPress 3 to filter car by car name\nPress 4 to filter car by year of manufacture\nPress 0 to quit\n");

        scanf("%d", &n);
        fflush(stdin);
        if (n == 1)
        {
            databasedisplay();
        }
        else if (n == 2)
        {

            printf("Enter the brand of car to be searched:\n");
            gets(carb);
            filterb(carb);
        }

        else if (n == 3)
        {

            printf("Enter the name of car to be searched:\n");
            gets(carn);

            filtern(carn);
        }
        else if (n == 4)
        {

            printf("Enter the manufacture year of car to be searched:\n");
            gets(cary);

            filtery(cary);
        }

        else if (n == 5)
        {
            displaybill();
        }

        else if (n == 0)
        {
            break;
        }
    }
}

// admin functionality

void billing()
{

    FILE *email = fopen("useremail.txt", "r");
    FILE *carregnum = fopen("carregnum.txt", "r");

    printf("Enter the aadhaar id of customer\n");
    gets(custemail); // validate the customer email id

    while (fgets(em, 100, email))
    {
        if (strcmp(em, custemail) == 0)
        {
            printf("User is already registered\n");
            printf("Enter the username of the user:\n");
            gets(billuser);
            sprintf(buff, "%s.txt", billuser);
            FILE *n = fopen(buff, "r");

            printf("Please enter the registration number of car in order to proceed for billing\n");
            gets(reg);

            FILE *carregnum = fopen("carregnum.txt", "r");
            FILE *carbrand = fopen("carbrand.txt", "r");
            FILE *carname = fopen("carname.txt", "r");
            FILE *caryear = fopen("caryear.txt", "r");
            FILE *carLP = fopen("carLP.txt", "r");

            while (fgets(details, sizeof(details), n) && fgets(creg, sizeof(creg), carregnum) && fgets(cb, sizeof(cb), carbrand) && fgets(cn, sizeof(cn), carname) && fgets(cy, sizeof(cy), caryear) && fgets(clist, 100, carLP))
            {
                if (strcmp(creg, reg) == 0)
                {
                    char filename[20]; // local variable
                    printf("Creating bill...");
                    sprintf(filename, "%s.txt", creg);
                    FILE *bill = fopen(filename, "a"); // billing file created
                    c++;

                    fprintf(bill, "--------Pre Owned Car Management Billing System--------");
                    gettime(); // calling gettime to get the current date and time for billing

                    fprintf(bill, "---Bill created on %s---", formattedTime);

                    fprintf(bill, "-------------User details-------------");
                    fprintf(bill, "Customer name                 Customer mobile number                 Customer Permanent Address                 Customer Aadhar number                  Customer email-id", n);
                    fprintf(bill, details);
                    fprintf(bill, "----------------------------------------------------");
                    fprintf(bill, "---Registration number of the vehicle:%s\n---", creg);
                    fprintf(bill, "---Brand of the vehicle:%s\n---", cb);
                    fprintf(bill, "---Name of the vehicle:%s\n---", cn);
                    fprintf(bill, "---Manufacture year of the vehicle:%s\n---", cy);
                    fprintf(bill, "---List Price of the vehicle:%s\n---", clist);

                    char *endptr; // converting char array to floating type to calculate gst
                    float flist = strtod(clist, &endptr);
                    float gst = flist * 0.18;

                    fprintf(bill, "GST applicable @18%% %.2f\n", gst);

                    float totalamt = gst + flist; // total amt to be paid by customer
                    fprintf(bill, "------------------------------------");
                    fprintf(bill, "Total amount to be paid:%.2f", totalamt);
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

// User functionality

void displaybill()
{

    printf("Please enter the registration number of your car in order to display the bill of your car\n");
    gets(userreg);

    char filename[20]; // local variable

    sprintf(filename, "%s.txt", userreg);

    FILE *bill = fopen(filename, "r");

    if (bill == NULL)
    {
        printf("Bill does not exist..Please contact the admin to generate the bill !\n");
    }
    else
    {

        while (fgets(readbill, sizeof(creg), bill))
        {
            printf("%s", readbill);
        }
    }
    fclose(bill);
}

void gettime()
{
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime); // Get the current time in seconds since the Epoch

    localTime = localtime(&currentTime); // Convert to local time

    // Format and print the current date and time

    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", localTime);
}

int main(int argc, char const *argv[])
{

    interface();

    return 0;
}
