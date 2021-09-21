#include <bits/stdc++.h>
using namespace std;

void print_braces(vector<string> &res){
    printf("count: %lu\n", res.size());
    for(string &braces: res)
        cout << braces << endl;
}

void  find_balanced_braces(size_t const &n, size_t open, size_t close, size_t index, string &s, vector<string> &res){
    if(open == n and close == n)
        res.push_back(s);
    else{
        if(open < n){
            s[index] = '(';
            find_balanced_braces(n, open+1, close, index+1, s, res);
        }
        if(close < open){
            s[index] = ')';
            find_balanced_braces(n, open, close+1, index+1, s, res);
        }
    }
}

class braces{
public:
    string s="";
    size_t open = 0, close = 0;
    braces(){}
    braces(string const s_, size_t open_, size_t close_): s(s_), open(open_), close(close_) {}
};

void find_balances_braces_loop(size_t const &n, vector<string> &res){
    deque<braces> dq;
    res.clear();
    dq.push_back(braces());
    while(dq.size()){
        braces t = dq.front(); dq.pop_front();
        if(t.open == n and t.close == n)
            res.push_back(t.s);
        else{
            if(t.open < n)
                dq.push_back(braces(t.s+'(', t.open+1, t.close));
            if(t.close < t.open)
                dq.push_back(braces(t.s+')', t.open, t.close+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    size_t n = 3;
    vector<string> res;
    string s;
    for(size_t i = 0; i < 2*n; ++i) s.push_back('0');
    find_balanced_braces(n, 0, 0, 0, s, res);
    printf("using recursion: ");
    print_braces(res);

    find_balances_braces_loop(n, res);
    printf("\nusing loops: ");
    print_braces(res);
    return 0;
}