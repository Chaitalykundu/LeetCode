class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1) return (!flowerbed[0] >= n);
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        int ans = 0;
        int down = -2;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 1){
                ans += (i - down - 2)/2;
                down = i;
            }
        }
        return (ans >= n);
    }
};