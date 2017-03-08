#include <stack>
using namespace std;
class MyQueue {
  public:
    stack<int> in;
    stack<int> out;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
      while(!out.empty()){
        int temp = out.top();
        out.pop();
        in.push(temp);
      }
      in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int res;
      while(!in.empty()){
        int temp = in.top();
        in.pop();
        out.push(temp);
      }
      res = out.top();
      out.pop();
      return res;
    }

    /** Get the front element. */
    int peek() {
      while(!in.empty()){
        int temp = in.top();
        in.pop();
        out.push(temp);
      }
      return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
