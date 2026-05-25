/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n)
    {
        int myGuess = n / 2;
        while (int res = guess(myGuess))     
        {
            if (res > 0) {
                myGuess = (myGuess + 1 + n) / 2;
            }
            else {
                myGuess = (myGuess - 1) / 2;
            }
        }

        return myGuess;
    }
};