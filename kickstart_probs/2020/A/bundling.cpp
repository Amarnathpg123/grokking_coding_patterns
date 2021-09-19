#include <bits/stdc++.h>
using namespace std;

#define us unsigned

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

class Trie{
public:
    us ct = 0;
    Trie *bit[26];
    Trie(){}
};

void insert(Trie *root, string &s){
    for(char &c: s){
        unsigned b = c-'A';
        if(!root->bit[b])
            root->bit[b] = new Trie();
        root = root->bit[b];
        (root->ct)++;
    }
}

us query(Trie *root, us const &K){
    if(!root) return 0;
    us ans = (root->ct/K);
    for(us i = 0; i < 26; ++i)
        if(root->bit[i])
           ans += query(root->bit[i], K);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    us T; fastInput<us>(T);
    for(us i = 1; i <= T; ++i){
        us N, K; fastInput<us>(N); fastInput<us>(K);
        string temp;
        Trie *root = new Trie();
        for(us j = 0; j < N; ++j){
            cin >> temp;
            insert(root, temp);
        }
        us ans = query(root, K);
        printf("Case #%u: %u\n", i, ans);
    }
    return 0;
}   