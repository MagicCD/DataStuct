#include <iostream>
using namespace std;

//定义宏常量 MAXSIZE = 100;
#define MAXSIZE 100

//将 int 改名为 ElemType
typedef int ElemType;

//将 struct 改名为 SqList
typedef struct SqList
{
	ElemType data[MAXSIZE];	  //相当于 int data[100];
	int length;				  //定义顺序表长度，也可以改成 ElemType length
};

void printArray(SqList s1)
{
	cout << "以下是你输入的数据元素：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.data[i] << " ";
	}
}

int main()
{
	SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cin >> s1.data[i];
	}

	printArray(s1);

	cout << endl;
	
	system("pause");
	return 0;
}