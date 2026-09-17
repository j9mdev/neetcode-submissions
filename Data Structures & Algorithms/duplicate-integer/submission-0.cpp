class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /*
        Q1: ordered? no
        Q2: can modify nums? no

        my proposal: using unordered_set (dictionary/hash) add into; if duplicate, return true;
        */
        unordered_set<int> numset;
        for (int i=0; i<(int)nums.size(); i++) {
            auto [it, inserted] = numset.insert(nums[i]);
            if (!inserted) return true;
        }
        return false;
    }
};