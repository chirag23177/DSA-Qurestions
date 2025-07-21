class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, pair<int, int>> hmap;
        int n = s.length();

        for(int l = 0; l<n; l++){
            if(s[l] == '0'){
                if(hmap.find(0) == hmap.end()){
                    hmap[0] = {l,l};
                }
                continue;
            }

            int num = 0;
            for(int r = l; r<n && r-l < 30; r++){
                num = (num << 1) | (s[r] - '0');

                if(hmap.find(num) == hmap.end()){
                    hmap[num] = {l,r};
                }
            }
        }

        vector<vector<int>> res;

        for(auto query: queries){
            int first = query[0];
            int second = query[1];
            int target = first^second;
            bool found = false;

            if(hmap.find(target) != hmap.end()){
                res.push_back({hmap[target].first, hmap[target].second});
            } else {
                res.push_back({-1, -1});
            }
        }
        return res;
    }
};