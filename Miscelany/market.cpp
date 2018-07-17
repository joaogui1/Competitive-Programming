#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;
typedef struct{
    double price;
    string name;
    }fruit;
fruit frutas[1000010];
int main(){
    int n,m,p,qunt;
    string f;
    scanf("%d", &n);
    for(int i=0;i<n ;i++){
        double tot=0;
        for (int k=0; k<1000010;k++){
                frutas[i].price=0.0;
                frutas[i].name="";
            }
        scanf("%d", &m);
        int res=0;
        for (int j=0; j<m; j++){
             cin >>frutas[j].name;
             cin >> frutas[j].price;
            }
        scanf("%d", &p);
        for(int k=0;k<p; k++){
            cin >> f;
            for (int j=0; j<m; j++){
                if (f==frutas[j].name){scanf("%d", &qunt);tot+=qunt*frutas[j].price;}
                }
        }printf("R$ %0.2lf\n", tot);
        }

    return 0;
    }
