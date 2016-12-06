#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int x = nums[0];
    	for(int i=1; i<nums.size(); ++i){
    		x = x ^ nums[i];
    	}
    	return x;
    }
};

int main(){
	vector<int> v;
	for(int i=0; i<2; ++i){
		for(int j=0; j<5; ++j){
			v.push_back(j);
		}
	}
	v.push_back(5);
	int x = Solution().singleNumber(v);
	cout << x << endl;
	return 0;
}