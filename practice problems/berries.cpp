#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,k,top = 0,given,curr,total,best=0;
int trees[1000];
int c[1000];

int main(){
  freopen("berries.in","r",stdin);
  freopen("berries.out","w",stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> trees[i];
    top = max(top,trees[i]);
  }
  for (int i = 1; i <= top; i++){
    for (int j = 1; j <= i; j++){
      c[j] = 0;
    }
    for (int j = 0; j < n; j++){
      c[i] += trees[j]/i;
      c[trees[j]%i]++;
    }
    if(k/2 > c[i]){continue;}
    c[i]-=k/2;
    curr = i;given = 0;total = 0;
    while(curr > 0 && given < k/2){
      if(c[curr] > 0){
        given++;
        total+=curr;
        c[curr]--;
      }
      else{
        curr--;
      }
    }
    if(given==k/2){
      best = max(best,total);
    }
  }
  cout << best << endl; 
}

