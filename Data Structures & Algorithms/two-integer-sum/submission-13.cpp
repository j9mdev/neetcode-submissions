class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force
        for (int i=0; i<(int)nums.size(); i++) {
            for (int j=i+1; j<(int)nums.size(); j++) {
                if ( nums[i] + nums[j] == target ) {
                    return {i,j};
                }
            }
        }
        // non recheable in theory
        return {-1,-1};
    }
};
