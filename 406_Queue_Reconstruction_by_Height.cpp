#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
      vector<pair<int, int> > res = people;
      
      sort(res.begin(), res.end(), Solution::heightDecrease);
      for(int i=0; i<res.size(); ++i){
        int j=i;
        while(res[j].first == res[i].first){
          ++j;
        }
        sort(res.begin()+i, res.begin()+j, Solution::kIncrease);
      }
      for(int i=0; i<res.size(); ++i){
        if(i!=res[i].second){
          pair<int, int> tmp = res[i];
          res.erase(res.begin()+i);
          res.insert(res.begin()+tmp.second, tmp);
        }
      }
      return res;
    }

    static bool heightDecrease(pair<int, int> lhs, pair<int, int> rhs){
      return lhs.first > rhs.first;
    }
    
    static bool kIncrease(pair<int, int> lhs, pair<int, int> rhs){
      return lhs.second < rhs.second;
    }
};

int main(){
  vector<pair<int, int> > people;
  pair<int, int> p = make_pair(7,0);
  people.push_back(p);
  p = make_pair(4,4);
  people.push_back(p);
  p = make_pair(7,1);
  people.push_back(p);
  p = make_pair(5,0);
  people.push_back(p);
  p = make_pair(6,1);
  people.push_back(p);
  p = make_pair(5,2);
  people.push_back(p);
  vector<pair<int, int> > res = Solution().reconstructQueue(people);
  for(int i=0; i<res.size(); ++i){
    cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
