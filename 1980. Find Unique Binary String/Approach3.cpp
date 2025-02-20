class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(); // Get the number of binary strings
        string res = ""; // Resultant binary string

        // Construct the new binary string using the diagonal flipping approach
        for (int i = 0; i < n; i++) {
            // Flip the i-th character of the i-th string (diagonal element)
            if (nums[i][i] == '0') {
                res += '1'; // Change '0' to '1'
            } else {
                res += '0'; // Change '1' to '0'
            }
        }

        return res; // Return the generated unique binary string
    }
};
