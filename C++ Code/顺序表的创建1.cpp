#include <iostream>
using namespace std;

#define MAXSIZE 100

//����ṹ����� SqList
struct SqList
{
public:
	int element[MAXSIZE];	//��������û����������Ԫ��
	int length;				//�������ĳ���
};

//����˳��������Ԫ��
void printArray(struct SqList s1)
{
	cout << "�����������������Ԫ�أ�" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.element[i] << " ";
	}
}

int main2()
{
	//�����ṹ����� s1
	struct SqList s1;

	cout << "��������Ҫ������˳����ȣ�" << endl;
	cin >> s1.length;

	cout << "���������������Ԫ�أ�" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cin >> s1.element[i];
	}
	
	//���ú��� printArray
	printArray(s1);

	cout << endl;
	
	system("pause");
	return 0;
}