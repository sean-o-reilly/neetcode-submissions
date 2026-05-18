class MyStack {
public:
    MyStack() : topQ{&q1}, otherQ{&q2}
    {}
    
    void push(int x)
    {
        while (!otherQ->empty())
        {
            topQ->push(otherQ->front());
            otherQ->pop();
        }
        otherQ->push(x);

        std::swap(topQ, otherQ);
    }
    
    int pop()
    {
        int res = topQ->front();
        topQ->pop();

        // move next element back to top q
        if (!otherQ->empty())
        {
            topQ->push(otherQ->front());
            otherQ->pop();
        }
        
        return res;
    }
    
    int top()
    {
        return topQ->front();
    }
    
    bool empty()
    {
        return q1.empty() && q2.empty();    
    }

    std::queue<int>* topQ;
    std::queue<int>* otherQ;
    std::queue<int> q1;
    std::queue<int> q2;
};

/*
input: 1 2 3

res:
3
2
1

queues:

q1: 4
q2: 3 2 1

push to queue alternating
each time queue with top changes,
    all elements must be moved to the other queue

pop from last queue pushed to
    take one element from other queue and add it to popped queue

pop from one with more elements
insert into one with less
juggle elements


*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */