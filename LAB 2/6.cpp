// Modify above class to work with compile time memory allocation i.e. withchar [].

#include <iostream>
#include <cstring> 
using namespace std;

class STRING {
private:
    static const size_t MAX_SIZE = 100; 
    char str[MAX_SIZE]; 
    size_t length;       

public:
 STRING() : length(0) {
        str[0] = '\0'; 
    }
    
    STRING(const char* s) {
        length = strlen(s);
        if (length >= MAX_SIZE) {
            throw "String exceeds maximum allowed size.";
        }
        strcpy(str, s); 
    }

    STRING& operator=(const STRING& other) {
        if (this != &other) { 
            length = other.length;
            strcpy(str, other.str);
        }
        return *this;
    }

    
    friend STRING operator+(const STRING& lhs, const STRING& rhs);
    friend bool operator==(const STRING& lhs, const STRING& rhs);


    void display() const {
        cout << str;
    }
};

STRING operator+(const STRING& lhs, const STRING& rhs) {
    STRING result;
    if (lhs.length + rhs.length >= STRING::MAX_SIZE) {
        throw "Concatenated string exceeds maximum allowed size.";
    }
    strcpy(result.str, lhs.str); // Copy first string
    strcat(result.str, rhs.str); // Concatenate second string
    result.length = lhs.length + rhs.length;
    return result;
}


bool operator==(const STRING& lhs, const STRING& rhs) {
    return (lhs.length == rhs.length && strcmp(lhs.str, rhs.str) == 0);
}

int main() {
    try {
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

        STRING s5("This string is too long to fit into the fixed-size array.");
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}