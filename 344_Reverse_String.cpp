#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
    	string res = s;
    	int head = 0, tail = res.size() - 1;
    	while(head < tail){
    		char temp =  res[head];
    		res[head++] = res[tail];
    		res[tail--] = temp;

    	}
    	return res;
    }
};

int main(){
	string s = "hello";
	string res = Solution().reverseString(s);
	cout << res << endl;
	return 0;
}