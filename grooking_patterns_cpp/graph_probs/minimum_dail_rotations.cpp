/*
AT&T just acquired a cellular company in a small town that owns four base stations. 
The company they acquired owned vintage equipment with dials that must be rotated clockwise or counterclockwise 
by hand to power up the base stations. There’s one dial for each of the base stations. 
Each dial has numbers from 0 to 9 and does not stop at either extreme; 
this means you can rotate clockwise at 9 to go back to 0 or counterclockwise at 0 to go to 9.

Each position on a dial represents a particular state for the corresponding base station. 
To power up the base stations, the dials must be taken from state 0000 to a target state, say abcd, where a, b, c, and d are digits between 0 and 9. 
The constraints are that only one dial may be turned (clockwise or counterclockwise) one position at a time and certain dead states are prohibited and must be avoided at all costs. 
The system will get stuck and fail if we land in a dead state.

We’ll be provided with a list of dead states that we need to avoid and a target state that we need to reach. 
You want to power up the system in the minimum number of dial turns by avoiding the dead states.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> dead = {"0201","0101","0102","1212","2002"};
unordered_set<string> visited(dead.begin(), dead.end());

vector<string> nextDails(string &dial) {
    vector<string> dials;
    for(int i = 0; i < dial.length(); ++i) {
        string temp = dial;
        temp[i]++;
        if(temp[i] > '9') temp[i] = '0';
        if(not visited.count(temp)) dials.emplace_back(temp);

        temp = dial;
        temp[i]--;
        if(temp[i] < '0') temp[i] = '9';
        if(not visited.count(temp)) dials.emplace_back(temp);
    }

    return dials;
}

int findMinimumDails(string &target) {
    if(target.length() != 4) return 0;
    if(target == "0000") return 0;
    queue<string> q;
    q.push("0000");

    int depth = 0;
    while(not q.empty()) {
        int x = q.size();
        while(x--) {
            visited.emplace(q.front());
            vector<string> temp = nextDails(q.front());
            q.pop(); 
            for(auto &dial: temp) {
                if(dial == target) return depth+1;
                if(not visited.count(dial)) q.push(dial);
            }
        }
        depth++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string target;
    cin >> target;
    printf("Minimum no. of dails required is: %d\n", findMinimumDails(target));
    return 0;
}