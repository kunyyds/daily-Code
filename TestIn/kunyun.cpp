#include <vector>
#include <string>
#include <iostream>
struct A{
    virtual std::string foo(){return "A";
    }
}
;
struct B : public A
{
    std::string foo() override { return s; }
    std::string s = "B";
};
struct C : public A{
              std::string foo() override{return "C";
}
}
;
const std::string& foo(const std::string& s){
    return s;
}
class rule1{
public:
    static bool check(const std::string& input){
        for(char c:input){
            if(c<'A' || c>'Z')return false;
        }
        return true;
    }
};
class rule2
{
public:
    static bool check(const std::string &input)
    {
        for (char c : input)
        {
            if (c < 'a' || c > 'z')
                return false;
        }
        return true;
    }
};
class rule3
{
public:
    static bool check(const std::string &input)
    {
        char f = input.front();
        if(f<'A' || f>'Z')return false;
        int i=0,n=input.length();
        for (i=1;i<n;++i)
        {
            char c = input[i];
            if (c < 'a' || c > 'z')
                return false;
        }
        return true;
    }
};
bool checkRules(const std::string& input){
    return rule1::check(input) ||
           rule2::check(input) ||
           rule3::check(input);
}
struct ListNode{
    int val;
    ListNode* next;
    ListNode() = default;
    ListNode(int x,ListNode* y=nullptr):val(x),next(y){}
};
ListNode* reverse(ListNode*& head){
    if(head == nullptr)return head;
    ListNode dummy(0),*prev = &dummy;
    prev->next = head;
    while(head->next){
        ListNode* cur = head->next;
        ListNode* nxt = cur->next;
        head->next = nxt;
        cur->next =  prev->next;
        prev->next = cur;
    }
    return dummy.next;
}
void printList(ListNode* head){
    while(head){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}
ListNode* reverseBetween(ListNode* head,int left,int right){
    // suppose the pos_index begin at 1;
    int i=0;
    ListNode dummy(-1,head),*prev = nullptr,*ruuner = &dummy;
    ListNode* start = nullptr,*end = nullptr;
    for(;i<left-1;++i){
        ruuner = ruuner->next;
    }
    prev = ruuner;
    start = ruuner->next;
    ruuner = start;
    for(;i<right-1;++i){
        ruuner = ruuner->next;
    }
    end = ruuner;
    ListNode* tmp = end->next;
    end->next = nullptr;
    ListNode* node = reverse(start);
    prev->next = node;
    start->next = tmp;
    return dummy.next;
}
int main()
{
    ListNode start(0);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);
    start.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    printList(&start);
    ListNode* head = &start;
    ListNode* new_s = reverseBetween(head,1,1);
    printList(new_s);
    return 0;
    std::string s = "NBA";
    std::cout<<std::boolalpha<<checkRules(s);
    return 0;
    std::string a;
    auto& f1 = foo(a);
    auto& f2 = foo("abv");
    std::cout<<f1<<std::endl<<f2<<std::endl;
    return 0;
    std::vector<A*> as;
    as.emplace_back( new A());
    as.emplace_back(new B());
    as.emplace_back(new C());
    // 结果应该是A, B,C
    std::cout << as[0]->foo() << ", " << as[1]->foo() << ", " << as[2]->foo()
              << std::endl;
    for(auto& p:as){
        delete p;
    }
    return 0;
}