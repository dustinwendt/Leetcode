#include "KthLargest.h"

using namespace std;

KthLargest::KthLargest(int k, vector<int>& nums){
  this->k = k;
  for(auto n: nums){
    pq.push(n);
  }

  while((int)pq.size() > k){
    pq.pop();
  }
}

int KthLargest::add(int val){
  if((int)pq.size() < k){
    pq.push(val);
  } else if(val > pq.top()){
    pq.pop();
    pq.push(val);
  }

  return pq.top();
}
