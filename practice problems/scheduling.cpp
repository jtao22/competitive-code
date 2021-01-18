#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,x,y,total=0;
vector<pii>vec;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    vec.push_back(pii(y,x));
  }
  int end = 0;
  sort(vec.begin(), vec.end());
  for(int i = 0; i < vec.size(); i++){
    if(vec[i].second >= end){
      total++;
      end = vec[i].first;
    }
  }
  cout << total << endl;
}