#include <bits/stdc++.h> 
using namespace std;
bool comp (pair<int,int> a, pair<int,int> b){
  return a.first < b.first;
}
int main(){
  int n,a,b; cin >> n;
  vector<pair<int,int>>v;
  for (int i = 0; i < n; i++){
    cin >> a >> b;
    v.push_back(make_pair(a,1));
    v.push_back(make_pair(b,-1));
  }
  sort(v.begin(),v.end(),comp);
  int sum = 0,best = -1;
  for (int i = 0; i < v.size(); i++){
    sum+=v[i].second;
    best = max(best,sum);
  }
  cout << best << endl;
}