class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        for(auto& n:arr1){
            bool cf = false;
            for(auto& m:arr2){
                if(abs(n-m)<=d)
                {
                    cf=true;
                    break;
                    c++;
                }
            }
            if(!cf){
            c++;
            }
        }
        return c;
    }
};