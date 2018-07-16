#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int h, w;
char board [50 + 5] [50 + 5];
int cnt;
int dr [] = {-1, 0, 1, 0 };
int dc [] = {0, 1, 0, -1};

void dfs1 (int x, int y)
{
    if ( x < 0 || x == h || y < 0 || y == w || board [x] [y] != 'X' ) return;

    board [x] [y] = '*';

    for ( int i = 0; i < 4; i++ ) {
        dfs1 (x + dr [i], y + dc [i]);
    }
}

void dfs (int x, int y)
{
    if ( x < 0 || x == h || y < 0 || y == w || board [x] [y] == '.' ) return;

    if ( board [x] [y] == 'X' ) {
        cnt++;
        dfs1 (x, y);
    }

    board [x] [y] = '.';

    for ( int i = 0; i < 4; i++ ) {
        dfs (x + dr [i], y + dc [i]);
    }

}

int main(int argc, char** argv)
{
    int cases = 0;

    while ( scanf ("%d %d", &w, &h) ) {
        if ( w == 0 && h == 0 ) break;

        for ( int i = 0; i < h; i++ ) scanf ("%s", board [i]);

        vector <int> output;

        for ( int i = 0; i < h; i++ ) {
            for ( int j = 0; j < w; j++ ) {
                if ( board [i] [j] != '.' ) {
                    cnt = 0;
                    dfs (i, j);
                    output.push_back(cnt);
                }
            }
        }

        sort (output.begin(), output.end());
        printf ("Throw %d\n", ++cases);
        printf ("%d", output [0]);
        for ( size_t i = 1; i < output.size(); i++ ) printf (" %d", output [i]);
        printf ("\n\n");
    }

    return 0;
}
