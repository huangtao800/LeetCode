#include <list>
#include <iostream>
#include <climits>
using namespace std;

class MinStack {

private:
    list<int> l;
    int min;
public:
    MinStack():min(INT_MAX){}
    void push(int x) {
        l.push_front(x); 
        if(x < min){
            min = x;
        }
    }

    void pop() {
        int t = top();
        l.pop_front();
        if(t==min){
            min = INT_MAX;
            list<int>::iterator it = l.begin();
            for(;it!=l.end();it++){
                if(*it < min){
                    min = *it;
                }
            }
        }
    }

    int top() {
        return l.front();
    }

    int getMin() {
        return min;
    }
};

int main(){
    MinStack m;
    m.push(2);
    m.push(0);
    m.push(3);
    m.push(0);

    m.pop();
    m.pop();
    cout << m.getMin()<< endl;
    m.pop();
    cout << m.getMin()<< endl;
    return 0;
}