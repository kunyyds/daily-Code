#include <vector>
#include <deque>
#include <random>
#include <iostream>
using namespace std;
class Solution{
public://思路错误，无需BFS遍历应当事先记录所有1的位置。然后挨个计算或者KD-Tree加速查找最小欧式距离的点
    int midDis_2(vector<vector<int>>& map,int i0,int j0){ //i,j到横向偏移和纵向偏移平方和最小的特殊位置
        //elements in map=1 or 0
        std::random_device rd;                     // 用于种子生成
        std::mt19937 gen(rd());                    // 使用梅森旋转算法
        std::uniform_int_distribution<> dis(0, 1); // 生成 0 或 1

        int m = map.size();
        if(m==0)return -1;
        int n = map[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                map[i][j] = dis(gen); // 随机填充 0 或 1
            }
        }

        vector<vector<bool>> visit(m,vector<bool>(n,false));
        vector<pair<int,int>> directs={{-1,0},{1,0},{0,1},{0,-1}};
        deque<pair<int,int>> dq;
        dq.emplace_back(i0,j0);
        visit[i0][j0]=true;
        while(!dq.empty()){
            int layersize = dq.size();
            for(int i=0;i<layersize;++i){
                auto [ci,cj]=dq.front();
                int dis1 = abs(ci - i0);
                int dis2 = abs(cj - j0);
                cout << dis1 * dis1 + dis2 * dis2 << " ";
                dq.pop_front();
                for(auto f:directs){
                    int ni = ci+f.first,nj=cj+f.second;
                    if(ni<0 || ni>=m || nj<0 || nj>=n || visit[ni][nj]){
                        continue;
                    }
                    dq.emplace_back(ni,nj);
                    visit[ni][nj]=true;
                }
            }
            cout << endl;
        }
        return 0;
    }
};

int main(){
    Solution solver;
    vector<vector<int>> map(10,vector<int>(10,0));
    solver.midDis_2(map,5,4);
    return 0;
}