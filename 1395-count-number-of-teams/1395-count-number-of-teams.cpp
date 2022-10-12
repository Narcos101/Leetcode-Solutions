class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        vector<int>smaller(n+1,0);
        vector<int>larger(n+1,0);
        for(int i = 0; i < n;i++){
            int l = 0;
            int s = 0;
            for(int j = n-1; j > i;j--){
                if(rating[j] > rating[i]){
                    s++;
                }
                else if(rating[i] > rating[j]){
                    l++;
                }
            }
            larger[i] = l;
            smaller[i] = s;
        }
        for(int i = 0; i < n;i++){
            for(int j = i + 1; j < n;j++){
                if(rating[j] > rating[i]){
                    ans += smaller[j];
                    // cout << rating[i]<< " " << rating[j] << " " << larger[j] << endl;
                }
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = i + 1; j < n;j++){
                if(rating[j] < rating[i]){
                    ans += larger[j];
                }
            }
        }
        return ans;
    }
};