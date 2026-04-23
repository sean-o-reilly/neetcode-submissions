class Solution {
public:
    bool isValid(const string s) {
        if (s.length() % 2 != 0) // odd length is false. O(1) time and space
        {
            return false;
        }

        std::stack<char> st;

        for (char c : s)
        {
            //opening
            if (c == '{' || c == '[' || c == '(')
            {
                st.push(c);
                continue;
            }
            
            // closing 
            if (st.empty()) return false;

            if (c == ')')
            {
                if (st.top() != '(')
                {
                    return false;
                }
                else 
                {
                    st.pop();
                }
            }
            else if (c == ']')
            {
                if (st.top() != '[')
                {
                    return false;
                }
                else 
                {
                    st.pop();
                }
            }
            else if (c == '}')
            {
                if (st.top() != '{')
                {
                    return false;
                }
                else 
                {
                    st.pop();
                }
            }
        }


        return st.empty();
    }
};

// if length of string isnt even, return false

// left and right indices
// while (left < right), stop when >=
    // if left != right, return false


// ([{}}]), short circuits from odd number

// {([)]