#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n;
int order[5][20000];
int ans[20000];
bool comp(int a, int b){
  int count = 0;
  for (int i = 0; i < 5; i++){
    if (order[i][a] < order[i][b]){
      count++;
    }
  }
  return count > 2;
}


int main(){
  freopen("photo.in","r",stdin);
  freopen("photo.out","w",stdout);
  cin >> n;
  for(int i = 0; i < 5; i++){
    for (int j = 0; j < n; j++){
      cin >> ans[j];
      order[i][ans[j]] = j;
    }
  }
  sort(ans,ans+n,comp);
  for (int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }
}
