#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      sort(ransomNote.begin(), ransomNote.end());
      sort(magazine.begin(), magazine.end());
      cout<<ransomNote<<endl;
      cout<<magazine<<endl;
      bool res = ransomNote.size()==0? true:false;
      for(int idxRN=0, idxMag=0; idxRN<ransomNote.size(); ++idxRN, ++idxMag){
        idxMag = magazine.find(ransomNote[idxRN], idxMag);
        if(idxMag==string::npos) break;
        if(idxRN==ransomNote.size()-1) res = true;
      }
      return res;
    }
};


int main(){
  string rn = "fihjjjjei";
  string mag = "hjibagacbhadfaefdjaeaebgi";
  cout << Solution().canConstruct(rn, mag);
  return 0;
}
