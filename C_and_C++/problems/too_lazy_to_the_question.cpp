#include<iostream>
using namespace std;

int main(){
    int a, b,c;
    cin>>a>>b>>c;
    int cth_value;
    int i = 2;
    while (c){
        if (i % a == 0 || i % b == 0){
            cth_value = i;
            c--;

        }
        i++;
    }

    int lcm;
    for (i = 1; i<= a*b; i++){
        if (i % a == 0 && i % b == 0){
            lcm = i;
            break;
        }
    }

    int step;
    if (cth_value % a == 0 && cth_value % b == 0){
        step = lcm;
    }

    else if (cth_value % a == 0){
        step = a;
    }

    else {
        step = b;
    }


    for (int i = cth_value; i >= 0; i = i - step){
        cout<<i<<" ";
    }

    
    return 0;
}