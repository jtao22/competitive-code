#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
int chick[20001];
pii cow[20001];
bool cows[200001];
int main(){
  freopen("helpcross.in","r",stdin);
  freopen("helpcross.out","w",stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> chick[i];
  }
  sort(chick,chick+n);
  for (int i = 0; i < m; i++){
    cin >> cow[i].first >> cow[i].second;
  }
  sort(cow,cow+m);
  int count = 0, min = 1000000000, minindex = -1;

  set<int>s;
  for (int chickcount = 0; chickcount < n; chickcount++){
    min = 1000000000, minindex = -1;
    for(int i = 0; i < m; i++){

      if(cow[i].first <= chick[chickcount]){
        if(!cows[i] && cow[i].second >= chick[chickcount] && cow[i].second < min){
          min = cow[i].second;
          minindex = i;
        }
      }
      else{
        break;
      }
    }
    if(minindex != -1){
      count++;
      cows[minindex] = true;
    }
  }
  cout << count << endl;
}