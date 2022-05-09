#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> allSubSet;

int nthRoot(vector<int> v){
    int ans = 1;
    for(int i : v){
        ans *= i;
    }
    return pow(ans, v.size());
}

void generateSubset(vector<int> &subset, int p, vector<int> &nums){
    if(p == nums.size()){
        allSubSet.push_back(subset);
        return;
    }
    // Picks the nums[p]
    subset.push_back(nums[p]);
    generateSubset(subset, p+1, nums);
    subset.pop_back();

    // Not pick the nums[p]
    generateSubset(subset, p+1, nums);
}

int main(){
    // vector<int> nums = {1,2,3};
    vector<int> nums = {36, 81 , 54 ,54};
    vector<int> empty;
    generateSubset(empty, 0, nums);
    for(auto v : allSubSet){
        for(int i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }

   

    return 0;
}