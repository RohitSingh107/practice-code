#include <iostream>
#include <string>
using namespace std;

int main() {
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

    string str = "Rohit";
    // cout<<"Enter the text to reverse"<<endl;
    // cin>>str;
    string str_rev;
    for (int i = str.size() - 1; i >= 0; i--) {
        str_rev.push_back(str[i]);
    }

    cout << str_rev << endl;

    string s = "748";
    // cout<<"enter the number"<<endl;
    // cin >>s;
    int last_digit = s[s.size() - 1] - '0';
    cout << last_digit << endl;

    string myst("GeeksForGeeks");
    string myst1(5, '*');
    cout << myst1 << endl;
    cout << myst1.size() << endl;
    cout << myst.substr(3, 6) << endl;
    myst.erase(3, 6);
    cout << myst << endl;
    cout << myst.find("ks") << endl;
    cout << " replacing: " << myst.replace(2, 3, "are") << endl;

    string s1 = "fam";
    string s2 = "ily";
    s1.append(s2);
    cout << s1 << endl;
    s1.insert(2, "dkjdaksdn");
    cout << s1 << endl;

    string party = "yoemaihuyempartericarhaiauryahappartyatyhorahihai";
    // cout << party.find("party") << endl;
    auto its = party.find("party");
    if(its != std::string::npos){
        cout<<"Found at: "<<its<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }


    return 0;
}