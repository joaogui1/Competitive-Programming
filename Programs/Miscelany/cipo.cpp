#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXM 2000100
#define MAXN 1010
using namespace std;

int rank[MAXN], mark[MAXN], parent[MAXN];
void zerargraph(int v[]){
    for(int i=0; i<MAXN; i++){
       v[i]=0;
    }
}

int find(int v){
     if(parent[v]==v)return v;
     else return parent[v]=find(parent[v]);
}

int unir(int a, int b){
    a=find(a); b=find(b);
    if(rank[a]>rank[b]) swap(a,b);
    parent[a]=b;
    if(rank[a]== rank[b]){
        rank[b]++;
    }

}
int main()
{
    int n,m,u,v,c,inst=1;
    vector <pair<int, int> > edges1;vector <pair<int, int> > edges2;vector <pair<int, int> > edges3;
    while(scanf("%d", &n)!=EOF ){
        zerargraph(rank); zerargraph(mark);edges1.clear();edges2.clear();edges3.clear(); //zera todos os grafos menos parente
        scanf("%d", &m);
        int  over=1;
        long long int res=0;
        for (int i=0; i<m; i++){ //inicializa os cipos
            scanf("%d%d%d", &u, &v, &c);
            if(c==1235){
                edges1.push_back(make_pair(u,v));edges1.push_back(make_pair(v,u));
            }
            else if(c==8977){
                edges2.push_back(make_pair(u,v));edges2.push_back(make_pair(v,u));
            }
            else {
                edges3.push_back(make_pair(u,v));edges3.push_back(make_pair(v,u));
            }
        }

        for (int i=0; i<MAXN; i++){ //inicializa parent
            parent[i]=i;
        }

        for (int i=0; i<edges1.size(); i++){ //gera a arvore com cipos de valor minimo
            int a=edges1[i].first,b=edges1[i].second;
            a=find(a); b=find(b);
            if(a!= b){
                unir(a,b);
                res+=1235;
            }

        }

        for(int j=1; j<=n; j++){ // checa se a arvore é completa
            for (int i=1; i<=n; i++){
                if(find(i)!= find(j)) over=0;
            }
    }

        if(!over){      //se não adiciona os cipos de valor medio
            for (int i=0; i<edges2.size(); i++){
            int a=edges2[i].first,b=edges2[i].second;
            a=find(a); b=find(b);
            if(a!= b){
                unir(a, b);
                res+=8977;
            }

        }
        over=1;
        }

        for(int j=1; j<=n; j++){ // checa se a arvore esta completa
            for (int i=1; i<=n; i++){
                if(find(i)!= find(j)) over=0;
            }
    }

        if(!over){ // se não adiciona os cipos caros
            for (int i=0; i<edges3.size(); i++){
            int a=edges3[i].first,b=edges3[i].second;
            a=find(a); b=find(b);
            if(a!= b){
                unir(a, b);
                res+=10923;
            }

        }
        over=1;
        }
        printf("Instancia %d\n%lld\n",inst, res);
        inst++;
    }
    return 0;
}
