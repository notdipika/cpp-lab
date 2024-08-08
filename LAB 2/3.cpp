// To write a C++ program to manipulate complex numbers using operator overloading. (addition,subtraction,multiplication,division)
#include<iostream>

using namespace std;

class Complex {
    private:
    float real;
    float img;

    public:
        Complex(float r = 0, float i = 0) {
        real = r;
        img = i;
        }

        void input(){
            cout<<"Enter real part: ";
            cin >> real;
            cout<<"Enter imaginary part: ";
            cin >> img;
        }

            friend Complex operator+(Complex&, Complex&);
            friend Complex operator-(Complex&, Complex&);
            friend Complex operator*(Complex&, Complex&);
            friend Complex operator/(Complex&, Complex&);
            friend ostream& operator<<(ostream&, Complex&);
};

Complex operator+(Complex& c1, Complex& c2) {
    return Complex(c1.real + c2.real, c1.img + c2.img);
}

Complex operator-(Complex& c1,  Complex& c2) {
    return Complex(c1.real - c2.real, c1.img - c2.img);
}

Complex operator*( Complex& c1,  Complex& c2) {
    return Complex(c1.real * c2.real - c1.img * c2.img, c1.real * c2.img + c1.img * c2.real);
}

Complex operator/( Complex& c1,  Complex& c2) {
    float denom = c2.real * c2.real + c2.img * c2.img;
    return Complex((c1.real * c2.real + c1.img * c2.img) / denom,
                   (c1.img * c2.real - c1.real * c2.img) / denom);
}

ostream& operator<<(ostream& os,  Complex& c) {
    if (c.img<0){
        os << c.real << c.img << "i";
    }
    else{
        os << c.real << " + " << c.img << "i";
    }
    return os;
}

int main(){
    Complex c1, c2, sum, diff, prod, quo;
    cout << "Enter first number:\n";
    c1.input();
    cout << "Enter second number:\n";
    c2.input();

    sum = c1 + c2;
    diff = c1 - c2;
    prod = c1 * c2;
    quo = c1 / c2;

    cout << "Addition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;
    cout << "Multiplication: " << prod << endl;
    cout << "Division: " << quo << endl;
    return 0;
}