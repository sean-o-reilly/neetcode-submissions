class Solution
{
public:
    // ace -> abcde
    // aec -> abcde

    bool isSubsequence(string s, string t)
    {
        int lastFound = 0;
        int j = lastFound;

        for (int i = 0; i < s.length(); ++i)
        {
            bool found = false;
            for (j = lastFound; j < t.length(); ++j)
            {
                if (t[j] == s[i])
                {
                    std::cout << "Found " << s[i] << " at j=" << j << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                return false;
            }

            lastFound = j + 1;
        }
        return true;
    }
};



/*
Recursive Decision Tree (Brute Force)

At each character of t, choose to either keep or delete the character
this will generate combonations of t without messing up ordering
and we can compare each one to node to see if they are equal

O(2^n * n)

abcde
ace

pseudocode:
    recursive(s, t, currIdx)

        base cases
            s == t
                return true

            if currIdx >= t.length()
                return false

        recursive case (new combonation)

            try deleting current character
                newT = t with t[currIdx] spliced out
                recursive(s, newT, currIdx + 1)
            try keeping current character
                recursive(s, t, currIdx + 1)

            return || OR of these two functions^

solution: return psuedocode(s, t, 0)


*/