#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
vector<int> mergesort(vector<int>v){
  if(v.size() <= 1){
    return v;
  }
  vector<int>l; vector<int>r;
  for(int i = 0; i < v.size()/2; i++){
    l.push_back(v[i]);
  }
  for (int i = v.size()/2; i < v.size(); i++){
    r.push_back(v[i]);
  }
  vector<int>lprime = mergesort(l); 
  vector<int>rprime = mergesort(r);
  int lc = 0, rc = 0;
  vector<int>ans;
  for(int i = 0; i < v.size(); i++){
    if(rc == rprime.size() || (lc < lprime.size() && lprime[lc] < rprime[rc])){
      ans.push_back(lprime[lc]);
      lc++;
    }
    else{
      ans.push_back(rprime[rc]);
      rc++;
    }
  }
  return ans;
}
int main(){
  cin >> n;
  vector<int>v;
  int x;
  for (int i = 0; i < n; i++){
    cin >> x;
    v.push_back(x);
  }
  vector<int> f = mergesort(v);
  for (int i = 0; i < f.size(); i++){
    cout << f[i] << " ";
  }
}