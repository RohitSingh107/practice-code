
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the value of y
int calculate_Y(int x, vector<int> &poly) {
  int y = 0;
  int temp = 1;

  for (auto coeff : poly) {
    y = (y + (coeff * temp));
    temp = (temp * x);
  }
  return y;
}

// Function to perform the secret sharing algorithm and encode the given secret
void secret_sharing(vector<int> &secret, vector<pair<int, vector<int>>> &points,
                    int N, int K) {
  int secret_len = secret.size();
  vector<vector<int>> poly(K, vector<int>(secret_len, 0));

  for (int i = 0; i < secret_len; ++i) {
    poly[0][i] = secret[i];
  }

  for (int j = 1; j < K; ++j) {
    for (int i = 0; i < secret_len; ++i) {
      int p = 0;
      while (p == 0) {
        p = (rand() % 997);
      }
      poly[j][i] = p;
    }
  }

  for (int j = 1; j <= N; ++j) {
    int x = j;
    vector<int> y(secret_len, 0);
    for (int i = 0; i < secret_len; ++i) {
      std::cout << j << " " << i << " h1 " << secret_len << std::endl;
      y[i] = calculate_Y(x, poly[i]);
      std::cout << j << " " << i << " h2 " << secret_len << std::endl;
    }
    points.push_back({x, y});
  }
  std::cout << "h2" << std::endl;
}

// Function to generate the secret back from the given points
vector<int> Generate_Secret(int x[], vector<int> y[], int M, int secret_len) {
  vector<int> ans(secret_len, 0);

  for (int i = 0; i < M; ++i) {
    vector<int> l = y[i];
    for (int j = 0; j < M; ++j) {
      if (i != j) {
        for (int k = 0; k < secret_len; ++k) {
          int temp = x[i] - x[j];
          l[k] *= -x[j];
          l[k] /= temp;
        }
      }
    }
    for (int k = 0; k < secret_len; ++k) {
      ans[k] += l[k];
    }
  }

  return ans;
}

// Function to encode and decode the given secret
void operation(vector<int> &secret, int N, int K) {
  vector<pair<int, vector<int>>> points;
  std::cout << "h1" << std::endl;

  secret_sharing(secret, points, N, K);

  cout << "Secret is divided into " << N << " parts - " << endl;
  for (auto point : points) {
    cout << point.first << " ";
    for (auto val : point.second) {
      cout << val << " ";
    }
    cout << endl;
  }

  cout << "We can generate Secret from any of " << K << " Parts" << endl;

  int M = 2;

  if (M < K) {
    cout << "Points are less than threshold " << K << " Points Required"
         << endl;
  } else {
    int x[M];
    vector<int> y[M];

    for (int i = 0; i < M; ++i) {
      x[i] = points[i].first;
      y[i] = points[i].second;
    }

    int secret_len = secret.size();
    vector<int> reconstructed_secret = Generate_Secret(x, y, M, secret_len);

    cout << "Our Secret Code is: ";
    for (int i = 0; i < secret_len; ++i) {
      cout << reconstructed_secret[i] << " ";
    }
    cout << endl;
  }
}

// Driver Code
int main() {
  vector<int> secret = {65, 42, 99}; // Example array of integers as the secret
  int N = 4;
  int K = 2;

  operation(secret, N, K);
  return 0;
}
