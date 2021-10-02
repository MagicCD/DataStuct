#include <iostream>
using namespace std;

#define MAXSIZE 100

//1.创建结构体 SqList
struct SqList
{
public:
	int data[MAXSIZE];
	int length;
};

//2.创建获取数据元素的函数，判断要获取的元素位置是否合法
int GetElem(struct SqList s1, int i, int *e)
{
	if (i < s1.length || s1.length == 0 || i > s1.length)
	{
		return 0;
	}

	*e = s1.data[i - 1];
	cout << "第 " << i << " 号元素的值为：" << *e << endl;
	return 1;
}

int main()
{
	struct SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int a = 0; a < s1.length; a++)
	{
		cin >> s1.data[a];
	}

	cout << "请输入你要访问的数据元素的位置" << endl;
	int n;
	cin >> n;

	int result = GetElem(s1, n, s1.data);
	cout << result << endl;

	system("pause");
	return 0;
}