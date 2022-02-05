#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){    // So that it is not copied
    cout<<"Size: "<<v.size()<<endl;
    for(int i = 0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    pair<int, string> p, q;
    
    p = make_pair(2, "ees");
    // or
    q = {5, "aaaw"};

    pair<int, string> p2 = p;
    p2.first = 7;

    pair<int, string> &q2 = q;
    
    p2.first = 7;
    q2.first = 9;


    cout<<p.first<<" "<<p.second<<endl;
    cout<<q.first<<" "<<q.second<<endl;

    int a[] = {42,4,3};
    int b[] = {342,64,34};

    pair<int, int>p_array[3];
    p_array[0] = {1,2};
    p_array[1] = {51,92};
    p_array[2] = {61,72};

    swap(p_array[0], p_array[2]);

    for(int i = 0; i< 3; i++){
        cout<<p_array[i].first<< " "<< p_array[i].second<<endl;
    }

    pair<int, string> inp;
    cout << "Enter some integer: ";
    cin >> inp.first;
    cout << inp.first<<endl;

    // vector<int> v;
    // for(int i = 0; i< inp.first; i++){
    //     printVec(v);
    //     cout<<"Enter the element: ";
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }

    // printVec(v);

    // vector<int> y(10);
    vector<int> y(10, 3);
    y.push_back(6);

    // vector<int> &z = y;
    vector<int> z = y; // O(n) copy
    z.push_back(45);
    y.push_back(76);
    y.push_back(769);

    printVec(y);
    printVec(z);

    return 0;
}