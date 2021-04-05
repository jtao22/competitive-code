#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int n,k,b,a;
bool broken[100001];
int psum[100001];
int main(){
  freopen("maxcross.in","r",stdin);
  freopen("maxcross.out","w",stdout);
  cin >> n >> k >> b;
  for (int i = 0; i < b; i++){
    cin >> a;
    broken[a] = true;
  }
  int best = n;
  for (int i = 1; i <= n; i++){
    psum[i] = psum[i-1];
    if(broken[i]){psum[i]++;}
    if(i >= k){
      best = min(psum[i]-psum[i-k], best);
    }
  }

  cout << best << endl;
}