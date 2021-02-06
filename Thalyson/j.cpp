#include <bits/stdc++.h>

using namespace std;

deque<int> a;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, n_, m_, ans = 0, test = 0;
  cin >> n >> m;
  n_ = n, m_ = m;
  a.push_back(0);
  --n_;
  for(int i = 0; i < n + m - 1; ++i){
    if(i & 1){
      if(a.front() == a.back()){
        if(a.front() == 0 && n_ != 0 || m_ == 0){
          a.push_back(0);
          --n_;
        }
        else{
          a.push_back(1);
          --m_;
        }
      }
      else{
        if(n_ > m_){
          if(a.front() == 0)  a.push_front(0);
          else  a.push_back(0);
          --n_;
        }
        else{
          if(a.front() == 1)  a.push_front(1);
          else  a.push_back(1);
        }
      }
    }
    else{
      if(a.front() == a.back()){
        if(a.front() == 0 && n_ != 0 || m_ == 0){
          a.push_back(1);
          --n_;
        }
        else{
          a.push_back(0);
          --m_;
        }
      }
      else{
        if(n_ > m_){
          if(a.front() == 0)  a.push_front(1);
          else  a.push_back(1);
          --n_;
        }
        else{
          if(a.front() == 1)  a.push_front(0);
          else  a.push_back(0);
        }
      }
    }
  }
  for(int i = 0; i < a.size() - 1; ++i){
    if(a[i] == a[i+1]){
      ++ans;
      if(i != 0 && a[i] != a[i - 1])  ++ans;
    }
  }
  a.clear();
  a.push_back(1);
  n_ = n, m_ = m - 1;
  for(int i = 0; i < n + m - 1; ++i){
    if(i & 1){
      if(a.front() == a.back()){
        if(a.front() == 0 && n_ != 0 || m_ == 0){
          a.push_back(0);
          --n_;
        }
        else{
          a.push_back(1);
          --m_;
        }
      }
      else{
        if(n_ > m_){
          if(a.front() == 0)  a.push_front(0);
          else  a.push_back(0);
          --n_;
        }
        else{
          if(a.front() == 1)  a.push_front(1);
          else  a.push_back(1);
        }
      }
    }
    else{
      if(a.front() == a.back()){
        if(a.front() == 0 && n_ != 0 || m_ == 0){
          a.push_back(1);
          --n_;
        }
        else{
          a.push_back(0);
          --m_;
        }
      }
      else{
        if(n_ > m_){
          if(a.front() == 0)  a.push_front(1);
          else  a.push_back(1);
          --n_;
        }
        else{
          if(a.front() == 1)  a.push_front(0);
          else  a.push_back(0);
        }
      }
    }
  }
  for(int i = 0; i < a.size() - 1; ++i){
    if(a[i] == a[i+1]){
      ++test;
      if(i != 0 && a[i] != a[i - 1])  ++test;
    }
  }
  cout << ans << " " << test << endl;
  ans = max(ans, test);
  cout << ans << " " << n + m - 1 - ans << "\n";
  return 0;
}
