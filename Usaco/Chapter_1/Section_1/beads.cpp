/*
ID: joaogui1
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
     int N, cur = 0, max = 0;
     char color;
     bool switched;
     ofstream fout ("beads.out");
     ifstream fin ("beads.in");
     fin >> N;
     string beads;
     fin >> beads;

    //if(beads.length() != N)    N = beads.length();

    for(int i = 0; i < N; ++i){
        cur = 0;
        switched = false;
        color = 'w';
        for(int j = 0; j < N; ++j){
            char cur_c = beads[(i + j) % N];
            if(cur_c != 'w'){
                if(color == 'w'){
                    color = cur_c;
                }
                else if(color != cur_c){
                    if(switched)
                        break;
                else{
                    color = cur_c;
                    switched = 1;
                }
            }
        }
       ++cur;
      }
    if(cur > max)
    max = cur;
    }

    fout << max << endl;
    return 0;
}

