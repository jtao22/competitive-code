//greedy
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,d,ans=0; string s;
int psum[100000];

int main(){
  //freopen("clumsy.in","r",stdin);
  //freopen("clumsy.out","w",stdout);
  cin >> s;
  for (int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      d++;
    }
    else{
      d--;
    }
    if(d < 0){
      ans++;
      d+=2;
    }
  }
  ans+=d/2;
  cout << ans << endl;
}
