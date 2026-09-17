class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        q1: nums ordered? no
        q2: no dupicate? no (ex3)
        q3: more than 3 duplicate (triplicate)? I guess no;
        q4: can i soert nums directly? yes

        proposal algorithm
        1. order nums (bcz only 1000 items)
        2. put two pointers begin and end
           while (i<j)
            1. if twosum > current, then dec endidx
            2. else inc beginidx
        */
        // O(nlgn)
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end()); // QQ: sorting algo? ; QQ2: asc order?

        int i=0, j=(int)nums2.size()-1;

        while (i<j) {
            if (nums2[i]+nums2[j] == target) break;
            if (nums2[i]+nums2[j] > target) j--;
            else i++;
        }

        int num1 = nums2[i];
        int num2 = nums2[j];
        int idx1 = -1 , idx2 = -1;

        for (int k=0; k<(int)nums.size()+1; k++) {
            if (idx1 == -1 && nums[k] == num1) {
                idx1 = k;
            } else if (idx2 == -1 && nums[k] == num2) {
                idx2 = k;
            }
        }
        return {min(idx1,idx2),max(idx1,idx2)};
    }
};
