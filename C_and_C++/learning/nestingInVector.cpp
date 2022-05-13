#include <bits/stdc++.h>
using namespace std;

void printPairVec(vector<pair<int, int>> &v){    // So that it is not copied
    cout<<"Size of Vecotor: "<<v.size()<<endl;
    for(int i = 0; i< v.size(); i++){
        cout<<v[i].first << " "<< v[i].second<<endl;
    }
}

void printVV(vector<vector<int>> &v){    // So that it is not copied
    cout<<"Size: "<<v.size()<<endl;
    for(int i = 0; i< v.size(); i++){
        cout<<"Size: "<<v[i].size()<<endl;
        for(int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<< " ";
        }
        cout<<endl;
    }
}

int main(){
    
    // vector<pair<int, int>> v;
    // cout<<"Enter size of vector: ";
    // int n;
    // cin>>n;
    // for(int i = 0; i< n; i++){
    //     cout<<"Enter the elements"<<endl;
    //     int x, y;
    //     cin>>x>>y;
    //     v.push_back({x,y});
    // }
    // printPairVec(v);

    vector<vector<int>> vv;

    cout<<"Enter size of vector of vectors: ";
    int ov;
    cin>>ov;

    for(int i = 0; i< ov; i++){
        cout<<"Enter size of vector at index "<<i<<": ";
        int iv;
        cin >> iv;
        vector<int> tmp;
        for(int j = 0; j< iv; j++){
            cout<<"Enter element at of vector at index "<<i<<j<<": ";
            int a;
            cin >>a;
            tmp.push_back(a);
        }
        vv.push_back(tmp);
    }

    printVV(vv);

    return 0;
}