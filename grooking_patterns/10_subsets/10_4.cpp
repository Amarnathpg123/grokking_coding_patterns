#include <bits/stdc++.h>
using namespace std;

void change_case(char &c){
    if(c >= 'A' and c <= 'Z')
        c += 32;
    else if(c >= 'a' and c <= 'z')
        c -= 32;
}

//using backtracking
void find_case_permutations(string s, vector<string> &res, size_t index){
    res.push_back(s);
    for(size_t i = index; i < s.size(); ++i){
        string s1 = s;
        if(s1[i] >= 'A') change_case(s1[i]);
        else continue;
        find_case_permutations(s1, res, i+1);
    }
}

void print_strings(vector<string> &res){
    printf("count: %lu\n", res.size());
    for(string &s: res)
        cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> res;
    find_case_permutations("abcd", res, 0);
    print_strings(res);
    return 0;
}