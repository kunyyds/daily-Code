#include <deque>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution{
public:
    void minCostNextStep(vector<vector<pair<int,int>>>& map,int si,int sj){
        if(si==sj){
            cout<<0<<" "<<-1<<endl;
            return ;
        }
        int n = map.size();
        prevNode.assign(n,{});
        priority_queue<pair<int,int>,vector<pair<int,int>>,std::greater<>>pq;
        vector<bool> visit(n,false);
        vector<int> dis(n,-1);
        pq.emplace(0,si);
        while(!pq.empty()){
            auto [cost,p] = pq.top();
            pq.pop();
            if(visit[p])continue;
            visit[p] = true;
            dis[p] = cost;
            // if(p==sj){break;};
            for(auto [nxt,k]:map[p]){
                int x = cost+k;
                if(dis[nxt]==-1 || dis[nxt]>=x){
                    if(dis[nxt]>x){
                        prevNode[nxt].clear();
                    }
                    prevNode[nxt].push_back(p);
                    dis[nxt] = x;
                    pq.emplace(x,nxt);
                }
            }
        }
        if(dis[sj]==-1){
            cout<<-1<<" "<<-1<<endl;
            return ;
        }
        deque<int> dq;
        dq.push_back(sj);
        visit.assign(n,false);
        visit[sj]=true;
        vector<int>si_step;
        while(!dq.empty()){
            int f = dq.front();
            dq.pop_front();
            for(int prev:prevNode[f]){
                if(prev == si){
                    si_step.push_back(f);
                }
                if(!visit[prev]){
                    dq.push_back(prev);
                    visit[prev] = true;
                }
            }
        }
        sort(si_step.begin(),si_step.end());
        cout<<dis[sj]<<endl;
        for(int nxt:si_step){
            cout<<nxt+1<<" ";
        }
        cout<<endl;
    }
private:
    vector<vector<int>> prevNode;
};
class Solution3{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        TreeNode(int x) : val(x) {};
        TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {};
    };
    vector<TreeNode *> nodes ;
public :
    int maxScore(vector<int> &nums)
    {
        auto root = createTree(nums);
        auto res = dfs(root);
        return max(res.first, res.second);
        // return 0;
    }
    pair<int,int> dfs(TreeNode* root){
        if(root==nullptr)return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int x1 = root->val+left.second+right.second;
        int x2 = max(left.first,left.second)+max(right.first,right.second);
        return {x1,x2};
    }
    TreeNode* createTree(vector<int>& nums){
        int n = nums.size();
        TreeNode* root = nullptr;
        nodes.assign(n,nullptr);
        for(int i=0;i<n;++i){
            if(nums[i]>0){
                nodes[i] = new TreeNode(nums[i]);
            }
        }
        int left = 0;
        for(int i=1;i<n-1;i+=2){
            while(nums[left]==0)++left;
            if(nums[i]>0){
                nodes[left]->left = nodes[i];
            }
            if(nums[i+1]>0){
                nodes[left]->right = nodes[i+1];
            }
            ++left;
        }
        return nodes[0];
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    Solution3 solver;
    cout << solver.maxScore(nums);
    return 0;
    /*
    int n;cin>>n;
    cin.get();
    deque<string> dq;
    unordered_map<string,int> count;
    string input;
    while(getline(cin,input)){
        istringstream iss(input);
        string ele;
        while(getline(iss,ele,' ')){
            if(count[ele]==0){
                dq.push_back(ele);
            }

            count[ele]++;
        }
        int i=0;
        for(;i<n;++i){
            if(dq.empty())break;
            cout<<dq.front()<<' '<<count[dq.front()]<<' ';
            count[dq.front()] = 0;
            dq.pop_front();
        }
        if(i==0){
            cout<<"null";
        }
        cout<<"\n";
    }
        *///test1
    // Solution solver;
    // int n,k;cin>>n>>k;
    // vector<vector<pair<int,int>>> map(n);
    // for(int i=0;i<k;++i){
    //     int ri,rj,l;
    //     cin>>ri>>rj>>l;
    //     map[ri-1].emplace_back(rj-1,l);
    //     map[rj - 1].emplace_back(ri - 1, l);
    // }
    // int si,sj;cin>>si>>sj;
    // solver.minCostNextStep(map,si-1,sj-1);
    return 0;
}