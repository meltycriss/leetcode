class Solution {
  public:
    bool isVowels(char x){
      return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' ||
      x=='A' || x=='E' || x=='I' || x=='O' || x=='U');
    }
//    string reverseVowels(string s) {
//      int l = 0;
//      int r = s.size()-1;
//      string res = s;
//      reverseVowelsAux(res, l, r);
//      return res;
//    }
//    void reverseVowelsAux(string &s, int l, int r){
//      if(l>=r){
//        return;
//      }
//      int left=r;
//      int right=l;
//      for(int i=l; i<r; ++i){
//        if(isVowels(s[i])){
//          left = i;
//          break;
//        }
//      }
//      for(int i=r; i>l; --i){
//        if(isVowels(s[i])){
//          right = i;
//          break;
//        }
//      }
//      if(left < right){
//        char temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        reverseVowelsAux(s, left+1, right-1);
//      }
//      else{
//        return;
//      }
//    }

    string reverseVowels(string s) {
      int l = 0;
      int r = s.size()-1;
      while(l<r){
        while(!isVowels(s[l]) && l<r) ++l;
        while(!isVowels(s[r]) && l<r) --r;
        if(l<r){
          char temp = s[l];
          s[l] = s[r];
          s[r] = temp;
          ++l;
          --r;
        }
      }
      return s;
    }
};

