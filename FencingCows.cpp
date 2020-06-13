#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#define ldb long double
#define N 50050
using namespace std;
const int Inf=1e9;
int read() {
	int s=0,m=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')m=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	}
	return m?-s:s;
}
int n,top;
struct Node {
	ldb x,y;
} P[N],S[N];
//p����ڵ��λ�ã�S������͹���ϵĵ�

//���������cmp
bool cmp(const Node &a,const Node &b) {
	ldb A=atan2((a.y-P[1].y),(a.x-P[1].x));//�����Ǹ��Ƕ�(����)
	ldb B=atan2((b.y-P[1].y),(b.x-P[1].x));
	if(A==B)
		return a.x<b.x;
	return A<B;
}

// �������������AB>0��B��A�����Ϸ���AB<0��B��A�����·�
ldb Cross(Node a,Node b,Node c) {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

void Get() {
	Node hh=(Node) {
		Inf,Inf
	};
	int kk=0;
	for(int i=1; i<=n; ++i)
		if((P[i].y<hh.y)||(P[i].y==hh.y&&P[i].x<hh.x))
			hh=P[i],kk=i;
	swap(P[1],P[kk]);//����һ��͹���ġ���㡱���ڵ�һ��
	sort(&P[2],&P[n+1],cmp);//��������
	S[0]=P[1],S[top=1]=P[2];
	for(int i=3; i<=n; ++i) { //�����������˳��һ��һ���ж�
		while(top&&Cross(S[top-1],P[i],S[top])>=0){
			top--;
		}
		//���͹�������� �� ���>=0(�¼ӵ���������ڴ�ǰ���������Ϸ�)��Ҫһֱ��
		S[++top]=P[i];
	}
}
ldb Dist(Node a,Node b) {
	//����֮��ľ���
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void GetAns() {
	ldb ans=0;
	for(int i=1; i<=top; ++i)
		ans+=Dist(S[i-1],S[i]);//͹��������ľ���
	if(top>1)
		ans+=Dist(S[top],S[0]);//�ǵ���β���
	printf("%.2Lf\n",ans);
}
int main() {
	n=read();
	for(int i=1; i<=n; ++i)
		scanf("%Lf%Lf",&P[i].x,&P[i].y);
	Get(),GetAns();
	return 0;
}
