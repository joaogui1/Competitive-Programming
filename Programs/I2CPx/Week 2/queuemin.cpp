#include <bits/stdc++.h>
#define ff first
#define ss second
#ifdef DEBUG
  #define fin cin
  #define fout cout
#endif

using namespace std;
typedef pair<int, int> pii;

deque <pii> dq;
int main(){
  #ifndef DEBUG
    ifstream fin ("queuemin.in");
    ofstream fout ("queuemin.out");
  #endif
  char op;
  int n, a, pos;
  fin >> n;
  for(int i = 0; i < n; ++i){
    fin >> op;
    if(op == '+'){
      pos = 1;
      fin >> a;
      while(dq.size() && a < dq.back().ff)  pos += dq.back().ss, dq.pop_back();
      dq.push_back(pii(a, pos));
    }
    else if(op == '-'){
      if(dq.front().ss == 1) dq.pop_front();
      else  --(dq.front().ss);
    }
    else{
      a = dq.front().ff;
      fout << a << "\n";
    }
  }





  return 0;
}
