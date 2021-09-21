#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>,pair<int,int>> quadriple;

quadriple make_quad(int &a, int &b, int &c, int &d){
    return make_pair(make_pair(a,b),make_pair(c,d));
}

void quadriple_sum_target(vector<int> &array, vector<quadriple> &quads, int const &target){
    if(array.size() < 4) cerr << "quads cann't be formed with < 4 elements\n", exit(1);
    if(array.size() == 4){
        if(accumulate(array.begin(), array.end(), 0) == target) 
            quads.push_back(make_quad(array[0], array[1], array[2], array[3]));
        return;
    }
    sort(array.begin(), array.end());
    for(int i = 0; i < array.size()-3; ++i){
        if(array[i] == array[i-1]) continue;

        for(int j = i+1; j < array.size()-2; ++j){
            if(array[j] == array[j-1]) continue;

            int left = j+1, right = array.size()-1;
            while(left < right){
                int sum = array[i]+array[j]+array[left]+array[right];
                if(sum == target){
                    quads.push_back(make_quad(array[i], array[j], array[left++], array[right--]));
                    while(left < right and array[left] == array[left-1]) left++;
                    while(left < right and array[right] == array[right+1]) right--;
                }
                else if(sum < target) left++;
                else right--;                  
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    size_t n; int tmp, target;
    vector<int> array = {};
    vector<quadriple> quads = {};

    cout << "Enter the target for quads: " << endl; cin >> target;
    cout << "Enter the number of elemnts: " << endl; cin >> n;
    cout << "Enter the array elements: " << endl;
    while(n--) cin >> tmp, array.push_back(tmp);

    quadriple_sum_target(array, quads, target);
    if(quads.size()) {
        printf("quads are:\n ");
        for(quadriple &quad: quads)
            printf("(%d, %d, %d, %d)\n", quad.first.first, quad.first.second, quad.second.first, quad.second.second);
    }
    else printf("No quads found!\n");    
    return 0;
}