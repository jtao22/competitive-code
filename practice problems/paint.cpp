#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,k,x,currpos=0; char c;
map<int,int>m;

int main(){
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> x >> c;
    if(c == 'L'){
      m[currpos-x]++;
      m[currpos]--;
      currpos-=x;
    }
    else{
      m[currpos]++;
      m[currpos+x]--;
      currpos+=x;
    }
  }
  int curr = 0,count=0,prev = m.begin()->first;
  for (auto itr = m.begin(); itr != m.end(); itr++){
    if(curr >= k){
      count+=itr->first-prev;
    }
    curr+=itr->second;
    prev = itr->first;
  }
  cout  << count << endl;
}
