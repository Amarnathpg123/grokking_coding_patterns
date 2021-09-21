#include <bits/stdc++.h>
using namespace std;

unordered_set

void findPath(list<int> maze[], int start, int finish, list<int> &path) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    list<int> maze[9];

    maze[0].emplace_back(1);
    maze[0].emplace_back(3);

    maze[1].emplace_back(2);
    maze[1].emplace_back(0);

    maze[2].emplace_back(1);

    maze[3].emplace_back(4);
    maze[3].emplace_back(6);

    maze[4].emplace_back(5);
    maze[4].emplace_back(7);

    maze[5].emplace_back(4);

    maze[6].emplace_back(3);

    maze[7].emplace_back(8);

    maze[8].emplace_back(7);

    list<int> path;
    findPath(maze, 0, 8, path);
    return 0;
}

//path:: 0 3 7 8