#include <bits/stdc++.h>

using namespace std;

typedef pair <double, double> pdd;

map<int, pdd> cart;
vector <int> com;
double dp[20][20][1010];

void translate(string in){
   for(int i = 0; i < in.size(); ++i){
      if(in[i] == ' ')  com.push_back(11);

      else if((int)(in[i] - 'a') < 3){
         if(i != 0 && (int)(in[i - 1] - 'a') < 3 && (int)(in[i - 1] - 'a') > -1) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'a'); ++j)  com.push_back(2);
      }

      else if((int)(in[i] - 'a') < 6){
         if(i != 0 && (int)(in[i - 1] - 'a') < 6 && (int)(in[i - 1] - 'a') > 2) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'd'); ++j)  com.push_back(3);
      }

      else if((int)(in[i] - 'a') < 9){
         if(i != 0 && (int)(in[i - 1] - 'a') < 9 && (int)(in[i - 1] - 'a') > 5) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'g'); ++j)  com.push_back(4);
      }

      else if((int)(in[i] - 'a') < 12){
         if(i != 0 && (int)(in[i - 1] - 'a') < 12 && (int)(in[i - 1] - 'a') > 8) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'j'); ++j)  com.push_back(5);
      }

      else if((int)(in[i] - 'a') < 15){
         if(i != 0 && (int)(in[i - 1] - 'a') < 15 && (int)(in[i - 1] - 'a') > 11)   com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'm'); ++j)  com.push_back(6);
      }

      else if((int)(in[i] - 'a') < 19){
         if(i != 0 && (int)(in[i - 1] - 'a') < 19 && (int)(in[i - 1] - 'a') > 14) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'p'); ++j)  com.push_back(7);
      }

      else if((int)(in[i] - 'a') < 22){
         if(i != 0 && (int)(in[i - 1] - 'a') < 22 && (int)(in[i - 1] - 'a') > 18) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 't'); ++j)  com.push_back(8);
      }

      else if((int)(in[i] - 'a') < 26){
         if(i != 0 && (int)(in[i - 1] - 'a') < 26 && (int)(in[i - 1] - 'a') > 21) com.push_back(12);
         for(int j = 0; j <= (int)(in[i] - 'w'); ++j)  com.push_back(9);
      }
   }
   return;
}

double dist(int a, int b){
   return sqrt((cart[a].first - cart[b].first)*(cart[a].first - cart[b].first) + (cart[a].second - cart[b].second)*(cart[a].second - cart[b].second))/30.0;
}

double solve(int posd, int pose, int i){
   if(dp[posd][pose][i] != 0) return dp[posd][pose][i];
   if(i == com.size())  return 0;
   return dp[posd][pose][i] = (min(solve(com[i], pose, i + 1) + dist(posd, com[i]), solve(posd, com[i], i + 1) + dist(pose, com[i])) + 0.2);
}

int main(){
   ios_base::sync_with_stdio(0);
   string in;
   cout.precision(2);
   cout.setf(ios::fixed);
   cart[2] = pdd(2.0, 4.0), cart[3] = pdd(3.0, 4.0), cart[4] = pdd(1.0, 3.0), cart[5] = pdd(2.0, 3.0), cart[6] = pdd(3.0, 3.0), cart[7] = pdd(1.0, 2.0), cart[8] = pdd(2.0, 2.0), cart[9] = pdd(3.0, 2.0), cart[10] = pdd(1.0, 1.0), cart[11] = pdd(2.0, 1.0), cart[12] = pdd(3.0, 1.0);
   while(getline(cin, in)){
      com.clear();
      for(int i = 0; i < 20; ++i)
      for(int j = 0; j < 20; ++j)
      for(int k = 0; k < 1000; ++k) dp[i][j][k] = 0.0;
      translate(in);
      cout << solve(6, 4, 0) << endl;
   }

   return 0;
}
