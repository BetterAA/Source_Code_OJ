//这个和用stack模拟队列不一样，用队列模拟栈的话用一个队列就好了，一个队列入队之后 再重复入队一次就能逆序了
    // Push element x onto stack.
    queue<int> myqueue;
    void push(int x){
        myqueue.push(x);
        for(int i=0 ; i<myqueue.size()-1; i++){
            myqueue.push(myqueue.front());
            myqueue.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!myqueue.empty()) myqueue.pop();
    }

    // Get the top element.
    int top() {
        return myqueue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return myqueue.empty();
    }