#include <fstream>
#include <iostream>
using namespace std;
const int v = 40010;
int main() {
  //   fstream cin;
  //   cin.open("4933.txt");
  int n;
  cin >> n;
  int sum = n;
  int *data = new int[n];
  int **dp = new int *[n];
  for (int j = 0; j < n; j++) {
    dp[j] = new int[v];
    for (int k = 0; k < v; k++)
      dp[j][k] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      dp[i][data[i] - data[j] + 20000] +=
          (dp[j][data[i] - data[j] + 20000] + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v; j++) {
      sum += dp[i][j];
      sum %= 998244353;
    }
  }
  delete[] data;
  for (int i = 0; i < n; i++) {
    delete[] dp[i];
  }
  cout << sum << endl;
}