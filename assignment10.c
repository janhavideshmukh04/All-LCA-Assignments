#include <stdio.h>
#include <string.h>

static const char *MONTHS[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, int y) {
    static const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2 && is_leap(y)) ? 29 : d[m - 1];
}

/* Sakamoto's algorithm: returns 0 = Sunday ... 6 = Saturday */
int day_of_week(int y, int m, int d) {
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y--;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

void print_month(int y, int m) {
    char title[40];
    snprintf(title, sizeof title, "%s %d", MONTHS[m - 1], y);

    int pad = (20 - (int)strlen(title)) / 2;
    if (pad < 0) pad = 0;
    printf("%*s%s\n", pad, "", title);
    printf("Su Mo Tu We Th Fr Sa\n");

    int start = day_of_week(y, m, 1);
    int n = days_in_month(m, y);

    for (int i = 0; i < start; i++)
        printf("   ");

    for (int d = 1; d <= n; d++) {
        printf("%2d", d);
        if ((start + d) % 7 == 0 || d == n)
            printf("\n");
        else
            printf(" ");
    }
    printf("\n");
}

int main(void) {
    int year;

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        fprintf(stderr, "Please enter a valid positive year.\n");
        return 1;
    }

    printf("\n      Calendar for %d\n\n", year);
    for (int m = 1; m <= 12; m++)
        print_month(year, m);

    return 0;
}
