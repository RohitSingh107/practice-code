#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private: 
        int x, y;
        friend float distance_points(Point a, Point b);
    public:
        Point(){ // Default constructor
            x = 0;
            y = 0;
        }
        Point(int a, int b){ // Parametric contructor
            x = a;
            y = b;
        }
        void displayPoint(){
            cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
        }

};

class Complex{
    private:
        int a, b;
    public:
        Complex(int x = 0, int y = 0);
        void printNumber(){
            cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

Complex :: Complex(int x, int y){
    a = x;
    b = y;
}

float distance_points(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


int main(){
    // default contructor
    // Complex c;
    // c.printNumber();

    // Implicit Call
    Complex a(4, 6);
    a.printNumber();

    // Explicit Call
    Complex b = Complex(5,7);
    b.printNumber();

    Complex c = Complex(5);
    c.printNumber();

    Complex d = Complex();
    d.printNumber();

    Point p = Point(6,1);
    p.displayPoint();

    Point q = Point(2,3);
    q.displayPoint();

    Point z = Point();
    z.displayPoint();

    Point r = Point(1,1);
    Point s = Point(0,1);
    Point t = Point(0,6);
    Point u = Point(1,0);
    Point v = Point(70,0);

    cout<<(distance_points(r,r))<<endl;
    cout<<(distance_points(s,t))<<endl;
    cout<<(distance_points(u,v))<<endl;
    cout<<(distance_points(p,q))<<endl;

    return 0;
}