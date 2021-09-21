#include <bits/stdc++.h>
using namespace std;

int next_index(vector<int> &list, bool is_forward, int current){
    bool direction = list[current] >= 0;

    if(is_forward != direction) return -1;
    int next = (current+list[current])%list.size();

    if(next == current) return -1;
    return next;
}

bool have_cycle_in_circular(vector<int> &list){
    for(int i = 0; i < list.size(); ++i){
        bool is_forward = list[i] >= 0;
        int slow = i, fast = i;

        while(1){
            slow = next_index(list, is_forward, slow);
            fast = next_index(list, is_forward, fast);
            if(fast != -1) fast = next_index(list, is_forward, fast);
            if(slow == -1 or fast == -1 or slow == fast) break;

        }
        if(slow != -1 and slow == fast) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    size_t n; int temp;
    vector<int> list;
    cout << "Enter number of nodes: " << endl; cin >> n;
    cout << "Enter the pointing indices: " << endl;
    while(n--) cin >> temp, list.push_back(temp);

    if(have_cycle_in_circular(list)) cout << "Yes, cycle found" << endl;
    else cout << "No cycle found" << endl;
    return 0;
}