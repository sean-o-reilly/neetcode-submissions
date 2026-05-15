class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::stack<std::pair<int, int>> st; // val -> idx
        std::vector<int> res(temperatures.size(), 0);

        int max = 0;

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            int currVal = temperatures.at(i);
            if (currVal >= max)
            {
                max = currVal;
            }
            else
            {
                while (currVal >= st.top().first) st.pop();
                res.at(i) = st.top().second - i;
            }

            st.push({currVal, i});
        }

        return res;
    }
};

/*

[30, 38, 30, 46, 35, 40, 28]
[22, 21, 20]
[999, 5, 10, 5, 20, 30, 35, 30]
[10, 20, 30, 40]
[40, 30, 20, 10, 5, 10, 20, 30, 40]
[3, 3, 3, 2, 2, 2, 1, 1, 1]
[3, 2, 1, 3, 2, 1, 3, 2, 1]
[999, 1, 1, 1, 1, 2, 999]

go backwards
track stack future
(index of last higher - i)

pop stack until top is > curr value
if curr value greater than or equal to max,
    update max and write a zero
else
    pop stack while current value > top of stack value
    write (the index on the top of stack - curr index)
then push current value

*/

