#include<iostream>
#include<cstring> 
using namespace std;
int M(char *str, int n, int index) {
	static char a[100];
	int x = 0, y = 0;

	if (n == -1) {
		a[index] = '\0';
		cout <<"{"<< a <<"}";
		return 1;
	}
	if (n >= 0) {
		a[index] = str[n];
		x = M(str, n - 1, index + 1);
		y = M(str, n - 1, index);
	}
	return x + y;
}

int main() {
	char a[20];
	cout<<"请输入字符串"<<endl;
	cin>>a;
	cout << "该集合所有幂集为:" << endl;
	M(a, strlen(a) - 1, 0);
	system("pause");
	return 0;
}

