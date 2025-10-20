#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;
// 对数组操作，让最大值小于等于最小值的两倍，具体每一次可以取出一个数并将其分解为x，y使x+y=这个数，插入x，y到数组中
//求最小的操作此时
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        // int x;cin>>x;
        // nums[i] = x;
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int target = nums.front() * 2;
    int count = 0;
    int i = n - 1;
    while (nums[i] > target)
    {
        int f = nums[i];
        --i;
        count +=(f-1)/target;
        // 将f分割为<=target的数字，最终得到的数字数量是f/target(向上取整)-1, = (f-1)/target
    }
    cout << count << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")