#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int>& tree,int index,int cc){
    if(index>=tree.size() || tree[index] == 0){
        return;
    }
    int left = 2*(index+1)-1;
    int right = 2*(index+1);
    int tmp=cc+tree[index]-1;
    tree[index] = tmp%5+1;
    dfs(tree,left,cc);
    dfs(tree,right,cc);
}
int main()
{
    int n;
    cin>>n;
    vector<int> tree(n,0);
    vector<int> ref(n,0);
    for(int i=0;i<n;++i){
        cin>>tree[i];
    }
    for(int i=0;i<n;++i){
        cin>>ref[i];
    }
    int result=0;
    for(int i=0;i<n;++i){
        if(tree[i] == 0)continue;
        int cc = ref[i]-tree[i];
        if(cc<0)cc+=5;
        if(cc==0)continue;
        result+=cc;
        //update;
        dfs(tree,i,cc);
    }
    cout<<result<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")