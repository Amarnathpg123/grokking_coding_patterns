#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    if(n < B) return {};
    if(n == B) return {*max_element(A.begin(), A.end())};

    deque<int> dq;
    vector<int> ans;
    int i = 0;
    for(; i < B; ++i) {
        while(not dq.empty() and A.at(dq.back()) < A.at(i)) dq.pop_back();
        dq.emplace_back(i);
    }
    ans.emplace_back(A.at(dq.front()));

    for(i = 1; i < (n-B+1); ++i) {
        if(A.at(i-1) == A.at(dq.front())) dq.pop_front();
        while(not dq.empty() and A.at(dq.back()) < A.at(i+B-1)) dq.pop_back();
        dq.emplace_back(i+B-1);
        ans.emplace_back(A.at(dq.front()));
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {10, 9, 8,7,6,5,4,3,2,1};
    //{648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
    int n = 3;

    for(auto &it: slidingMaximum(arr, n)) cout << it << " ";
    cout << endl;
    return 0;
}