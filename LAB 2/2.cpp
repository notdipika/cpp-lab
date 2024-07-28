// To write a C++ program to overload all relational operators to compare US currency with Nepalese currency. Use conversion rate $1=NRs 101.36(Note: make two classes to represent each currency)
#include <iostream>
using namespace std;

class dol {
private:
    float A;
public:
    dol(float amt = 0.0) : A(amt) {}

    float input() {
        return A;
    }
    friend bool operator==( dol& us, class rup& nr);
    friend bool operator!=( dol& us, rup& nr);
    friend bool operator<( dol& us, rup& nr);
    friend bool operator<=( dol& us, rup& nr);
    friend bool operator>( dol& us, rup& nr);
    friend bool operator>=( dol& us, rup& nr);
};

class rup {
private:
    float A;
public:
    rup(float amt = 0.0) : A(amt) {}

    float input()  {
        return A;
    }

    dol todol()  {
        return dol(A / 101.36);
    }

    friend bool operator==( dol& us, rup& nr);
    friend bool operator!=( dol& us, rup& nr);
    friend bool operator<( dol& us, rup& nr);
    friend bool operator<=( dol& us, rup& nr);
    friend bool operator>( dol& us, rup& nr);
    friend bool operator>=( dol& us, rup& nr);
};

bool operator==( dol& us,  rup& nr) {
    return us.input() == nr.todol().input();
}

bool operator!=( dol& us,  rup& nr) {
    return us.input() != nr.todol().input();
}

bool operator<( dol& us,  rup& nr) {
    return us.input() < nr.todol().input();
}

bool operator<=( dol& us,  rup& nr) {
    return us.input() <= nr.todol().input();
}

bool operator>( dol& us,  rup& nr) {
    return us.input() > nr.todol().input();
}

bool operator>=( dol& us,  rup& nr) {
    return us.input() >= nr.todol().input();
}

int main() {
    float D, R;


    cout << "Enter Dollars: ";
    cin >> D;
    dol dol(D);


    cout << "Enter Rupees: ";
    cin >> R;
    rup rup(R);

    cout << "\nComparisons between US Currency and Nepalese Currency:" << endl;
    cout << "Dollars == Rupees: " << (dol == rup ? "True" : "False") << endl;
    cout << "Dollars != Rupees: " << (dol != rup ? "True" : "False") << endl;
    cout << "Dollars < Rupees: " << (dol < rup ? "True" : "False") << endl;
    cout << "Dollars <= Rupees: " << (dol <= rup ? "True" : "False") << endl;
    cout << "Dollars > Rupees: " << (dol > rup ? "True" : "False") << endl;
    cout << "Dollars >= Rupees: " << (dol >= rup ? "True" : "False") << endl;

    return 0;
}