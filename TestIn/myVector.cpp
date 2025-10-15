#include <iostream>
using namespace std;

template<typename T>
class Vector{
public:
    Vector(int s){
        capacity = s>1 ? s:1;
        data = new T[capacity];//(T*) malloc(capacity* sizeof(T))
        //fill
    }
    Vector() = default;
    Vector(const Vector<T>& other){
        if(data)delete[]data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for(int i=0;i<size;++i){
            data[i] = other.data[i];
        }
    }
    // Vector& push(T ele){
    //     ++size;
    //     if(size>capacity){
    //         capacity = capacity*2;
    //         T* old = data;
    //         // delete []data;
    //         data = new T[capacity];
    //         for(int i=0;i<size-1;++i){
    //             data[i] = old[i];
    //         }
    //         delete []old;
    //     }
    //     data[size-1] = ele;
    //     return *this;
    // }
    template<typename U>
    Vector& push(U&& ele){
        ++size;
        if (size > capacity)
        {
            capacity = capacity * 2;
            T *old = data;
            // delete []data;
            data = new T[capacity];//malloc
            for (int i = 0; i < size - 1; ++i)
            {
                data[i] = old[i];
            }
            delete[] old;
        }
        data[size - 1] = std::forward<U>(ele);
        //placement new
        
        return *this;
    }
    T& operator[](int x){
        if(x>=size){

        }
        return data[x];
    }
    ~Vector(){
        if(data)delete []data;
    }
    void print(){
        for(int i=0;i<size;++i){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
private:
    T*data=nullptr;
    int size=0;
    int capacity=1;
};
struct Node{
    int val;
    Node() = delete;
    Node(int x):val(x){};
};
int main(){
    // Vector<int> nums(2);
    // nums.push(0);
    // nums.push(1);
    // nums.print();
    // nums.push(2);
    // nums.print();
    // nums[0]=3;
    // nums.print();
    Vector<int> nums2(3);
    nums2.push(1);
    nums2.push(4);
    nums2.push(5);
    Vector<int> nums3(nums2);
    nums3.print();

    Vector<Node> nums4();

    return 0;
}