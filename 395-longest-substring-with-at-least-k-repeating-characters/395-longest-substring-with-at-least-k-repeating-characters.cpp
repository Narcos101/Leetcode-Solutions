class Solution {
public:
    int longestSubstring(string s, int k) {
        // divide and conquer method 
        return longestSubstringtwo(s,0,s.size(),k);
    }
    
    int longestSubstringtwo(string s,int start,int end,int k){
        if(start >= end){
            return 0;
        }
        int charc[26] = {0};
        
        for(int i = start; i < end; i++){
            charc[s[i]-'a']++;   
        }
        for(int i = start; i < end; i++){
            if(charc[s[i]-'a'] >= k) continue;
            return max(longestSubstringtwo(s,start,i,k),longestSubstringtwo(s,i+1,end,k)); 
        }
        return (end-start);
    }
};