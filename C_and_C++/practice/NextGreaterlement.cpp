#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i< nums2.size(); i++){
        while(!st.empty() && nums2[i] > nums2[st.top()]){
            m.insert({nums2[st.top()], nums2[i]});
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        m.insert({nums2[st.top()], -1});
        st.pop();
    }
    for(int i : nums1){
        ans.push_back(m[i]);
    }

    return ans;
        
}
int main(){
    // vector<int> nums1 = {4,1,2};
    vector<int> nums1 = {2,4};
    // vector<int> nums2 = {1,3,4,2};
    vector<int> nums2 = {1,2,3,4};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}