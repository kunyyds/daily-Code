#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m,M;
    cin>>n>>m>>M;
    vector<vector<int>> power(n,vector<int>(m,0));
    vector<vector<int>> mam(n,vector<int>(m,0));
    vector<int> pw(n);
    vector<int> cost(n);
    vector<int>scale(m);
    for(int i=0;i<n;++i){
        cin>>pw[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> scale[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            power[i][j] = pw[i]*scale[j];
            mam[i][j] = cost[i]*scale[j];
        }
    }
    // vector<vector<vector<int>>> dp(m,)
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(M+1,vector<int>(m,0)));
    int maxPower = 0;
    int cc = 1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=M;++j){
            for(int k=0;k<m;++k){
                int cost = mam[i-1][k];
                int val = power[i-1][k];
                if(j<cost)continue;
                int maxVal = 0;
                for(int h=0;h<m;++h){
                    int add = max(0,k-h);
                    if(i==1)add=0;
                    maxVal = max(dp[i-1][j-cost][h]+val-add,maxVal);
                }
                dp[i][j][k] = maxVal;
                maxPower = max(maxPower,maxVal);
            }
        }
    }
    cout<<maxPower<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")