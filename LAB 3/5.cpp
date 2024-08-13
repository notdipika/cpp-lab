/*Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.*/

#include <iostream>
#include <string>

using namespace std;

class TwentyFour;

class Twelve {
    int hr, min, sec;
    string meridiam;

public:
    Twelve(int h, int m, int s, const string& me) : hr(h), min(m), sec(s), meridiam(me) {}

    operator TwentyFour();

    void show() const {
        cout << (hr < 10 ? "0" : "") << hr << ":"
             << (min < 10 ? "0" : "") << min << ":"
             << (sec < 10 ? "0" : "") << sec << " "
             << meridiam << endl;
    }

    bool isValid() const {
        return hr >= 1 && hr <= 12 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59 &&
               (meridiam == "AM" || meridiam == "PM");
    }
};

class TwentyFour {
    int hr, min, sec;

public:
    TwentyFour() : hr(0), min(0), sec(0) {}
    TwentyFour(int h, int m, int s) : hr(h), min(m), sec(s) {}

    void show() const {
        cout << (hr < 10 ? "0" : "") << hr << ":"
             << (min < 10 ? "0" : "") << min << ":"
             << (sec < 10 ? "0" : "") << sec << endl;
    }
};

Twelve::operator TwentyFour() {
    int hourIn24 = hr;

    if (meridiam == "AM") {
        if (hr == 12) hourIn24 = 0; 
    } else if (meridiam == "PM") {
        if (hr != 12) hourIn24 = hr + 12; 
    }

    return TwentyFour(hourIn24, min, sec);
}

int main() {
    int h, m, s;
    string me;

    cout << "Enter the hour (1-12): ";
    cin >> h;
    cout << "Enter the minute (0-59): ";
    cin >> m;
    cout << "Enter the second (0-59): ";
    cin >> s;
    cout << "Enter the meridian (AM/PM): ";
    cin >> me;

    Twelve t12(h, m, s, me);

    if (!t12.isValid()) {
        cout << "Invalid time entered. Please enter a valid time." << endl;
        return 1;
    }

    TwentyFour t24 = t12;

    cout << "12-hour format: ";
    t12.show();
    cout << "24-hour format: ";
    t24.show();

    return 0;
}
