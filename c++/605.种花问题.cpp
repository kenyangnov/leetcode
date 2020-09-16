class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i=1; i<flowerbed.size()-1; i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
            }
        }
        if(cnt>=n){
            return true;
        }
        return false;
    }
};