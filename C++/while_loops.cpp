# include <iostream>
# include <iomanip>
using namespace std;

int main(){
    for (int i = 0; i<100; i++){
        cout<<i<<endl;
    }

    int i = 0;
    while(i<=40){
        cout<<i<<endl;
        i++;
 
    }


    i = 1;
    do{
        cout<<i<<endl;
        i++;
 
    }while(false);

    int t=1;
    while(t<=10){
        cout<<"6 * "<<t<<" = "<<setw(3)<<6*t<<endl;
        t++;
    }

    return 0;
}