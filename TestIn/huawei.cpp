#include<bits/stdc++.h>
using namespace std;
int mineditLenght(const string& a,const string& b){
    int x = a.size(), y = b.size();
    vector<vector<int>> t(x + 1, vector<int>(y + 1));
    for (int i = 0; i <= x; i++)
        t[i][0] = i;
    for (int j = 0; j <= y; j++)
        t[0][j] = j;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            t[i][j] = min({t[i - 1][j] + 1, t[i][j - 1] + 1, t[i - 1][j - 1] + cost});
        }
    }
    return t[x][y];
}

int main(){
    unordered_map<string,int> name_val;
    unordered_map<string, int> name_id;
    unordered_map<int ,string> val_name;
    int n;
    cin>>n;
    vector<string> names(n);
    string tmp_name;int tmp_val;
    for(int i=0;i<n;++i){
        cin>>tmp_name>>tmp_val;
        name_val[tmp_name] = tmp_val;
        name_id[tmp_name] = i;
        names[i] = tmp_name;
        // val_name[tmp_val] = tmp_name;
    }
    int m;
    cin>>m;
    unordered_map<int,vector<int>> graph;
    string node1,node2;
    for(int i=0;i<m;++i){
        cin>>node1>>node2;
        int id1 = name_id[node1];
        int id2 = name_id[node2];
        graph[id1].push_back(id2);
        graph[id2].push_back(id1);
    }
    string maxNodeName;
    int maxSum=0;
    unordered_set<int> visit;

    for(auto& [name,id]:name_id){
        if(visit.count(id)==0){
            int sum = 0;
            int maxVal = 0;
            int maxValID = -1;
            deque<int> dq;
            dq.push_back(id);
            visit.insert(name_id[name]);
            while(!dq.empty()){
                int f = dq.front();dq.pop_front();
                int val =name_val[names[f]];
                sum+=val;
                if(val>maxVal){
                    maxValID = f;
                    maxVal = val;
                }
                for(int nxt:graph[f]){
                    if(visit.count(nxt)==0){
                        dq.push_back(nxt);
                        visit.insert(nxt);
                    }
                }
            }
            if(sum>maxSum){
                maxSum = sum;
                maxNodeName = names[maxValID];
            }
        }
    }
    cout<<maxNodeName<<" "<<maxSum<<endl;
    return 0;
}