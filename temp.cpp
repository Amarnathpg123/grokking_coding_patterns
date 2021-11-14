#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dis=0,w,d; 
pair<int,int> cur;
vector<vector<bool>> vis;
int cur_dir = 0, turn = 0;//0 E; 1 S; 2 W; 3 N //0 S; 1 L; 2 R
vector<vector<pair<int,int>>> dir = {{{1,0},{0,1},{0,-1}}, {{0,-1},{1,0},{-1,0}}, {{-1,0},{0,-1},{0,1}}, {{0,1},{-1,0},{1,0}}};

void changeDir() {
    if(dir[cur_dir][turn] == make_pair(0,1)) cur_dir = 3;
    else if(dir[cur_dir][turn] == make_pair(0,-1)) cur_dir = 1;
    else if(dir[cur_dir][turn] == make_pair(1,0)) cur_dir = 0;
    else if(dir[cur_dir][turn] == make_pair(-1,0)) cur_dir = 2;
}

bool move(char &c, int &t) {
    if(c == 'L') turn =1;
    else if(c == 'R') turn =2;
    int x = cur.f, y = cur.s;

    for(int i = 0; i < t; ++i) {
        x += dir[cur_dir][turn].f; y += dir[cur_dir][turn].s;
        if(x<1 or y<1 or x>w or y>d or not vis[x][y]) return 0;
        cur = {x,y};
    }
    changeDir();
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> w >>d;
    cin >> cur.f >> cur.s;

    vis.resize(w+1,vector<bool>(d+1,1));
    vis[cur.f][cur.s] = 0;

    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        char c; int t;
        cin >> c >> t;

        if(not move(c,t)) {
            cout << dis << "\n(" << cur.f << "," << cur.s << ") D";
            return 0;
        }
        dis += t;
    }
    cout << dis << "\n(" << cur.f << "," << cur.s << ") A";
    return 0;
}
