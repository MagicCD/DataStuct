#include <iostream>
using namespace std;

//1.先定义好我们需要使用的常量
#define MAXSIZE 100

//定义：查询第i个元素GetElem的操作是否成功
#define OK 1
#define ERROR 0

//定义：函数类型，返回函数结果状态的代码，在这里就是返回 OK ERROR等
typedef int Status;
typedef int ElemType;

//2.创建结构体
struct SqList
{
public:
	int data[MAXSIZE];
	int length;
};

//把 struct SqList 重命名为 SqList
typedef struct SqList SqList;

//3.创建获取数据元素的函数，判断要获取的元素位置是否合法
Status GetElem(SqList s1, int i, ElemType *e)
{
	if (s1.length == 0 || i < 1 || i > s1.length)
	{
		return ERROR;
	}

	*e = s1.data[i - 1];
	cout << "第 " << i << " 号元素的值为：" << *e << endl;
	return OK;
}

int main()
{
	SqList s1;

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