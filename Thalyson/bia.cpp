#include <bits/stdc++.h>
#define MAX 100005
#define MAXL 17
#define mp make_pair

using namespace std;

int n;
int nivel[MAX];
int pai[MAX];
int a[MAX][MAXL];
long long int d[MAX];
vector<pair<int, long long int> > adj[MAX];

void dfs(int s){
    int u;
    long long int w;
    for(int i = 0; i < adj[s].size(); i++){
        u=adj[s][i].first;
        w=adj[s][i].second;
        if(nivel[u]==-1){
            nivel[u]=nivel[s]+1;
            d[u]=d[s]+w;
            pai[u]=s;
            dfs(u);
        }
    }
}

void dp(){

    for(int i = 0; i < MAX;i++)
        for(int j = 0; j < MAXL; j++)
            a[i][j] = -1;

    for(int i=1; i<=n; i++)a[i][0]=pai[i];

    for(int j=1; j<MAXL; j++){
        for(int i=0; i<=n; i++){
            if(a[i][j-1]!=-1)
                a[i][j]=a[a[i][j-1]][j-1];
        }
    }

}

int lca(int u, int v){

    if(nivel[u]<nivel[v])swap(u, v);

    for(int i=MAXL-1; i>=0; i--){
        if(nivel[u]-(1<<i)>=nivel[v])
            u=a[u][i];
    }

    if(u==v) return u;

    for(int i=MAXL-1; i>=0; i--){
        if(a[u][i] != -1 && a[u][i]!=a[v][i]){
            u=a[u][i];
            v=a[v][i];
        }
    }

    return a[u][0];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int u, v;
    long long int w;

    cin>>n;

    while(n){

        for(int i=0; i<n; i++){
            d[i] = -1;
            pai[i] = -1;
            nivel[i] = -1;
            adj[i].clear();
        }

        d[0]=0;
        nivel[0]=0;

        for(int u=1; u<n; u++){
            cin>>v>>w;
            adj[u].push_back(mp(v, w));
            adj[v].push_back(mp(u, w));
        }

        for(int i=1; i<n; i++){
            d[i]=-1;
        }

//        cout<<"Distancia ant"<<endl;
//        for(int i=0; i<n; i++){
//            cout<<i<<" "<<d[i]<<"\n";
//        }

        dfs(0);
        dp();

//        cout<<"Distancia atual"<<endl;
//        for(int i=0; i<n; i++){
//            cout<<i<<" "<<d[i]<<"\n";
//        }

        int q;
        int x, y;
        int l;
        long long int dist;

        cin>>q;

        for(int i=0; i<q; i++){
            cin>>x>>y;
            l=lca(x, y);
            dist=d[x]-d[l]+d[y]-d[l];
            cout << dist << " \n"[i + 1 == q];
        }
        // cout<<"\n";

        cin>>n;
    }
}
