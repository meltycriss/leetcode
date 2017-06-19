#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      // the original list may be unsorted
      sort(houses.begin(), houses.end());
      sort(heaters.begin(), heaters.end());
      // vSepPosHeaterPos[i] indicate interval's corresponding heater
      vector<pair<double, int> > vSepPosHeaterPos;
      for(int i=0; i<heaters.size(); ++i){
        pair<double, int> p;
        if(i+1<heaters.size()){
          p.first = (double(heaters[i]) + double(heaters[i+1]))/2;
          p.second = heaters[i];
        }
        else{
          p.first = INT_MAX;
          p.second = heaters[i];
        }
        vSepPosHeaterPos.push_back(p);
      }
      //for(int i=0; i<vSepPosHeaterPos.size(); ++i){
      //  pair<double, int> p = vSepPosHeaterPos[i];
      //  cout << p.first << " " << p.second << endl;
      //}
      int res = INT_MIN;
      int currIdx = 0;
      for(int i=0; i<houses.size(); ++i){
        double currSepPos = vSepPosHeaterPos[currIdx].first;
        int currHeaterPos = vSepPosHeaterPos[currIdx].second;
        int housePos = houses[i];
        if(housePos<currSepPos){
          int dis = abs(housePos - currHeaterPos);
          if(dis > res){
            res = dis;
          }
        }
        else{
          ++currIdx;
          --i;
        }
      }
      return res;
    }
};

int main(){
  vector<int> houses;
  houses.push_back(1);
  houses.push_back(2);
  houses.push_back(3);
  houses.push_back(4);
  vector<int> heaters;
  heaters.push_back(1);
  heaters.push_back(4);
  cout << Solution().findRadius(houses, heaters) << endl;
  return 0;
}
