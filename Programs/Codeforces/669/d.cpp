#include <bits/stdc++.h>

using namespace std;
int nums[100100];
int main(){
  ios_base::sync_with_stdio(0);
  int op, x, n, q, shift1 = 0, shift2 = 0;
  cin >> n >> q;
  for(int i = 0; i < q; ++i){
    cin >> op;
    if(op == 2){
      shift1 -= 1;
      shift2 += 1;
    }
    else{
      cin >> x;
      shift1 += x;
      shift2 += x;
    }
    if(shift1 >= n)  shift1 %= n;
    if(shift1 < 0)  shift1 += n;
    if(shift2 >= n)  shift2 %= n;
    if(shift2 < 0)  shift2 += n;
  }
  shift1 = (shift1 + n)%n;
  shift2 = (shift2 + n)%n;
  for(int i = 0; i < n; i += 2)
    nums[(i + shift2 + n)%n] = i + 1;
  for(int i = 1; i < n; i += 2)
    nums[(i + shift1 + n)%n] = i + 1;
  for(int i = 0; i < n; ++i) cout << nums[i] << " \n"[i + 1 == n];


  return 0;
}
