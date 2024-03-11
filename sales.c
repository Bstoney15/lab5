#include <stdio.h>
#include <stdlib.h> 
void getSales(double sales[])
{
    FILE *salesNumbers = fopen("sales.txt", "r");
    if (!salesNumbers) {
        perror("Failed to open sales.txt");
        exit(1); 
    }
    for(int i = 0; i < 12; i++)
    {
        if(fscanf(salesNumbers, "%lf", &sales[i]) != 1) {
            printf("Error reading sales data.\n");
            exit(2);
        }
    }
    fclose(salesNumbers);
}

void printMonthly(const double sales[], const char* months[])
{
    printf("Sales Report\n");
    printf("Month       Sales\n");
    for(int i = 0; i < 12; i++)
    {
        printf("%-10s %0.2lf\n", months[i], sales[i]);
    }
}

void salesSummary(const double sales[], const char* months[])
{
    double max = sales[0], min = sales[0];
    int maxMonth = 0, minMonth = 0;
    double rollingTotal = 0;
    
    for(int i = 0; i < 12; i++)
    {
        rollingTotal += sales[i];
        if(sales[i] > max)
        {
            max = sales[i];
            maxMonth = i;
        }
        if(sales[i] < min)
        {
            min = sales[i];
            minMonth = i;
        }
    }
    printf("\nSales Summary\n \n");
    printf("Total Sales: %.2lf\n", rollingTotal);
    printf("Average Sales: %.2lf\n", rollingTotal / 12);
    printf("Maximum Sales: %.2lf (%s)\n", max, months[maxMonth]);
    printf("Minimum Sales: %.2lf (%s)\n", min, months[minMonth]);

}

void printMoving(const double sales[], const char* months[])
{
    double tmp;
    printf("\nSix Month Moving Average \n \n");
    for(int j = 0; j < 7; j++)
    {
        for(int i = j; i < j+6; i++)
        {
                tmp += sales[i];
        }
        printf("%-10s - %-10s $%.2lf \n", months[j], months[j+5], tmp/6);

    }

}

void printHightoLow(double sales[], char* months[])
{
    double tmp;
    char* tmp2;
    printf("\nSales High to Low \n \n");
    for(int j = 0; j < 12; j++)
    {
        for(int i = j; i < 12; i++)
        {
                if(sales[i] > sales[j])
                {
                    tmp = sales[i];
                    tmp2 = months[i];

                    sales[i] = sales[j];
                    months[i] = months[j];

                    sales[j] = tmp;
                    months[j] = tmp2;
                }
        }
        printf("%-10s $%.2lf \n", months[j], sales[j]);
    }

}
    


int main()
{
    double sales[12];
    const char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    getSales(sales);
    printMonthly(sales, months);
    salesSummary(sales, months);
    printMoving(sales, months);
    printHightoLow(sales, months);

    return 0;
}
