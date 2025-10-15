#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int m = board.size();
        int n = board[0].size();
        if (board[m - 1][n - 1] == 'X')
        {
            return {0, 0};
        }
        vector<vector<int>> value(m , vector<int>(n , 0));
        vector<vector<int>> step(m, vector<int>(n , 0));
        step[m-1][n-1]=1;
        for(int i=m-2;i>=0;--i){
            if(board[i][n-1] == 'X')break;
            value[i][n-1] = board[i][n-1]-'0'+value[i+1][n-1];
            step[i][n-1] = 1;
        }
        for(int j=n-2;j>=0;--j){
            if(board[m-1][j]=='X')break;
            value[m-1][j] = board[m-1][j]-'0'+value[m-1][j+1];
            step[m-1][j] = 1;
        }
        for (int i = m -2; i >=0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                if(board[i][j] == 'X')continue;
                int val = max(value[i + 1][j + 1], max(value[i + 1][j], value[i][j + 1]));
                value[i][j] = val + board[i][j] - '0';
                int count = 0;
                if (value[i + 1][j + 1] == val)
                {
                    count = (count + step[i + 1][j + 1]) % MOD;
                }
                if (value[i + 1][j] == val)
                {
                    count = (count + step[i + 1][j]) % MOD;
                }
                if (value[i][j + 1] == val)
                {
                    count = (count + step[i][j + 1]) % MOD;
                }
                step[i][j] = count;
            }
        }
        value[0][0]-=('E'-'0');
        if(step[0][0] ==0)value[0][0]=0;
        return {value[0][0], step[0][0]};
    }

private:
    vector<vector<int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}};
    const int MOD = 1E9 + 7;
    struct Node
    {
        int s;
        int e;
        Node() = default;
        Node(int x, int y) : s(x), e(y) {};
        bool operator < (const Node &other) const
        {
            return s < other.s;
        };
    };
};
int main(){

    vector<vector<int>> events ={{1,2,4 }, { 3,4,3}, { 2,3,10 }};
    Solution soluter;
    vector<string> board = {"E11", "XXX", "11S"};
    soluter.pathsWithMaxScore(board);
    return 0;
}