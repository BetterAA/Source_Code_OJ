#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
     //典型的floyd判环  快慢指针 龟兔赛跑指针
	 ListNode* slow = head;
	 ListNode* fast;
	 if(head->next && head->next->next) fast = head->next->next;
	 else return false;
	 while(fast&&slow){
	 	if(fast==slow) return true;
	 	slow = slow->next;
	 	if(fast->next) fast = fast->next->next;
	 	else return false;
	 }
	 return false;
}

int main(int argc, char const *argv[])
{
	ListNode* list[5] ;
	list[0] = new ListNode(0);
	list[1] = new ListNode(1);
	list[2] = new ListNode(2);
	list[3] = new ListNode(3);	
	list[4] = new ListNode(4);
	list[0]->next = list[1];
	list[1]->next = list[2];
	list[2]->next = list[3];
	list[3]->next = list[4];
	list[4]->next = list[2];

	cout<<hasCycle(list[0]);
	/* code */
	return 0;
}