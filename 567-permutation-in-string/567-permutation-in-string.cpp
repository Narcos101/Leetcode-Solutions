class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>arr(26,0),arr2(26,0);
        if(s2.size() < s1.size()) return false;
        for(int i = 0;i < s1.size(); i++){
            arr[s1[i]-'a']++;
        }
        for(int i = 0; i < s1.size(); i++){
            arr2[s2[i]-'a']++;
        }
        if(arr == arr2) return true;
        for(int i = s1.size(); i < s2.size(); i++){
            ++arr2[s2[i]-'a'];
            --arr2[s2[i-s1.size()]-'a'];
            if(arr == arr2) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> pv(26,0), sv(26,0), res;
//         if(s.size() < p.size())
//            return res;
//         // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
//         for(int i = 0; i < p.size(); ++i)
//         {
//             ++pv[p[i]-'a'];
//             ++sv[s[i]-'a'];
//         }
//         if(pv == sv)
//            res.push_back(0);

//         //here window is moving from left to right across the string. 
//         //window size is p.size(), so s.size()-p.size() moves are made 
//         for(int i = p.size(); i < s.size(); ++i) 
//         {
//              // window extends one step to the right. counter for s[i] is incremented 
//             ++sv[s[i]-'a'];
            
//             // since we added one element to the right, 
//             // one element to the left should be discarded. 
//             //counter for s[i-p.size()] is decremented
//             --sv[s[i-p.size()]-'a']; 

//             // if after move to the right the anagram can be composed, 
//             // add new position of window's left point to the result 
//             if(pv == sv)  // this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
//                res.push_back(i-p.size()+1);
//         }
//         return res;
//     }
// };