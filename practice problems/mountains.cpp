#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,currmax,x,y,total;
vector<pii> coord;
map<int,int>m;
bool inside = false;
bool hidden[100001];
bool comp(pii a, pii b){
  return a.second > b.second;
}
int main(){
  freopen("mountains.in","r",stdin);
  freopen("mountains.out","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    if (m.find(x) == m.end()){
      m[x] = y;
    }
    else{
      m[x] = max(m[x],y);
    }
  }
  for (auto i = m.begin(); i != m.end(); i++){
    coord.push_back(make_pair(i->first, i->second));
  }
  sort(coord.begin(),coord.end(),comp);
  total = coord.size();
  for (int i  = 0; i < coord.size(); i++){
    if (!hidden[i]){
      for (int j = coord.size()-1; j > i; j--){
        if(!hidden[j]){
          if(coord[j].first  >= coord[j].second - (coord[i].second - coord[i].first) && coord[j].first <= (coord[i].second+coord[i].first)-coord[j].second){
            total--;
            hidden[j] = true;
          }
        }
      }
    }
  }
  cout << total << endl;
}