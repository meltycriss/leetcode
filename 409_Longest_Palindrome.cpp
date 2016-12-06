#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      int res = 0;
      map<char, int> mp;
      for(int i=0; i<s.size(); ++i){
        char c = s[i];
        if(mp.find(c)==mp.end()){
          mp[c] = 1;
        }
        else{
          ++mp[c];
        }
      }
      map<char, int>::const_iterator it = mp.begin();
      bool hasOdd = false;
      while(it!=mp.end()){
        int val = it->second;
        if(val & 1){
          hasOdd = true;
          res += val-1;
        }
        else{
          res += val;
        }
        ++it;
      }
      if(hasOdd){
        ++res;
      }
      return res;
    }
};

int main(){


  string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

  cout << Solution().longestPalindrome(s) << endl;
  return 0;
}
