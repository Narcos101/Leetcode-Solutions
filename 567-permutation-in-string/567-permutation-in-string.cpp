class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int chars[26] = {0};
        int chars2[26] = {0};
        // we can use a sliding window approach and use a char array in order to find the answer 
        // and a match function to check it
        for(int i = 0; i < s1.size();i++){
            chars[s1[i]-'a']++;            
        }
        for(int i = 0; i < s1.size();i++){
            chars2[s2[i]-'a']++;
        }
        if(matches(chars,chars2)) return true;
        for(int i = s1.size(); i < s2.size(); i++){
            chars2[s2[i]-'a']++;
            int n = s1.size();
            chars2[s2[i-n]-'a']--;
            if(matches(chars,chars2)) return true;
        }
        return false; 
    }
    bool matches(int chars[],int chars2[]){
        for(int i = 0; i < 26; i++){
            if(chars[i] != chars2[i]){
                return false;
            }
        }
        return true;
    }
};






