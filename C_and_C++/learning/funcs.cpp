# include <iostream>
using namespace std;

// Function prototype
int add_f(int a, int b);
void g(void);

int main(){

    int a,b;

    cout<<"Enter first number:"<<endl;
    cin>>a;

    cout<<"enter second no:"<<endl;
    cin>>b;

    cout<<"The function returned "<<add_f(a,b)<<endl;

    g();

    return 0;
}


int add_f(int a, int b){
    // Formal Parameters a and b will be taking value from actual parameters num1 and num2
    int c;
    c = a + b;
    return c;
}

void g(){
    cout<<"Helo from void function"<<endl;
}