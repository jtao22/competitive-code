#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,r,x,y;
map<int,pii>milk;
bool bigtosmall (int a, int b){
  return a > b;
}
int main(){
 freopen("rental.in","r",stdin);
  freopen("rental.out","w",stdout);
  cin >> n >> m >> r;
  int cow[n],tempcow[n],milkcost[m], itr = 0, rent[r], milkindex = 0,temp,breakindex,total,best = -1,psumrent[r],cowsum=0,upperbound,milksum=0;
  bool overflow = false;
  for (int i = 0; i < n; i++){
    cin >> cow[i];
    cowsum+=cow[i];
  }
  sort(cow,cow+n,bigtosmall);
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    if (milk.find(y) == milk.end()){
      milkcost[itr] = y;
      itr++;
    }
    milk[y].first+=x;
    milksum+=x;
    if (milksum >= cowsum){
      upperbound = m+1;
    }
  }
  sort(milkcost,milkcost+itr,bigtosmall);
  for (int i = 0; i < r; i++){
    cin >> rent[i];
  }
  sort(rent,rent+r,bigtosmall);
  psumrent[0] = 0;
  for (int i = 1; i <= r; i++){
    psumrent[i] = psumrent[i-1]+rent[i-1];
  }
  for (int i = n-r; i <= upperbound; i++){
    milkindex = 0; total=0;
    for (int j = 0; j < m; j++){
      milk[milkcost[j]].second = milk[milkcost[j]].first;
    }
    for (int j = 0; j < m; j++){
      tempcow[j] = cow[j];
    }
    for (int j = 0; j < i; j++){
      while(tempcow[j] > 0){
        temp = milk[milkcost[milkindex]].second;
        total+=milkcost[milkindex]*min(temp,tempcow[j]);
        milk[milkcost[milkindex]].second-=min(temp,tempcow[j]);
        tempcow[j]-=min(temp,tempcow[j]);
        if (milk[milkcost[milkindex]].second == 0){
          milkindex++;
        }
      }
    }
    total+=psumrent[n-i];
    best = max(best,total);
  }
  cout << best << endl;
}