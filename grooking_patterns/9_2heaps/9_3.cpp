#include <bits/stdc++.h>
using namespace std;
typedef vector<unsigned> vu;
typedef pair<unsigned,unsigned> puu;

class comp_{
public:
    constexpr bool operator()(puu const &a, puu const &b) const noexcept {
        return a.first > b.first;
    }
};

unsigned find_maximum_capital(vu &capital_inv, vu &profits, unsigned const &no_proj, unsigned init_cap){
    priority_queue<unsigned> profit_maxh;
    priority_queue<puu, vector<puu>, comp_> capital_minh;
    for(unsigned i = 0; i < capital_inv.size(); ++i)
        capital_minh.push(make_pair(capital_inv[i],i));

    for(size_t i = 0; i < no_proj; ++i){
        while(capital_minh.size() and capital_minh.top().first <= init_cap ){
            unsigned j = capital_minh.top().second; capital_minh.pop();
            profit_maxh.push(profits[j]);
        }

        if(not profit_maxh.size()) break;

        init_cap += profit_maxh.top(); profit_maxh.pop();
    }
    return init_cap;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    unsigned no_proj=3, init_cap=0;
    vu capital_inv = {0, 1, 2, 3}, profits = {1, 2, 3, 5};
    printf("Maximised Capial is: %u\n", find_maximum_capital(capital_inv, profits, no_proj, init_cap));

    no_proj=2; init_cap=1;
    capital_inv = {0, 1, 2}; profits = {1, 2, 3};
    printf("Maximised Capial is: %u\n", find_maximum_capital(capital_inv, profits, no_proj, init_cap));
    return 0;
}