class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        1. how to group & count => 2001 buckets of ints
        2. buckets into {count,idx} -> sort by count
        3. return k
        */

        // phase 1
        int counts[2001] = {0};
        for (const auto &num : nums) counts[num+1000]++;

        // 2
        vector<pair<int,int>> cntidx;
        cntidx.reserve(2001);
        for (int i=0; i<2001; i++) cntidx.push_back({counts[i],i-1000});
        
        // sort
        sort(cntidx.begin(),cntidx.end(),std::greater<>());
        vector<int> topk;
        topk.reserve(k);
        for (int i=0; i<k; i++) {
            topk.push_back(cntidx[i].second);
        }
        return topk;
    }
};