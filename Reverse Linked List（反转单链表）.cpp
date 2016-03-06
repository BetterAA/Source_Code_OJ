#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode* reverseList(ListNode* head) {
	if(!head) return NULL;
	ListNode* tail = NULL, *newHead = NULL;
	///!!!!!!!!!!!!!!!!!!!!!!
	//盲区：！！  tail= head;意味着两个是一个东西，所以如果改变tail相当于改变head！！
	//就像newHead = head->next;	 newHead->next = tail;这句，其实也就是改了head－》next－》next！！
	//重点在下边这句
	//所以链表操作应该写成 a＝b；b＝c；c＝d这种的！！
	while(head){
		 newHead = head->next;
		 head->next = tail;
		 tail = head;
		 head = newHead;
	}
	return  tail;   
}
int main(){
	ListNode *list[4];
	list[0] = new ListNode(1);  
	list[1] = new ListNode(2);
	list[2] = new ListNode(3);
	list[3] = new ListNode(4);

	list[0]->next = list[1];
	list[1]->next = list[2];
	list[2]->next = list[3];
	
	ListNode *tmp = reverseList(list[0]);
	while(tmp){
		cout<<tmp->val;
		tmp = tmp->next;
	}
}