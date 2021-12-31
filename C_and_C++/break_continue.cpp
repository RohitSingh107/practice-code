#include<iostream>
using namespace std;

int main(){
    for (int i = 0; i < 40 ; i++)
    {
        /* code */
        // cout<<i<<endl;
        if (i==2)
        {
            /* code */
            break;
        }
        cout<<i<<endl;
    }

    for (int j = 0; j < 4 ; j++)
    {
        /* code */
        // cout<<i<<endl;
        if (j==2)
        {
            /* code */
            continue;
        }
        cout<<j<<endl;
    }
    
    return 0;
}