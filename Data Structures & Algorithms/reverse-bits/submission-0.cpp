class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res =0;
        for(int i=0;i<32;i++){
            res<<=1; //make space;
            res = res|(n&1); //add last bit
            n>>=1; //remove last bit
        }
        return res;
    }
};
