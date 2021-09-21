#include <bits/stdc++.h>
using namespace std;

void print_abries(vector<string> &res){
    printf("count: %lu\n", res.size());
    for(string &abr: res)
        cout << abr << endl;
}

void find_abrivations(string const &str, string s, size_t start, size_t count, vector<string> &res, size_t lvl){
    if( start == str.size()){
        if(count) s.append(to_string(count));
        res.push_back(s);
    }

    else{
        find_abrivations(str, s, start+1, count+1, res, lvl+1);

        if(count) s.append(to_string(count));
        string t = s;
        t.push_back(str[start]);

        find_abrivations(str, t, start+1, 0, res, lvl+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << "enter the string: " << endl;
    string str; cin >> str;
    vector<string> res;

    find_abrivations(str, "", 0, 0, res, 0);
    print_abries(res);
    return 0;
}