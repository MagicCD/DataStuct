#include <iostream>
using namespace std;

#define MAXSIZE 100

//定义结构体变量 SqList
struct SqList
{
public:
	int element[MAXSIZE];	//用来存放用户输入的数据元素
	int length;				//存放数组的长度
};

//遍历顺序表的数据元素
void printArray(struct SqList s1)
{
	cout << "以下是你输入的数据元素：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.element[i] << " ";
	}
}

int main2()
{
	//创建结构体变量 s1
	struct SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cin >> s1.element[i];
	}
	
	//调用函数 printArray
	printArray(s1);

	cout << endl;
	
	system("pause");
	return 0;
}