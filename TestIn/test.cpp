#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
public:
    int minInitVal(vector<vector<int>> & map,int x0,int y0,int x1,int y1){
        int init = 1;
        if(map[x0][y0]<0){
            init = -1*map[x0][y0];
        }
    }
};
int main(){
    int k,n;
    cin>>k>>n;
    vector<int> scores(n,0);
    long long sum=0,maxSum = 0;
    for(int i=0;i<n;++i){
        cin>>scores[i];
    }
    vector<long long> dp(n,0);
    dp[0] = scores[0];
    priority_queue<pair<long long,int>> pq;
    pq.push({dp[0],0});
    for(int i=1;i<n;++i){
        while(pq.top().second<i-k){
            pq.pop();
        }
        dp[i] = pq.top().first+scores[i];
        pq.push({dp[i],i});
    }
    cout<<dp[n-1]<<endl;
    return 0;
}