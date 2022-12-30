//Importing necessary libraries.
#include <iostream>
using namespace std;

//Declaring structs holding date components (dd/mm/yy).
struct Date 
{
    int dd, mm, yy;
};

//Stores the number of days passed in the months prior.
//E.g. in March (represented by the 59 in the array).
//says that 59 days have passed in the months prior.
const int monthdays[] = 
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

//Counts the number of leap years passed between.
//the date entered and 0 A.D. 
int count_leap_years(Date date) 
{
    int num_leap = 0;
    for (int i = 0; i <= date.yy; i += 4)
    {
        if (i % 4 == 0)
        {
            if (i % 100 == 0)
            {
                if (i % 400 == 0)
                {
                    //Deducts one from the count if the date entered is a leap year.
                    //AND is before 2/29/[leap year] (29th of February of any given leap year).
                    num_leap++;
                    if (i == date.yy && date.mm <= 2 && date.dd <= 29)
                    {
                        num_leap--;
                    }
                }
            }
            else
            {
                //Deducts one from the count if the date entered is a leap year.
                //AND is before 2/29/[leap year] (29th of February of any given leap year).
                num_leap++;
                if (i == date.yy && date.mm <= 2 && date.dd <= 29)
                {
                    num_leap--;
                }
            }
        }
    }
    return num_leap;
}

//calculates the difference of days between 2 entered dates.
int day_diff_calc(Date dt1, Date dt2)
{
    //count the number of days between dt1/ dt2 and 0 A.D. 
    //E.g. dt1days = 61149.
    int dt1days = dt1.dd + monthdays[dt1.mm - 1] + dt1.yy * 365 + count_leap_years(dt1);
    int dt2days = dt2.dd + monthdays[dt2.mm - 1] + dt2.yy * 365 + count_leap_years(dt2);
    int day_diff = dt1days - dt2days;
    return day_diff;
}

int main()
{
    //Declaring variables.
    string date;
    int index, wday;
    char delimiter = '/';
    string weekday[] = 
        {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    time_t rawtime;
    tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    wday = timeinfo -> tm_wday;

    //Declaring new Date struct value "current_date" for the date during the run of the program.
    Date current_date = {timeinfo -> tm_mday, (timeinfo -> tm_mon) + 1, (timeinfo -> tm_year) + 1900};

    //Taking input from user as the "new_date"
    cout << "Enter a date (dd/mm/yy): ";
    getline (cin, date);
    date.erase(remove(date.begin(), date.end(), ' '));
    //Declaring temporary date components; "tmm" means temporary month integer
    int tdd = stoi(date.substr(0, date.find(delimiter)));
    date.erase(0, date.find(delimiter) + 1);
    int tmm = stoi(date.substr(0, date.find(delimiter)));
    int tyy = stoi(date.substr(date.find(delimiter) + 1));
    //Declearing new Date struct value "new_date"
    Date new_date = {tdd, tmm, tyy};

    //Calculates the new index
    index = (day_diff_calc(new_date, current_date) + wday) % 7;

    //The index returns negative numbers for past dates.
    //In order to corrcet it, it adds 7 to the index. 
    if (index < 0)
    {
        index = 7 + index;
    }

    cout << "The day of the week on the given date is:" << weekday[index] << endl;
}
