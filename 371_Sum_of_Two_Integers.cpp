#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
    	int sum = a^b;
    	int carry = (a&b) << 1;
    	if(carry) return getSum(sum, carry);
    	else return sum;
    }
};

int main(){
	cout << Solution().getSum(10,50) << endl;
	return 0;
}