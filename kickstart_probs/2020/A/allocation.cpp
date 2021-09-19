#include <bits/stdc++.h>
using namespace std;

template <typename T>
void fastInput(T &x){
    bool neg = false;
    register int c; x = 0; c = getchar();
    if(c == '-') { neg = true; c=getchar(); }
    for(; (c>47 && c<58); c=getchar()) x = (x<<1) + (x<<3) + c-48; //x = x*2 + x*8 + c-48
    if(neg) x *= -1;
}

void count_sort(vector<unsigned> &A){
    if(A.size()<2) return;

    vector<unsigned> output(A.size());

    unsigned maxe = 0, mine = INT32_MAX, range = 0;
    for(unsigned i = 0; i < A.size(); ++i){
        if(maxe < A[i]) maxe = A[i];
        if(mine > A[i]) mine = A[i];
    }

    range = maxe-mine+1;
    vector<unsigned> count(range);

    for(unsigned i = 0; i < A.size(); ++i)
        count[A[i]-mine]++;

    for(unsigned i = 1; i < count.size(); ++i)
        count[i] +=  count[i-1];

    for(long i = A.size()-1; i >= 0; --i)
        output[(count[A[i]-mine]--)-1] = A[i];

    for(unsigned i = 0; i < A.size(); ++i)
        A[i] = output[i];
}

void find_max_no_houses(vector<unsigned> &A, unsigned B, unsigned &max_no){
    count_sort(A);
    unsigned i = 0;
    while(B > A[i] and i < A.size()){
        B -= A[i++]; max_no++;
    }
}

/*
void find_max_no_houses(vector<int1> &A, int1 &B, size_t &max_no){
    priority_queue<int1, vector<int1>, greater<int1>> pq(A.begin(), A.end());
    while(pq.size() and B > pq.top()){
        B -= pq.top(); pq.pop();
        max_no++;
    }
}
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    unsigned T;
    cout <<  "Enter number of cases: " << endl; fastInput<unsigned>(T);
    for(unsigned i = 1; i <= T; i++){
        unsigned N, B, temp, max_no = 0;
        cout << "\nCase #" << i << ": \n";
        cout << "Enter no. houses: " << endl; fastInput(N); 
        cout << "Enter the budget: " << endl; fastInput(B);

        vector<unsigned> A;
        cout << "Enter the cost of houses: " << endl;
        while(N){
            fastInput(temp); A.push_back(temp);
            N--;
        }
        find_max_no_houses(A,B,max_no);
        cout << "case #" << i << ": Maximum no of houses can bought is: " << max_no << endl;

    }
    return 0;
}

/*
3
4 100
20 90 40 90
4 50
30 30 10 10
3 300
999 999 999
*/