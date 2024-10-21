class MinStack
{
public:
    std::stack<int> stack;
    std::stack<int> stack1;

    MinStack()
    {
    }

    void push(int val)
    {
        if (this->stack.size() == 0)
        {
            this->stack.push(val);
            this->stack1.push(val);
        }
        else
        {
            if (this->stack1.top() >= val)
            {
                this->stack1.push(val);
            }
            this->stack.push(val);
        }
    }

    void pop()
    {
        if ((this->stack1.top() == this->stack.top()) && (this->stack.size() != 0))
        {
            this->stack1.pop();
            this->stack.pop();
        }
        else if (this->stack.size() != 0)
        {
            this->stack.pop();
        }
    }

    int top()
    {
        return this->stack.top();
    }

    int getMin()
    {
        return this->stack1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */