#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

long nChoosek(int n, int k){
  long ans = 1;
  for(int i=1; i<=k; ++i){
    ans *= (n - i + 1);
    ans /= i;
  }

  return ans;
}

int threeSumMulti(vector<int>& arr, int target){
  int MOD = 1e9+7;
  int count[101] = {0};

  for(auto i: arr){
    count[i]++;
  }

  long ans = 0;
  for(int i=0; i<=100; ++i){
    for(int j=i; j<=100; ++j){
      int v = target - (i + j);
      if(v < j) break;
      if(v > 100) continue;

      int n = count[j];
      if(i == v && v == j){
        ans += nChoosek(n, 3);
      } else if(v == j){
        ans += nChoosek(n, 2) * count[i];
      } else if(i == j){
        ans += nChoosek(n, 2) * count[v];
      } else{
        ans += count[i] * count[j] * count[v];
      }

      ans %= MOD;
    }
  }

  return ans;
}


int main(){
  vector<int> bigVec = {92,4,59,23,100,16,7,15,3,78,98,17,77,33,83,15,87,35,54,72,58,14,87,47,58,31,72,58,87,22,25,54,27,53,13,54,61,12,96,24,35,43,94,1,88,76,89,89,41,56,61,65,60,91,89,79,86,52,27,2,97,46,50,46,87,93,71,87,95,78,65,10,35,51,34,66,61,7,49,38,10,1,88,37,50,84,35,20,7,83,51,85,11,12,89,93,54,23,36,95,100,19,82,67,96,77,53,56,51,16,54,7,30,68,78,13,38,52,91,44,54,17,21,44,4,10,85,19,11,88,73,36,47,53,3,21,41,24,60,53,88,35,48,89,35,3,43,85,45,67,56,78,44,49,29,35,68,96,29,21,51,17,52,99,3,48,65,51,22,38,77,81,30,64,99,35,88,72,73,29,29,2};
  vector<vector<int>> tests = {{1,1,2,2,3,3,4,4,5,5}, {1,1,2,2,2,2}, bigVec};
  vector<int> targets = {8, 5, 105};
  vector<int> ans = {20, 12, 5166};

  for(int i=0; i<tests.size(); ++i){
    int test = threeSumMulti(tests[i], targets[i]);
    assert(test == ans[i]);
    printf("%d  == %d\n", test, ans[i]); 
  }
  return 0;
}
