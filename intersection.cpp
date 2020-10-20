#include <bits/stdc++.h> 
using namespace std;
struct coord{
  int x;
  int y;
};
int interscount[10000];
bool colinear(coord p, coord q, coord r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)){
       return true; 
    }
    return false; 
} 
// 0 = colinear
// 1 = Clockwise 
// 2 = Counterclockwise 
int o(coord p, coord q, coord r){ 
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
  if (val == 0){ 
    return 0; //colinear
  }
    return (val > 0)? 1: 2; // cw/ccw
} 
bool intersect(coord p1, coord q1, coord p2, coord q2){ 
    int o1 = o(p1, q1, p2); 
    int o2 = o(p1, q1, q2); 
    int o3 = o(p2, q2, p1); 
    int o4 = o(p2, q2, q1); 
    if (o1 != o2 && o3 != o4){
        return true; 
    }
    else if (o1 == 0 && colinear(p1, p2, q1)){
      return true; 
    }
    else if (o2 == 0 && colinear(p1, q2, q1)){
      return true; 
    }
    else if (o3 == 0 && colinear(p2, p1, q2)){
      return true; 
    }
    else if (o4 == 0 &&  colinear(p2, q1, q2)){
      return true; 
    }
    return false; 
} 
  
  //driver code 