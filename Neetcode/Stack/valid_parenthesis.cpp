class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (auto i : s)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                stack.push(i);
            }
            else
            {
                if (stack.empty())
                    return false;
                char ch = stack.top();
                if (i == ')')
                    if (ch != '(')
                        return false;
                if (i == '}')
                    if (ch != '{')
                        return false;
                if (i == ']')
                    if (ch != '[')
                        return false;
                stack.pop();
            }
        }
        if (stack.size() != 0)
            return false;
        return true;
    }
};