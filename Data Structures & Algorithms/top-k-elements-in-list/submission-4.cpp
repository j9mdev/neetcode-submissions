class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        1. how to group & count => 2001 buckets of ints
        2. buckets into {count,idx} -> sort by count
        3. return k
        */

        // phase 1
        array<int,2001> counts = {};
        for (const auto &num : nums) counts[num+1000]++;
   
        // sort
        array<int,2001> sorted_counts = counts;
        // copy(counts, counts+2001, sorted_counts);
        sort(sorted_counts.begin(), sorted_counts.end(), std::greater<>());
        int topk_boundary = sorted_counts[k-1];
        vector<int> topk;
        topk.reserve(k);
        for (int i=0; i<2001 && (int)topk.size() <= k; i++) {
            if (counts[i] >= topk_boundary) topk.push_back(i-1000);
        }
        return topk;
    }
};