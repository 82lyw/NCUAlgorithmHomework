#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int>PII;
PII logs[100000];
int d1[10000]; //����p[i]�����Ľ�ֹ����
int x[10000];//
int b[10000];
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first>p2.first)
        return true;
    else
        return false;
}
int main() {
    cout << "��������ҵ��" << endl;
    int n;
    cin >> n;
    int *v, *p, *d;
    v = (int*)calloc(n, sizeof(int));//��ҵ��
    p = (int*)calloc(n, sizeof(int));//����
    d = (int*)calloc(n, sizeof(int));//����
    cout << "�밴��ҵ�ţ����棬���޸�ʽ���룬�м��пո�" << endl;
    for (int i = 0; i<n; i++) {
        cin >> v[i] >> p[i] >> d[i];
    }
    for (int i = 0; i<n; i++) {
        logs[i].first = p[i];
        logs[i].second = d[i]; 
    }
    sort(logs, logs + n, cmp);
    for (int i = 0; i<n; i++) {
        d1[i] = logs[i].second;
    }
    for (int i = 0; i<n; i++) {
        logs[i].first = p[i];
        logs[i].second = v[i];
    }
    sort(logs, logs + n, cmp);
    int k = 0;
    x[0] = 0;
    for (int j = 1; j<n; j++) {
        int r = k;
        while (r >= 0 && d1[x[r]]>d1[j] && d1[x[r]]>r + 1) {
            r--;
        }
        if ((r<0 || d1[x[r]] <= d1[j]) && d1[j]>r + 1) {
            for (int i = k; i >= r + 1; i--) x[i + 1] = x[i];
            x[r + 1] = j;
            k++;
        }
    }
    for (int i = 0; i <= k; i++) {
        b[i] = logs[x[i]].second;
    }
    sort(b, b + k + 1);
    cout << "�����Ӽ�Ϊ:";
    for (int i = 0; i <= k; i++) {
        cout << b[i] << " ";
    }
    system("pause");
    return 0;
}
