#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,g,b,d; char c;
pii stops[50001];
bool comp(int a, int b){
  if(stops[a].second != stops[b].second){
    return stops[a].second < stops[b].second;
  }
  return stops[a].first < stops[b].first;
}

int main(){
  freopen("fuel.in","r",stdin);
  freopen("fuel.out","w",stdout);
  cin >> n >> g >> b >> d;
  for (int i = 0; i < n; i++){
    cin >> stops[i].first >> stops[i].second;
  }
  stops[n] = make_pair(d,0);
  sort(stops,stops+n);
  int pos = 0,total=0;
  for(int i = 0; i < n; i++){
    b-=stops[i].first - pos;
    pos = stops[i].first;
    if(stops[i+1].second < stops[i].second){
      if(b < stops[i+1].first-stops[i].first){
        total+=stops[i].second*(stops[i+1].first-stops[i].first-b);
        b=stops[i+1].first-stops[i].first;
      }
    }
    else{
      for(int j = i+1; j <= n; j++){
        if(stops[j].second < stops[i].second){
          if(stops[j].first-stops[i].first > g){
            total+=stops[i].second*(g-b);
            b = g;
          }
          else{
            if(stops[j].first-stops[i].first > b){
              total+=stops[i].second*(stops[j].first-stops[i].first-b);
              b = stops[j].first-stops[i].first;
            }
          }
          break;
        }
      }
    }
  }
  cout << total << endl;
}
