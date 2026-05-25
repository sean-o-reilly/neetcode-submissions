class MyQueue {
public:
    MyQueue() = default;
    
    void push(int x)
    {
        std::stack<int> temp;

        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }

        st.push(x);

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
    
    int pop()
    {
        int res = st.top();
        st.pop();
        return res;
    }
    
    int peek()
    {
        return st.top();
    }
    
    bool empty()
    {
        return st.empty();
    }
private:
    std::stack<int> st;
};


/*
[1, 2, 3]

stack: 5 4 3 2 1 
tempStack: 

push
    move all elements to other stack, push new, then move all back


*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */