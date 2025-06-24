class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        unordered_map<char,int> freq;

        int l = 0;
        int maxlength = 0;
        int maxfreq = 0;

        for(int r = 0; r<n; r++){
            freq[s[r]]++;
            maxfreq = max(maxfreq,freq[s[r]]);

            while((r-l+1) -maxfreq >k){
                freq[s[l]]--;
                l++;
            }

            maxlength = max(maxlength,(r-l+1));
        }


        // while(r<n){
        //     if(freq.find(s[r]) == freq.end()){
        //         freq.insert({s[r],1});
        //     }
        //     else{
        //         freq[s[r]]++;
        //     }

        //     maxfreq = max(maxfreq, freq[s[r]]);

        //     while( (r-l+1) - maxfreq > k){
        //         freq[s[l]]--;
        //         maxfreq = 0;
        //         for(auto [key,val] : freq){
        //             maxfreq =max(maxfreq,val);
        //         }
        //         l++;
        //     }
        //     if( (r-l+1) - maxfreq <= k){
        //         maxlength = max(maxlength, (r-l+1));
        //         r++;
        //     }
        // }

        return maxlength;
    }
};