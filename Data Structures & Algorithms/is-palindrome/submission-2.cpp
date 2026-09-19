class Solution {
public:
    bool isPalindrome(string s) {
        // 1. convert to alphabet only & lowercase
        // 2. check palindrome

        // 1.
        string s2;
        s2.reserve(s.size());
        for (auto &c: s) {
            if ( ( c >= 'a' && c <= 'z' ) ||  
                 ( c >= 'A' && c <= 'Z' ) || 
                 ( c >= '0' && c <= '9' ))
            {
                s2 += tolower(c);
            }
        }

        // 2.
        int n = s2.size();
        for (int i=0; i<n/2; i++) {
            if (s2[i] != s2[n-1-i]) {
                return false;
            }
        }
        return true;
    }
};
