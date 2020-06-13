#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 1000
#define INFINITY  1 << 30
int N;  
int M;  
int pic[MAXN][MAXN];
int parent[MAXN];   //根节点 
int flag[MAXN]; 
int dist[MAXN]; 

int FindMinDist() {
    int MinV;
    int MinDist = INFINITY;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] != 0 && dist[i] < MinDist) {
            MinDist = dist[i];
            MinV = i;
        }
    }
    if (MinDist < INFINITY)
        return MinV;
    else return -1;
}

void Prim() {
    parent[1] = -1;
    int V;  //未被收录顶点
    for (int i = 1; i <= N; ++i) {
        dist[i] = pic[1][i];
        parent[i] = 0;
    }
    int TotalWeight = 0;    //初始化权重和
    int VCount = 0;         //初始化收录的顶点数
    dist[1] = 0;
    VCount++;
    parent[1] = -1; //1 为树根

    while (1) {
        V = FindMinDist();
        if (V == -1) break;

        TotalWeight += dist[V];
        dist[V] = 0;
        VCount++;

        for (int i = 1; i <= N; ++i) {
            if (dist[i] != 0 && pic[V][i] < INFINITY) {
                if (pic[V][i] < dist[i]) {
                    dist[i] = pic[V][i];
                    parent[i] = V;
                }
            }
        }
    }
    if (VCount < N)
        cout << "no spanning tree"<<endl;
    else
        cout<<TotalWeight<<endl;
}

int main(void) {
    int x, y, temp;
    cin>>N>>M;
    //初始化图
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            pic[i][j] = INFINITY;

    //初始化parent
    for (int i = 0; i < M; ++i) {
        cin>>x>>y>>temp;
        pic[x][y] = temp;
        pic[y][x] = temp;
    }

    Prim();
    system("pause");
    return 0;
}
