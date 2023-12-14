

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

bool ilc(char c) { return (c >= 'a' && c <= 'z'); }

string threeLetter(char d) {
  switch (d) {
  case '0':
    return "zer";
  case '1':
    return "one";
  case '2':
    return "two";
  case '3':
    return "thr";
  case '4':
    return "for";
  case '5':
    return "fiv";
  case '6':
    return "six";
  case '7':
    return "sev";
  case '8':
    return "eig";
  case '9':
    return "nin";
  default:
    return "";
  }
}

int normalize(int num) {
  while (num >= 10) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    num = sum;
  }
  return num;
}

int normalizeExponent(int exp) { return normalize(exp); }

int noramalizeFinal(const string &numStr) {
  size_t dpos = numStr.find('.');
  if (dpos != string::npos) {
    int sum = 0;
    for (size_t i = dpos + 1; i < numStr.length(); ++i) {
      if (isdigit(numStr[i])) {
        sum += numStr[i] - '0';
      }
    }
    return normalize(sum);
  }
  return 0;
}

string solve(double n, string name) {
  stringstream sn;
  sn << scientific << setprecision(10) << n;
  string sns = sn.str();

  string dp = sns.substr(0, sns.find('e'));
  string ep = sns.substr(sns.find('e') + 1);
  char esn = ep[0];
  ep = ep.substr(1);

  int sDigit = noramalizeFinal(dp);
  int sExponent = normalizeExponent(stoi(ep));
  char f = dp[0];

  // Generate S1
  string S1 = "";
  S1 += threeLetter(f);
  S1 += ".";
  S1 += threeLetter((char)('0' + sDigit));
  S1 += "e" + (esn == '+' ? string("+") : "-") +
        threeLetter(static_cast<char>(sExponent + '0'));

  if (sExponent == 0) {
    size_t pos = S1.find('+');
    if (pos != string::npos) {
      S1.erase(pos, 1);
    }
  }
  string S2 = "";
  if (sExponent % 2) {
    for (size_t i = 0; i < name.length(); i += 2) {
      if (ilc(name[i])) {
        S2 += name[i];
      }
    }
  } else {
    for (size_t i = 1; i < name.length(); i += 2) {
      if (ilc(name[i])) {
        S2 += name[i];
      }
    }
  }

  return S1 + "@" + S2;
}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    double number;
    string name;

    cin >> number >> name;

    bool vName = true;
    for (char c : name) {
      if (!ilc(c)) {
        vName = false;
        break;
      }
    }

    bool vNumber = true;
    stringstream numStream;
    numStream << number;
    string numStr = numStream.str();
    for (char c : numStr) {
      if (!isdigit(c) && c != '.' && c != 'e' && c != '+' && c != '-') {
        vNumber = false;
        break;
      }
    }

    if (!vName || !vNumber) {
      cout << "Invalid" << endl;
    } else {
      cout << solve(number, name) << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return 0;
}
