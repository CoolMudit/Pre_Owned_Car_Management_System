
void DataBase()
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
