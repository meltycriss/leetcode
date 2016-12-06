#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      set<int> s(nums1.begin(), nums1.end());
      vector<int> res;
      for(int i=0; i<nums2.size(); ++i){
        set<int>::iterator it = s.find(nums2[i]);
        if(it != s.end()){
          res.push_back(nums2[i]);
          s.erase(it);
        }
      }
      return res;
    }
};
