class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        std::stack<int> st;

        for (int num : asteroids)
        {
            if (num > 0)
            {
                st.push(num);
            }
            else
            {
                bool exploded = false;

                while (!st.empty())
                {
                    if (st.top() < 0) break;

                    if (std::abs(num) > st.top())
                    {
                        std::cerr << num << " destroys " << st.top() << std::endl;
                        st.pop();
                    }
                    else if (std::abs(num) == st.top())
                    {
                        std::cerr << num << " and " << st.top() << " destroy each other " << std::endl;
                        st.pop();
                        exploded = true;
                        break;
                    }
                    else // left moving < right moving
                    {
                        exploded = true;
                        break;
                    }
                }

                if (!exploded) st.push(num);
            }
        }

        std::vector<int> res;
        res.reserve(st.size());
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        std::ranges::reverse(res);

        return res;
    }
};

/*
[2,4,-4,-1]
4 and -4 explode each other
2 explodes -1
[2]

parantheses matching -> stack memory / LIFO

[1, 1, 1, -4]
[-4]

[1, 2, 3, -1]

int stack

for num in asteroids
    if num > 0
        push num
    else 
        bool exploded = false
        while stack non empty
            if abs(num) > stack top
                pop stack
            else if abs(num) == stack top
                pop stack
                exploded = true
                break 
            else
                exploded = true
                break
        if !exploded, push num




*/