// To write a C++ program to swap two private data members using friend functions.

// #include <iostream>

// using namespace std;

// class MyClass {
// private:
//     int x;
//     int y;
//     friend void swap(MyClass&, MyClass&);

// public:
//     MyClass(int a, int b) : x(a), y(b) {}

//     void display() {
//         cout << "x = " << x << ", y = " << y << endl;
//     }
// };

// void swap(MyClass& obj1, MyClass& obj2) {
//     int temp = obj1.x;
//     obj1.x = obj2.x;
//     obj2.x = temp;

//     temp = obj1.y;
//     obj1.y = obj2.y;
//     obj2.y = temp;
// }

// int main() {
//     int a, b, c, d;

//     cout << "Enter values for object 1 (x, y): ";
//     cin >> a >> b;
//     MyClass obj1(a, b);

//     cout << "Enter values for object 2 (x, y): ";
//     cin >> c >> d;
//     MyClass obj2(c, d);

//     cout << "Before swapping:" << endl;
//     obj1.display();
//     obj2.display();

//     swap(obj1, obj2);

//     cout << "After swapping:" << endl;
//     obj1.display();
//     obj2.display();

//     return 0;
// }

#include<iostream>

using namespace std;

class B;

class A{
    int a;
    public:
        void getNum(){
            cin >> a;
        }

        void show(){
            cout << a << endl;
        }

        friend void swap(A &, B &);
};

class B{
    int b;
    public:
        void getNum(){
            cin >> b;
        }

        void show(){
            cout << b << endl;
        }

        friend void swap(A &, B &);
};

void swap(A &aobj, B &bobj){
    int temp = aobj.a;
    aobj.a = bobj.b;
    bobj.b = temp;
}

int main(){
    A aobj;
    B bobj;
    
    cout << "Enter A: ";
    aobj.getNum();
    cout << "Enter B: ";
    bobj.getNum();

    swap(aobj, bobj);

    aobj.show();
    bobj.show();
}