#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,x,y; char c;
bool stopped[1000];
int blame[1000];
vector<pair<pii,int>>north;
vector<pair<pii,int>>east;
bool compn(pair<pii,int> a, pair<pii,int> b){
  return a.first.first < b.first.first;
}
bool compe(pair<pii,int> a, pair<pii,int> b){
  return a.first.second < b.first.second;
}
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> c >> x >> y;
    if(c == 'E'){
      east.push_back(make_pair(pii(x,y),i));
    }
    else{
      north.push_back(make_pair(pii(x,y),i));
    }
  }
  sort(north.begin(),north.end(),compn);
  sort(east.begin(),east.end(),compe);
  for(int i = 0; i < east.size(); i++){
    for (int j = 0; j < north.size(); j++){
      if(north[j].first.first < east[i].first.first || north[j].first.second > east[i].first.second || stopped[north[j].second]){
        continue;
      }
      if(north[j].first.first-east[i].first.first > east[i].first.second - north[j].first.second){
        blame[north[j].second]+= blame[east[i].second]+1;
        break;
      }
      else if (north[j].first.first-east[i].first.first < east[i].first.second - north[j].first.second){
        stopped[north[j].second] = true;
        blame[east[i].second]+= blame[north[j].second]+1;
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << blame[i] << endl;
  }
}
