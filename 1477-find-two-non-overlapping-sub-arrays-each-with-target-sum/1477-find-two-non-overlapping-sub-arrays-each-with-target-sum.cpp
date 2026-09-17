class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>minl(n,INT_MAX);
        unordered_map<int,int> psum;
        int csum=0;
        int bslen=INT_MAX;
        int res=INT_MAX;
        for(int i=-0;i<n;i++){
            csum+=arr[i];
            if(csum==target){
                bslen=min(bslen,i+1);
            }
            if(psum.count(csum-target)){
                int st=psum[csum-target];
                int clen=i-st;
                bslen=min(bslen,clen);
            }
            minl[i]=bslen;
            psum[csum]=i;
        }
        csum = 0; 
        psum.clear();
        bslen = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            csum += arr[i];
            if (csum == target) {
                bslen = min(bslen, n - i);
            }
            
            if (psum.count(csum - target)) {
                int st= psum[csum - target];
                int clen = st - i;
                bslen = min(bslen, clen);
            }
            if (i > 0 && minl[i - 1] != INT_MAX && bslen != INT_MAX) {
                res = min(res, minl[i - 1] + bslen);
            }
            
            psum[csum] = i;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};