#include <bits/stdc++.h>
using namespace std;

template<typename T>
class custom_pq: public priority_queue<T, vector<T>>{
    // size_t parent(size_t i){ return (i-1)/2;}
    size_t left(size_t const &i) { return 2*i+1;}
    size_t right(size_t const &i){ return 2*i+2;}
    
    void heapify(size_t const &i){
        size_t largest = i, l = left(i), r = right(i);

        if(l < this->c.size() and this->c[l] > this->c[largest])
            largest = l;
        
        if(r < this->c.size() and this->c[r] > this->c[largest])
            largest = r;
        
        if(largest != i){
            swap(this->c[i], this->c[largest]);
            heapify(largest);
        }
    }

    void shift_i(size_t const &i){
        for(long j = i; j >= 0; j--){  //to build heap back use j = ((c.size()-1)/2-1)  --> last inner node;
            heapify(size_t(j));
        }
    }
public:
    // check whether heaps has duplicate elemenst before removing
    void remove(T const &temp){
        size_t i = 0;
        for(; i < this->c.size(); ++i)
            if(temp == this->c[i]) break;
        swap(this->c[i], this->c.back());
        this->c.pop_back();
        shift_i(i);
    }

};

class SlidingWindowMedian{
    custom_pq<int> max_heap, min_heap;

    void rebalance_heaps(){
        if(max_heap.size() > min_heap.size()+1){
            int temp = max_heap.top();
            max_heap.pop(); min_heap.push(-temp);
        }
        else if(max_heap.size() < min_heap.size()){
            int temp = -min_heap.top();
            min_heap.pop(); max_heap.push(temp);
        }
    }
public:
    void finding_sliding_window_median(vector<int> &input, vector<float> &medians, size_t const &k){
        if(k==0) return;
        else if(k==1) {medians.assign(input.begin(),input.end()); return;}
        for(size_t i = 0; i < input.size(); ++i){
            if(not max_heap.size() or max_heap.top() >= input[i])
                max_heap.push(input[i]);
            else min_heap.push(-input[i]);
            rebalance_heaps();

            if(i >= k-1){
                if(max_heap.size() == min_heap.size())
                    medians.push_back((max_heap.top()-min_heap.top())/2.0);
                else medians.push_back(max_heap.top()/1.0);

                int temp = input[i-k+1];
                if(temp <= max_heap.top())
                    max_heap.remove(temp);
                else min_heap.remove(-temp);

                rebalance_heaps();
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    SlidingWindowMedian sliding_medians = SlidingWindowMedian();
    vector<float> medians={};
    vector<int> input={};
    size_t k=0;

    input = {1, 2, -1, 3, 5}; k=2;
    sliding_medians.finding_sliding_window_median(input, medians, k);
    printf("Medians of sliding window are: ");
    for(float &i: medians) printf("%.3f ", i);
    printf("\n");
    return 0;
}