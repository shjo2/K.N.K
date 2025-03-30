#include <stdio.h>
#include <stdlib.h>

const char* month_num_to_name(int month_number);

int main(int argc, char* argv[]) {
    int year;
    int month;
    int day;
    int read;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <MM-DD-YYYY or MM/DD/YYYY>", argv[0]);
        return 1;
    }

    read = sscanf(argv[1], "%d/%d/%d", &month, &day, &year);

    if (read != 3)
        read = sscanf(argv[1], "%d-%d-%d", &month, &day, &year);

    if (read != 3) {
        fprintf(stderr, "Error: Use MM-DD-YYYY or MM/DD/YYYY");
        return 1;
    }

    const char* month_name = month_num_to_name(month);
    if (month_name == NULL) {
        fprintf(stderr, "Error: month number %d\n", month);
        return 1;
    }

    printf("%s %d, %d\n", month_name, day, year);

    return 0;
}

const char* month_num_to_name(int month_number) {

    if (month_number < 1 || month_number > 12)
        return NULL;

    switch (month_number) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    }
}