#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    static const int N = 10;
    vector<string> readBinaryWatch(int num) {
      vector<string> res;
      vector<int> comb = getComb(num);
      for(int i=0; i<comb.size(); ++i){
        string s = bin2Time(comb[i]);
        if(s.size()>0) res.push_back(s);
      }
      return res;
    }

    vector<int> getComb(int m){
      vector<int> res;
      //m = 0
      if(m==0){
        res.push_back(0);
        return res;
      }
      int curr = (1<<m) - 1;
      while(curr < (1<<N)){                     //110011100 -> 110100011
        res.push_back(curr);                    //curr    = 110011100
        int lastOne = curr & (-curr);           //lastOne = 000000100
        int carry = lastOne + curr;             //carry   = 110100000
        int oneInterval = (~carry) & curr;      //interv  = 000011100
        int minusOne = (oneInterval / lastOne) >> 1; //m1 = 000000011
        curr = carry + minusOne;
      }
      return res;
    }

    string bin2Time(int i){
      string res;
      stringstream ss;
      int hour = i >> 6;
      int minute = i & ((1<<6) -1);
      if(hour<12 && minute<60){
        //ss.clear(), ss.flush() are wrong, should be ss.str("")
        ss.str("");
        ss << hour;
        string strHour = ss.str();
        ss.str("");
        ss << minute;
        string strMinute = ss.str();
        if(strMinute.size()<2) strMinute.insert(0, "0");
        res = strHour + ":" + strMinute;
      }
      return res;
    }
};

int main(){
  vector<string> v = Solution().readBinaryWatch(1);
  for(int i=0; i<v.size(); ++i){
    cout << v[i] << endl;
  }
  return 0;

}
