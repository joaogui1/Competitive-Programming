#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

pii input[100010];

int main(){
  int c, m, i, ans, beg;
  scanf("%d", &c);

  while(c--){
    scanf("%d", &m);
    vector <pii> sol, aux;
    i = ans = beg = 0;
    for(int ii = 0; ii < 100010; ++ii) input[ii].first = input[ii].second = 0;
    while(1){
      scanf("%d %d", &input[i].first, &input[i].second);
      if(input[i].second == 0 && input[i].first == 0) break;
      input[i].second = -input[i].second;
      ++i;
    }
    sort(input, input + i);

    for(int j = 0; j < i; ++j){
      if(input[j].first > beg && aux.size()){
        ++ans;
        sort(aux.begin(), aux.end());
        beg = -aux[0].first;
        sol.push_back(pii(aux[0].second, -aux[0].first));
        aux.clear();
      }
      if(input[j].first <= beg)aux.push_back(pii(input[j].second, input[j].first));
      if(beg >= m)  break;
    }

    if(beg < m && aux.size()){
      ++ans;
      sort(aux.begin(), aux.end());
      beg = -aux[0].first;
      sol.push_back(pii(aux[0].second, -aux[0].first));
    }

    if(beg >= m && input[0].first <= 0){
       printf("%d\n", ans);
       sort(sol.begin(), sol.end());
       for(int k = 0; k < sol.size(); ++k)  printf("%d %d\n", sol[k].first, sol[k].second);
    }
    else  printf("0\n");
    printf("\n");
  }


  return 0;
}
