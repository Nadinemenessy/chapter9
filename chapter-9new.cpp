/////////////////////////1. The version from §9.4.1/////////////////////////
/*
#include "std_lib_facilities.h"

struct Date //we use struct to group d, m, and y into 1 place
{
    int d, m, y;
};

void init_date(Date& date, int y, int m, int d) //function to check if the initial date is valid
{
    if (y > 0)
    {
        date.y = y;
    }
    else
    {
        error("Invalid year");
    }

    if (m > 0 && m <= 12)
    {
        date.m = m;
    }
    else
    {
        error("Invalid month");
    }
    if (d > 0 && d <= 31)
    {
        date.d = d;
    }
    else
    {
        error("Invalid day");
    }
}

void add_day(Date& date, int n) //increase the Date by n days
{
    date.d += n;
    if (date.d > 31)
    {
        date.m++;
        date.d %= 31;
        if (date.m > 12)
        {
            date.y++;
            date.m %= 12;
        }
    }
}

int main()
{
    Date today; //Date variable
    Date invalid_date; //Date variable

    init_date(today, 1978, 6, 25); //assigning 'today' the the date '1978, 6, 25'

    cout << "Date:" << endl;
    cout << "y: " << today.y << endl;
    cout << "m: " << today.m << endl;
    cout << "d: " << today.d << endl;
    cout << endl;

    cout << "Today:" << endl;
    cout << "y: " << today.y << endl;
    cout << "m: " << today.m << endl;
    cout << "d: " << today.d << endl;
    cout << endl;

    Date tomorrow = today;
    add_day(tomorrow,1);
    cout << "Tomorrow:" << endl;
    cout << "y: " << tomorrow.y << endl;
    cout << "m: " << tomorrow.m << endl;
    cout << "d: " << tomorrow.d << endl;
    cout << endl;

    init_date(invalid_date, 1987, 12, -5);

    return 0;
}
*/
/////////////////////////1. The version from §9.4.1/////////////////////////


/////////////////////////2. The version from §9.4.2/////////////////////////
/*
#include "std_lib_facilities.h"

struct Date //we use struct to group d, m, and y into 1 place
{
    int year, month, day;
    Date(int y, int m, int d); //declaration for the constructor Date if the order of the date changes an error message will appear
    void add_day(int n); //declaration for the function add_day
};

Date::Date(int y, int m, int d) //function to check if the initial date is valid
{
    if (y > 0)
    {
        year = y;
    }
    else
    {
        error("Invalid year");
    }

    if (m > 0 && m <= 12)
    {
        month = m;
    }
    else
    {
        error("Invalid month");
    }
    if (d > 0 && d <= 31)
    {
        day = d;
    }
    else
    {
        error("Invalid day");
    }
}

void Date::add_day(int n) //increase the Date by n days
{
    day += n;
    if (day > 31)
    {
        month++;
        day %= 31;
        if (month > 12)
        {
            year++;
            month %= 12;
        }
    }
}

int main() try
{
    Date today {1978, 6, 25};

    cout << "Date:" << endl;
    cout << "y: " << today.year << endl;
    cout << "m: " << today.month << endl;
    cout << "d: " << today.day << endl;
    cout << endl;

    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "Tomorrow:" << endl;
    cout << "y: " << tomorrow.year << endl;
    cout << "m: " << tomorrow.month << endl;
    cout << "d: " << tomorrow.day << endl;
    cout << endl;

    Date invalid_date {2004, 11, 34};

    return 0;
}
catch (exception& e) //if there's an error in the code this catches it and prints an error message
{
    cout << "Error: " << e.what() << endl;
    return 1;
}
*/
/////////////////////////2. The version from §9.4.2/////////////////////////

/////////////////////////3. The version from §9.4.3/////////////////////////
/*
#include "std_lib_facilities.h"

class Date
{
    int y, m, d;
public:
    Date(int y, int m, int d); //declaration for the constructor Date if the order of the date changes an error message will appear
    void add_day(int n); //declaration for the function add_day
    int year() const
    {
        return y;
    }
    int month() const
    {
        return m;
    }
    int day() const
    {
        return d;
    }
};
Date::Date(int yy, int mm, int dd) //function to check if the initial date is valid
    :y{yy}, m{mm}, d{dd}
{
    if (y < 1) error("invalid year"); //if the year is less than 1 the 'catch(exception& e)' prints this error message.
    if (m < 1 || 12 < m) error("invalid month"); //if the month is greater than 31 or less than 1 the 'catch(exception& e)' prints this error message.
    if (d < 1 || 31 < d) error("invalid day"); //if the day is greater than 31 or less than 1 the 'catch(exception& e)' prints this error message.
}
void Date::add_day(int n) //increase the Date by n days
{
    d += n;
    if (d > 31)
    {
        d %= 31;
        m++;
    }
    if (m > 12)
    {
        m %= 12;
        y++;
    }

}
ostream& operator<<(ostream& os, const Date& d) //lay out of the date
{
    return os
           << endl
           << "y: "<< d.year() << endl
           << "m:" << d.month() << endl
           << "d:" << d.day() << endl;
}
int main() try
{
    Date today(1978,6,25);
    cout << "Today: " << today << endl;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "Tomorrow: " << tomorrow << endl;

    Date invalid_date(2004, 12, -5);

    return 0;
}
catch(exception& e) //if there's an error in the code this catches it and prints an error message
{
    cerr << e.what() << '\n';
    return 1;
}
*/
/////////////////////////3. The version from §9.4.3/////////////////////////

