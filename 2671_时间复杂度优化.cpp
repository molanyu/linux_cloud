#include <fstream>
#include <iostream>
#include <list>

using namespace std;
class Data {
private:
  long long sum_x_numx, sum_x, sum_numx, sum, size;

public:
  static long long *NUM;
  Data() { sum_numx = sum_x_numx = sum_x = sum = size = 0; }
  long long get(long long z) {
    long long numz = NUM[z - 1];
    if (size != 0)
      sum = sum_x_numx + numz * sum_x + z * sum_numx + z * numz * size;
    sum_x_numx += z * numz;
    sum_x += z;
    sum_numx += numz;
    size++;
    return sum;
  }
};
long long *Data::NUM = new long long[100000];
int main() {
  long long n, m, color;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> Data::NUM[i];
  }
  Data *p = new Data[2 * m];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> color;
    sum += p[color * 2 - i % 2 - 1].get(i + 1);
  }
  cout << sum % 10007 << endl;
}