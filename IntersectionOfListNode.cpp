ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //如果有相交的话，长度一样右对齐的话肯定后面肯定会重合，a的后面接一个b，b后面接一个a，即A+B ＝ B＋A 这样就可以了
        ListNode* p1 = headA,*p2 = headB;
        //指针相等，不是值相等!！ eg>
        //a1 a2 a3 c1 c2 c3|b1 b2 c1 c2 c3
        //b1 b2 c1 c2 c3|a1 a2 a3 c1 c2 c3
        while(p1!=p2){
            p1 = p1?p1->next:headB;
            p2 = p2?p2->next:headA;
        }
        return p1;
    }