#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,previous,itr,ans = 0;

int main(){
  //freopen("poker.in","r",stdin);
  //freopen("poker.out","w",stdout);
  cin >> n;
  int cardcount[n+1];
  set<int>cards;
  for (int i = 1; i <= n; i++){
    cin >> cardcount[i];
    cards.insert(i);
  }
  while(!cards.empty()){
    previous = *cards.begin()-1;
    for(auto i = cards.begin(); i != cards.end(); i++){
      if(*i != previous+1){
        break;
      }
      previous++;
    }
      for(int i = *cards.begin(); i <= previous; i++){
        cardcount[i]--;
        if(cardcount[i] == 0){
          cards.erase(i);
        }
      }
    ans++;
  }
  cout << ans << endl;
}

