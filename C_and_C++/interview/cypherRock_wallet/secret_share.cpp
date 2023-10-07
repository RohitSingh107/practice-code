
// C++ implementation of shamir’s
// secret sharing algorithm

#include <bits/stdc++.h>
using namespace std;

class Shareholder {

public:
  pair<int, int> share;
  Shareholder(pair<int, int> _share) { share = _share; }

  int reconstructSecret(Shareholder &other_shareholder) {

    // Using Euclid's formula : y1 = ((y0 - y1) / (x0 - x1)) * x1 + c
    // so c = y1 - (((y0 - y1) / (x0 - x1)) * x1)
    return share.second -
           ((other_shareholder.share.second - share.second) * share.first) /
               (other_shareholder.share.first - share.first);
  }
};

class Dealer {

private:
  int secret; // y = mx + c, c = secret
  int m = 0;  // y = mx + c, m != 0, it will be used for verification

public:
  Dealer(int _secret) { secret = _secret; }

  vector<Shareholder> distribute() {
    // Using the polynomial of degree 1: ax + b

    vector<Shareholder> shareholders;

    while (m == 0) {
      m = (rand() % 127);
    }

    for (int i = 1; i <= 4; ++i) {
      int x = (rand() % 127);
      int y = (m * x) + secret; // y = mx + c

      shareholders.push_back(Shareholder({x, y}));
    }

    return shareholders;
  }

  bool verifyShare(pair<int, int> share) {

    if (share.second == m * share.first + secret) { // y = mx + c
      cout << "Share is valid" << std::endl;
      return true;
    } else {
      cout << "Share is invalid" << std::endl;
      return false;
    }
  }

  int reconstructSecret(vector<Shareholder> &shares) {

    if (shares.size() < 2) {
      cout << "At least two shares are required!" << endl;
      return 0;
    }

    // Using Euclid's formula : y1 = ((y0 - y1) / (x0 - x1)) * x1 + c
    // so c = y1 - (((y0 - y1) / (x0 - x1)) * x1)
    return shares[1].share.second -
           ((shares[0].share.second - shares[1].share.second) *
            shares[1].share.first) /
               (shares[0].share.first - shares[1].share.first);
  }
};

int main() {

  int secret = 0;
  std::cout << "Original Secret is " << secret << std::endl;

  Dealer dealer = Dealer(secret);

  vector<Shareholder> shareholders = dealer.distribute();

  cout << "Secret is divided to 4 parts: " << endl;
  for (auto shareholder : shareholders) {
    cout << shareholder.share.first << " " << shareholder.share.second << endl;
  }

  cout << "We can reconstruct Secret from any of 2 parts" << endl;
  vector<Shareholder> anyTwoShare = {shareholders[0], shareholders[2]};
  int reconstructedSecret = dealer.reconstructSecret(anyTwoShare);

  cout << "Reconstructed Secret with 1st and 3nd share is : "
       << reconstructedSecret << endl;

  cout << "Reconstructed Secret with 4st and 2nd share is : "
       << shareholders[3].reconstructSecret(shareholders[1]) << endl;

  // dealer.verifyShare({3, 5073});

  return 0;
}
