#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi evaluate_expressions(unordered_map<string, vi> &umap, string s){
    if(umap.find(s) != umap.end()) return umap[s];
    
    vi res = {};

    if(s.find('+') == string::npos and s.find('-') == string::npos and s.find('*') == string::npos)
        res.push_back(stoi(s));

    else{
        for(size_t i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c < 48){
                vi left = evaluate_expressions(umap, s.substr(0,i));
                vi right  = evaluate_expressions(umap, s.substr(i+1));
                for(int &l: left){
                    for(int &r: right){
                        if(c == '+')
                            res.push_back(l+r);
                        else if(c == '-')
                            res.push_back(l-r);
                        else if(c == '*')
                            res.push_back(l*r);
                    }
                }
            }
        }
    }
    umap[s] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    unordered_map<string, vi> umap;
    umap[""] = {};
    cout << "enter the expession: " << endl; cin >> str;
    vi res = evaluate_expressions(umap, str);
    printf("these are the results of the experession: \n");
    for(int &num: res)
        printf("%d ", num);
    printf("\n");
    return 0;
}