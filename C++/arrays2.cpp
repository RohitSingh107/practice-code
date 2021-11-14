#include<iostream>
using namespace std;

int main(){
    
    int marks[] = {23, 45, 56, 89};
    int mathMarks[4];

    mathMarks[0] = 78;
    mathMarks[1] = 64;
    mathMarks[2] = 8;
    mathMarks[3] = 7;

    cout<<"These are math marks"<<endl;
    cout<<mathMarks[0]<<endl;
    cout<<mathMarks[1]<<endl;
    cout<<mathMarks[2]<<endl;
    cout<<mathMarks[3]<<endl;


    cout<<"These are marks"<<endl;
    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;

    int i = 0;
    while(i < 4){
        cout<<"Marks of "<<i<<" is "<<marks[i]<<endl;
        i++;
    }

    // Pointer and Marks

    int* p = marks;
    // cout<<"The value of marks[0] "<<*p<<endl;
    // cout<<"The value of marks[1] "<<*(p+1)<<endl;
    // cout<<"The value of marks[2] "<<*(p+2)<<endl;
    // cout<<"The value of marks[3] "<<*(p+3)<<endl;

    cout<<*(++p)<<endl;

    // int r, c;
    // cout<<"Enter row and column";
    // cin>> r >>c;
    // int m[r][c];
    // for (int i = 0; i< r; ++i){
    //     for(int j = 0; j < c; ++j){
    //         cin>> m[i][j];
    //     }
    // }

    // for (int i = 0; i< r; ++i){
    //     for(int j = 0; j < c; ++j){
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int z;
    cout<<"Enter no"<<endl;    
    cin>>z;
    int ar[z];
    for (int j = 0; j<z; ++j){
        cin>>ar[j];
    }
    for (int j = z-1; j >= 0; j--){
        cout<<ar[j]<<" ";
    }
    



    return 0;
}