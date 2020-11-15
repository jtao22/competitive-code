#include <bits/stdc++.h> 
using namespace std;

struct cowinp{
  int pos;
  int breed;
  int sum;
};
bool comp(cowinp a, cowinp b){
  return a.pos < b.pos;
}
map<int,int>sumocc;
int main(){
  int n; cin >> n; char c;
  cowinp cow[n+1]; 
  for (int i = 1; i <= n; i++){
    cin >> cow[i].pos >> c;
    if (c == 'G'){
      cow[i].breed = 1;
    }
    else{cow[i].breed = -1;}
  }
  sort(cow+1,cow+n+1,comp);

  cow[0].sum = 0; int longcont = 0,best = -1; cow[0].breed = cow[1].breed; cow[0].pos = cow[1].pos;
  for (int i = 1; i <= n; i++){
    cow[i].sum = cow[i-1].sum+cow[i].breed;
    if (cow[i].breed == cow[i-1].breed){
      longcont+=cow[i].pos-cow[i-1].pos;
    }
    else{
      best = max(longcont,best);
      longcont=0;
    }
  }
  for (int i = 1; i <= n; i++){
    if (!sumocc.count(cow[i].sum)){
      sumocc[cow[i].sum] = i;
    }
    else{
      best = max(best,cow[i].pos - cow[sumocc[cow[i].sum]+1].pos);
    }
  }
  cout << best << endl;
}
