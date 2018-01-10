#include <stdio.h>
#include <stdbool.h>

int days_of_year(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0 ? 366 : 365;
    } else {
        return year % 4 == 0 ? 366 : 365;
    }
}

int days_of_month(int month, bool is_leap) {
    switch (month) {
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return is_leap ? 29 : 28;
        default:
            return -1;
    }
}


int main() {
    const char* day_of_weeks[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int T;
    while (scanf("%d", &T) == 1 && T > 0) {
        // 2000/1/1 (Saturday)
        int day_of_week = T % 7;
        int year = 2000;
        int days = days_of_year(year);
        while (T >= days) {
            T -= days;
            year++;
            days = days_of_year(year);
        }

        bool is_leap = days == 366;
        int month;
        for (month = 1; month <= 12; month++) {
            days = days_of_month(month, is_leap);
            if (T >= days) {
                T -= days;
            } else {
                T++;
                break;
            }
        }

        printf("%d-%d-%d %s\n", year, month, T, day_of_weeks[day_of_week]);
    }
    return 0;
}
