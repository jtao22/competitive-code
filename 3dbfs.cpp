#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n,curri = -1,currj,count = 1,currk;
    cin >> n;
    
    char space[n][n][n];
    int num[n][n][n];
    bool mark[n][n][n];
    for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> space[i][j][k];         
            num[i][j][k] = 0;
            mark[i][j][k] = false;
            if (curri == -1 && space[i][j][k] == '*'){
                curri = i;
                currj = j;
                currk = k;
            }
        }
    }
    }
    int di[6] = {0,1,0,-1,0,0};
    int dj[6] = {1,0,-1,0,0,0};
    int dk[6] = {0,0,0,0,1,-1};
    queue<int>i;queue<int>j;queue<int>k;
    mark[curri][currj][currk] = true;
    num[curri][currj][currk] = count;
    space[curri][currj][currk] = '.';
    i.push(curri);j.push(currj);k.push(currk);
    int found = 0;
    while (i.size() > 0){
        curri = i.front();
        currj = j.front();
        currk = k.front();
        i.pop();
        j.pop();
        k.pop();
        for (int l = 0; l < 6; l++){
            int tempi = curri+di[l];
            int tempj = currj+dj[l];
            int tempk = currk+dk[l];
            if (tempi < n && tempi >= 0 && tempj < n && tempj >= 0 && tempk < n && tempk >= 0){
                if (!mark[tempi][tempj][tempk] && space[tempi][tempj][tempk] == '*'){
                    mark[tempi][tempj][tempk] = true;
                    num[tempi][tempj][tempk] = count;
                    space[tempi][tempj][tempk] = '.';
                    i.push(tempi); j.push(tempj); k.push(tempk);
                }
            }
        }
        if (i.size() == 0 && j.size() == 0 && k.size() == 0){
            count++;
            for (int z = 0; z < n; z++){
                for (int x = 0; x < n; x++){
                    for (int y = 0; y < n; y++){
                        if (space[x][y][z] == '*'){
                            mark[x][y][z] = true;
                            num[x][y][z] = count;
                            space[x][y][z] = '.';
                            i.push(x);
                            j.push(y);
                            k.push(z);
                            found = 1;
                            break;
                        }
                    }
                    if (found == 1){
                        break;
                    }
                }
                if (found == 1){
                    break;
                }
            }
        }
        found = 0;
    }
    cout << count-1 << endl;
}