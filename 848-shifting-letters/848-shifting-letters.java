class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        StringBuilder ans = new StringBuilder();
        int X = 0;
        for(int i = 0;i < shifts.length; i++){
            X = (X +shifts[i])%26;
        }
        for(int i = 0; i < s.length(); i++){
            int index = (s.charAt(i)-'a');
            ans.append((char)((index + X)%26 + 97));
            X = Math.floorMod(X - shifts[i],26);
        }
         return ans.toString();
    }
   
}