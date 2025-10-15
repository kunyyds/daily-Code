#include <string>
using namespace std;

class Solution{
public:
    int count(string& str){
        int res = 0;
        int n = str.length();
        for(int i=0;i<n;++i){
            res+=check(str,i);
        }
        return res;
    }
private:
    int check(string& str, int index){
        if(str.length()<=1)return 0;
        if(index == 0){
            if( str[1]==str[index]){
                return 1;
            }
            return 0;
        }
        if(index == str.length()-1){
            if( str[str.length()-2] == str[index]){
                return 1;
            }
            return 0;
        }
        char c0 = str[index];
        char c1 = str[index-1];
        char c2 = str[index+1];

        int res = 0;
        if(c1==c2)++res;
        if(c0 == c1)++res;
        if(c0 == c2)++res;
        return res;
    }
};