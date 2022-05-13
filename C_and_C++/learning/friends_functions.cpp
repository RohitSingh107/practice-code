#include<iostream>
using namespace std;

// forward declaration
class Complex;

class Calculator{
    public:
        int add(int a, int b){
            return a + b;
        }

        int sumRealComplex(Complex o1, Complex o2);
        int sumCompComplex(Complex o1, Complex o2);
};

class Complex{
    private:
        int a;
        int b;
        friend Complex sumComplex(Complex o1, Complex o2);
        // friend int Calculator::sumRealComplex(Complex o1, Complex o2);
        // friend int Calculator::sumCompComplex(Complex o1, Complex o2);
        friend class Calculator;

    public:
        void setData(int v1, int v2){
            a = v1;
            b = v2;
        }

        void printNumber(){
            cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
        }

};

class Y;
class X{
    private:
        int data;
        friend void addf(X, Y);
    public:
        void setValue(int value){
            data = value;
        }
};

class Y{
    private:
        int num;
        friend void addf(X, Y);
    public:
        void setValue(int value){
            num = value;
        }
};
class C2;
class C1{
    private:
        int val1;
        friend void exchange(C1 &, C2 &);
    public:
        void indata(int a){
            val1 = a;
        }

        void display(void){
            cout<<val1<<endl;
        }
};

class C2{
    private:
        int val2;
        friend void exchange(C1 &, C2 &);
    public:
        void indata(int a){
            val2 = a;
        }

        void display(void){
            cout<<val2<<endl;
        }
};

void exchange(C1 &x, C2 &y){
    int tmp = x.val1;
    x.val1 = y.val2;
    y.val2 = tmp;
}

void addf(X o1, Y o2){
    cout<<"Summing data of X and Y objects gives me "<< o1.data + o2.num<<endl;
}


Complex sumComplex(Complex o1, Complex o2){
    Complex o3;
    o3.setData((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

 int Calculator :: sumRealComplex(Complex o1, Complex o2){
            return o1.a + o2.a;
        }
 
 int Calculator :: sumCompComplex(Complex o1, Complex o2){
            return o1.b + o2.b;
        }

int main(){
    
    Complex c1, c2, sum;

    Calculator calc;

    c1.setData(1,2);
    c1.printNumber();
    
    c2.setData(3,4);
    c2.printNumber();
    
    sum = sumComplex(c1, c2);
    sum.printNumber();
    
    int resr = calc.sumRealComplex(c1, c2);
    cout<<"The sum of real part of c1 and c2 is "<<resr<<endl;
    
    int resc = calc.sumCompComplex(c1, c2);
    cout<<"The sum of imagenary part of c1 and c2 is "<<resc<<endl;

    X x;
    x.setValue(3);
    
    Y y;
    y.setValue(5);

    addf(x,y);

    cout<<"Swapping values"<<endl;
    C1 oc1;
    C2 oc2;

    oc1.indata(34);
    oc2.indata(67);

    exchange(oc1, oc2);

    cout<<"The value of oc1 after exchanging becomes: "<<endl;
    oc1.display();

    cout<<"The value of oc2 after exchanging becomes: "<<endl;
    oc2.display();

    return 0;
}

