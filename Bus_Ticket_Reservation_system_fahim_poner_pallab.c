#include<stdio.h>
struct bus_reservation_system
{
    int id;
    double arrival;
    double departure;
    char from[40];
    char to[40];
    int totalSeatsAvailable;
    double ticketPrice;
} busArray[100];

int sizeOfArray=0;

void UserPortalmenu()
{

    printf("\n1.View All Bus Schedule : \n");
    printf("2.Purchase Ticket.\n");
    printf("3.Exit and save data \n");

}

void purchaseTicket()
{

    readFileContents();

    int targetId;
    printf("\n\nEnter Bus No : ");
    scanf("%d",&targetId);
    int ticketQuantity;
    printf("How many tickets? ");
    scanf("%d",&ticketQuantity);
    double price=0;
    int index=-1;
    int isFound=0;

    for(int i=0; i<sizeOfArray; i++)
    {
        if(busArray[i].id==targetId)
        {
            if(busArray[i].totalSeatsAvailable>ticketQuantity)
            {

                price=busArray[i].ticketPrice*ticketQuantity;
                index=i;
                isFound=1;
                busArray[i].totalSeatsAvailable=busArray[i].totalSeatsAvailable-ticketQuantity;
                break;

            }
            else
            {

                printf("\n%d SEATS NOT AVAILABLE\n",ticketQuantity-busArray[i].totalSeatsAvailable);
                break;
            }


        }

    }

    if(isFound==1)
    {
    char name[100];
    printf("Enter your name : ");
    scanf("%s",name);
    char number[100];
    printf("Enter your phone number : ");
    scanf("%s",number);
    fflush(stdin);

        printf("\n\n-------------------------------------------------------------------------\n");

        printf("Purchase History : \n");

        printf("Name :  %s\n",name);
        printf("Contact number : %s\n",number);

        printf("\nBus No : %d. \nArrival Time : %.2lf \nDeparture Time : %.2lf \nFrom : %s \nTo : %s \nTotal tickets: %d\nTotal Price : %.2lf\n\n",busArray[index].id,busArray[index].arrival,busArray[index].departure,busArray[index].from,busArray[index].to,ticketQuantity,price);
        printf("\n-----------------------------------------------------------------------------\n");

    }
    else
    {

        printf("\nFailed to purchase ticket!\n");
    }







}
void initialiseFile()
{

    FILE*file;
    file=fopen("BUS_MANAGEMENT.txt","w");
    fprintf(file,"1 1.40 4.00 DHAKA  KHULNA 35 750\n");
    fprintf(file,"2 2.40 6.00 DHAKA  KHULNA 35 650\n");
    fprintf(file,"3 4.40 5.00 DHAKA  KHULNA 35 450\n");
    fprintf(file,"4 5.40 6.00 DHAKA  KHULNA 35 750\n");
    fprintf(file,"5 6.40 6.00 DHAKA  KHULNA 35 1200\n");
    fclose(file);





}
void display()
{
    for(int i=0; i<sizeOfArray; i++)
    {

        printf("Bus No : %d. \nArrival Time : %.2lf \nDeparture Time : %.2lf \nFrom : %s \nTo : %s \nTotal Seats Available : %d\nPrice : %.2lf\n\n",busArray[i].id,busArray[i].arrival,busArray[i].departure,busArray[i].from,busArray[i].to,busArray[i].totalSeatsAvailable,busArray[i].ticketPrice);
    }

}

void readFileContents()
{


    FILE *file;

    file=fopen("BUS_MANAGEMENT.txt","r");

    int i=0;
    while(fscanf(file,"%d %lf %lf %s %s %d %lf",&busArray[i].id,&busArray[i].arrival,&busArray[i].departure,busArray[i].from,busArray[i].to,&busArray[i].totalSeatsAvailable,&busArray[i].ticketPrice)!=EOF)
    {
        i++;

    }
    sizeOfArray=i;

}

void writeToFile()
{

    FILE *file;

    file=fopen("BUS_MANAGEMENT.txt","w");

    for(int i=0;i<sizeOfArray;i++)
    {
    fprintf(file,"%d %lf %lf %s %s %d %lf\n",busArray[i].id,busArray[i].arrival,busArray[i].departure,busArray[i].from,busArray[i].to,busArray[i].totalSeatsAvailable,busArray[i].ticketPrice);
    }

    fclose(file);

    printf("Data Saved to File Successfully!");


}



int main()
{
    initialiseFile();
    readFileContents();

    int option=0;
    printf("\t\t\tWelcome to NSU Elite Transport System\t\t\t\n");

    while(option!=3)
    {
        UserPortalmenu();

        printf("Enter your option : ");

        scanf("%d",&option);

        if(option==1)
        {
            display();

        }
        else if(option==2)
        {
            purchaseTicket();
        }
        else if(option==3)
        {
        writeToFile();
            exit(1);
        }
        else
        {
            printf("\nInvalid Input!\n");
            printf("Try again!\n\n");
        }
    }


}

