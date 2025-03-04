class Solution {
private:
    string convertToTernary(int N){
        string result = "";
        // Base case
        if (N == 0)
            return "0";

       while(N != 0){
        int x = N%3;
        N/= 3;

        result = to_string(x) + result;
       }
       return result;
    }
public:
    bool checkPowersOfThree(int n) {
        string result = convertToTernary(n);

        for(auto c : result){
            if(c == '2')
                return false;
        }
        return true;
    }
};