class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        std::stack<int> st;
        auto topTwo = [&] -> std::pair<int, int> {
            int rhs = st.top();
            st.pop();
            int lhs = st.top();
            st.pop();
            return {lhs, rhs};
        };

        for (const auto& str : tokens)
        {
            if (str == "+")
            {
                auto [lhs, rhs] = topTwo();
                st.push(lhs + rhs);
            }
            else if (str == "-")
            {
                auto [lhs, rhs] = topTwo();
                st.push(lhs - rhs);
            }
            else if (str == "*")
            {
                auto [lhs, rhs] = topTwo();
                st.push(lhs * rhs);
            }
            else if (str == "/")
            {
                auto [lhs, rhs] = topTwo();
                st.push(lhs / rhs);
            }
            else
            {
                st.push(std::stoi(str));
            }
        }

        return st.top();
    }
};

/*
[4, 3, - 10, *, 4, +, 2, *]


stack of ints
for each token
    if number, push to stack
    if operation +, -, *, /
        pop two numbers
        lhs, rhs, = st.top_two()
        st.push(lhs (operation) rhs)

    return st top
*/
