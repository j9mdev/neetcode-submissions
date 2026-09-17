class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        1. how to group & count => hash ; unordered_map<int,int>
        2. order grouped (aggregated) number by its count
        3. return k

        */

        // phase 1
        unordered_map<int,int> um;
        for (auto num : nums) {
            auto it = um.find(num);
            if (it != um.end()) {
                it->second++;
            } else {
                um.insert({num,1});
            }
        }

        // phase 2
        vector<pair<int,int>> freqv;// [freq,num]
        for (auto it : um) {
            freqv.push_back({it.second,it.first});
        }
        sort(freqv.begin(),freqv.end(),std::greater<>());

        // return k
        vector<int> kvals;
        for (int i=0; i<k; i++) {
            kvals.push_back(freqv[i].second);
        }
        return kvals;
    }
};
