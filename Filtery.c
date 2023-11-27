
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
