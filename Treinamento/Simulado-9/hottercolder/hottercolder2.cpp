#include <iostream>
#include "grader.h"

using namespace std;

int HC(int N){
  int i, j, k, beg = 1, end = N, m;
  // std::cout << N << "\n";
  while(end > beg){
    m = (beg + end)/2;
    if(m == beg){
      i = Guess(beg), j = Guess(end);
      if(j == -1) return beg;
      return end;
    }
    // std::cout << '\t' << beg << " " << m << " " << end << " ";
    i = Guess(beg), j = Guess(m);
    // cout << i << " " << j << " ";
    if(j == 0)  return (m + beg)/2;
    else if(j == -1)  end = (m + beg)/2;
    else{
      k = Guess(end);
      if(k == -1){
        beg = (beg + m)/2 + 1;
        end = (end + m)/2;
      }
      if(k == 0)  return (m + end)/2;
      if(k == 1)  beg = (end + m)/2 + 1;
    }
  }
  return beg;
}
