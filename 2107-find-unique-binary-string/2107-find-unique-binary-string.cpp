class Solution {
public:
    string returnbinary(int n, int length) {
        string binary = "";
        for (int i = 0; i < length; i++) {
            if (n & (1 << i)) {
                binary += "1";
            } else {
                binary += "0";
            }
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

    int binarytonum(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                num += pow(2, s.length() - i - 1);
            }
        }
        return num;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int maxVal = pow(2, nums.size()) - 1;
        set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(binarytonum(nums[i]));
        }

        for (int i = 0; i <= maxVal; i++) {  
            if (s.find(i) == s.end()) {
                return returnbinary(i, nums.size());
            }
        }
        return "";
    }
};