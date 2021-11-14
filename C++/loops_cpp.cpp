# include <iostream>
using namespace std;

int main(){

    int index = 0;
    while(index<34)
    {
        cout<<"You are at index number "<<index<<endl;
        index = index + 1;
    }

    do {
        cout << "We are at Index "<<index<< endl;
        index = index + 1;
    } while (index > 3453);

    for (int i =0; i < 5; i++)
    {
        cout<< "The value of i is "<<i<<endl;
    }

    int t;
    cout<<"Enter the number of test cases"<<endl;
    cin>>t;

    while(t--){

        // cout<<t<<endl;

        int n;
        cout<<"Enter the number"<<endl;
        cin >> n;


        for(int i =0; i<=n; i++){

            for(int j = 0; j<=i; j++){
                cout<<"+";
            }
            cout<<endl;


        }
    }

    





    return 0;
}