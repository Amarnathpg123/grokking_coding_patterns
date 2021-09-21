// max height can be achieved by stacking box(l1,w1,h1) on box(l2,w2,h2) if l1 < l2 and w1 < w2
// DP problems need good practice and creativity in problem solving

#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<unsigned,unsigned>,unsigned> box;

bool canBeStacked(box &box1, box &box2){
    return box1.first.first < box2.first.first and box1.first.second < box2.first.second;
}

bool sort_lengths(box &box1, box &box2){
    return box1.first.first < box2.first.first;
}

unsigned tallestStack(vector<box> &boxes){
    sort(boxes.begin(), boxes.end(), sort_lengths);
    map<box,unsigned> heights;
    unsigned temp = 0;
    for(box &i: boxes) heights.insert(pair<box,unsigned> (i, i.second));
    for(size_t i = 1; i < boxes.size(); ++i){
        temp = 0;
        for(size_t j = 0; j < i; ++j)
            if(canBeStacked(boxes[j], boxes[i])){
                if(heights[boxes[j]] > temp) temp = heights[boxes[j]];
            }
        if(temp) heights[boxes[i]] = boxes[i].second + temp;
    }
    temp = 0;
    for(auto &i: heights) if(i.second > temp) temp = i.second;
    return temp;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<box> boxes;
    unsigned n;
    cout << "Enter the no. of boxes: " << endl, cin >> n;
    printf("Enter the boxes (l,w,h) of a box in a line:\n ");
    while(n--){
        box temp;
        cin >> temp.first.first >> temp.first.second >> temp.second;
        boxes.push_back(temp);
    }
    // boxes = {make_pair(make_pair(1,5),4),make_pair(make_pair(1,2),2),make_pair(make_pair(2,3),2),
    //             make_pair(make_pair(2,4),1),make_pair(make_pair(3,6),2),make_pair(make_pair(4,5),3)};
    

    cout << "maximum height of the stack: " << tallestStack(boxes);
    return 0;
}