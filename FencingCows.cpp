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
//p储存节点的位置，S储存在凸包上的点

//极角排序的cmp
bool cmp(const Node &a,const Node &b) {
	ldb A=atan2((a.y-P[1].y),(a.x-P[1].x));//就是那个角度(极角)
	ldb B=atan2((b.y-P[1].y),(b.x-P[1].x));
	if(A==B)
		return a.x<b.x;
	return A<B;
}

// 计算向量叉积：AB>0，B在A的左上方；AB<0，B在A的右下方
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
	swap(P[1],P[kk]);//先找一个凸包的“起点”放在第一个
	sort(&P[2],&P[n+1],cmp);//极角排序
	S[0]=P[1],S[top=1]=P[2];
	for(int i=3; i<=n; ++i) { //按极角排序的顺序一个一个判断
		while(top&&Cross(S[top-1],P[i],S[top])>=0){
			top--;
		}
		//如果凸包还存在 且 叉积>=0(新加的这个向量在从前向量的左上方)就要一直弹
		S[++top]=P[i];
	}
}
ldb Dist(Node a,Node b) {
	//两点之间的距离
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void GetAns() {
	ldb ans=0;
	for(int i=1; i<=top; ++i)
		ans+=Dist(S[i-1],S[i]);//凸包上两点的距离
	if(top>1)
		ans+=Dist(S[top],S[0]);//记得首尾相接
	printf("%.2Lf\n",ans);
}
int main() {
	n=read();
	for(int i=1; i<=n; ++i)
		scanf("%Lf%Lf",&P[i].x,&P[i].y);
	Get(),GetAns();
	return 0;
}
