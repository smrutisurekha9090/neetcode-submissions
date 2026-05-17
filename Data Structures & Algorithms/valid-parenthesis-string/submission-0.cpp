class Solution {
public:
    bool checkValidString(string s) {
       int min=0;
       int max=0;
       for(char c:s){
            if(c == '('){
                min++;
                max++;
            }else if(c == ')'){
                min--;
                max--;
            }else if(c == '*'){
                min--;
                max++;
            }

            if(max < 0){
                return false;
            }
            if(min <0) min=0;

       }
       return min ==0; 
    }
};
