#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,a,b,answer;
pair<pii,pii>coord[50000];
bool comp(int a, int b){
  if(coord[a].second.first != coord[b].second.first){
    return coord[a].second.first > coord[b].second.first;
  }
  return coord[a].second.second > coord[b].second.second;
}

int main(){
  freopen("painting.in","r",stdin);
  freopen("painting.out","w",stdout);
  cin >> n;
  answer = n;
  int arr[n];
  bool stillexists[n];
  set<int>s;
  for (int i = 0; i < n; i++){
    cin >> coord[i].first.first >> coord[i].first.second >> coord[i].second.first >> coord[i].second.second;
    arr[i] = i;
    stillexists[i] = true;
    s.insert(i);
  }
  sort(arr,arr+n,comp);
  for(int i = 0; i < n; i++){
    if(stillexists[arr[i]]){
      a = arr[i];
      for (int j= i; j < n; j++){
        if(stillexists[arr[j]] && i != j){
          b = arr[j];
          if(coord[b].first.first >= coord[a].first.first && coord[b].first.second >= coord[a].first.second && coord[b].second.second <= coord[a].second.second){
            stillexists[b] = false;
            answer--;
          }
        }
      }
    }
  }
  cout << answer << endl;
}
