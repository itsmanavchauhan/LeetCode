class Solution {
public:
    long long totalHours(vector<int>& piles, int speed){
        int n = piles.size();
        long long hours =0;
        for(int i = 0; i < n; i++){
            hours+= ceil((double)piles[i] /(double)speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high){
            int mid = low+(high - low)/2;
            long long hours = totalHours(piles, mid);
            if(hours<=h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};