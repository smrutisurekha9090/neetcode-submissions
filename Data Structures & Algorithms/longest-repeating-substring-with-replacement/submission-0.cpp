class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp; 
        int i=0;
        int j=0;
        int maxfre = 0;
        int maxlen = 0;
        while(j< s.length()){
            mp[s[j]]++;
            maxfre = max(maxfre , mp[s[j]]);

            //invalid 
            if((j-i+1)-maxfre > k){
                mp[s[i]]--;
                i++;
            }
            //valid
            if((j-i+1)-maxfre <= k){
                maxlen = max(maxlen,j-i+1);
            }
            j++;
        }
        return maxlen;

    }
};
