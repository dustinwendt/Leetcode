#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void reverse(vector<T>& v, int l, int r){
  while(l < r){
    T temp = v[l];
    v[l] = v[r];
    v[r] = temp;
    ++l;
    --r;
  }
}

void nextPermutation(vector<int>& nums){
  int i = nums.size() - 2;

  while(i >= 0 && nums[i] >= nums[i+1]){
    --i;
  }

  if(i < 0){
    reverse(nums, 0, nums.size() - 1);
    return;
  }

  int j = nums.size() - 1;
  while(nums[j] <= nums[i]){
    --j;
  }

  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
  reverse(nums, i+1, nums.size() - 1);
}

bool vecEq(vector<int> a, vector<int> b){
  if(a.size() != b.size()) return false;
  for(int i=0; i<a.size(); ++i){
    if(a[i] != b[i]) return false;
  }
  return true;
}

int main(){
  vector<vector<int>> tests = {{1,2,3}
                               ,{3,2,1}
                               ,{1,1,5}
                               ,{1,3,2}};
  vector<vector<int>> ans = {{1,3,2}
                             ,{1,2,3}
                             ,{1,5,1}
                             ,{2,1,3}};

  for(int i=0; i<tests.size(); ++i){
    vector<int> test = tests[i];
    nextPermutation(test);
    assert(vecEq(test, ans[i]));
    cout << i << ": Test Passed\n";
  }
  return 0;
}
