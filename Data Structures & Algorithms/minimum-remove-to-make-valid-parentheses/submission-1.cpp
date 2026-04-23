class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        std::unordered_set<int> indexes;
        std::stack<int> st;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    indexes.insert(i); // invalid closer
                }
                else
                {
                    st.pop(); // pop off opener, which has now been closed
                }
            }
        }

        while (!st.empty())
        {
            indexes.insert(st.top()); // add all invalid idx to indexes
            st.pop();
        }

        std::string res; // build new string without invalid indx

        for (int i = 0; i < s.length(); ++i)
        {
            if (!indexes.count(i))
            {
                res += s[i];
            }
        }

        return res;
    }
};

/*

BruteForce -> run valid parentheses algo, whenever invalid is found, remove it and repeat

))()((

))()(()

(() -> stack is non empty, invalid opener

O(n) time and space

Solution:
    find indexes of all invalid parentheses using stack algo

    traverse through and build a new string, only
    add indexes that are not in the set of invalid indexes


Find indexes:
    Use a stack<bool, int>
        bool -> isClosing parentheses
        int -> idx

    unordered set of <int> indexes

    for i = 0, i < s length, ++i
        if opener:
            stack push true, i
        else:
            if stack is empty, -> invalid closer
                indexes insert i
            else if stack top is a opener:
                stack pop

    if stack is not empty, 
        for element in stack, indexes insert element.idx


    
*/
