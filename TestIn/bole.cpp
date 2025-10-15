#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int minOpeCount(vector<int>& nums,int m){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2*m,0));
        for(int j=1;j<m;++j){
            dp[0][j] = j;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<2*m;++j){
                dp[i][j] =min(dp[i-1][j]+1,dp[i-1][(j-nums[i]+m)%m]);
                if(j>0){
                    dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        return min(dp[n][0],dp[n][m]);
    }
};
void func(const int& num){
    cout<<num<<endl;
}
int main(){
    int a=0;
    func(a);
    func(2);
    func(std::move(a));
    return 0;
}