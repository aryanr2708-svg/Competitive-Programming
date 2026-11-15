class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod =1e9+7;
        int oc=0,ec=1,cs=0;
        int totalsubarr=0;
        for(int n:arr){
            cs+=n;
            if(cs%2!=0){
                totalsubarr=(totalsubarr+ec)%mod;
                oc++;
            }
            else{
                totalsubarr=(totalsubarr+oc)%mod;
                ec++;
            }
        }
        return static_cast<int>(totalsubarr);
    }
};