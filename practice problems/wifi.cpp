#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,a,b;

int main(){
  //freopen("wifi.in","r",stdin);
  //freopen("wifi.out","w",stdout);
  cin >> n >> a >> b;
  ll arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);
  ll num = 1, l = 0;
  for (int i = 0; i < n-1; i++){
    if((arr[i+1]-arr[i])*b > 2*a){
      num++;
    }
    else{
      l+=arr[i+1]-arr[i];
    }
  }
  if(((num*a*2 + l*b)/2)%2 == 0){
    cout << (num*a*2 + l*b)/2 << endl;
  }
  else{
    cout << (num*a*2 + l*b)/2 << ".5" << endl;
  }
}
