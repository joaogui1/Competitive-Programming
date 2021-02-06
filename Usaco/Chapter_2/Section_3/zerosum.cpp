/*
ID: joaogui1
LANG: C++
TASK: zerosum
*/
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>
#define max(a, b) a>b?a:b
using namespace std;
int n,e[10]={1,2,3,4,5,6,7,8,9};
ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");
void dfs(int s,int sum,int num,int sign,string str){
    if(s==n){
        if(sum+sign*num == 0)
        fout << str << endl;
        return;
    }
    dfs(s + 1,sum,num*10+e[s],sign,str+" "+char(e[s]+'0'));
    dfs(s + 1,sum+sign*num,e[s],1,str+"+"+char(e[s]+'0'));
    dfs(s + 1,sum+sign*num,e[s],-1,str+"-"+char(e[s]+'0'));
}
int main(){
   fin >> n;
   dfs(1,0,1,1,"1");

   return 0;
}
