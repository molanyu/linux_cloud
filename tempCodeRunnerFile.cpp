#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Data {
  string name;
  int num;
  string sex;
  int age;
  string class1;
  string con;
  Data(string a1, int b1, string a2, int b2, string a3, string a4)
      : name(a1), num(b1), sex(a2), age(b2), class1(a3), con(a4) {}
};

struct LinkNode {
  Data *data;
  LinkNode *link;
  LinkNode(string a1, int b1, string a2, int b2, string a3, string a4,
           LinkNode *p = NULL) {
    link = p;
    data = new Data(a1, b1, a2, b2, a3, a4);
  }
};

class CirList {
public:
  LinkNode *head;
  CirList(fstream &infile, int n);
  ~CirList() { delete[] head; }
  void yuesefu(CirList &c, int n, int m);
};

CirList::CirList(fstream &infile, int n) {
  head = new LinkNode("", 0, "", 0, "", "");
  string a1, a2, a3, a4;
  int b1 = 0, b2 = 0;
  LinkNode *p = head, *r;
  for (int i = 0; i < n; i++) {
    infile >> a1 >> b1 >> a2 >> b2 >> a3 >> a4;
    p->link = new LinkNode(a1, b1, a2, b2, a3, a4);
    //	r->link=p;
    //  r=p;
    p = p->link;
  }

  // r->link=head->link;
  //
  p->link = head->link;
  // p = p->link;
  // printf("%s %d %s %d %s %s\n", p->data->name.c_str(), p->data->num,
  //        p->data->sex.c_str(), p->data->age, p->data->class1.c_str(),
  //        p->data->con.c_str());
  // delete[] head;
  // head = p->link;
};
void CirList::yuesefu(CirList &c, int n, int m) {
  //	LinkNode *p=head,*q;
  //	while(p->link!=p)
  //	{
  //		for(int k=0;k<m;k++)
  //		p=p->link;
  //		q=p;
  //		//cout<<q->data<<endl;
  //		printf("%s %d %s %d %s %s\n",
  // q->data->name.c_str(),q->data->num,q->data->sex.c_str(),q->data->age,q->data->class1.c_str(),q->data->con.c_str());
  //
  //
  //		p->link=q->link;
  //		delete q;
  //		p=p->link;
  //
  //	}
  ////	cout <<p->data<<endl;
  //		printf("%s %d %s %d %s %s\n",
  // p->data->name.c_str(),p->data->num,p->data->sex.c_str(),p->data->age,p->data->class1.c_str(),p->data->con.c_str());

  LinkNode *p = head->link, *q = NULL;
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < m; j++) {
      q = p;
      p = p->link;
    }
    printf("%s %d %s %d %s %s\n", p->data->name.c_str(), p->data->num,
           p->data->sex.c_str(), p->data->age, p->data->class1.c_str(),
           p->data->con.c_str());
    q->link = p->link;
    delete p;
    p = q->link;
  }
  printf("%s %d %s %d %s %s\n", q->data->name.c_str(), q->data->num,
         q->data->sex.c_str(), q->data->age, q->data->class1.c_str(),
         q->data->con.c_str());
};

int main() {
  int n = 0, m = 0;
  fstream infile;
  infile.open("test.txt");
  infile >> n >> m;

  if (n > 0) {
    CirList c1(infile, n);
    c1.yuesefu(c1, n, m);
  }
  return 0;
}
