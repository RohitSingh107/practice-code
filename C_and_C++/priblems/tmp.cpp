#include <bits/stdc++.h>
#define nl "\n"
#define ll long long
#define loop b<a[0]  || b>a[chooot2-1]
#define loop2 int k=0;k<m;k++
#define all(v) v.begin(),v.end()

#define inf 1999999996000000010

using namespace std;



void solve() {
ll chooot2,b;
       cin>>chooot2>>b;
       vector<ll> a(chooot2);
       for(ll &x: a) cin>>x;
       sort(all(a));
	   cout<<"plag: "<<a[0] <<" "<< a[chooot2-1] << b<<endl;
       if(b<a[0] || b> a[chooot2-1])
       cout<<"NO"<<endl;
       else
      cout<<"YES"<<endl;
        
 
}




int main() {
int t;
cin>>t;
while(t--)
  solve();

 return 0;
}
