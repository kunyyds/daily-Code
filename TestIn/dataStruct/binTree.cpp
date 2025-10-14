#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode*y,TreeNode*z):val(x),left(y),right(z){};
};
class Solution{ //计算二叉树的所有路径中的路径和最大值
public:
    int minPathLen(TreeNode*root){
        dfs(root);
        return max_sum;
    }
private:
    int max_sum=0;
    int dfs(TreeNode*root){
        if(root==nullptr)return 0;
        int left_max = max(dfs(root->left),0);
        int right_max = max(dfs(root->right),0);

        max_sum = max(max_sum,left_max+root->val+right_max);

        return max(left_max,right_max)+root->val;
    }
    vector<int> max_sum_path{};
    std::pair<int,vector<int>> dfs2(TreeNode* root){
        if(root==nullptr)return {0,{}};
        auto left_gain = dfs2(root->left);
        if(left_gain.first<0){
            left_gain.second.clear();
            left_gain.first = 0;
        }
        auto right_gain = dfs2(root->left);
        if (right_gain.first < 0)
        {
            right_gain.second.clear();
            right_gain.first = 0;
        }
        int n = left_gain.second.size();
        vector<int> reverse_left(n,0);
        for(int i=0;i<n;++i){
            reverse_left[i] = left_gain.second[n-1-i];
        }

        int current_sum = left_gain.first+root->val+right_gain.first;
        if(current_sum>max_sum){
            reverse_left.push_back(root->val);
            reverse_left.insert(reverse_left.end(),right_gain.second.begin(),right_gain.second.end());
            max_sum_path = std::move(reverse_left);
        }
        if(left_gain.first>right_gain.first){
            left_gain.second.insert(left_gain.second.begin(),root->val);
            return {left_gain.first+root->val,left_gain.second};
        }//
    }
};