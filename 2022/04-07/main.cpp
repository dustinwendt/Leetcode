#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones){
  priority_queue<int> pq;

  for(auto s: stones){
    pq.push(s);
  }

  while(pq.size() > 1){
    int y = pq.top();
    pq.pop();
    int x = pq.top();
    pq.pop();

    if(x != y){
      pq.push(y - x);
    }
  }

  return pq.empty() ? 0 : pq.top();
}

int main(){
  vector<vector<int>> tests = {{2,7,4,1,8,1}, {1}};
  vector<int> ans = {1, 1};

  for(int i=0; i<tests.size(); ++i){
    assert(lastStoneWeight(tests[i]) == ans[i]);
    cout << "Test passed\n";
  }

  return 0;
}
