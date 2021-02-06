#include <bits/stdc++.h>

using namespace std;

int ans_beg, ans_end, test_beg, test_end;
long long int kad[20100], dp[20100];

void initialize(){
  ans_beg = 0;
  ans_end = -1;
  test_beg = 0;
  test_end = 0;
  memset(dp, -1, sizeof dp);
  memset(kad, 0, sizeof kad);
}

int kadane(int n){
  int best = 0, test = 0;
  for(int i = 0; i < n; ++i){
    test += kad[i];
    dp[i] = test;
    if(test > best) best = test;
    if(test < 0)  test = 0;

  }
  return best;
}

int main(){
  int t, n;
  long long int best;
  scanf("%d", &t);

  for(int i = 1; i <= t; ++i){
    initialize();

    scanf("%d", &n);
    for(int j = 0; j < n - 1; ++j)
      scanf("%lld", &kad[j]);

    best = kadane(n - 1);
    for(int j = 0; j < n - 1; ++j){
      //if(i == 3 && dp[j] == best) cout << "ok\n";
      if(dp[j] == best){
        test_end = j;
        for(int k = j; k > -1; --k)
          if(dp[k] < 0){
            test_beg = k + 1;
            break;
          }
        if(test_end - test_beg > (ans_end - ans_beg)){
          ans_end = test_end;
          ans_beg = test_beg;
        }
      }
    }

    if(best == 0)printf("Route %d has no nice parts\n", i);
    else  printf("The nicest part of route %d is between stops %d and %d\n", i, ans_beg + 1, ans_end + 2);
  }


  return 0;
}
