#include<bits/stdc++.h>

using namespace std;

int arr[1 << 11];

int main(){
  int c, n, t, m, ans, pos;
  scanf("%d", &c);

  while(c--){
    scanf("%d %d %d", &n, &t, &m);
    ans = pos = 0;
    memset(arr, 0, sizeof arr);
    for(int i = 0; i < m; ++i)  scanf("%d", &arr[i]);

    sort(arr, arr + m);

    if(m%n == 0){
      ans = arr[n - 1] + 2*t;
      pos = n;
    }
    else{
      ans = arr[m % n - 1] + 2*t;
      pos = m % n;
    }
    for(; pos < m; pos += n)
      ans = max(ans, arr[pos + n - 1]) + 2*t;

    printf("%d %d\n", ans - t, (m + n - 1)/n);
  }

  return 0;
}
