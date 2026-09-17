class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* 
        1. get prefix sum
        2. get postfix sum
        */
        vector<int> prefix;
        vector<int> postfix;
        prefix.reserve(nums.size());
        postfix.reserve(nums.size());

        for(int i=0; i<(int)nums.size(); i++) {
            if (i>0) prefix[i] = prefix[i-1] * nums[i];
            else if (i==0) prefix[i] = nums[i];
            // else unrecheable
        }
        for(int i=(int)nums.size()-1; i>=0; i--) {
            if (i<(int)nums.size()-1) postfix[i] = postfix[i+1] * nums[i];
            else postfix[i] = nums[i];
        }

        vector<int> out(nums.size(),1);
        for(int i=0; i<(int)nums.size(); i++) {
            if (i>0) out[i] *= prefix[i-1];
            if (i<(int)nums.size()-1) out[i] *= postfix[i+1];
        }

        return out;
    }
};
