#include <iostream>
using namespace std;

#define MAXSIZE 100

//1.�����ṹ�� SqList
struct SqList
{
public:
	int data[MAXSIZE];
	int length;
};

//2.������ȡ����Ԫ�صĺ������ж�Ҫ��ȡ��Ԫ��λ���Ƿ�Ϸ�
int GetElem(struct SqList s1, int i, int *e)
{
	if (i < s1.length || s1.length == 0 || i > s1.length)
	{
		return 0;
	}

	*e = s1.data[i - 1];
	cout << "�� " << i << " ��Ԫ�ص�ֵΪ��" << *e << endl;
	return 1;
}

int main()
{
	struct SqList s1;

	cout << "��������Ҫ������˳����ȣ�" << endl;
	cin >> s1.length;

	cout << "���������������Ԫ�أ�" << endl;
	for (int a = 0; a < s1.length; a++)
	{
		cin >> s1.data[a];
	}

	cout << "��������Ҫ���ʵ�����Ԫ�ص�λ��" << endl;
	int n;
	cin >> n;

	int result = GetElem(s1, n, s1.data);
	cout << result << endl;

	system("pause");
	return 0;
}