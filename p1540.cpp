#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
  int M, N;
  cin >> M >> N;
  vector<int> num(M);
  vector<int>::iterator p = num.begin();
  int cnt = 0;
  int *text = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> text[i];
  }
  for (int i = 0; i < N; i++) {
    bool judge = false;
    for (vector<int>::iterator t = num.begin(); t != p; t++) {
      if (*t == text[i]) {
        judge = true;
        break;
      }
    }
    if (!judge) {
      cnt++;
      p--;
      p++;
      if (p == num.end()) {
        num.erase(num.begin());
        num.push_back(text[i]);
        p = num.end();
        continue;
      }
      *p = text[i];
      p++;
    }
  }
  cout << cnt << endl;
}