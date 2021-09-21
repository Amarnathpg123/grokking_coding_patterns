#include <bits/stdc++.h>
using namespace std;

unsigned bitwise_compliment(unsigned const &n){
    unsigned count = 0, t = n;

    while(t){  // this is to count of bits
        t >>= 1;
        count++;
    }

    // while(t){  this is to count number of set bits
    //     t = t&(t-1);
    //     count++;
    // }

    count = (1<<count)-1; //pow(2, count)-1;
    return n^count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unsigned n;
    cin >> n;
    printf("Bitwise complement of %u is: %u\n", n ,bitwise_compliment(n));
    printf("Bitwise complement of %u is: %u\n", n ,~(n));  
    return 0;
}