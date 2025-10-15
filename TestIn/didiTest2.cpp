#include <iostream>
#include <vector>
// #include <set>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;++i){
        int n;
        cin>>n;
        vector<vector<int>> map(n+1);
        map[0].push_back(1);
        int num;
        for(int i=2;i<=n;++i){
            cin>>num;
            map[num].push_back(i);
        }
        vector<int> vcount;
        for(int i=0;i<=n;++i){
            if(!map[i].empty()){
                vcount.push_back(map[i].size());
            }
        }
        sort(vcount.begin(),vcount.end());
        int ref = vcount.size();

        for(int i=0;i<ref;++i){
            vcount[i] -=i+1;
        }
        int add = 0;
        int tmp = 0;
        bool finish = false;
        while(true){
            for(int i=0;i<ref;++i){
                tmp+=max(vcount[i],0);
                --vcount[i];
            }
            if(tmp==0 || tmp <= add)break;
            ++add;
        }
        cout<<ref+add<<endl;
    }
    return 0;
}