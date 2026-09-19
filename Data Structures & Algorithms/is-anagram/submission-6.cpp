class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char,count>
        // 1. count up using s
        // 2. count down using t
        // if map is empty => anagram

        unordered_map<char,int> ac; // anagram counter

        for (auto &c : s) {
            auto it = ac.find(c);
            if (it != ac.end()) {
                it->second++;
            } else {
                ac.insert({c,1});
            }
        }

        for (auto &c : t) {
            auto it = ac.find(c);
            if (it != ac.end()) {
                it->second--;
                if (it->second < 0) return false;
                if (it->second == 0 ) ac.erase(it);
            } else return false;
        }

        if (ac.size() == 0) return true;
        else return false;
    }
};
