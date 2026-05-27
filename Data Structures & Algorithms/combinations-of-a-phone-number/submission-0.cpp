class Solution {
public:
    vector<string>ans;
    void solve(int idx,string &digits,map<char,string>& mapping, string &curr ){
        if(idx ==digits.size() ){
            ans.push_back(curr); 
            return;
        }

        char ch= digits[idx];
        for(char letter:mapping[ch]){
            curr +=letter;
            solve(idx+1,digits, mapping,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        map<char,string>mapping;
        mapping['2'] = {"abc"};
        mapping['3'] = {"def"};
        mapping['4'] = {"ghi"};
        mapping['5'] = {"jkl"};
        mapping['6'] = {"mno"};
        mapping['7'] = {"pqrs"};
        mapping['8'] = {"tuv"};
        mapping['9'] = {"wxyz"};
        string curr;
        solve(0,digits,mapping,curr);
        return ans;
   

    }
};