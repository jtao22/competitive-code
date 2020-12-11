#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int>> piii;
int n;
int t[200001];
bool comp(piii a, piii b){
  return a.first <= b.first;
}
int main() {
  freopen("lifeguards.in","r",stdin);
  freopen("lifeguards.out","w",stdout);
  cin >> n;
  piii arr[2*n];
  int itr = 1;
  for (int i = 0; i < 2*n; i+=2){
    cin >> arr[i].first >> arr[i+1].first;
    arr[i].second.first = 1;
    arr[i+1].second.first = -1;
    arr[i].second.second = itr;
    arr[i+1].second.second = itr;
    itr++;
  }
  sort(arr,arr+2*n,comp);
  set<int>s;
  bool tf = false;
  int prev = 0,best = arr[2*n-1].first-arr[0].first, total = 0;
  for (int i = 0; i < 2*n; i++){
    if (s.size() == 1){
      t[*s.begin()]+=arr[i].first-prev;
    }
    if (!s.empty()){
      total+=arr[i].first-prev;
    }
    if (arr[i].second.first == 1){
      s.insert(arr[i].second.second);
    }
    else{
      s.erase(arr[i].second.second);
    }
    prev = arr[i].first;
  }
  for (int i = 1; i <= n; i++){
    best = min(best,t[i]);
  }
  cout << total-best << endl;
}