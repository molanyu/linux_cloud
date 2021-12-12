#include <fstream>
#include <iostream>
using namespace std;
int max(int a, int b, int c, int d) {
  a = a > b ? a : b;
  c = c > d ? c : d;
  return a > c ? a : c;
}
int f(int **p, int **data, int r, int c, int R, int C) {
  if (p[r][c] > 0) {
    return p[r][c];
  }
  int up, down, left, right;
  up = down = left = right = 0;
  if (r - 1 >= 0 && data[r - 1][c] < data[r][c]) {
    up = f(p, data, r - 1, c, R, C);
  }
  if (c - 1 >= 0 && data[r][c - 1] < data[r][c]) {
    left = f(p, data, r, c - 1, R, C);
  }
  if (c + 1 < C && data[r][c + 1] < data[r][c]) {
    right = f(p, data, r, c + 1, R, C);
  }
  if (r + 1 < R && data[r + 1][c] < data[r][c]) {
    down = f(p, data, r + 1, c, R, C);
  }
  if (!(up + down + left + right)) {
    p[r][c] = 1;
    return 1;
  }
  p[r][c] = max(up, down, left, right) + 1;
  return p[r][c];
}
int main() {
  int R, C, **data, **p;
  cin >> R >> C;
  data = new int *[R];
  p = new int *[R];
  for (int i = 0; i < R; i++) {
    data[i] = new int[C];
    p[i] = new int[C];
    for (int j = 0; j < C; j++) {
      cin >> data[i][j];
      p[i][j] = 0;
    }
  }
  int max = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      max = max > f(p, data, i, j, R, C) ? max : f(p, data, i, j, R, C);
    }
  }
  cout << max;
}