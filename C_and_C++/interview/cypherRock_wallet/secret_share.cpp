
// C++ implementation of shamir’s
// secret sharing algorithm

#include <bits/stdc++.h>
#include <cstdint>
#include <utility>
#include <vector>
using namespace std;

class Shareholder {

public:
  vector<pair<int, int>> share;
  Shareholder() {

    for (int i = 0; i < 32; i++) {
      share.push_back({0, 0});
    }
  }

  vector<int> reconstructSecret(Shareholder &other_shareholders) {

    vector<int> reconstructSecret(32);

    // Using Euclid's formula : y1 = ((y0 - y1) / (x0 - x1)) * x1 + c
    // so c = y1 - (((y0 - y1) / (x0 - x1)) * x1)
    for (int i = 0; i < 32; i++) {

      int y1 = share[i].second;
      int y0 = other_shareholders.share[i].second;
      int x1 = share[i].first;
      int x0 = other_shareholders.share[i].first;
      reconstructSecret[i] = y1 - ((y0 - y1) * x1) / (x0 - x1);
    }

    return reconstructSecret;
  }
};

class Dealer {

private:
  int secret[32]; // y = mx + c, c = secret
  int mArray[32]; // y = mx + c, m != 0, it will be used for verification

public:
  Dealer(const int secretByteArray[32]) {
    for (int i = 0; i < 32; i++) {
      secret[i] = secretByteArray[i];
    }
  }

  vector<Shareholder> distribute() {
    // Using the polynomial of degree 1: ax + b

    vector<Shareholder> shareholders(4);

    for (int c = 0; c < 32; c++) {
      int m = 0;
      while (m == 0) {
        m = (rand() % 127);
      }
      mArray[c] = m;

      for (int i = 0; i < 4; ++i) {
        int x = (rand() % 127);
        int y = (m * x) + secret[c]; // y = mx + c

        shareholders[i].share[c] = {x, y};
      }
    }

    return shareholders;
  }

  bool verifyShare(vector<pair<int, int>> &share) {

    for (int i = 0; i < 32; i++) {

      if (share[i].second !=
          mArray[i] * share[i].first + secret[i]) { // y = mx + c
        return false;
      }
    }
    cout << "Share is valid" << std::endl;
    return true;
  }
  vector<int> reconstructSecret(vector<Shareholder> &shareholders) {

    vector<int> reconstructSecret(32);

    if (shareholders.size() < 2) {
      cout << "At least two shares are required!" << endl;
      return {};
    }

    // Using Euclid's formula : y1 = ((y0 - y1) / (x0 - x1)) * x1 + c
    // so c = y1 - (((y0 - y1) / (x0 - x1)) * x1)
    for (int i = 0; i < 32; i++) {

      int y1 = shareholders[1].share[i].second;
      int y0 = shareholders[0].share[i].second;
      int x1 = shareholders[1].share[i].first;
      int x0 = shareholders[0].share[i].first;
      reconstructSecret[i] = y1 - ((y0 - y1) * x1) / (x0 - x1);
    }

    return reconstructSecret;
  }
};

int main() {

  // Declare an array of bytes with a size of 32
  int secretByteArray[32] = {4,  2, 4,  3, 71, 41, 3, 1,  6,  7,  1,
                             22, 3, 0,  7, 8,  9,  1, 0,  5,  25, 3,
                             56, 8, 94, 2, 3,  4,  5, 67, 33, 4};

  // // You can initialize or manipulate the elements as needed
  // for (int i = 0; i < 32; ++i) {
  //   secretByteArray[i] = i; // Initialize with values from 0 to 31
  // }

  // Print the array elements
  std::cout << "Original Secret: ";
  for (int i = 0; i < 32; ++i) {
    std::cout << static_cast<int>(secretByteArray[i]) << " ";
  }
  std::cout << std::endl;

  Dealer dealer = Dealer(secretByteArray);

  vector<Shareholder> shareholders = dealer.distribute();

  cout << "Secret is divided to 4 parts: " << endl;
  // Here we can print all the cordinates but because of too many parts (each
  // having 32 bytes) it will look messy
  // for (auto shareholder : shareholders) {
  //   for (auto p : shareholder.share) {
  //
  //     std::cout << "{" << p.first << "," << p.second << "}, ";
  //   }
  //   std::cout << std::endl;
  // }

  cout << "We can reconstruct Secret from any of 2 parts" << endl;
  cout << "Constructing from 1st and 3nd share: " << endl;
  vector<Shareholder> anyTwoShare = {shareholders[0], shareholders[2]};
  vector<int> reconstructedSecret = dealer.reconstructSecret(anyTwoShare);

  // Print the reconstructed elements
  std::cout << "Secret from 1st and 3rd share: ";
  for (int i = 0; i < 32; ++i) {
    std::cout << reconstructedSecret[i] << " ";
  }
  std::cout << std::endl;

  cout << "Constructing from 4th and 2nd share: " << endl;
  vector<int> reconstructedSecretAgain =
      shareholders[3].reconstructSecret(shareholders[1]);

  // Print the reconstructed elements
  std::cout << "Secret from 4th and 2nd share: ";
  for (int i = 0; i < 32; ++i) {
    std::cout << reconstructedSecretAgain[i] << " ";
  }
  std::cout << std::endl;

  // dealer.verifyShare(shareholders[3].share);
  return 0;
}
