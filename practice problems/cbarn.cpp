#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[100001];
bool fails[100001];
int counts[100001];
int main(){
  freopen("cbarn.in","r",stdin);
  freopen("cbarn.out","w",stdout);
  cin >> n;
  int lowpoint,lowindex,currtotal = 0;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
    currtotal+=arr[i]-1;
    if(currtotal < lowpoint){
       lowpoint = currtotal;
       lowindex = i;
    }
  }
  vector<int>v; int cownum = 0,curr,best = INT_MAX;
  ll sum = 0;
  rotate(arr,arr+(lowindex+1)%n,arr+n);
  for (int i = 0; i < n; i++){
    if(!v.empty()){
      for (int j :v){
        counts[j]++;
      }
    }
    for(int j = 0; j < arr[i]; j++){
      v.push_back(cownum);
      cownum++;
    }
    v.erase(v.begin());
  }
  for (int i = 0; i < n; i++){
    sum += counts[i]*counts[i];
  }
  cout << sum << endl;
}