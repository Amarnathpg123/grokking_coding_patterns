#include <bits/stdc++.h>
using namespace std;

class MeadianOfStream{
    priority_queue<int> max_heap, min_heap;
public:
    void insert_num(int num){
        if(not max_heap.size() or max_heap.top() >= num)
            max_heap.push(num);
        else min_heap.push(-num);

        if(max_heap.size() > min_heap.size()+1){
            int temp = max_heap.top();
            max_heap.pop(); min_heap.push(-temp);
        }
        else if(max_heap.size() < min_heap.size()){
            int temp = -min_heap.top();
            min_heap.pop(); max_heap.push(temp);
        }
    }

    float median(){
        if(max_heap.size() == min_heap.size())
            return (max_heap.top()-min_heap.top())/2.0;
        return max_heap.top()/1.0;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    MeadianOfStream num_stream =  MeadianOfStream();
    num_stream.insert_num(3);
    num_stream.insert_num(1);
    printf("Median of the stream is: %.3f\n", num_stream.median());

    num_stream.insert_num(5);
    printf("Median of the stream is: %.3f\n", num_stream.median());

    num_stream.insert_num(4);
    printf("Median of the stream is: %.3f\n", num_stream.median());

    num_stream.insert_num(10);
    printf("Median of the stream is: %.3f\n", num_stream.median());

    return 0;
}