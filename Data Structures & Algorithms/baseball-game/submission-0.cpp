class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        std::vector<int> st;

        for (const auto& str : operations)
        {
            if (str == "C")
            {
                st.pop_back();
            }
            else if (str == "D")
            {
                st.push_back(st.back() * 2);
            }
            else if (str == "+")
            {
                st.push_back(st.back() + st.at(st.size() - 2));
            }
            else 
            {
                int num = std::stoi(str);
                st.push_back(num);
            }
        }

        return std::accumulate(st.begin(), st.end(), 0);
    }
};