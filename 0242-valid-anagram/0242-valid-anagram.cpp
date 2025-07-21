class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(auto ch : s){
            s_map[ch]++;
        }

        for(auto ch2 : t){
            t_map[ch2]++;
        }

        return s_map == t_map;
    }
};