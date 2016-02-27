#include<iostream>

using namespace std;

struct ListNode
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	//$$$其实只需要将下一节点的值赋给此节点，然后删除下一个节点即可！！
	//感谢 @戎烈锋 
	if(!node) return ;
	//assume that not the tail
	node->val = node->next->val;
	node->next = node->next->next;
}
/*
void deleteNode(ListNode* node) {
    if(!node) return;

    ListNode *tmp;
    while(node->next){
    	node->val = node->next->val;

    	tmp = node->next;
    	if(!tmp->next) {
    		//1 2 3 4 中的3，下一个就是tail了，可以直接删除 返回
    		//注意，删除节点应该按照标准来，前一个的next＝NULL
    		node->next = NULL;
    		return ;
    	}
    	node = node->next;
    }
    return;
}
*/
int main(){
	ListNode *list[4];
	list[0] = new ListNode(1);  
	list[1] = new ListNode(2);
	list[2] = new ListNode(3);
	list[3] = new ListNode(4);

	list[0]->next = list[1];
	list[1]->next = list[2];
	list[2]->next = list[3];
	
	ListNode *tmp = list[0];

	deleteNode(list[2]);
	while(tmp){
		cout<<tmp->val;
		tmp = tmp->next;
	}
}
