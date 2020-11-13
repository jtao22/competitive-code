#include <bits/stdc++.h> 
using namespace std;
int n,x; char c;
struct cows{
  int pos = 0;
  int breed = 0;
  int psum = 0;
};
bool comp(cows a, cows b){
  return a.pos <= b.pos;
}
int occ[1100000];
int main(){
  cin >> n;
  cows cow[n+1];
  for (int i = 1; i <= n; i++){
    cin >> x >> c;
    if (c == 'H'){
      cow[i].breed = 1;
    }
    else{
      cow[i].breed = -1;
    }
    cow[i].pos = x;
  }
  sort(cow,cow+n+1,comp);
  occ[n] = cow[1].pos;
  cow[0].psum = n; int best = 0; 
  for (int i = 1; i <= n; i++){
    cow[i].psum = cow[i-1].psum+cow[i].breed;
    if (occ[cow[i].psum] == 0){
      occ[cow[i].psum] = i;
    }
    else{
      best = max(best,cow[i].pos-cow[occ[cow[i].psum]+1].pos);
    }
  } int prev = cow[1].breed, count = 0; cow[0].pos = cow[1].pos;
  for (int i = 1; i <= n; i++){
    if (cow[i].breed == prev){
      count+=(cow[i].pos-cow[i-1].pos);
    }
    else{
      best = max(best,count);
      count = 0;
    }
    prev = cow[i].breed;
  }
  cout << best << endl;
}