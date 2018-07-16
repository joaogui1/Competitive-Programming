#include<cstdio>
#include<cstdlib>
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4
bool G[360610][10]
int main(){
    int n;
    char a;
    scanf("%d", &n);
    if(n%2 == 0){
        for(int i = 0; i < 2*n - 1; ++i){
            for(int j = 1; j <= n; ++j){
                getchar(a);
                if(a == 'V'){
                    G[(2*n+1)*i+j-1][LEFT] = G[(2*n+1)*i+j][RIGHT] = G[(2*n+1)*(i+1)+j-1][LEFT] = G[(2*n+1)*(i+1)+j-1][RIGHT] = 0;
                }
            }
        }
    }
    else{



    }


    return 0;
}
