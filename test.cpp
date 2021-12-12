#include <cmath>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
class tree {
private:
  char *N;
  int size;

public:
  tree(int size) : size(size) {
    N = new char[size];
    for (int i = 0; i < size; i++)
      N[i] = ' ';
  }
  void set(string str) {
    for (int i = 0; i < size && str[i] != '\0'; i++) {
      N[i] = str[i];
    }
    int cnt = 0;
  }
  void output(int visit, int begin = 1) {
    if (begin >= size - 1) //判断数组是否越界
      return;
    if (N[begin - 1] == ' ') //判断该节点是否为空 空用 ' '表示
      return;
    if (visit == 1) //前序遍历
      cout << N[begin - 1];
    output(visit, 2 * begin);
    if (visit == 2) //中序遍历
      cout << N[begin - 1];
    output(visit, 2 * begin + 1);
    if (visit == 3) //后序遍历
      cout << N[begin - 1];
  }
};
int main() {
  // tree t(pow(2, 5));
  // string str = "-+/a*ef  b-          cd        ";
  // t.set(str);
  // for (int i = 1; i < 4; i++) {
  //   t.output(i);
  //   cout << endl;
  // }
  fstream infile;
  infile.open("P3916_1_out.txt");
  int cnt = 0, t;
  while (infile >> t) {
    cnt++;
  }
  cout << cnt << endl;
}
