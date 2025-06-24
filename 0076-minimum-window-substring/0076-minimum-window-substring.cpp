class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();

        if (n > m) return "";

        int reslen = INT_MAX;
        pair<int, int> resCor = {-1,-1};

        unordered_map<char,int> window, tMap;

        for(char c : t){
            tMap[c]++;
        }

        int l = 0, r = 0;
        int found = 0;
        int need = tMap.size();

        while(r<m){
            char c = s[r];
            
            window[c]++;

            if(tMap.count(c) && window[c] == tMap[c]){
                found++;
            }

            while (found == need){
                if(reslen > r-l+1){
                    reslen = r-l+1;
                    resCor = {l,r};
                }

                window[s[l]]--;
                if(tMap.count(s[l]) && window[s[l]] < tMap[s[l]]){
                    found--;
                }
                l++;
            }

            r++;
        }

        return reslen == INT_MAX ? "" : s.substr(resCor.first, reslen);

    }
};