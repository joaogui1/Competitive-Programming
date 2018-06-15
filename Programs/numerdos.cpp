#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include<cstring>
#include <queue>
#include <algorithm>
#define MAXN 110
using namespace std;
map <string, int > author;
int G[MAXN][MAXN], mark[MAXN], vect[MAXN];

void bfs(int v, int *vec)
{
    queue<int> q;
    q.push(v);
    mark[v]=1;

    while(!q.empty())
    {
        int v=q.front();q.pop();
        for (int l=1; l<MAXN; l++)
        {
            if(G[v][l]==1 && !mark[l])
            {
                vec[l]=vec[v]+1;
                mark[l]=1;
                q.push(l);
            }
        }
    }
}

int main(){
    int t=0,a, b, remain=1, num, cont=0;
    string namea, nameb;
    char c='a';
    scanf("%d", &remain);
    while(remain){
        scanf("%d", &num);
        for(int i=0; i<num; i++){
            while (1){
                c=getchar();
                if(c==',') break;
                namea.push_back(c);
            }
            if(author.find(namea)==author.end()){
                cont++;
            }
            author.insert(pair <string,int >(namea, cont));
            getchar();
            while (1){
                c=getchar();
                if(c=='.') break;
                nameb.push_back(c);
            }
            if(author.find(nameb)==author.end()){
                cont++;
            }
            author.insert(pair <string,int >(namea, cont));
            a=author[namea];b=author[nameb];
            G[a][b]=G[b][a]=1;
        }
        string erdos="P. Erdos";
        a=author[erdos];
        bfs(a,vect);
        scanf("%d", &remain);
    }

    return 0;
}
