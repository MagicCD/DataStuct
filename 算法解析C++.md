# 算法代码笔记



## 1. 顺序表的创建



+ 顺序表由结构体的成员属性决定，一般的，我们在顺序表的结构体中创建 ==顺序表数组==和==顺序表表长==
+ 以下是两种方法定义结构体



<h3>⭐顺序表的创建步骤：</h3>

1. 定义结构体 SqList，成员变量有 整型数组和数组长度



自己定义的：

~~~cpp
#define MAXSIZE 100

//定义结构体变量 SqList
struct SqList
{
public:
	int element[MAXSIZE];	//用来存放用户输入的数据元素
	int length;				//存放数组的长度
};
~~~



书本定义的：

~~~cpp
//定义宏常量 MAXSIZE = 100;
#define MAXSIZE 100

//将 int 改名为 ElemType
typedef int ElemType;

//将 struct 改名为 SqList
typedef struct SqList
{
public:
	ElemType data[MAXSIZE];	  //相当于 int data[100];
	int length;				  //定义顺序表长度，也可以改成 ElemType length
};
~~~



2. 在主函数中创建结构体变量，并通过语句 cin 给 数组元素和数组长度 赋值



自己定义的：

~~~cpp
int main()
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
}
~~~



书本定义的：

~~~cpp
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
}
~~~



3. 定义函数 printArray 来访问数组中的元素，并且在主函数中调用



自己写的：

~~~cpp
void printArray(struct SqList s1)
{
	cout << "以下是你输入的数据元素：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.element[i] << " ";
	}
}

int main()
{
    struct SqList s1;
    printArray(s1);
}
~~~



书本写的：

~~~cpp
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
    printArray(s1);
}
~~~



***



<h1>顺序表创建及遍历示例</h1>



按照书本的定义写的：

~~~cpp
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
~~~





自己写的：

~~~cpp
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
~~~









## 2. 顺序表的各项操作



### 2.1 获得元素



对于线性表的顺序存储结构来说，如果我们要实现 GetElem 操作。即将线性表 L 中的第 i 个位置元素值返回

其实是非常简单的，就程序而言，只要 i 的数值在数组的下标范围内，就是把数组第 i - 1 下标的值返回即可



`GetElem (SqList &l, int i, ElemType *e)`

+ 传入顺序表 SqList，传入要获得的第 i 个元素，*e用来接收 顺序表SqList 在 第 i 个元素位置 返回的数据



按自己的理解写的

示例：

~~~cpp
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
~~~



按书上理解写的：

~~~cpp
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
~~~





## 3. 单链表的创建



+ 参考 bolg：

[C++ 详解创建链表过程](https://blog.csdn.net/qq_41620518/article/details/81143414)

[一步一步教你从零开始写C语言链表](https://zhuanlan.zhihu.com/p/85504177)

[typedef介绍](https://blog.csdn.net/liitdar/article/details/80069638)

[关于typedef的用法总结](https://blog.csdn.net/wangqiulin123456/article/details/8284939)



+ 代码示意：

  1. `typedef`：类型定义（是C语言的关键字）

  + 作用：为一种 ==数据类型== 定义一个 ==新名字==
  + 这里的数据类型包括 <font color="red">内部数据类型（如 int 、char）和自定义的数据类型（struct等）</font>



+ 用法：在 定义传统变量名 的情况下，用 ==自定义的数据类型名== 替换 传统的数据类型名，然后加入 typedef



示例1：

~~~cpp
int main()
{
	//typedef 的用法
	int a = 10;		//定义传统变量，变量名为 a，数据类型为 int
	cout << "使用传统定义变量的结果 a = " << a << endl;	//10

	//使用 typedef 重命名
	//用法：在 定义传统变量名的情况下，用 自定义的数据类型名 替换 传统的数据类型名，然后加入 typedef
	typedef int element;	//这行代码的意思是：把 int 用自定义的 element 替换，使element具有int的功能
	element b = 30;
	cout << "使用typedef定义变量的结果 b = " << b << endl;	//30

	//验证使用 typedef 重新定义的数据类型 是否是 整型
	b = 23.5;
	cout << "使用typedef定义变量的结果 b = " << b << endl;	//23
}
~~~









### 1.1 头插法



示例：

~~~cpp
#include <iostream>
using namespace std;

//1.创建链表结构体
struct LinkList
{
    int data;              //数据域
    struct LinkList *next; //指针域
};

typedef struct LinkList lNode;

void creatLinkList(lNode *l, int length)
{
    lNode *p = l;

    cout << "please input element Data: " << endl;
    for (int i = 0; i < length; i++)
    {
        lNode *pNewNode = new lNode; //创建一个新结点

        //为新结点的数据域和指针域赋值
        cin >> pNewNode->data;
        pNewNode->next = NULL;

        //进行头插法
        p->next = pNewNode; //把新结点的地址赋值给上一个结点，也就是上一个结点的指针域存放新结点的地址
        p = pNewNode;
    }


}

void traveLinkList(lNode *l, int length)
{
    lNode *p = l->next;

    cout << "Link List element Display: " << endl;
    for(int i = 0; i < length; i++)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    //创建一个结构体指针，指针指向为空
    lNode *pointer = NULL;

    //创建空链表结点
    pointer = new lNode;

    //初始化
    pointer->data = 0;
    pointer->next = NULL;

    //输入表长
    int len = 0;
    cout << "please input you need save LinkList Length: " << endl;
    cin >> len;
    cout << "you need input " << len << "element to Link List: " << endl;

    //调用函数 creatLinkList
    creatLinkList(pointer, len);

    //调用函数 traveLinkList
    traveLinkList(pointer, len);

    system("pause");
    return 0;
}
~~~

