class Solution {
public:
    string decodeString(string s)
    {
        std::stack<int> numSt;
        std::stack<std::string> strSt;

        std::vector<std::string> tokens;

        for (int i = 0; i < s.length(); ++i)
        {
            char c = s.at(i);
            if (std::isdigit(c)) 
            {
                std::string num;
                while (i < s.length() && std::isdigit(s.at(i)))
                {
                    num += s.at(i);
                    ++i;
                }

                tokens.push_back(num);
            }
            else
            {
                tokens.push_back(std::string{c});
            }
        }

        for (auto tok : tokens)
            std::cout << tok << std::endl;

        for (auto& tok : tokens)
        {
            if (tok == "[") continue;
            else if (std::isdigit(tok.at(0)))
            {
                numSt.push(std::stoi(tok));
                strSt.push("");
            }
            else if (tok == "]")
            {
                std::string str = strSt.top();
                strSt.pop();
                int mult = numSt.top();
                numSt.pop();

                if (strSt.empty()) strSt.push("");
                for (int i = 0; i < mult; ++i)
                    strSt.top() += str;
            }
            else
            {
                if (strSt.empty())
                {
                    strSt.push("");
                }

                strSt.top() += tok;
            }
        }

        return strSt.top();
    }
};

/*
two stacks
one for numbers one for strings

read the string
    if non numeric append to top string
        create a top string if one does not exist

    after reading a number,
        push number to number stack
        push a new empty string to top of string stack
    
    after reading a closing brace
        str = str stack pop() # pop string off
        str = str * num stack pop() # multiply string
        # append string to str stack top() (insert if no top)

    return string stack top()

*/