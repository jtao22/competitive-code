#include <bits/stdc++.h> 
using namespace std;

int main(){
  //freopen("cowjog.in","r",stdin);
  //freopen("cowjog.out","w",stdout);
  int n; cin >> n;
  long long arr[n],x,ans=0;
  for (int i = 0; i < n; i++){
    cin >> x >> arr[i];
  }
  long long minim = arr[n-1];
  for (int i = n-1; i >= 0; i--){
    if (arr[i] <= minim){
      ans++;
      minim = arr[i];
    }
  }
  cout << ans << endl;
}
