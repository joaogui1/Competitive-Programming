#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 1010
using namespace std;
int mark[MAXN][MAXN];
char World[MAXN][MAXN];
struct language{
    char name;
    int num;
};
language languages[36];
int dfs(int x, int y){
    mark[x][y]=1;
    if( World[x][y+1]==World[x][y] && mark[x][y+1]!=1 ) dfs(x,y+1);
    if( World[x][y-1]==World[x][y] && mark[x][y-1]!=1 ) dfs(x,y-1);
    if( World[x+1][y]==World[x][y] && mark[x+1][y]!=1 ) dfs(x+1,y);
    if( World[x-1][y]==World[x][y] && mark[x-1][y]!=1 ) dfs(x-1,y);
}

void zerarl(){
    for (int i=0; i<26; i++){
        languages[i].num=0;
        languages[i].name=(char)(i+97);
    }

}
bool comp(language x, language y){
    if(x.num!= y.num) return x.num>y.num;
    else return x.name<y.name;
}
void zerarG(){
    for (int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++) World[i][j]=' ';
    }

}
void zerarM(){
    for (int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++) mark[i][j]=1;
    }

}
int main()
{
    int world, h, w;
    scanf("%d", &world);
    for(int k=1; k<=world; k++){
        zerarl();zerarG();zerarM();
        scanf("%d%d", &h, &w);
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                scanf(" %c", &World[i][j]);
                mark[i][j]=0;
            }

        }

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(!mark[i][j]){
                    int x = ((int)World[i][j])%97;
                    languages[x].num++;
                    printf("\nlanguage %c %d\n", languages[x].name, languages[x].num);
                    dfs(i, j);
                }

            }

        }

        sort(languages, languages+26, comp);
        printf("World #%d\n", k);
        for(int i=0; i<26; i++){
            printf("%c: %d\n", languages[i].name, languages[i].num);
        }

    }
    return 0;
}
