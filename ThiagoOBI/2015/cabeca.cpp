#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
typedef pair<char, pii> pcp;

pcp v[100100];
int esq[200200];

int main(){
  char l;
  int n, d, e;
  esq[1] = -1;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d %c %d", &v[i].ss.ff, &v[i].ff, &v[i].ss.ss);
    esq[v[i].ss.ff] = i;
  }

  for(int pos = esq[0]; pos != -1; pos = esq[v[pos].ss.ss])  printf("%c", v[pos].ff);
  printf("\n");


  return 0;
}
