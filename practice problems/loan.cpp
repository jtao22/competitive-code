#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
ll n,k,m,y,endblock,rem;
bool check(ll left, ll days, ll x){
  y = left/x;
  if(y < m){return days*m >= left;}
  if(y * days < left){return false;}
  if(left <= 0){return true;}
  endblock = y*x;
  rem = min(days,(left-endblock)/y+1);
  return check(left-y*rem,days-rem,x);
}
int main(){
  freopen("loan.in","r",stdin);
  freopen("loan.out","w",stdout);
  cin >> n >> k >> m;
  ll r = k+1, l = 1, mid;
  while(l < r-1){
    mid = (l+r)/2;
    if(check(n,k,mid)){
      l = mid;
    }
    else{
      r = mid;
    }
  }
  cout << l << endl;
}
