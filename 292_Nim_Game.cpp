#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return !(n%4 == 0);
        //return !(n&3)
    }
};

int main(){
	bool res = Solution().canWinNim(5);
	cout << res << endl;
	return 0;
}