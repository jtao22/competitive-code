#include <bits/stdc++.h> 
using namespace std;
struct foo{
  int x;
  int y;
  int power;
};
int cantransmit[200][200];
int n;
int dfs(int curr,  bool c[200], int canTransmit[200][200]) {
		if(c[curr]) {
			return 0;
		}
		c[curr] = true;
		int ret = 1;
		for(int i = 0; i < n; i++) {
			if(canTransmit[curr][i]) {
				ret += dfs(i, c, canTransmit);
			}
		}
		return ret;
	}
int main(){
  freopen("moocast.in","r",stdin);
  freopen("moocast.out","w",stdout);
  int curri; cin >> n;
  foo cow[n];
  for (int i = 0; i < n; i++){
    cin >> cow[i].x >> cow[i].y >> cow[i].power;
  } 
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (pow(cow[j].x-cow[i].x, 2)+pow(cow[j].y - cow[i].y, 2) <= pow(cow[i].power, 2)){
            cantransmit[i][j] = 1;
        }
        if (pow(cow[j].x-cow[i].x, 2)+pow(cow[j].y - cow[i].y, 2) <= pow(cow[j].power, 2)){
          cantransmit[j][i] = 1;
        }
      }
    }
    int best = 1;
    for (int i = 0; i < n; i++){
      bool c[200];
      for (int j = 0; j < n; j++){
        c[j] = false;
      }
        best = max(best, dfs(i, c, cantransmit));
    }
    cout << best << endl;
}
