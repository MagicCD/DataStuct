#include <iostream>
using namespace std;

//1.�ȶ����������Ҫʹ�õĳ���
#define MAXSIZE 100

//���壺��ѯ��i��Ԫ��GetElem�Ĳ����Ƿ�ɹ�
#define OK 1
#define ERROR 0

//���壺�������ͣ����غ������״̬�Ĵ��룬��������Ƿ��� OK ERROR��
typedef int Status;
typedef int ElemType;

//2.�����ṹ��
struct SqList
{
public:
	int data[MAXSIZE];
	int length;
};

//�� struct SqList ������Ϊ SqList
typedef struct SqList SqList;

//3.������ȡ����Ԫ�صĺ������ж�Ҫ��ȡ��Ԫ��λ���Ƿ�Ϸ�
Status GetElem(SqList s1, int i, ElemType *e)
{
	if (s1.length == 0 || i < 1 || i > s1.length)
	{
		return ERROR;
	}

	*e = s1.data[i - 1];
	cout << "�� " << i << " ��Ԫ�ص�ֵΪ��" << *e << endl;
	return OK;
}

int main()
{
	SqList s1;

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