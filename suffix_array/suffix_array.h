#include<string> 
#include<vector>
#include<algorithm>

struct SufArray
{
	std::vector<std::vector<int>> comp;
	std::vector<int> arr;
	std::string s;
	SufArray(const std::string &t) : s(t + '$')
	{
		int n = s.size();
		std::vector<std::pair<int, int>> vec;
		for (int i = 0; i < n; ++i)
		{
			vec.emplace_back(s[i], i);			
		}
		std::sort(vec.begin(), vec.end());
		comp.emplace_back(n);
		for (int i = 0; i < n; ++i)
		{
			comp[0][vec[i].second] = vec[i].first;
		}

		std::vector<std::pair<std::pair<int, int>, int>> q;
		q.resize(n);
		for (int len = 1, k = 1;len < n; len *= 2, ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				q[i] = std::make_pair(std::make_pair(comp[k - 1][i], comp[k - 1][(i + len) % n]), i);
			}
			std::sort(q.begin(), q.end());

			comp.emplace_back(n);
			int cnt = 1;
			for (int i = 0; i < n; ++i)
			{
				if (i > 0 && q[i].first != q[i - 1].first)
				{
					++cnt;
				}
				comp[k][q[i].second] = cnt;
			}
		}

		arr.resize(n);
		for (int i = 0; i < n; ++i)
		{
			arr[comp.back()[i] - 1] = i;
		}
	}
};