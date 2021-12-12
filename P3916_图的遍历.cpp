#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>

using namespace std;

void dfs(map<int, list<int>>::iterator p, map<int, list<int>> &data,
         map<int, int> &output, int value) {
  if (p == data.end()) {

    return;
  }
  if (output.find(p->first) == output.end()) {
    int max = p->first > value ? p->first : value;
    output.insert(pair<int, int>(p->first, max));
  }
  for (list<int>::iterator i = p->second.begin(); i != p->second.end(); i++) {
    if (output.find(*i) == output.end()) {
      if (*i <= value) {
        output.insert(pair<int, int>(*i, value));
        dfs(data.find(*i), data, output, value);
      }
    }
  }
}

int main() {
  fstream cin;
  cin.open("P3916_3_in.txt");
  int N, M;
  cin >> N >> M;
  map<int, list<int>> data;
  map<int, int> output;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    map<int, list<int>>::iterator p = data.find(b);
    if (p == data.end()) {
      data.insert(pair<int, list<int>>(b, list<int>(1, a)));

    } else {
      p->second.push_back(a);
    }
  }
  map<int, list<int>>::iterator i = data.end();
  do {
    i--;
    dfs(i, data, output, i->first);
  } while (i != data.begin());
  for (map<int, int>::iterator i = output.begin(); i != output.end(); i++) {
    if (i != output.begin())
      cout << " ";
    cout << i->second;
  }
}