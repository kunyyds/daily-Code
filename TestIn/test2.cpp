#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int a,b,s;
    cin>>a>>b>>s;
    int n;
    cin>>n;
    vector<int> len1(n,0);
    vector<int> len2(n,0);
    int tt = 0;
    for(int i=0;i<n;++i){
        cin>>len1[i];
        tt+=len1[i];
    }
    for(int i=0;i<n-1;++i){
        cin>>len2[i];
        tt+=len2[i];
    }
    int sum = a+b*(tt-s);
    int add = a-b*s;
    int cur = 0;
    for(int i=0;i<n-1;++i){
        cur+=len1[i];
        int d = len2[i];
        if(cur<a){
            d-=a-cur;
        }
        int tmp = sum;
        sum-=b*d;
        sum+=add;
        if(sum>tmp){
            sum = tmp;
            cur+=len2[i];
        }else{
            cur = 0;
        }
    }
    cout<<sum<<endl;
    return 0;
}