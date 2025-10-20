#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
class Solution{
public:
    int maxObjectCount(vector<int>& values,int sum){//test1
        sort(values.begin(),values.end());
        dfs(values,0,0,sum);
        return count;
    }
    int avgCPUload(vector<int>& cpu1,vector<int>& cpu2){//test2
        int n = cpu1.size();
        unordered_map<int,int> total_count;
        unordered_map<int,int> count1;
        for(int num:cpu1){
            count1[num]++;
        }
        for(int num:cpu2){
            total_count[num]++;
        }
        vector<int> in,out;
        for(auto [k,v]:count1){
            total_count[k]+=v;
        }
        for(auto [k,v]:total_count){
            if(v%2==1){
                return -1;
            }else{
                int v1 = v/2;
                int x = v1-count1[k];
                if(x>0){
                    for(int i=0;i<x;++i){
                        in.push_back(k);
                    }
                }else{
                    x=-x;
                    for(int i=0;i<x;++i){
                        out.push_back(k);
                    }
                }
            }
        }
        sort(in.begin(),in.end());
        sort(out.begin(),out.end(),std::greater<>());
        int result=0;
        n = in.size();
        for(int i=0;i<n;++i){
            result+=min(in[i],out[i]);
        }
        return result;
    }

    int maxValueInLimitCount(int n,vector<int>& values,vector<int>& weights,int m){//test3
        vector<Node> data;
        for(int i=0;i<n;++i){
            data.emplace_back(values[i],weights[i]);
        }
        sort(data.begin(),data.end());
        long long result = 0;
        const int MOD = 1E9+7;
        priority_queue<int> pq;
        long long tmp = 0;
        for(int i=0;i<m;++i){
            pq.push(data[i].weight);
            tmp+=data[i].weight;
        }
        result = max(result,tmp*data[m-1].val);
        for(int i=m;i<n;++i){
            int x = pq.top();
            if(x>=data[i].weight)continue;
            tmp-=x;
            pq.pop();
            pq.push(data[i].weight);
            tmp += data[i].weight;
            result = max(result, tmp * data[i].val);
        }
        return result;
    }
private:
    //index,cur_sum,count
    //cur_sum == sum
    int count=0;
    void dfs(vector<int>& values,int index,int cur_sum,int sum){
        if(cur_sum >= sum){
            if(cur_sum == sum){
                ++count;
            }
            return ;
        }
        for(int i=index;i<values.size();++i){
            if(i>index && values[i]==values[i-1])continue;
            cur_sum+=values[i];
            dfs(values,i+1,cur_sum,sum);
            cur_sum-=values[i];
        }
        return;
    }

    struct Node{
        int val;
        int weight;
        Node(int x,int y):val(x),weight(y){}
        bool operator<(const Node& other)const{
            return val<other.val;
        }
    };
};

int main(){
    Solution solver;
    string input1,input2;
    vector<int> cpu1,cpu2;
    getline(cin,input1);
    getline(cin, input2);
    string num;

    istringstream iss(input1);
    while(getline(iss,num,',')){
        cpu1.push_back(stoi(num));
    }

    iss.str(input2);
    iss.clear();
    while (getline(iss, num, ','))
    {
        cpu2.push_back(stoi(num));
    }

    cout<<solver.avgCPUload(cpu1,cpu2);
}