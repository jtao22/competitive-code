#include <bits/stdc++.h> 
using namespace std;
int card[100001];
int main(){
  freopen("highcard.in","r",stdin);
  freopen("highcard.out","w",stdout);
  int n,x,plus = 0,score=0;cin >> n;
  bool maxreach = false;
  int elsie[n];
  int bessie[n];
  for (int i = 0; i < n; i++){
    cin >> elsie[i];
    card[elsie[i]] = 1;
  }
  sort(elsie,elsie+n);
  for (int i = 1; i <= 2*n; i++){
    if (card[i] == 0){
      bessie[plus] = i;
      plus++;
    }
  }
  int bb = 0,be = 0;
  while (bb < n && be < n){
    if (bessie[bb] > elsie[be]){
      bb++;
      be++;
      score++;
    }else{
      bb++;
    }
  }
  cout << score << endl;
}
