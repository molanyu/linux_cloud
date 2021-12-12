#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int SIZE = 1000000;
int main() {
  //   fstream cin;
  //   cin.open("1020.txt");

  int *data = new int[SIZE];
  int *cmp1 = new int[SIZE];
  int *cmp2 = new int[SIZE];
  int last = 0;
  cin >> data[last++];
  while (cin >> data[last]) {
    cmp1[last] = 0;
    cmp2[last] = 0;
    last++;
  }
  //最长不升子序列
  int size = 0;
  cmp1[0] = data[last - 1];
  for (int i = last - 2; i >= 0; i--) {
    if (data[i] >= cmp1[size]) {
      size++;
      cmp1[size] = data[i];
    } else {
      int pos = upper_bound(cmp1, cmp1 + size, data[i]) - cmp1;
      cmp1[pos] = data[i];
    }
  }
  //最长不升子序列的反链 最长上升子序列？
  int size2 = 0;
  cmp2[0] = data[0];
  for (int i = 1; i < last; i++) {
    if (data[i] > cmp2[size2]) {
      size2++;
      cmp2[size2] = data[i];
    } else {
      int pos = lower_bound(cmp2, cmp2 + size2, data[i]) - cmp2;
      cmp2[pos] = data[i];
    }
  }
  cout << size + 1 << endl;
  cout << size2 + 1 << endl;
}