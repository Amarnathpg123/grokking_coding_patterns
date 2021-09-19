#include <bits/stdc++.h>
using namespace std;

#define us uint_fast32_t
#define MAX us(1e9)

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

void ns(us &h){
    h++;
    if(h > 1e9) h -= 1e9;
}

void sn(us &h){
    h--;
    if(!h) h += 1e9;
}

void we(us &w){
    w++;
    if(w > 1e9) w -= 1e9;
}

void ew(us &w){
    w--;
    if(!w) w += 1e9;
}

void move(char const &c, us &w, us &h){
    switch(c){
        case 'N':
            sn(h); break;
        case 'S':
            ns(h); break;
        case 'E':
            we(w); break;
        default:
            ew(w); break;
    }
}

void solve(string const &s, us &w, us &h){
    if(s.size() == 0) return;

    us i = 0;
    for(; i < s.size(); ++i){
        char c = s.at(i);
        if(c > 'A') move(c, w, h);

        else{
            int_fast8_t temp = c-'0';
            us temp2 = 1; i += 2;
            string t; 
            while(1){
                c = s.at(i);
                if(c == '(') temp2++;
                else if(c == ')'){
                    temp2--;
                    if(!temp2) break;
                }
                t.push_back(c);
                i++;
            }
            // while(temp--) solve(t, w, h);
            us w1 = 1, h1 = 1;
            solve(t, w1, h1);
            h = (h + h1*temp-temp)%(MAX);
            w = (w + w1*temp-temp)%(MAX);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    us T; fastInput<us>(T);
    for(us i = 1; i <= T; ++i){
        string s; 
        getline(cin, s);
        us w = 1, h = 1;
        solve(s, w, h);
        printf("Case #%lu: %lu %lu\n", i, w, h);
    }
    return 0;
}