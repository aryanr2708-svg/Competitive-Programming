class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for(int n=2;n<nums.size();n++){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[n]);
            }
            else{
                arr2.push_back(nums[n]);
            }
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};