#ifndef KTH_LARGEST_H
#define KTH_LARGEST_H

#include <queue>
#include <vector>

using namespace std;

class KthLargest{
 private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

 public:
  KthLargest(int k, vector<int>& nums);

  int add(int val);
};

#endif
