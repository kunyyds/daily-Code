#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     *
     * @param n1 int整型  1元纸币的数量
     * @param n5 int整型  5元纸币的数量
     * @param n10 int整型  10元纸币的数量
     * @param n20 int整型  20元纸币的数量
     * @param n50 int整型  50元纸币的数量
     * @param M int整型  需要支付的金额
     * @return int整型
     */
    int getMin(int n1, int n5, int n10, int n20, int n50, int M)
    {
        // write code here
        // 1,5
        int res = 0;
        while(n50>0 && M>=50){
            M-=50;
            n50--;
            ++res;
        }
        if(M==0)return res;

        while(n20>0 && M>=20){
            M-=20;
            n20--;
            ++res;
        }
        if (M == 0)
            return res;

        while (n10 > 0 && M >= 10)
        {
            M -= 10;
            n10--;
            ++res;
        }
        if (M == 0)
            return res;

        while (n5 > 0 && M >= 5)
        {
            M -= 5;
            n5--;
            ++res;
        }
        if (M == 0)
            return res;
        
        while (n1 > 0 && M >= 1)
        {
            M -= 1;
            n1--;
            ++res;
        }
        if (M == 0){
            return res;
        }
        else{
            return -1;
        }
    }
    int dfs(int n1, int n5, int n10, int n20, int n50, int M)
    {
        if (M == 0)
            return 0;
        int t1 = M, t2 = M, t3 = M, t4 = M, t5 = M;
        if (M >= 50 && n50 > 0)
            t1 = dfs(n1, n5, n10, n20, n50 - 1, M - 50);
        if (M >= 20 && n20 > 0)
            t2 = dfs(n1, n5, n10, n20 - 1, n50, M - 20);
        if (M >= 10 && n10 > 0)
            t3 = dfs(n1, n5, n10 - 1, n20, n50, M - 10);
        if (M >= 5 && n5 > 0)
            t4 = dfs(n1, n5 - 1, n10, n20, n50, M - 5);
        if (M >= 1 && n1 > 0)
            t5 = dfs(n1 - 1, n5, n10, n20, n50, M - 1);
        return min(min(min(t1, t2), min(t3, t4)), t5) + 1;
    }
};
// 10,10,10,10,10,50 = 1
// 10,10,10,10,10,70 = 2