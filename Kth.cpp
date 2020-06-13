#include <stdio.h>
#include <iostream>
using namespace std;

//�ҵ���λ��
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

//������K-th Number
int Select(int s[], int l, int r, int k)
{
	if (l > r) return -1;
	if (l == r) return s[l];
	//�õ��м������±�
	int i = partition(s, l, r);
	//jΪ�����䳤��
	int j = i - l + 1;
	//λ�ô�����������ң����������������
	if (j == k) return s[i];
	else if (j > k) return Select(s, l, i, k);
	else return Select(s, i + 1, r, k - j);
}
int main()
{
	int n, k;
	//���ĸ���n
	cin >> n;
	int num[10000];
	for (int i = 0; i < n; i++) {
		//����n����
		cin >> num[i];
	}
	//����k
	cin >> k;
	cout << Select(num, 0, n - 1, k);
	system("pause");
}

