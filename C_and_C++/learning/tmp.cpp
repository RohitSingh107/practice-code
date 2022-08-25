#include <bits/stdc++.h>
#include <vector>

#define FAST                                                                   \
  {                                                                            \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);                                                               \
  }
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>

using namespace std;

template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

const int N = 200005;

void solve() {
  std::cout << "h1" << std::endl;

  int size, add, diff;
  cin >> size >> add >> diff;

  vector<int> arr(size);
  std::cout << "h2" << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << "h3 i is " << i << std::endl;
    cin >> arr[i];
  }
  std::cout << "h4" << std::endl;
  vi needStudents;
  std::cout << "h5" << std::endl;
  sort(arr.begin(), arr.end());
  std::cout << "h6" << std::endl;
  for (int i = 0; i < size - 1; ++i) {
    std::cout << "h7" << std::endl;
    int temp = abs(arr[i] - arr[i + 1]);
    std::cout << "h8" << std::endl;
    if (temp > diff) {
      std::cout << "h9" << std::endl;
      if (temp % diff == 0)
        needStudents.pb((temp / diff) - 1);
      else
        needStudents.pb(temp / diff);
    }
    std::cout << "h10" << std::endl;
  }
  sort(needStudents.begin(), needStudents.end());
  std::cout << "h11" << std::endl;
  int i = 0, j = 0;
  while (add) {
    std::cout << "h12" << std::endl;
    if (needStudents[i] <= add) {
      std::cout << "h13" << std::endl;
      add -= needStudents[i];
      std::cout << "h14" << std::endl;
      needStudents[i] = 0;
      std::cout << "h15" << std::endl;
      j++;
      std::cout << "h16" << std::endl;
    }
    std::cout << "h17" << std::endl;
    i++;
  }
  std::cout << "h18" << std::endl;
  cout << needStudents.size() - j + 1 << endl;
}

int32_t main() {

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
