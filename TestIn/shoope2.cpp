#include <vector>
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
     * @param arr int整型 vector
     * @return int整型
     */
    int run(vector<int> &arr)
    {
        // write code here
        sort(arr.begin(), arr.end());
        if (arr.front() == arr.back())
        {
            return arr.size();
        }
        int sum = 0;
        for (int num : arr)
        {
            sum += num;
        }
        int m = 1;
        for(int i=1;i<=sum;++i){
            if(sum%i==0 && check(arr,i,sum)){
                m = max(m,sum/i);
                break;
            }
        }
        return m;
    }
    bool check(vector<int> &arr, int val,int sum)
    {
        if (val < arr.back() || val<arr.front())
            return false;
        int group = sum/val;
        
        return true;
    }
};
// [3,4,2,3,5,2,1] =4