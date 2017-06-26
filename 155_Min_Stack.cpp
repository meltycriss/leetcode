#include <stack>
using namespace std;

class MinStack {
private:
  stack<long long> stk;
  long long min;

public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
      if(stk.empty()){
        stk.push(0);
        min = x;
      }
      else{
        stk.push(x-min);
        if(x<min){
          min = x;
        }
      }
    }
    
    void pop() {
      long long tmp = stk.top();
      stk.pop();
      if(tmp<0){
        min -= tmp;
      }
    }
    
    int top() {
      if(stk.top()>=0){
        return int(stk.top()+min);
      }
      else{
        return int(min);
      }
    }
    
    int getMin() {
      return int(min);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(){
  
}
