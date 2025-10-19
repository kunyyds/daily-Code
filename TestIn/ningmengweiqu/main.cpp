#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxTreeSum(vector<int>& nums,int upper){
        sort(nums.begin(),nums.end(),std::greater<int>());
        int maxResult = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            int left = 0,right=n-1;
            if(left==i)++left;
            if(right==i)--right;
            int target = upper-nums[i];
            while(left<right){
                int sum = nums[right]+nums[left];
                if(sum == target){
                    return upper;
                }
                if(sum>target)++left;
                else{
                    maxResult = max(maxResult,sum+nums[i]);
                    --right;
                }
                if (left == i)
                    ++left;
                if (right == i)
                    --right;
            }
        }
        return maxResult;
    }
};