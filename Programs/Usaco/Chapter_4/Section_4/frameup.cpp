/*
ID: joaogui1
LANG: C++
TASK: frameup
*/
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int w, h, num_frames;
char a[33][33];
bool pre[26][26];
char order[26];
bool output[26];

struct Frame {
  int min_x, min_y, max_x, max_y;
} frame[26];

vector<string> solutions;

void TopSort(int p) {
  if (p == num_frames) {
    solutions.push_back(string(order, num_frames));
  } else {
    for (int i = 0; i < 26; i++) {
      if (output[i] || frame[i].min_x == -1) continue;
      bool oldest = true;
      for (int j = 0; j < 26; j++) {
        if (!output[j] && pre[j][i]) {
          oldest = false;
          break;
        }
      }
      if (oldest) {
        output[i] = true;
        order[p] = 'A' + i;
        TopSort(p + 1);
        output[i] = false;
      }
    }
  }
}

int main() {
  ifstream fin("frameup.in");
  ofstream fout("frameup.out");
  fin >> h >> w;
  for (int i = 0; i < h; i++)
    fin >> a[i];
  fin.close();

  // Find the corner of each frame.
  for (int i = 0; i < 26; i++)
    frame[i].min_x = frame[i].min_y = frame[i].max_x = frame[i].max_y = -1;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '.') continue;
      int id = a[i][j] - 'A';
      if (frame[id].min_x == -1 || i < frame[id].min_x)
        frame[id].min_x = i;
      if (frame[id].min_y == -1 || j < frame[id].min_y)
        frame[id].min_y = j;
      if (frame[id].max_x == -1 || i > frame[id].max_x)
        frame[id].max_x = i;
      if (frame[id].max_y == -1 || j > frame[id].max_y)
        frame[id].max_y = j;
    }

  // Compute the ordering relations.
  for (int i = 0; i < 26; i++) {
    if (frame[i].min_x == -1) continue;
    ++num_frames;
    char c;
    for (int j = frame[i].min_x; j <= frame[i].max_x; j++) {
      c = a[j][frame[i].min_y];
      if (c != '.' && c - 'A' != i)
        pre[i][c - 'A'] = true;
      c = a[j][frame[i].max_y];
      if (c != '.' && c - 'A' != i)
        pre[i][c - 'A'] = true;
    }
    for (int j = frame[i].min_y; j <= frame[i].max_y; j++) {
      c = a[frame[i].min_x][j];
      if (c != '.' && c - 'A' != i)
        pre[i][c - 'A'] = true;
      c = a[frame[i].max_x][j];
      if (c != '.' && c - 'A' != i)
        pre[i][c - 'A'] = true;
    }
  }

  // Topsort.
  TopSort(0);
  sort(solutions.begin(), solutions.end());
  for (int i = 0; i < solutions.size(); i++)
    fout << solutions[i] << endl;
  fout.close();
  return 0;
}
