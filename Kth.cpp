#include <stdio.h>
#include <iostream>
using namespace std;

//找到中位数
int partition(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l;
		int j = r;
		int x = s[i];
		while (i < j)
		{
			while (i < j && s[j] >= x)
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		return i;
	}
	return -1;
}

//分治找K-th Number
int Select(int s[], int l, int r, int k)
{
	if (l > r) return -1;
	if (l == r) return s[l];
	//得到中间数的下标
	int i = partition(s, l, r);
	//j为左区间长度
	int j = i - l + 1;
	//位置大就在左区间找，否则就在右区间找
	if (j == k) return s[i];
	else if (j > k) return Select(s, l, i, k);
	else return Select(s, i + 1, r, k - j);
}
int main()
{
	int n, k;
	//数的个数n
	cin >> n;
	int num[10000];
	for (int i = 0; i < n; i++) {
		//输入n个数
		cin >> num[i];
	}
	//输入k
	cin >> k;
	cout << Select(num, 0, n - 1, k);
	system("pause");
}

