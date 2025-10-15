#include <bits/stdc++.h>
using namespace std;

pair<int,bool> lessLargeEle(vector<int>& nums){
    if(nums.size()<2){
        return {0,false};
    }
    int s1 = nums[0],s2=nums[1];
    if(s1<s2){
        swap(s1,s2);
    }
    int i=2;
    for(;i<nums.size();++i){
        if(nums[i]>s1){
            s2 = s1;
            s1 = nums[i];
        }else if(nums[i]>s2){
            s2 = nums[i];
        }
    }
    return {s2,true};
}

class BlackListMonitor{
public:
    static int id;
    void add_black_list(string entity_type,string entity_id){
        if(name_id.find(entity_id) == name_id.end()){
            name_id[entity_id] = id++;
            names.push_back(entity_id);
        }
        int cur_id = name_id[entity_id];
        if(entity_type == "user"){
            black_user.insert(cur_id);
        }else if(entity_type == "device"){
            black_device.insert(cur_id);
        }else {
            black_ip.insert(cur_id);
        }
        update_black(cur_id);
    }
    bool check_transaction(string user_id,string device_id,string ip){
        if(name_id.find(user_id)==name_id.end()){
            name_id[user_id]=id++;
        }
        if (name_id.find(device_id) == name_id.end())
        {
            name_id[device_id] = id++;
        }
        if (name_id.find(ip) == name_id.end())
        {
            name_id[ip] = id++;
        }
        int u_id = name_id[user_id], d_id = name_id[device_id], ip_id = name_id[ip];
        graph[u_id].emplace_back(1,d_id);
        graph[u_id].emplace_back(2, ip_id);
        graph[d_id].emplace_back(0,u_id);
        graph[d_id].emplace_back(2,ip_id);
        graph[ip_id].emplace_back(0,u_id);
        graph[ip_id].emplace_back(1,d_id);
        // blcak_user
        if(black_user.find(u_id)!=black_user.end()){
            update_black(u_id);
            return true;
        }
        // black_device
        if(black_device.find(d_id)!=black_device.end()){
            update_black(d_id);
            return true;
        }
        // black_ip
        if(black_ip.find(ip_id)!=black_ip.end()){
            update_black(ip_id);
            return true;
        }
        return false;
    }
private:
    unordered_map<string,int> name_id;
    unordered_map<int,vector<pair<int,int>>> graph;//0 user,1device , 2ip
    vector<string> names;
    set<int> black_user;
    set<int> black_device;
    set<int> black_ip;
    void update_black(int cur_id){
        deque<int> dq;dq.push_back(cur_id);
        while(!dq.empty()){
            int f = dq.front();dq.pop_front();
            for (auto &[type, tmp_id] : graph[f])
            {
                if (type == 0){
                    if(black_user.count(tmp_id)>0)continue;
                    black_user.insert(tmp_id);
                }

                if (type == 1){
                    if(black_device.count(tmp_id)>0)continue;
                    black_device.insert(tmp_id);
                }

                if (type == 2){
                    if(black_ip.count(tmp_id)>0)continue;
                    black_ip.insert(tmp_id);
                }
                dq.push_back(tmp_id);
            }
        }
    }
};
int BlackListMonitor::id = 0;
int main(){
    BlackListMonitor monitor;
    cout<<std::boolalpha<<monitor.check_transaction("u0","d0","ip0")<<endl;
    monitor.add_black_list("user","u0");
    cout<<monitor.check_transaction("u1","d0","ip2")<<endl;

    BlackListMonitor monitor2;
    cout<<monitor2.check_transaction("u0","d0","i0")<<endl;
    cout << monitor2.check_transaction("u1", "d0", "i1") << endl;
    cout << monitor2.check_transaction("u2", "d2", "i1") << endl;
    monitor2.add_black_list("user","u0");
    cout << monitor2.check_transaction("u3", "d2", "i3") << endl;
    return 0;
    vector<int> nums = {1};
    auto f = lessLargeEle(nums);
    if(f.second){
        cout<<f.first<<endl;
    }else{
        cout<<"no enough elements\n";
    }
}