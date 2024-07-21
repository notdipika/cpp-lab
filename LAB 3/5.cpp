/*Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.*/

#include <iostream>
#include <string>

using namespace std;

class TwentyFour;

class Twelve
{
    int hr, min, sec;
    string meridiam;

public:
    Twelve() {}
    Twelve(int h, int m, int s, string me) : hr(h), min(m), sec(s), meridiam(me) {}

    operator TwentyFour();

    void show()
    {
        cout << hr << ":" << min << ":" << sec << " " << meridiam << endl;
    }
};

class TwentyFour
{
    int hr, min, sec;

public:
    TwentyFour() {}
    TwentyFour(int h, int m, int s) : hr(h), min(m), sec(s) {}

    int getH()
    {
        return hr;
    }

    int getM()
    {
        return min;
    }

    int getS()
    {
        return sec;
    }

    void show()
    {
        cout << hr << ":" << min << ":" << sec << endl;
    }
};

Twelve::operator TwentyFour()
{
    if (meridiam == "AM")
    {
        return TwentyFour(hr, min, sec);
    }
    else
    {
        if (hr == 12)
        {
            return TwentyFour(hr, min, sec);
        }
        else
        {
            return TwentyFour(hr + 12, min, sec);
        }
    }
}

int main()
{
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
    TwentyFour t24 = t12;

    cout << "12-hour format: ";
    t12.show();
    cout << "24-hour format: ";
    t24.show();

    return 0;
}