#include <cstdio>
#include <iostream>
#include <list>

using namespace std;
struct value {
  double m, v;
  value(double m, double v) : m(m), v(v) {}
  bool operator<(value &t) { return v > t.v; }
};
int main() {
  int N, T;
  list<value> V;
  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    double m, v;
    cin >> m >> v;
    V.push_back(value(m, v / m));
  }
  V.sort();
  list<value>::iterator p = V.begin();
  double ans = 0;
  while (p != V.end()) {
    if (T - p->m > 0) {
      ans += (p->m) * (p->v);
      T -= p->m;
      p++;
    } else {
      ans += T * (p->v);
      break;
    }
  }
  printf("%.2f", ans);
}