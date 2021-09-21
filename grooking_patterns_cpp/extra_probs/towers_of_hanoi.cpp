#include <bits/stdc++.h>
using namespace std;

void print_moves(short &start, short &end){
    printf("%i -> %i\n", start, end);
}

void towers_of_hanoi(unsigned n, short &start, short &end, unsigned long &count){
    short other;

    if(n >= 1) {
        count++;
        other = 6 - (start + end);
        towers_of_hanoi(n-1, start, other, count);
        print_moves(start, end);
        towers_of_hanoi(n-1, other, end, count);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    unsigned long count = 0;
    unsigned n;
    short start, end;
    cout << "Enter number of rings n >= 1, start and end [1,3] (start != end):\t" << endl;
    cin >> n >> start >> end;
    //n = atoi(argv[1]); start = atoi(argv[2]); end = atoi(argv[3]);
    towers_of_hanoi(n, start, end, count);
    cout << "No. of moves: " << count <<  " -> which equals (2^n - 1)" << endl;

    return 0;
}