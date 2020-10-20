#include <bits/stdc++.h> 
using namespace std;
struct cowpair{
  int num;
  int val;
};
bool comp(cowpair a, cowpair b){
  return a.val < b.val;
}
int main(){
  int n; cin >> n;
  cowpair cp[n];
  int total=0,itb=0,ite=n-1; 
  for (int i = 0; i < n ;i++){
    cin >> cp[i].num >> cp[i].val;
  }
  sort(cp,cp+n,comp);
  while (itb <= ite){
    total = max((cp[itb].val+cp[ite].val),total);
    cp[itb].num--;cp[ite].num--;
    if (cp[itb].num == 0){
      itb++;
    }
    if (cp[ite].num == 0){
      ite--;
    }
  }
  cout << total << endl;
}