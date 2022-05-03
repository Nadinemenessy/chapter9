#include "std_lib_facilities.h"

using namespace std;

//converts all months to numbers
enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};//numbers start with zero this makes it so the numbers can start with one so it can match the months

//vector of months
vector<string> month_tbl = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December" };


//to pass enumeration of months to vector of months and return month in string
ostream& operator<<(ostream& os, Month m)
{
    return os << month_tbl[int(m)];
}


class Date {
    int y; //number of year
    Month m;//name of month
    int d;// number of day
public:
    Date(int y, Month m, int d); //constructor used to initialize some valid values to the data members of an object
    void add_day(int n); //add day function by number of days
    int year() const { return y; }//getters used to retrieve the variable value ends with return
    Month month() const { return m; }
    int day() const { return d; } 

Date::Date(int yy, Month mm, int dd)//implementation for constructor that initializes the object of that type
    :y{ yy }, m{ mm }, d{ dd }
{
    if (d < 1 || 31 < d) error("impossible day");
}

void Date::add_day(int n) //implementation for (protoype function - enables the compiler to perform more vigorous type checking)
{
    d += n;
    if (d > 31) d %= 31;
}

ostream& operator<<(ostream& os, const Date& d) //operator overloading to allow u to print objects of Date
{
    return os << '(' << d.year()
        << ',' << d.month()
        << ',' << d.day() << ')';
}

int main()
try {
    Date today(1978, Month::jun, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << today << '\n'
        << tomorrow << '\n';

    //Date bad_day(2004, 13, -5);
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "unknown error" << '\n';
    return 2;
}
