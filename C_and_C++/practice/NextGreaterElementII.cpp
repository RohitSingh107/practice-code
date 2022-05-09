#include<bits/stdc++.h>
using namespace std;

int f(vector<int> a, int b){
    int ans = -1;
    for(int i : a){
        if(i > b){
            return i;
        }
    }
    return ans;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    vector<int> ans(nums.size());
    for(int i = 0; i< nums.size(); i++){
        while(!st.empty() && nums[i] > nums[st.top()]){
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()] = f(nums, nums[st.top()]);
        st.pop();
    }
    return ans;   
}
int main(){
    vector<int> nums = {1,2,1};

    vector<int> ans = nextGreaterElements(nums);
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}