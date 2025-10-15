#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int gcd(int y,int x){
    if(x!=0){
        y = x;
        x = y%x;
        return gcd(y,x);
    }else{
        return y;
    }
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    vector<vector<bool>> map(n+1,vector<bool>(m+1,false));
    vector<pair<int,int>> points;
    unordered_set<double> direct;
    for(int i=0;i<k;++i){
        cin>>x>>y;
        map[x][y]=true;
        points.push_back({x,y});
    }
    double ref_dir = (double)m/n;
    double epsilon = 0.0000001;
    int max_result = 0;
    for(auto p:points){
        double dir = p.second*1.0/p.first; //y/x
        if(direct.find(dir)!=direct.end()){
            continue;
        }
        direct.insert(dir);

        int stepx = p.first;
        int stepy = p.second;
        if(stepy<stepx){
            swap(stepx,stepy);
        }
        int pub_ele = gcd(stepy,stepx);
        stepx /=pub_ele;
        stepy /=pub_ele;
        int nx = 0,ny = 0;
        int result = 0;
        do{
            nx+=stepx;
            ny+=stepy;
            if(map[nx%(n+1)][ny%(m+1)]){
                ++result;
            }
        } while (nx % n != 0 && ny % m != 0);
        max_result = max(result, max_result);
    }
    cout<<max_result;
    return 0;
}