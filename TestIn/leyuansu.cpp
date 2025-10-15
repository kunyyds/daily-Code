#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getTime(int task_count,vector<int>& durations,vector<vector<int>>& dependecies,int worker_count){
        vector<int> indim(task_count,0);
        for(int i=0;i<task_count;++i){
            for(int j=0;j<task_count;++j){
                if(dependecies[i][j]==1){
                    indim[j]+=1;
                }
            }
        }

        vector<int> task_start_time(task_count,0);
        vector<int> task_end_time(task_count,0);
        vector<int> worker_time(worker_count,0);
        priority_queue<Node> pq;
        for(int i=0;i<task_count;++i){
            if(indim[i]==0){
                pq.emplace(i,durations[i]);
            }
        }
        while(!pq.empty()){
            Node f = pq.top();
            pq.pop();
            //woker
            int min_worker = 0;
            for(int i=1;i<worker_count;++i){
                if(worker_time[i]<worker_time[min_worker]){
                    min_worker = i;
                }
            }
            int start_time = max(worker_time[min_worker],task_start_time[f.index]);
            int end_time = start_time+durations[f.index];

            worker_time[min_worker] = end_time;
            task_end_time[f.index] = end_time;

            for(int j=0;j<task_count;++j){
                if(dependecies[f.index][j]){
                    task_start_time[j] = max(task_start_time[j],end_time);
                    indim[j]--;
                    if(indim[j]==0){
                        pq.emplace(j,durations[j]);
                    }
                }
            }
        }
        int result=0;
        for(int j=0;j<task_count;++j){
            result = max(result,task_end_time[j]);
        }
        return result;
    }
private:
    struct Node{
        int index;
        int time;
        Node(int x,int y):index(x),time(y){}
        bool operator<(const Node& other)const{
            return time>other.time;
        }
    };
};