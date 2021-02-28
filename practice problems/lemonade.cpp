#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,total = 0;
int cows[100001];
int main() {
  freopen("lemonade.in","r",stdin);
  freopen("lemonade.out","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  sort(cows,cows+n);
  for (int i = n-1; i >= 0; i--){
    if(cows[i] >= total){
      total++;
    }
    else{
      break;
    }
  }
  cout << total << endl;
}