#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> mpPtn;
        map<string, int> mpStr;
        string space = " ";
        int strBegin = 0;
        int counter = 0;
        for(int i=0; i<pattern.size(); ++i){
            char cPtn = pattern[i];
            if(strBegin == string::npos){
                return false;
            }
            string sStr = str.substr(strBegin, str.find_first_of(space, strBegin)-strBegin);
            strBegin = str.find_first_not_of(space, str.find_first_of(space, strBegin));
            if(mpPtn.count(cPtn)==0 && mpStr.count(sStr)==0){
                mpPtn[cPtn] = counter;
                mpStr[sStr] = counter;
                ++counter;
            }
            if(mpPtn.count(cPtn)==0 || mpStr.count(sStr)==0){
                return false;
            }
            if(mpPtn[cPtn]!=mpStr[sStr]){
                return false;
            }
        }
        //different length
        return strBegin==string::npos;
    }
};

