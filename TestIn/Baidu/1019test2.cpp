#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
//无限次操作，将n/i == n/j的两个下标i和j的数替换为gcd(a,b)，求最终可以得到的最小数组和
//错误原因：想到了计算区间内所有元素的最大公因数，但是实现不够高效，而且因为举得反例错误2，4，6，9浪费了检查机会
int gcd(int a, int b)
{
    while (b != 0)
    {
        int x = a % b;
        a = b;
        b = x;
    }
    return a;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> nums[j];
        }
        int result=0;
        for(int i=1;i<=n;++i){
            int k = n/i;
            int r = n/k;
            //[i,r]:
            int gcd_num = nums[i];
            while(r!=i){
                gcd_num = gcd(gcd_num,nums[r]);
                --r;
            }
            result+=gcd_num*(r-i+1);
        }
        cout << result << '\n';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")