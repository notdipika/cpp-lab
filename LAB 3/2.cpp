/*Program to convert Polar Coordinate to Cartesian.*/
#include<iostream>
#include<cmath>

#define PI 3.141592

using namespace std;

class polar{
    float rad, ang;
    public:
        polar(float r, float a){
            rad = r;
            ang = PI * a / 180;
        }

        float getR(){
            return rad;
        }

        float getA(){
            return ang;
        }
};

class cartesian{
    float x, y;
    public:
        cartesian(){}
        cartesian(polar p){
            float r = p.getR();
            float a = p.getA();
            x = r * cos(a);
            y = r * sin(a);
        }
        void show(){
            cout << "X: " << x << "\tY: " << y;
        }
};

int main(){
    float r, a;
    cout << "Enter the radius: ";
    cin >> r;
    cout << "Enter the angle (in degrees): ";
    cin >> a;

    polar p(r, a);
    cartesian c(p);

    c.show();

    return 0;
}