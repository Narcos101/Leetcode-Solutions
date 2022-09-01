class Solution {
private:
	int maxA(vector<int> &a) {
		int n = a.size();
		stack<int> st;
		int left[n], right[n];

		for (int i = 0; i < n; ++i) {
			while (st.size() && a[st.top()] >=  a[i]) st.pop();
			if (st.empty()) left[i] = -1;
			else left[i] = st.top();
			st.push(i);
		}
		while (st.size()) st.pop();
		for (int i = n - 1; i >= 0; --i) {
			while (st.size() && a[st.top()] >=  a[i]) st.pop();
			if (st.empty()) right[i] = n;
			else right[i] = st.top();
			st.push(i);
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, a[i] * 1LL * (right[i] - left[i] - 1));
		}
		return ans;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<int> t(m, 0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == '1') t[j]++;
				else t[j] = 0;
			}
			int cost = maxA(t);
			ans = max(cost, ans);
		}
		return ans;
	}
};
