class Solution {
public:
    string simplifyPath(string path)
    {
        std::stringstream ss{std::move(path)};
        const char delimiter = '/';

        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(ss, token, delimiter))
        {
            if (!token.empty())
            {
                if (token == "..")
                {
                    if (!tokens.empty())
                        tokens.pop_back();
                }
                else if (token != ".")
                {
                    tokens.emplace_back(std::move(token));
                }
            }
        }

        for (auto t : tokens) std::cout << t << std::endl;

        std::ostringstream oss;
        oss << delimiter;

        for (int i = 0; i < tokens.size(); ++i)
        {
            oss << tokens.at(i);
            if (i + 1 < tokens.size())
                oss << delimiter;
        }

        return oss.str();
    }
};


/*
absolute path -> simplify

. curr dir
.. parent dir
... or more = vaild file name or directory name

parsing via string streams
    / = delimeter
    /// should be treated as /


stack:

    parse string into tokens delimited by /
    for each token,
        if its a .. (go to parent) pop from stack (if non empty)
        else push to stack

    create a string starting with "/"
        add each token to the string, as well as a "/" (dont add one to the end)

"/a/b/c/d/../../..//////" -> "/a"



*/