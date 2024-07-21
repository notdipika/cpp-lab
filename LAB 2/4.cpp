/* Create a class called 'TIME' that has
- three integer data members for hours, minutes and seconds
- constructor to initialize the object to zero
- constructor to initialize the object to some constant value
- overload +,- to add and subtract two TIME objects
- overload > function to compare two time
- member function to display time in HH:MM:SS format */

#include<iostream>

using namespace std;

class TIME{
    int hour;
    int min;
    int sec;

    public:
        TIME(){
            hour=0;
            min = 0;
            sec = 0;
        }
        TIME(int h, int m, int s){
            hour = h;
            min = m;
            sec = s;
        }

        friend TIME operator+(TIME& t1, TIME& t2);
        friend TIME operator-(TIME& t1, TIME& t2);
        friend bool operator>(TIME& t1, TIME& t2);
        
        void display(){
            cout << hour << ":" << min << ":" << sec << endl;
        }

        void setTimeFromUser() {
            cout << "Enter hours: ";
            cin >> hour;
            cout << "Enter minutes: ";
            cin >> min;
            cout << "Enter seconds: ";
            cin >> sec;
        }

};
        TIME operator+(TIME& t1, TIME& t2){
            TIME t;
            t.sec = t1.sec + t2.sec;
            t.min = t1.min + t2.min + t.sec / 60;
            t.hour = t1.hour + t2.hour + t.min / 60;
            t.min %= 60;
            t.sec %= 60;
            return t;
        }

        TIME operator-(TIME& t1, TIME& t2){
            TIME t;
            int total_sec1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
            int total_sec2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
            int diff_sec = total_sec1 - total_sec2;
            if (diff_sec < 0)
            diff_sec += 24 * 3600;
            t.hour = diff_sec / 3600;
            t.min = (diff_sec % 3600) / 60;
            t.sec = (diff_sec % 3600) % 60;
            return t;
        }

        bool operator>(TIME& t1, TIME& t2){
            if (t1.hour > t2.hour)
            return true;
            else if (t1.hour < t2.hour)
            return false;
            if (t1.min > t2.min)
            return true;
            else if (t1.min < t2.min)
            return false;
            if (t1.sec > t2.sec)
            return true;
            return false;
        }

int main(){
    TIME t1, t2, t;

    cout << "Enter first time:" << endl;
    t1.setTimeFromUser();

    cout << "\nEnter second time:" << endl;
    t2.setTimeFromUser();


    if (t1 > t2) {
        cout << "\nt1 = ";
        t1.display();
        cout << " is greater than t2 = ";
        t2.display();
        cout << endl;

        TIME sum = t1 + t2;
        cout << "\nSum: ";
        sum.display();
        cout << endl;

        TIME difference = t1 - t2;
        cout << "Difference: ";
        difference.display();
        cout << endl;
    } else if (t2 > t1) {
        cout << "\nt2 = ";
        t2.display();
        cout << " is greater than t1 = ";
        t1.display();
        cout << endl;

        TIME sum = t1 + t2;
        cout << "\nSum: ";
        sum.display();
        cout << endl;

        TIME difference = t2 - t1;
        cout << "Difference: ";
        difference.display();
        cout << endl;

    } 
    else {
        cout << "\nBoth times are equal." << endl;
    }

    return 0;
}
