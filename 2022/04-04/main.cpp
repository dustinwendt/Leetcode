#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
};

ListNode* swapNodes(ListNode* head, int k){
  stack<ListNode*> stack;

  ListNode* temp = head;
  while(temp){
    stack.push(temp);
    temp = temp->next;
  }

  temp = head;
  ListNode* r = stack.top();
  while(k > 1){
    stack.pop();
    r = stack.top();
    temp = temp->next;
    --k;
  }

  int v = temp->val;
  temp->val = r->val;
  r->val = v;
  return head;
}

ListNode* ll(vector<int> v){
  if(v.empty()) return NULL;
  ListNode* head = new ListNode();
  head->val = v[0];
  ListNode* temp = head;
  for(int i=1; i<v.size(); ++i){
    ListNode* nex = new ListNode();
    nex->val = v[i];
    temp->next = nex;
    temp = nex;
  }

  return head;
}

bool llEq(ListNode* l1, ListNode* l2){
  if(!l1 && !l2) return true;
  if(!l1 || !l2 || l1->val != l2->val) return false;
  return llEq(l1->next, l2->next);
}

void freeMem(ListNode* t){
  while(t){
    ListNode* n = t->next;
    delete t;
    t = n;
  }
}


int main(){
  vector<vector<int>> tests = {{1,2,3,4,5}, {7,9,6,6,7,8,3,0,9,5}};
  vector<int> ks = {2, 5};
  vector<vector<int>> ans = {{1,4,3,2,5}, {7,9,6,6,8,7,3,0,9,5}};

  for(int i=0; i<tests.size(); ++i){
    ListNode* test = ll(tests[i]);
    ListNode* res = ll(ans[i]);
    assert(llEq(swapNodes(test, ks[i]) , res));
    cout << "Test Passed\n";

    freeMem(test);
    freeMem(res);
  }


  return 0;
}
