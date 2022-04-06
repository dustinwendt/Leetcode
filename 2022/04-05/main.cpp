#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height){
  int l = 0;
  int r = height.size() - 1;
  int ans = INT_MIN;

  while(l < r){
    int w = r - l;
    int h = min(height[l], height[r]);
    ans = max(ans, w * h);

    if(height[l] < height[r]){
      ++l;
    } else if(height[r] < height[l]){
      --r;
    } else{
      ++l;
      --r;
    }
  }

    return ans;
}

int main(){
  vector<vector<int>> tests = {{1,8,6,2,5,4,8,3,7}, {1,1}};
  vector<int> ans = {49, 1};

  for(int i=0; i<tests.size(); ++i){
    assert(maxArea(tests[i]) == ans[i]);
    cout << "Test passed\n";
  }

  return 0;
}
