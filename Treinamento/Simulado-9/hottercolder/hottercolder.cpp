#include <iostream>
#include "grader.h"

int HC(int N){
  int i, j, beg = 1, end = N, m;
  while(end > beg){
    m = (beg + end)/2;
    i = Guess(beg), j = Guess(end);
    if(j == -1) end = m;
    if(j == 0)  return m;
    if(j == 1)  beg = m + 1;
  }
  return beg;
}
