class Solution {
public:
    string convert(string s, int numRows) {
        // using a adjacency list to store the num of rows and then add them according to the list
        // TC would be O(n) and space Complexity would be O(n)
        // I want to do it in O(n) time and O(1) space
        if(numRows == 1){
            return s;
        }
        
        
        
        string ans = "";
        for(int i = 0; i < numRows; i++){
            int increment = 2 * (numRows-1);
            for(int j = i; j < s.size(); j += increment){
                ans += s[j];
                if(i > 0 && i < numRows-1 && ((j + increment) - 2 * i) < s.size()){
                    ans += s[j+increment-2*i];
                } 
            }
        }
        return ans;
    }
};