#include <iostream>
using namespace std;

//����곣�� MAXSIZE = 100;
#define MAXSIZE 100

//�� int ����Ϊ ElemType
typedef int ElemType;

//�� struct ����Ϊ SqList
typedef struct SqList
{
	ElemType data[MAXSIZE];	  //�൱�� int data[100];
	int length;				  //����˳����ȣ�Ҳ���Ըĳ� ElemType length
};

void printArray(SqList s1)
{
	cout << "�����������������Ԫ�أ�" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.data[i] << " ";
	}
}

int main()
{
	SqList s1;

	cout << "��������Ҫ������˳����ȣ�" << endl;
	cin >> s1.length;

	cout << "���������������Ԫ�أ�" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cin >> s1.data[i];
	}

	printArray(s1);

	cout << endl;
	
	system("pause");
	return 0;
}