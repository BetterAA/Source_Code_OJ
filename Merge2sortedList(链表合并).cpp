ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return l1;//same NULL
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = l1->val>l2->val?l2:l1;
        while(l1||l2){
            if(l1->val<l2->val){
                ListNode* cur = l1;
                if(!l1->next){
                    l1->next = l2;
                }
                else l1 = l1->next;
            }
            else{
                ListNode* cur = l2;
                if(!l2->next){
                    l2->next = l1;
                }
                else l2 = l2->next;
            }
        }
        return head;
    }