/*class Date
{
int day,month,year;
public:
Date();
~Date();
void display();// displays the date
Date get();// accesses the date members
void set(); // sets the date members
};
class Time
{
int hour;
int minute;
int second;
public:
Time();
~Time();
void display();// displays the time
Time get();// accesses the time members
void set();// sets the time members
};
class DateAndTime : public Date, public Time
{
public:
void display();// prints date and time
};
a.Define an instance object of class DateTime called Watch.
b.Write a main () function that would initialize the values through the constructorfunctions, and then allows them to be reset through the set () functions. Be sure anddisplay the results following the constructor before you use the set functions.
c.Through the use of the display () function, the time and date are to be displayed. Notethat the display () functions in all three classes need to be defined, as well as theconstructor and all the access functions. */


#include <iostream>

using namespace std;

class Date {
    int day, month, year;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y){}
        ~Date(){};
        void display(){
            cout << year << "/" << month << "/" << day << endl;
        }; 
        Date get(){
            return *this;
        };     
        void set(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }    
};

class Time {
    int hour;
    int minute;
    int second;

    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s){}
        ~Time(){};
        void display(){
            cout << hour << ":" << minute << ":" << second << endl;
        } 
        Time get(){
            return *this;
        };     
        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        };     
};

class DateAndTime : public Date, public Time {
    public:
        DateAndTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y) , Time(h, min, s){}

        void display(){
            Date :: display();
            Time :: display();
        }; 
};

int main(){
    DateAndTime Watch(14, 7, 2024, 01, 19, 55);
    cout << "Before resetting:" << endl;
    Watch.display();
    Watch.Date::set(21, 5, 2024);
    Watch.Time::set(2,30,42);
    cout << "After resetting:" << endl;
    Watch.display();
}