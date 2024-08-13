/*Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.*/

#include <iostream>
#include <iomanip> 

using namespace std;

class TwentyFour {
    int hr, min, sec;

public:
    TwentyFour() : hr(0), min(0), sec(0) {}
    TwentyFour(int h, int m, int s) : hr(h), min(m), sec(s) {}

    int getH() const { return hr; }
    int getM() const { return min; }
    int getS() const { return sec; }

    void show() const {
        cout << setw(2) << setfill('0') << hr << ":"
             << setw(2) << setfill('0') << min << ":"
             << setw(2) << setfill('0') << sec << endl;
    }

    bool isValid() const {
        return hr >= 0 && hr < 24 && min >= 0 && min < 60 && sec >= 0 && sec < 60;
    }
};

class Twelve {
    int hr, min, sec;
    string meridiam;

public:
    Twelve() : hr(0), min(0), sec(0), meridiam("AM") {}

    // Constructor for conversion from TwentyFour to Twelve
    Twelve(const TwentyFour &t) {
        int h = t.getH();
        min = t.getM();
        sec = t.getS();

        if (h == 0) {
            hr = 12;
            meridiam = "AM";
        } else if (h == 12) {
            hr = 12;
            meridiam = "PM";
        } else if (h > 12) {
            hr = h - 12;
            meridiam = "PM";
        } else {
            hr = h;
            meridiam = "AM";
        }
    }

    void show() const {
        cout << setw(2) << setfill('0') << hr << ":"
             << setw(2) << setfill('0') << min << ":"
             << setw(2) << setfill('0') << sec << " "
             << meridiam << endl;
    }
};

int main() {
    int h, m, s;

    cout << "Enter the hour (0-23): ";
    cin >> h;
    cout << "Enter the minute (0-59): ";
    cin >> m;
    cout << "Enter the second (0-59): ";
    cin >> s;

    TwentyFour t24(h, m, s);

    if (!t24.isValid()) {
        cout << "Invalid time entered. Please enter a valid time." << endl;
        return 1;
    }

    Twelve t12(t24);

    cout << "24-hour format: ";
    t24.show();
    cout << "12-hour format: ";
    t12.show();

    return 0;
}
