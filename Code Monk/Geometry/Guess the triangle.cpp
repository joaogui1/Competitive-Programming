#include <bits/stdc++.h>

using namespace std;

class point{
  public:
    double x, y;

    point operator+(point other){
      point ret;
      ret.x = x + other.x;
      ret.y = y + other.y;
      return ret;
    }
    point operator-(point other){
      point ret;
      ret.x = x - other.x;
      ret.y = y - other.y;
      return ret;
    }

    void operator=(point other){
      x = other.x;
      y = other.y;
      return;
    }

    bool operator>(point other){
      if(x > other.x) return 1;
      if(x < other.x) return 0;
      return (y > other.y);
    }
    bool operator<(point other){
      if(x < other.x) return 1;
      if(x > other.x) return 0;
      return (y < other.y);
    }

};
point medians[5], points[5];

int main(){
  double aux, auy;
  for(int i = 0; i < 3; ++i){
    scanf("%lf %lf", &aux, &auy);
    medians[i].x = aux;
    medians[i].y = auy;
  }
  points[0] = medians[0] + medians[1] - medians[2];
  points[1] = medians[2] + medians[0] - medians[1];
  points[2] = medians[1] + medians[2] - medians[0];
  sort(points, points + 3);

  for(int i = 0; i < 3; ++i)  printf("%0.4lf %0.4lf\n", points[i].x, points[i].y);
  return 0;
}
