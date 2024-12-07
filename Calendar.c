#include <stdio.h>

int getFirstDayOfMonth(int year, int month) 
{
    int day;
    
    if (month == 1 || month == 2) 
    {
        month += 12;
        year--;
    }
    day = (2 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return day;
}

void printCalendar(int year, int month) 
{
    const char *months[] = {
        "Invalid", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        daysInMonth[2] = 29; 
    }

    printf("\n\t\t\t  %s %d\n", months[month], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int firstDay = getFirstDayOfMonth(year, month);
    int days = daysInMonth[month];

    
    for (int i = 0; i < firstDay; i++) {
        printf("    ");
    }

    
    for (int day = 1; day <= days; day++) {
        printf("%3d ", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");  
        }
    }

    printf("\n");
}

int main() {
    int year, month;
    char continueChoice;

    
    do {
        printf("Enter year: ");
        scanf("%d", &year);
        printf("Enter month (1-12): ");
        scanf("%d", &month);

       
        if (month < 1 || month > 12) {
            printf("Invalid month!\n");
        } else {
            printf("==========================================================");
            printCalendar(year, month);
            printf("==========================================================\n");
        }

        
        printf("Do you want to enter another year and month? (y/n): ");
        getchar();  
        scanf("%c", &continueChoice);
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