/////////////////////////4. The version from §9.7.1/////////////////////////
/*
#include "std_lib_facilities.h"

enum class Month //enumeration is a user defined class that includes a limited number of constance
{
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December"
                           };

ostream& operator<<(ostream& os, Month m) //operator to print the month
{
    return os << month_tbl[int(m)];
}

class Date
{
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d); //declaration for the constructor Date if the order of the date changes an error message will appear
    void add_day(int n); //declaration for the function add_day
    int year() const
    {
        return y;
    }
    Month month() const
    {
        return m;
    }
    int day() const
    {
        return d;
    }
};

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (d < 1 || 31 < d) error("invalid day"); //if the day is greater than 31 or less than 1 the 'catch(exception& e)' prints this error message.
    if (y < 1) error("invalid year"); //if the year is less than 1 the 'catch(exception& e)' prints this error message.

}

Month operator++(Month& m) //increments the month in case the days increases from 31 to 1.
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1); //in case the month is dec we change the month to jan otherwise increment m
    return m;
}

void Date::add_day(int n) //increase the Date by n days
{
    d += n;
    if (d > 31)
    {
        d %= 31;
        ++m;
    }
    if (m==Month::jan)
    {
        y++;
    }
}

ostream& operator<<(ostream& os, const Date& d) //lay out of the date
{
    return os
           << "y: "<< d.year() << endl
           << "m:" << d.month() << endl
           << "d:" << d.day() << endl;
}

int main() try
{
    Date today(1978, Month::jan, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << today << '\n'
         << tomorrow << '\n';

    Date invalid_date(1978, Month::dec, 32);
}
catch(exception& e) //if there's an error in the code this catches it and prints an error message
{
    cerr << e.what() << '\n';
    return 1;
}
*/
/////////////////////////4. The version from §9.7.1/////////////////////////

/////////////////////////5. The version from §9.7.4/////////////////////////
/*
#include "std_lib_facilities.h"

enum class Month //enumeration is a user defined class that includes a limited number of constance
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
    Date(int y, Month m, int d); //declaration for the constructor Date if the order of the date changes an error message will appear

    void add_day(int n); //declaration for the function add_day
    void add_month(int n); //declaration for the function add_month
    void add_year(int n); //declaration for the function add_year

    Month month() const
    {
        return m;
    }
    int day() const
    {
        return d;
    }
    int year() const
    {
        return y;
    }

private:
    int y, d;
    Month m;
};

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (d < 1 || 31 < d) error("invalid day"); //if the day is greater than 31 or less than 1 the 'catch(exception& e)' prints this error message.
    if (int(m) < 1 || 12 < int(m)) error("invalid month"); //if the month is greater than 31 or less than 1 the 'catch(exception& e)' prints this error message.
    if (y < 1) error("invalid year"); //if the year is less than 1 the 'catch(exception& e)' prints this error message.

}
Month operator++(Month& m) //increments the month in case the days increases from 31 to 1.
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}


void Date::add_year(int n) //increase the Date by n years
{
    y += n;
}
void Date::add_month(int n) //increase the Date by n months
{
    int NextMonth = 0;
    NextMonth = int(m) + n;
    if (NextMonth > 12)
    {
        NextMonth %= 12;
        y++;
    }
    switch(NextMonth)
    {
    case 1 :
        m=Month::jan;
        break;
    case 2 :
        m=Month::feb;
        break;
    case 3 :
        m=Month::mar;
        break;
    case 4 :
        m=Month::apr;
        break;
    case 5 :
        m=Month::may;
        break;
    case 6 :
        m=Month::jun;
        break;
    case 7 :
        m=Month::jul;
        break;
    case 8 :
        m=Month::aug;
        break;
    case 9 :
        m=Month::sep;
        break;
    case 10 :
        m=Month::oct;
        break;
    case 11 :
        m=Month::nov;
        break;
    case 12 :
        m=Month::dec;
        break;
    }
}

void Date::add_day(int n) //increase the Date by n days
{
    d += n;
    if (d > 31)
    {
        d %= 31;
        ++m;
    }
}

ostream& operator<<(ostream& os, const Date& d) //lay out of the date
{
    return os
           << endl
           << "y: "<< d.year() << endl
           << "m: " << int(d.month()) << endl
           << "d: " << d.day() << endl;
}

int main() try
{
    int dc = 1;
    int mc = 1;
    int yc = 1;
    Date today(1978, Month::jul, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);


    cout << "today: " <<today << endl;
    cout << "tomorrow: " << tomorrow << endl;

    today.add_day(dc);
    cout << "add day: " << today << endl;

    today.add_month(mc);
    cout << "add month: " << today << endl;

    today.add_year(yc);
    cout << "add year: " << today << endl;

    Date invalid_date(1978, Month::jan, 32);

}
catch(exception& e) //if there's an error in the code this catches it and prints an error message
{
    cerr << e.what() << '\n';
    return 1;
}
*/
/////////////////////////5. The version from §9.7.4/////////////////////////
