#include<iostream>
using namespace std;

class Employee {
    private:
        int a, b, c;
    
    public:
        int d,e;
        void setData(int a1, int b1, int c1);
        void getData(void){
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};


class binary {
    private:
        string s;
    public:
        void read(void);
        void check_bin(void);
        void ones(void);
        void display(void);

};


int main(){
    

    Employee rohit;
    // rohit.a = 9;
    rohit.d = 5;
    rohit.e = 6;
    rohit.setData(1, 2 , 40);
    rohit.getData();

    binary b;
    b.read();
    // b.check_bin();
    b.display();
    b.ones();
    b.display();


    return 0;
}


void Employee :: setData(int a1, int b1, int c1){

    a = a1;
    b = b1;
    c = c1;

}

void binary :: read(void){
    cout<<"Enter a binary no"<<endl;
    cin>>s;
    cout<<"Length of no is "<<s.length()<<endl;
}

void binary :: check_bin(void){

    for (int i = 0; i < s.length(); i++){
        if (s.at(i) != '0' && s.at(i) != '1'){
            cout<<"Incorrect Binary"<<endl;
            exit(0);
        }
    }

}

void binary :: ones(void){
    check_bin();
    for (int i = 0; i < s.length(); i++){
        if (s.at(i) =='0'){
            s.at(i) = '1';
        }

        else {
            s.at(i) = '0';
        }

    }
}

void binary :: display(void){
    cout<<"Displaying no: "<<endl;
    for (int i = 0; i < s.length(); i++){
        cout<<s.at(i);

    }
    cout<<endl;
}
