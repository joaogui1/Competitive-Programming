/*
ID: joaogui1
LANG: C++
TASK: window
*/
#include <bits/stdc++.h>

using namespace std;

struct window{
  char id;
  int x1, x2, y1, y2, area;
  window(){
	   x1 = x2 = y1 = y2 = 0;
  }
  void create(string s){
    int pos = 4,num = 0;
	  int xx1, xx2, yy1, yy2;
	  id = s[2];
	  for(;s[pos] != ','; ++pos)
      num = 10*num + s[pos] - '0';
    ++pos;
    xx1 = num;
    num = 0;

    for(;s[pos] != ','; ++pos)
      num = 10*num + s[pos] - '0';
    ++pos;
    yy1 = num;
    num = 0;

    for(;s[pos] != ','; ++pos)
      num = 10*num + s[pos] - '0';
    ++pos;
    xx2 = num;
    num = 0;

    for(;s[pos] != ')'; ++pos)
      num = 10*num + s[pos] - '0';
    ++pos;
    yy2 = num;
    num = 0;

	  x1 = min(xx1, xx2); x2 = max(xx1, xx2);
	  y1 = min(yy1, yy2); y2 = max(yy1, yy2);
	  area = (x2 - x1)*(y2 - y1);
    }
};

int sum_window;
window win[110];

int calc_area(int x1,int x2,int y1,int y2,int step){
    int ans = 0;
    while((step <= sum_window) && ((x1 >= win[step].x2) || (x2 <= win[step].x1) || (y1 >= win[step].y2) || (y2 <= win[step].y1)))
      ++step;
    if(step > sum_window){
      ans += (x2 - x1)*(y2 - y1);
      return ans;
    }
    if(x1 < win[step].x1){
      ans += calc_area(x1, win[step].x1, y1, y2, step + 1);
      x1 = win[step].x1;
    }
    if(x2 > win[step].x2){
      ans += calc_area(win[step].x2, x2, y1, y2, step + 1);
      x2 = win[step].x2;
    }
    if(y1 < win[step].y1){
      ans += calc_area(x1, x2, y1, win[step].y1, step + 1);
      y1 = win[step].y1;
    }
    if(y2 > win[step].y2){
      ans += calc_area(x1, x2, win[step].y2, y2, step + 1);
      y2 = win[step].y2;
    }
    return ans;
}

int find(char c){
  for(int i = 1; i <= sum_window; ++i)
	 if(win[i].id == c)
    return i;
}

void swap(int x,int y){
    win[0] = win[x];
    win[x] = win[y];
    win[y] = win[0];
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  ifstream fin ("window.in");
  ofstream fout ("window.out");
  int pos;
  string str;
  while (!fin.eof()){
  	getline(fin, str);
  	if(str[0] == 'w'){
      ++sum_window;
      win[sum_window];
      win[sum_window].create(str);
    }
  	else if(str[0] == 't'){
      pos = find(str[2]);
      swap(pos, 100);
      for(int i = pos; i < sum_window; ++i)
        win[i] = win[i+1];
      swap(100, sum_window);
    }
  	else if(str[0] == 'b'){
      pos = find(str[2]);
      swap(pos, 100);
      for(int i = pos; i >= 2; --i)
        win[i] = win[i-1];
      swap(100, 1);
    }
  	else if(str[0] == 'd'){
      pos = find(str[2]);
      for(int i = pos; i < sum_window; ++i)
        win[i] = win[i + 1];
      --sum_window;
    }
  	else if(str[0] == 's'){
      pos = find(str[2]);
      fout << fixed  << setprecision(3) << (double)calc_area(win[pos].x1,win[pos].x2,win[pos].y1,win[pos].y2,pos+1)/win[pos].area*100 << "\n";
    }
  }
  return 0;
}
