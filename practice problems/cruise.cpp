#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,k; char c;
string s = "",seq="";
int arr[1001][2];
int main(){
  freopen("cruise.in","r",stdin);
  freopen("cruise.out","w",stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++){
    cin >> arr[i][0] >> arr[i][1];
  }
  for (int i = 0; i < m; i++){
    cin >> c;
    s+=c;
  }
  int curr = 1;
  while(s.find("LR") < s.length()){
    s.erase(s.find("LR"),2);
  }
  while(s.find("RL") < seq.length()){
    s.erase(seq.find("RL"),2);
  } 
  for (int i = 0; i < k; i++){
    seq+=s;
  }
  while(seq.find("LR") < seq.length()){
    seq.erase(seq.find("LR"),2);
  }
   while(seq.find("RL") < seq.length()){
    seq.erase(seq.find("RL"),2);
  } 
  for(int i = 0; i < seq.length(); i++){
    if (seq[i] == 'L'){
      curr = arr[curr][0];
    }
    else{
      curr = arr[curr][1];
    }
  }
  cout << curr << endl;
}
