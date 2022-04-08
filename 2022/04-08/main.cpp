#include <cassert>
#include <cstdio>
#include <vector>

#include "KthLargest.h"

using namespace std;

int main(){
  vector<vector<int>> streams = {{4,5,8,2}};
  vector<int> ks = {3};
  vector<vector<int>> adds = {{3,5,10,9,4}};
  vector<vector<int>> ans = {{4,5,5,8,8}};

  for(int i=0; i<(int)streams.size(); ++i){
    printf("Test %d: ", i);
    KthLargest data = KthLargest(ks[i], streams[i]);

    for(int j=0; j<(int)adds[i].size(); ++j){
      assert(data.add(adds[i][j]) == ans[i][j]);
    }
    printf("Passed\n");
  }

  return 0;
}
