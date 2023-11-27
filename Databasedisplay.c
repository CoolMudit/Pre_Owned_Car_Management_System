
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
