#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
      int res = 0;
      for(int i=0; i<points.size(); ++i){
        pair<int, int> currPoint = points[i];
        unordered_map<int, int> mapDistCount;
        for(int j=0; j<points.size(); ++j){
          if(j!=i){
            pair<int, int> tempPoint = points[j];
            int dist = distSquare(currPoint, tempPoint);
            if(mapDistCount.find(dist)!=mapDistCount.end()){
              ++mapDistCount[dist];
            }
            else{
              mapDistCount[dist] = 1;
            }
          }
        }
        unordered_map<int, int>::iterator it = mapDistCount.begin();
        while(it!=mapDistCount.end()){
          int count = it->second;
          if(count > 1){
            res += count * (count-1);
          }
          ++it;
        }
      }
      return res;
    }
    int distSquare(const pair<int, int> &x, const pair<int, int> &y){
      int xx = x.first - y.first;
      int yy = x.second - y.second;
      return xx*xx + yy*yy;
    }
};

