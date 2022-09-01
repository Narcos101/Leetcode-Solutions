class Solution {
public:
	int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		int u[n][n], d[n][n], l[n][n], r[n][n];

		vector<vector<int>> grid(n, vector<int>(n, 1));

		for (auto &e : mines) {
			grid[e[0]][e[1]] = 0;
		}

		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				if (!grid[i][j]) sum = 0;
				else {
					sum += grid[i][j];
				}
				l[i][j] = sum;
			}
		}

		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = n - 1; j >= 0; --j) {
				if (!grid[i][j]) sum = 0;
				else {
					sum += grid[i][j];
				}
				r[i][j] = sum;
			}
		}

		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				if (!grid[j][i]) sum = 0;
				else {
					sum += grid[j][i];
				}
				u[j][i] = sum;
			}
		}

		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = n - 1; j >= 0; --j) {
				if (!grid[j][i]) sum = 0;
				else {
					sum += grid[j][i];
				}
				d[j][i] = sum;
			}
		}
		int ans = INT_MIN;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = max(ans, min(min(u[i][j], d[i][j]), min(l[i][j], r[i][j])));
			}
		}
		return ans;
	}
};
