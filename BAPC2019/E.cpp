#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long INF = 1e18;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

llint dp[1010101][2];

int main() {
  string s;
  cin >> s;
  s = '0' + s;
  int n = s.size();
  for (int i = 0; i < 1010101; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int a = s[i] - '0';
    chmin(dp[i + 1][0], dp[i][0] + a);
    chmin(dp[i + 1][1], dp[i][0] + a + 1);
    chmin(dp[i + 1][0], dp[i][1] + 10 - a);
    chmin(dp[i + 1][1], dp[i][1] + 9 - a);
  }
  cout << dp[n][0] << endl;

  return 0;
}
