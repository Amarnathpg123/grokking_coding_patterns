#include <bits/stdc++.h>
using namespace std;

int bfs(int &i, int &j, vector<vector<char>> &map) {
    int depth = 0;
    queue<pair<int, int>> qp;
    qp.push({i,j});
    while(!qp.empty()) {
        int x = qp.size();
        while(x--) {
            auto t = qp.front(); qp.pop();
            i = t.first, j = t.second;
            if(map[i][j] == 'P') continue;
            if(map[i][j] == 'E') return depth;
            map[i][j] = 'P';

            if(i-1>=0 and (map[i-1][j] == 'O' or map[i-1][j] == 'E')) qp.push({i-1, j});
            if(i+1<(int)map.size() and (map[i+1][j] == 'O' or map[i+1][j] == 'E')) qp.push({i+1, j});
            if(j-1>=0 and (map[i][j-1] == 'O' or map[i][j-1] == 'E')) qp.push({i, j-1});
            if(j+1<(int)map[0].size() and (map[i][j+1] == 'O' or map[i][j+1] == 'E')) qp.push({i, j+1});
        }
        depth++;
    }
    return -1;
}

int findMinimumSteps(vector<vector<char>> &map) {
    //find position of R
    int i = 0, j = 0;
    for(; i<(int)map.size(); ++i) {
        for(; j<(int)map[0].size(); ++j)
            if(map[i][j] == 'R') break;
        if(map[i][j] == 'R') break;
    }

    return bfs(i, j, map);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<char>> map;
    map = {{'O','O','R','O','O','O','P'}, {'P','O','O','P','P','O','O'}, {'P','O','P','O','P','P','O'}, 
            {'O','O','P','O','O','P','O'}, {'P','O','O','P','O','P','O'}, {'O','O','P','P','O','O','O'}, 
            {'O','O','P','O','E','P','O'}};
    // map = {{'P','O','R','O'},{'O','P','P','O'},{'P','P','O','O'},{'O','P','E','O'}};
    //map = {{'R','E'}};
    printf("Minimum steps needs to reach R to E (through O): %d\n", findMinimumSteps(map));
    return 0;
}