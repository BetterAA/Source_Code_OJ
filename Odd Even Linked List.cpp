#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //！！！！！！！对于链表，传入链表头就可以了
ListNode* oddEvenList(ListNode* head) {
    /*要点： 把整个链表还是想象成几个离散的点，用两个新指针（odd，even）把链表分成两个子链表（odd，even），
    最后把偶数链表接到奇数链表后面即可
	*/
	if(head==NULL||head->next==NULL){
		return head;
	}
    
	ListNode* oddList = head; //new pointer, only 复制一下
	ListNode* evenList = head->next;

	ListNode* odd_pointer_now = oddList;
	ListNode* even_pointer_now = evenList; 
	//这两个是用来保存（复制）两个链表各自的表头，这样在最后才能找到头,这两个指针指向当前各自链表位置

	while(true){
		if(even_pointer_now->next!=NULL){
			odd_pointer_now->next = even_pointer_now->next;
			odd_pointer_now = odd_pointer_now->next;
		}
		else break; ////这个很重要，没有这句的话，1，2，3，4这种情况不会停下来。。
		if(odd_pointer_now->next!=NULL){
			even_pointer_now->next = odd_pointer_now->next;
			even_pointer_now = even_pointer_now->next;
		}
		else break; 
	}
	odd_pointer_now->next = evenList;
	even_pointer_now->next =NULL;
	return oddList;//????!!!!!
}

int main(){
	/*
	ListNode* post_lists = oddEvenList(lists);

	while(post_lists->next){
		cout<<post_lists->value;
		post_lists=post_lists->next;
	}
	*/
}