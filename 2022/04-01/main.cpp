#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(string& s){
  int l = 0;
  int r = s.size() - 1;
  while(l < r){
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    ++l;
    --r;
  }
}

int main(){
  vector<string> v = {"hello", "Hannah"};
  vector<string> a = {"olleh", "hannaH"};

  for(int i=0; i<v.size(); ++i){
    string s = v[i];
    reverseString(s);
    assert(s == a[i]);
    cout << "Correct\n";
  }
  return 0;
}
