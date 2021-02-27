#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n;
pii point[100001];
struct p{
  bool active = false;
  int ylow = INT_MAX;
  int yhigh = 0;
};
p components[100001];
int main() {
  freopen("moop.in","r",stdin);
  freopen("moop.out","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> point[i].first >> point[i].second;
  }
  sort(point,point+n);
  vector<int>low;
  int count = 0;
  for (int i = 0; i < n; i++){
    components[i].active = true;
    count++;
    components[i].ylow = point[i].second;
    components[i].yhigh = point[i].second;
    for(int j = 0; j < i; j++){
      if(components[j].active){
        if(components[i].ylow >= components[j].ylow){
          components[i].ylow = components[j].ylow;
          components[i].yhigh = max(components[i].yhigh, components[j].yhigh);
          components[j].active = false;
          count--;
        }
      }
    }
  }
  cout << count << endl;
}