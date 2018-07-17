#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
   string alphabet, phrase, ans;
   cin >> alphabet >> phrase;
   for(int i = 0; i < phrase.size(); ++i)
      ans += alphabet[phrase[i] - 'a'];
   cout << ans << endl;




   return 0;
}
