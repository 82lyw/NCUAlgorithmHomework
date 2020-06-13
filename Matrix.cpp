#include<iostream>
using namespace std;
void MatrixChainOrder(int *p, int **m, int **s, int N)
{
    int n = N - 1;
    int l, i, j, k, q = 0;
    //m[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;
    for (i = 1; i<N; i++)
    {
        m[i][i] = 0;
    }
    //l表示矩阵链的长度
    // l=2时，计算 m[i,i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1; //以i为起始位置，j为长度为l的链的末位，
            m[i][j] = 0x7fffffff;
            //k从i到j-1,以k为位置划分
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout <<"最少乘法次数："<< m[1][N - 1] << endl<<endl;
}
int main()
{
    int N;
    cout << "请输入矩阵个数：" << endl;
    cin >> N;
    int *p= (int*)calloc(N+1, sizeof(int));
    int **m = (int **)calloc(N+1, sizeof(int));
    for (int i = 0; i<N+1; i++) {
        m[i] = (int*)calloc(N+1, sizeof(int));
    }
    int **s = (int **)calloc(N+1, sizeof(int));
    for (int i = 0; i<N+1; i++) {
        s[i] = (int*)calloc(N+1, sizeof(int));
    }
    cout << "请输入各个矩阵维数：" << endl;
    for (int i = 0; i < N+1; i++)
    {
        cin >> p[i];
    }
    MatrixChainOrder(p, m, s, N+1);
    system("pause");
    return 0;
}
