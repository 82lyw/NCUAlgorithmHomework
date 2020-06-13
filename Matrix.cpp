#include<iostream>
using namespace std;
void MatrixChainOrder(int *p, int **m, int **s, int N)
{
    int n = N - 1;
    int l, i, j, k, q = 0;
    //m[i][i]ֻ��һ������������˴���Ϊ0����m[i][i]=0;
    for (i = 1; i<N; i++)
    {
        m[i][i] = 0;
    }
    //l��ʾ�������ĳ���
    // l=2ʱ������ m[i,i+1],i=1,2,...,n-1 (����l=2��������С����)
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1; //��iΪ��ʼλ�ã�jΪ����Ϊl������ĩλ��
            m[i][j] = 0x7fffffff;
            //k��i��j-1,��kΪλ�û���
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
    cout <<"���ٳ˷�������"<< m[1][N - 1] << endl<<endl;
}
int main()
{
    int N;
    cout << "��������������" << endl;
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
    cout << "�������������ά����" << endl;
    for (int i = 0; i < N+1; i++)
    {
        cin >> p[i];
    }
    MatrixChainOrder(p, m, s, N+1);
    system("pause");
    return 0;
}
