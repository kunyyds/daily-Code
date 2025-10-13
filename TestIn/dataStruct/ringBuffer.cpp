#include <iostream>
#include <utility>
template<typename T>
class RingBuffer{
public:
    RingBuffer(int s):capacity(s){
        if(capacity<=0)capacity = 1;
        buffer = new T[capacity];
        head=0;
        tail=0;
        std::cout<<"init capcity="<<capacity<<std::endl;
    }
    std::pair<T,int> getElement(int index){
        if((tail>head && index>tail)
        || index<0 || index>=capacity){
            return {T(),0};
        }
        return {buffer[(index+head)%capacity],1};
    }
    /*
    RingBuffer& putElement(T&& ele){
        buffer[tail] = std::forward<T>(ele);
        int nxtPos = (tail+1)%capacity;
        if(nxtPos==head)head = (head+1)%capacity;
        tail = nxtPos;
        return *this;
    }

    RingBuffer &putElement(const T& ele)
    {
        buffer[tail] = std::forward<T>(ele);
        int nxtPos = (tail + 1) % capacity;
        if (nxtPos == head)
            head = (head + 1) % capacity;
        tail = nxtPos;
        return *this;
    }
        */
    template<typename U>
    RingBuffer& putElement(U&& ele){
        buffer[tail] = std::forward<U>(ele);
        int nxtPos = (tail + 1) % capacity;
        if (nxtPos == head)
            head = (head + 1) % capacity;
        tail = nxtPos;
        return *this;
    }
    void print(){
        for(int i=head;i!=tail;i=(i+1)%capacity){
            std::cout<<buffer[i]<<" ";
        }
        std::cout<<std::endl;
    }
private:
    T* buffer=nullptr;
    int capacity=0;
    int head = 0;//当前有效元素的第一个
    int tail = 0;//下一个可以放元素的位置
};

int main(){
    RingBuffer<int> buffer(5);
    for(int i=0;i<10;++i){
        buffer.putElement(i);
        buffer.print();
    }
    std::cout<<buffer.getElement(0).first<<std::endl;
    return 0;
}