#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
bool check(int num,int k){
    int cur1 = num%k;
    num/=k;
    if(num==0)return true;
    int cur2 = num%k;
    num/=k;
    if(cur1==cur2)return false;
    int cur = cur1, ref = cur1+cur2;
    while(num>0){
        int last = num%k;
        if(last!=cur){
            return false;
        }else{
            cur = ref-cur;
        }
        num/=k;
    }
    return true;
}
int main(){
    // cout<<std::boolalpha<<check(300,13);
    // return 0;
    int a,b,l,r,k;
    cin>>a>>b>>l>>r>>k;
    int n = r-l+1;
    int m = b-a+1;
    vector<vector<bool>> data(n,vector<bool>(m,false));
    vector<int> result;
    ostringstream oss;
    for(int i=l;i<=r;++i){
        for(int j=a;j<=b;++j){
            data[i-l][j-a]=check(i,j);
        }
        int tmp=0;
        for(int j=0;j<m;++j){
            if(data[i-l][j])++tmp;
        }
        if(tmp==k){
            // result.push_back(i);
            oss<<i<<'\n';
        }
    }
    cout<<oss.str();
    return 0;
}