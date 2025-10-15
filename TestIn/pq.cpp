#include <queue>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int left = 0;
        priority_queue<Node, vector<Node>, std::less<Node>> maxpq;
        priority_queue<Node, vector<Node>, std::greater<Node>> minpq;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            maxpq.emplace(nums[i], i);
            minpq.emplace(nums[i], i);
            while(!maxpq.empty() && maxpq.top().index<left){
                maxpq.pop();
            }
            while(!minpq.empty() && minpq.top().index<left){
                minpq.pop();
            }
            if (maxpq.top().val <= limit + minpq.top().val)
            {
                result = max(result, i - left + 1);
                continue;
            }
            if (nums[i] == maxpq.top().val)
            {
                int low = nums[i] - limit;
                while (!minpq.empty() && minpq.top().val < low)
                {
                    left = max(left, minpq.top().index+1);
                    minpq.pop();
                }
                while (!minpq.empty() && minpq.top().index < left)
                {
                    minpq.pop();
                }
                if (minpq.empty())
                {
                    left = i;
                }
            }
            else
            {
                int high = nums[i] + limit;
                while (!maxpq.empty() &&
                       (maxpq.top().val > high))
                {
                    left = max(left, maxpq.top().index+1);
                    maxpq.pop();
                }
                while (!maxpq.empty() && maxpq.top().index < left)
                {
                    maxpq.pop();
                }
                if (maxpq.empty())
                {
                    left = i;
                }
            }
            result = max(result, i - left + 1);
            // cout << result << endl;
        }
        return result;
    }

private:
    struct Node
    {
        int val;
        int index;
        Node() = default;
        Node(int i, int j) : val(i), index(j) {};
        bool operator<(const Node &other) const
        {
            return val < other.val || (val == other.val && index < other.index);
        }
        bool operator>(const Node &other) const
        {
            return val > other.val || (val == other.val && index > other.index);
        }
    };
};
Solution soluter;
int main(){
    vector<int> nums = {1, 5, 6, 7, 8, 10, 6, 5, 6};
    cout<<soluter.longestSubarray(nums,4);
    return 0;
}