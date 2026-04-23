class MinStack {
public:
    MinStack() = default;
    
    void push(int val)
    {
        filoStack.push(val);
        minStack.push(std::min(val, minStack.empty() ? val : minStack.top()));  
    }
    
    void pop()
    {
        filoStack.pop();
        minStack.pop();
    }
    
    int top()
    {
        return filoStack.top();
    }
    
    int getMin()
    {
        return minStack.top();
    }

private:
    std::stack<int> filoStack;
    std::stack<int> minStack;
};


/*

Stack, but we have to track where the min is

plan:
    two stacks

    filo stack

    min stack
        push the minimum of the top of filo stack and min stack


push 1
    filo - 1
    min - 1

push 2
    filo - 2 1
    min - 1 1

push 0
    filo - 0 2 1
    min - 0 1 1

get mi 
    return min top

top 
    return filo top

pop
    pop filo 
    pop min
    filo - 2 1
    min - 1 1
top
    return filo top

get min
    return min top

push 5
    filo - 5 2 1
    min - 1 1 1

push 3
    filo - 3 5 2 1
    min - 1 1 1 1

push 7
    filo - 7 3 5 2 1
    min - 1 1 1 1 1

push -10
    filo - -10 7 3 5 2 1
    min - -10 1 1 1 1 1

*/
