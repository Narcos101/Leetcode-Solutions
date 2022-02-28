class Solution{
    public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
            int size = s.size();
            // replaceIndex[i] means the index of targets will be replaced at i, where i is the index of s
            // initially all items in replaceIndex are -1, means no replacement happens
            vector<int> replaceIndex(size, -1);
            int k = indices.size();
            for (int i = 0; i < k; i++) {
                int length = sources[i].size();
                // if the sub string matches the sources[i], then s from index indices[i] should be replaced by targets[i] 
                if (s.substr(indices[i], length) == sources[i]) {
                    replaceIndex[indices[i]] = i;
                }
            }
            int index = 0;
            string res = "";
            while (index < size) {
                // if no replacement happens, concatenate s[index],
                // otherwise concatenate targets[index]
                if (replaceIndex[index] == -1) {
                    res += s[index];
                    index++;
                } else {
                    int targetIndex = replaceIndex[index];
                    res += targets[targetIndex];
                    index += sources[targetIndex].size();
                }
            }
            return res;
        }
};