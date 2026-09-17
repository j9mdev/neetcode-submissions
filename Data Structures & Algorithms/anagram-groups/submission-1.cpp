class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
         unordered_map<string,vector<string>>
         -> string key is sorted word which means sort the English letters in alphabetical order
        */
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> am; // anagram map

        // Phase 1. sorting and put into map
        for (auto s : strs) {
            auto org_s = s;
            sort(s.begin(),s.end());
            auto it = am.find(s);
            if (it != am.end()) {
                it->second.push_back(org_s);
            } else {
                am.insert({s,{org_s}});
            }
        }

        // Phase 2. build ans from map
        for (auto vs : am) {
            ans.push_back(vs.second);
        }

        return ans;
    }
};
