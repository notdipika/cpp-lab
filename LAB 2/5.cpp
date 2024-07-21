// Create a 'STRING' class which char* and length as data member and overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations. Use constructor and destructor whenever suitable.
#include <iostream>
#include <cstring> 
using namespace std;

class STRING {
private:
    char* str;    
    size_t length; 

public:
    STRING() : str(nullptr), length(0) {}
    STRING(const char* s) {
        length = strlen(s);
        str = new char[length + 1]; 
        strcpy(str, s); 
    }
    
    ~STRING() {
        if (str != nullptr) {
            delete[] str; 
        }
    }

    STRING(const STRING& other) {
        length = other.length;
        str = new char[length + 1]; 
        strcpy(str, other.str); 
    }

    STRING& operator=(const STRING& other) {
        if (this != &other) {
            if (str != nullptr) {
                delete[] str;
            }
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    friend STRING operator+( STRING& lhs, STRING& rhs);
    friend bool operator==( STRING& lhs,  STRING& rhs);

    void display() const {
        cout << str;
    }
};


STRING operator+( STRING& lhs, STRING& rhs) {
    size_t newLength = lhs.length + rhs.length;
    char* tempStr = new char[newLength + 1]; 
    strcpy(tempStr, lhs.str); 
    strcat(tempStr, rhs.str); 
    STRING result(tempStr); 
    delete[] tempStr; 
    return result;
}

bool operator==( STRING& lhs, STRING& rhs) {
    return (lhs.length == rhs.length && strcmp(lhs.str, rhs.str) == 0);
}

int main() {
    STRING s1("Hello");
    STRING s2(" World");


    STRING s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
    cout << endl;

    STRING s4;
    s4 = s3;
    cout << "Assigned string: ";
    s4.display();
    cout << endl;

    if (s1 == s2) {
        cout << "s1 and s2 are equal." << endl;
    } else {
        cout << "s1 and s2 are not equal." << endl;
    }

    if (s3 == s4) {
        cout << "s3 and s4 are equal." << endl;
    } else {
        cout << "s3 and s4 are not equal." << endl;
    }

    return 0;
}