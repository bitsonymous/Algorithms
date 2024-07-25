class Solution {
public:
    void merge(int l, int mid, int r, vector<int> &nums){
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int a[n1], b[n2];
        for(int i = 0; i<n1; i++){
            a[i] = nums[i+l];
        }
        for(int i = 0; i<n2; i++){
            b[i] = nums[i+mid+1];
        }
        int i = 0, j = 0, k = l;
        while(i<n1 and j<n2){
            if(a[i]<b[j]){
                nums[k] = a[i];
                i++;
            }else{
                nums[k] = b[j];
                j++;
            }
            k++;
        }
        while(i<n1 || j<n2){
            if(i<n1){
                nums[k] = a[i];
                i++;
            }else{
                nums[k] = b[j];
                j++;
            }
            k++;
        }
    }
    void mergesort(int l, int r,vector<int> &nums){
        if(l<r){
            int mid = (l+r)/2;
            mergesort(l, mid, nums);
            mergesort(mid+1, r, nums);
            merge(l, mid, r, nums); 
        }  
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0, nums.size()-1, nums);
        return nums;
    }
};
