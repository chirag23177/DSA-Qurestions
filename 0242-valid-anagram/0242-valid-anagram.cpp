class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> s_set;
        for(char a : s){
            s_set[a]++;
        }
        for(char b : t){
            s_set[b]--;
            if(s_set[b]<0) 
            return false;
        }

        return true;;
    }
};