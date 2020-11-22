#include <bits/stdc++.h> 
using namespace std;
struct cows{
  long long pos;
  long long speed;
};
bool comp(cows a, cows b){
  return a.pos <= b.pos;
}
int main(){
  int n,t;
  cin >> n >> t;
  cows cow[n];
  for (int i = 0; i < n; i++){
    cin >> cow[i].pos >> cow[i].speed;
  }
  sort(cow,cow+n,comp);
  int count = n;
  long long max;
  max = cow[n-1].pos+cow[n-1].speed*t;
  for (int i = n-2; i >= 0; i--){
    if (cow[i].pos+cow[i].speed*t >= max){
      count--;
    }
    else{
      max = cow[i].pos+cow[i].speed*t;
    }
  }
  cout <<  count << endl;
}