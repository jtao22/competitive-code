#include <bits/stdc++.h> 
using namespace std;
  bool comp(pair<int,int> a, pair<int,int> b){
    if (a.first != b.first){
    return a.first < b.first;
    }
    else{
      return a.second < b.second;
    }
  }
int main(){
  int n; cin >> n;
  int x,y,r;
  vector<pair<int,int>>cross;
  set<int> passing;
  set<int> seen;
  for (int i = 0; i < n; i++){
    cin >> x >> y >> r;
    x*=-1;
    cross.push_back(make_pair(x*r-r,y));
    cross.push_back(make_pair(x*r,-y));
  }
  sort(cross.begin(),cross.end(),comp);
  int i = 0,j;
  while (i < cross.size()){
    j = i;
    while (j < cross.size() && cross[i].first == cross[j].first){
        if (cross[j].second > 0){
          passing.insert(cross[j].second);
        }
        else{
          passing.erase(-cross[j].second);
        }
        j++;
    }
    if (passing.size() != 0){
      seen.insert(*passing.begin());
    }
    i = j;
  }
  cout << seen.size() << endl;
}