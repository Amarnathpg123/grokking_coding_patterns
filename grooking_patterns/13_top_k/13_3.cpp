#include <bits/stdc++.h>
using namespace std;

class point{
public: 
    long x = 0, y = 0, distance = 0;
    point(long x_, long y_): x(x_), y(y_) { distance = distance_fo(); }
    inline long distance_fo(){return x*x + y*y;}
};

class comp_distance{
public:
    constexpr inline bool operator()(const point &a, const point &b) const {return a.distance < b.distance;}
};

void find_k_closest(vector<point> &arr, size_t const &k, priority_queue<point, vector<point>, comp_distance> &pq){
    if(arr.size() == k) return;
    for(size_t i = k; i < arr.size(); ++i){
        if(arr[i].distance < pq.top().distance){
            pq.pop();
            pq.push(arr[i]);
        }
    }
}

void print_points(priority_queue<point, vector<point>, comp_distance> &pq){
    while(pq.size()){
        printf("(%ld, %ld) ", pq.top().x, pq.top().y);
        pq.pop();
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<point> arr;
    size_t n, k;
    long t1,t2;
    cout << "Enter no. points and k: " << endl; cin >> n; cin >> k;
    cout << "Enter points as x and y: " << endl;
    while(n){
        cin >> t1 >> t2; arr.push_back(point(t1,t2));
        n--;
    }
    assert(arr.size() >= k);
    priority_queue<point, vector<point>, comp_distance> pq(arr.begin(), arr.begin()+k);
    find_k_closest(arr, k, pq);
    printf("%lu closest points are: ", k);
    print_points(pq);
    return 0;
}