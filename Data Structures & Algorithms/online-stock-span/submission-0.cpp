class StockSpanner {
public:
    StockSpanner() = default;
    
    int next(int price)
    {
        std::cerr << price << ", " << currDay << std::endl;

        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        if (st.empty())
        {
            st.push({price, currDay++});
            return currDay;
        }

        int res = currDay - st.top().second;
        st.push({price, currDay++});
        return res;
    }

    using Pair = std::pair<int, int>;
    std::stack<Pair> st{};
    int currDay{};
};

/*
[100, 80, 60, 70, 60, 75, 85]

stack
price, day 

int next(int currPrice)
{
    print err

    while stack non empty, and stack top.price <= currPrice
        stack pop
    
    if stack empty
        stack push {currPrice, currDay++}
        return currDay
    else
        int res = currDay - stack top day
        stack push 

        ++currDay
        return res
}

pop stack until top > curr price
return curr day - top of stack day
push curr price, curr day

999, 7
30, 6
40, 2
50, 1
60, 0
*/