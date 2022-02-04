class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int sum = 0;
        int n = cards.size();
        for(int i = cards.size()-1; i > n-k-1; i--){
            sum += cards[i];
        }
        int maxx = sum;
        for(int i = 0; i < k; i++){
            sum -= cards[n-k+i];
            sum += cards[i];
            maxx = max(maxx,sum);
        }
        return maxx;
    }
};