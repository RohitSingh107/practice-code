#include<iostream>
using namespace std;

string f(int a[], int k, int n){
    for(int i = 0; i< n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] + a[j] == k){
                return "YES";
            }
        }
    }
    return "NO";
}

string g(int a[], int k, int n){
    int l = 0;
    int r = n-1;
    while(l<r){
        if(a[l] + a[r] < k){
            l++;
        }
        else if(a[l] + a[r] > k){
            r--;
        }
        else{
            return "YES";
        }
    }
    return "NO";
}


int main(){
    
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    // cout<<f(a,k,n);
    cout<<g(a,k,n);
 

    return 0;
}

