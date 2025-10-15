#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    vector<int> result(n, -1);
    vector<int> presum(n + 1, 0);
    presum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        presum[i] = presum[i - 1] + nums[i - 1]; // 前i
    }
    vector<int> prev(n);
    vector<int> back(n);
    stack<int> ff, bb;
    for (int i = 0; i < n; ++i)
    {
        int tmp = nums[i];
        while (!ff.empty() && nums[ff.top()] <= tmp)
        {
            tmp = nums[ff.top()];
            ff.pop();
        }
        if (ff.empty())
        {
            prev[i] = -1;
        }
        else
        {
            prev[i] = ff.top();
        }
        ff.push(i);
    }
    for (int j = n - 1; j >= 0; --j)
    {
        int tmp = nums[j];
        while (!bb.empty() && nums[bb.top()] <= tmp)
        {
            tmp = nums[bb.top()];
            bb.pop();
        }
        if (bb.empty())
        {
            back[j] = n + 1;
        }
        else
        {
            back[j] = bb.top();
        }
        bb.push(j);
    }
    for (int i = 0; i < n; ++i)
    {
        int left = i - 1, right = i + 1;
        if (left >= 0 && nums[left] > nums[i] ||
            right < n && nums[right] > nums[i])
        {
            result[i] = 1;
            continue;
        }
        left = prev[i];
        int sum1 = 0;
        int tmpI = i;
        int tmpL = left;
        while (left >= 0 && sum1 < nums[i])
        {
            sum1 += presum[i] - presum[left];
            i = left;
            left = prev[left];
            if (result[i] == -1)
            {
                break;
            }
        }
        i=tmpI;
        left = tmpL;
        bool ll = sum1 > nums[i];
        if (ll)
        {
            result[i] = i - left;
        }
        // bool rr = right <= n && presum[right] + nums[right - 1] - presum[i] - nums[i] > nums[i];
    }
    vector<int> result2(n,-1);
    for(int i=n-1;i>=0;--i){
        int left = i - 1, right = i + 1;
        if (left >= 0 && nums[left] > nums[i] ||
            right < n && nums[right] > nums[i])
        {
            result2[i]=1;
            continue;
        }
        right = back[i];
        int sum1 = 0;
        int tmpI = i;
        int tmpR = right;
        while (right<=n && sum1 < nums[i])
        {
            sum1 += presum[right] + nums[right - 1] - presum[i] - nums[i] > nums[i];
            i = right;
            right = back[right];
            if (result2[i] == -1)
            {
                break;
            }
        }
        i = tmpI;
        right = tmpR;
        bool rr = sum1 > nums[i];
        if (rr)
        {
            result2[i] = right-i;
        }
    }
    for(int i=0;i<n;++i){
        int s1 = result[i],s2 = result2[i];
        if(s1==-1 && s2==-1){
            cout<<-1;
        }else if(s1!=-1){
            if(s2!=-1){
                cout<<min(s1,s2);
            }else{
                cout<<s1;
            }
        }else{
            cout<<s2;
        }
        cout<<" ";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")