#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string lhs, string rhs) {
      pair<int, int> factorsA = extractFactors(lhs);
      pair<int, int> factorsB = extractFactors(rhs);
      int a = factorsA.first, b = factorsA.second, c = factorsB.first, d = factorsB.second;
      int x = a*c-b*d, y = a*d+b*c;
      string res = buildComplexNumber(x, y);
      return res;
    }

    pair<int, int> extractFactors(string s){
      int a = stoi(s.substr(0, s.find('+')));
      int b = stoi(s.substr(s.find('+')+1, s.find('i')-s.find('+')-1));
      return make_pair(a,b);
    }

    string buildComplexNumber(int a, int b){
      string res = to_string(a) + "+" + to_string(b) + "i";
      return res;
    }
};

int main(){
  cout << Solution().complexNumberMultiply("1+1i", "1+1i") << endl;
  return 0;
}
