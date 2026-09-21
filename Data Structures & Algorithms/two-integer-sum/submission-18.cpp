class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash map based solution
        unordered_map<int,int> numidx;
        for (int i=0; i<(int)nums.size(); i++) {
            numidx[nums[i]] = i; // if dupicate, last i survives
        }
        for (int i=0; i<(int)nums.size(); i++) {
            int diff = target - nums[i];
            auto it = numidx.find(diff);
            if (it != numidx.end()) {
                if (it->second != i)
                    return {i,it->second};
            }
        }
        return {};
    }
};
