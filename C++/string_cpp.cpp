# include <iostream>
# include <string>
using namespace std;

int main(){

    // string name ="rohit";
    // string last = "singh";
    // cout<<"The name is "<<name<<endl;
    // cout<<"The length of name is "<<name.length()<<endl;
    // cout<<"The name is "<<name.substr(0,3)<<endl;
    // cout<<"The name is "<<name.substr(2,3)<<endl;
    // cout<<"The name is "<<name.size();
    // cout<<"The name is "<<name + last<<endl;

    // int n;
    // cin>>n;
    // n++;
    // while(n--){

    
    // string s;
    // getline(cin, s);

    // cout<<s<<endl;
    // }

    string str;
    cout<<"Enter the text to reverse"<<endl;
    cin>>str;
    string str_rev;
    for (int i = str.size() - 1; i >=0; i-- ){
        str_rev.push_back(str[i]);
    }

    cout<<str_rev<<endl;

    string s ;
    cout<<"enter the number"<<endl;
    cin >>s;
    int last_digit = s[s.size() - 1] - '0';
    cout<<last_digit<<endl;


    return 0;
}