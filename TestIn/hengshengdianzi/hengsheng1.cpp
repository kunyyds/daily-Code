#include <numeric>
#include <limits>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAXNUM = 1000000;
vector<int> min_prime(MAXNUM+1,0);
void pre_compute(){
    for(int i=2;i<=MAXNUM;++i){
        if(min_prime[i] == 0){
            min_prime[i] = i;
            if((long long)i*i<=MAXNUM){
                for(int j=i*i;j<=MAXNUM;j+=i){
                    if(min_prime[j]==0)
                        min_prime[j] = i;
                }
            }
        }
    }
}
long long get_mask(int n){
    if(n==1)return 0;
    long long mask = 0;
    while(n>1){
        int p = min_prime[n];
        int count = 0;
        while (n % p == 0)
        {
            ++count;
            n /= p;
        }

        if(count%2==1){
            mask ^=1LL << (p%60);
        }
    }
    return mask;
}
int maxLen(vector<int>& nums){
    int n = nums.size();
    unordered_map<long long, int> mask_pos;
    mask_pos[0]=-1;
    vector<long long> masks(n,0);
    for(int i=0;i<n;++i){
        masks[i] = get_mask(nums[i]);
    }
    int result = 0;
    long long mask = 0;
    for(int i=0;i<n;++i){
        mask^=masks[i];
        if(mask_pos.find(mask)!=mask_pos.end()){
            result = max(result,i-mask_pos[mask]);
        }else{
            mask_pos[mask] = i;
        }
    }
    return result;
}
int main(){
    // 预计算最小质因数
    pre_compute();

    // 测试案例
    vector<int> test1 = {1, 4, 3, 12, 9};
    cout << "测试案例1最长长度: " << maxLen(test1) << endl; // 应该输出4

    vector<int> test2 = {2, 3, 5, 6, 7};
    cout << "测试案例2最长长度: " << maxLen(test2) << endl; // 应该输出1

    vector<int> test3 = {1, 1, 1, 1};
    cout << "测试案例3最长长度: " << maxLen(test3) << endl; // 应该输出4

    return 0;
}