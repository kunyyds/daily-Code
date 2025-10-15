
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     *
     * @param rooms int整型 vector<vector<>> 房间
     * @param startPoint int整型 vector 起始点
     * @param endPoint int整型 vector 终点
     * @return int整型
     */
    int minimumInitHealth(vector<vector<int>> &rooms, vector<int> &startPoint, vector<int> &endPoint)
    {
        // write code here
        int m = rooms.size(), n = rooms[0].size();
        int si = startPoint[0], sj = startPoint[1];
        int ei = endPoint[0], ej = endPoint[1];
        if (si == ei && sj == ej)
        {
            return 1;
        }
        vector<vector<bool>> vis(m * n, vector<bool>(4, false));
        vector<vector<int>> dp(m * n, vector<int>(4, 100000000));
        vector<int> count(m*n,0);
        int poss = si*n+sj;
        vis[poss] = {true, true, true, true};
        count[poss]=4;
        int s = rooms[si][sj];
        if (s <= 0)
            s = abs(s + 1);
        // dp[si*n+sj]={s,s,s,s};
        dp[poss] = {1, 1, 1, 1};
        // deque<pair<int, int>> dq;
        deque<Node>dq;
        dq.emplace_back(si,sj,-1);
        
        while (!dq.empty())
        {
            auto node = dq.front();
            int fi = node.i;
            int fj = node.j;
            int dir = node.dir;
            dq.pop_front();
            int pos = fi * n + fj;
            int cur = min(min(dp[pos][0], dp[pos][1]), min(dp[pos][2], dp[pos][3]));
            int cost = rooms[fi][fj];
            int tmp = cur + cost;
            if (tmp <= 0)
            {
                cur += abs(tmp) + 1;
            }
            for (int i = 0; i < 4; ++i)
            {
                int ni = fi + dirs[i][0];
                int nj = fj + dirs[i][1];
                int pos = ni* n+nj;
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || count[pos]>=4 || i == 3-dir)
                {
                    continue;
                }
                dp[pos][i] = cur;
                vis[pos][i]=true;
                count[pos]++;
                dq.emplace_back(ni,nj,i);
            }
        }
        int pos = ei*n+ej;
        int minres=dp[pos][0];
        for(int i=1;i<4;++i){
            minres = min(minres,dp[pos][i]);
        }
        return minres;
    }
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    struct Node{
        int i;
        int j;
        int dir;
        Node(int x,int y,int z):i(x),j(y),dir(z){};
    };
};
// [[-2,-3,3],[-5,-10,1],[10,30,-5]],[0,0],[2,2] = 7
// [[100]],[0,0],[0,0] = 1