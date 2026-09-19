class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        two possible solutions

        sol1. sort(s), sort(t), and scan and compare => O(nlg(n))

        sol2. [a-z] CARD([a-z]) = 26
           vector of a-z and count the alphabet;
        */
        // vector<int> lc; // letter_counter;
        // for (int i=0; i<=(int)('z'-'a'); i++) lc.push_back(0); // QQ: can I set 26 values at once?
        int lc[('z'-'a')+1] = {0};

        // count for string s
        for (int i=0; i<(int)s.size(); i++) {
            int idx = s[i]-'a';
            lc[idx]+=1;
        }

        // minus
        for (int i=0; i<(int)t.size(); i++) {
            int idx = t[i]-'a';
            lc[idx]-=1;
        }

        // if s an t are anagram, then all lc[i] == 0
        for (int i=0; i<=(int)('z'-'a'); i++)
            if (lc[i]!=0) return false;
        return true;
    }
};
