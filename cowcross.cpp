#include <bits/stdc++.h> 
using namespace std;
bool comp(pair <int,int> a, pair <int,int> b){
  return a.second < b.second;
}
int main(){
  int chick,cow,n,n1,count=0; cin >> chick >> cow;
  multiset <int> chicken;
  multiset <int> :: iterator it,it1;
  for (int i = 0; i < chick; i++){
    cin >> n;
    chicken.insert(n);
  }
  vector <pair<int,int>> cows;
  for (int i = 0; i < cow; i++){
    cin >> n >> n1;
    cows.push_back(make_pair(n,n1));
  }
  sort(cows.begin(), cows.end(),comp);
  for (int i = 0; i < cows.size(); i++){
    it = chicken.lower_bound(cows[i].first);
    if (*it <= cows[i].second && it != chicken.end()){
      count++; 
      chicken.erase(it);
    }
  }
  cout << count << endl;
}
