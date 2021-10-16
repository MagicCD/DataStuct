﻿# 算法代码笔记

> 本章讨论有关线性表的各项操作


## 1. 顺序表的创建



+ 顺序表由结构体的成员属性决定，一般的，我们在顺序表的结构体中创建 ==顺序表数组==和==顺序表表长==
+ 以下是两种方法定义结构体



<h3>⭐顺序表的创建步骤：</h3>



1. 定义结构体 SqList，成员变量有 整型数组和数组长度

自己尝试：

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



按照书本写的

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





以下是创建和遍历的关键代码



**创建**：

~~~cpp
void createSqList(SqList &L)
{
	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> L.length;

	cout << "请输入" << L.length << "个数据" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cin >> L.data[i];
	}
}
~~~



**遍历**：

~~~java
void printSqList(SqList L, int len)
{
	cout << "遍历的结果为：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;
}
~~~





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



关键的代码片段（绑定函数）：

~~~cpp
//获得顺序表的元素
//获得的第 i 个元素，*e用来接收 顺序表SqList 在 第 i 个元素位置和数据
int GetElem(SqList L, int i, int* e)
{
	//先判断 i 是否合法
	//不合法情况：查找位置 大于表长或小于1 // 表长为0（也就是顺序表不存在）
	if (i < 1 || i > L.length || L.length == 0)
	{
		cout << "操作失败！你查找的位置不存在" << endl;
		return 0;
	}

	//用e存储带回查找的元素值，i-1为数组下标
	*e = L.data[i - 1];
	cout << "查找成功！第" << i << "号位置的元素数值为：" << *e << endl;
	return 1;
}
void GetFunction(SqList L)
{
	int i = 0;
	cout << "请输入查找第几号位置：" << endl;
	cin >> i;
	GetElem(L, i, L.data);
}
~~~





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
    //先判断 i 是否合法
	//不合法情况：查找位置 大于或小于 表长 // 表长为0（也就是顺序表不存在）
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
![请添加图片描述](https://img-blog.csdnimg.cn/7f4bbbbe01694ed0bc50a06a8bdce579.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16)










### 2.2 插入元素



刚才我们也谈到，这里的时间复杂度为 O(1)。我们现在来考虑，如果我们要实现 ListInsert(*L, i, e)

即在线性表中的第 i 个位置插入新元素e，应该如何操作？



举个例子，我们在春运时去买火车票，大家都在排队排的好好的，这时来了一个美女，对着队伍中排在第三位的你说

“大哥，求求你帮帮忙，我家母亲又病，我得急着回去看她，这队伍这么长，你可否让我排在你的前面？” 你心一软

就同意了。这时，你必须后退一步，否则她是没办法进到队伍里面来的。这可不得了，后面的人像蠕虫一样

全部都得后退一步。骂声四起，但后面的人也不清楚这加塞是怎么回事，没什么办法。



![请添加图片描述](https://img-blog.csdnimg.cn/e1c70b503eb9452ca257d7c0add481c2.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_12,color_FFFFFF,t_70,g_se,x_16)


<h2>插入算法的思路</h2>



+ 如果插入位置不合理，抛出异常
+ 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量
+ 从最后一个元素开始向前遍历到第 i 个位置，分别将他们都向后移动一个位置
+ 将要插入的元素填入位置 i 处
+ 表长加1



代码片段：

~~~cpp
//插入元素
//在线性表中的第 i 个位置插入新元素e
int insertSqList(SqList& L, int i, int e)
{
	if (L.length == MAXSIZE)
	{
		cout << "顺序表已满！插入失败！" << endl;
		return 0;
	}
	if (i < 1 || i > L.length + 1)
	{
		cout << "插入位置不合法！插入失败！" << endl;
		return 0;
	}

	int k;	//定义下标
	if (i <= L.length)
	{
		//括号括起来的是下标
		for(k = (L.length - 1); k >= (i - 1); k--)
		{
			L.data[k + 1] = L.data[k];
		}
	}

	//插入元素
	L.data[i - 1] = e;
	L.length++;
	cout << "操作成功！" << endl;
	return 1;
}
void insertFunction(SqList& L)
{
	int i = 0;
	cout << "请输入你要插入的位置：" << endl;
	cin >> i;

	int e = 0;
	cout << "请输入你要插入的数值：" << endl;
	cin >> e;

	insertSqList(L, i, e);
}
~~~





自己理解写的

示例：

~~~cpp
#include <iostream>
using namespace std;

#define MAXSIZE 100

struct SqList
{
	int data[MAXSIZE];
	int length;
};

//这里必须使用引用修改实参，否则使用值传递是无法获得插入的数据的
//因为局部变量在执行完毕时已经被销毁，所以无法访问插入的数组
int ListInsert(struct SqList& s1, int i, int e)
{
	//判断 插入元素插入的位置是否合法
	//不合法的插入情况：
	//1.顺序表已满，没有空间，不能插入
	//2.插入位置超过表尾
	//3.插入位置比第一个元素还前面，比如 0、-1等位置插入
	if (i < 1 || i > s1.length + 1 || s1.length == MAXSIZE)
	{
		return 0;
	}

	int k;
	if (i <= s1.length + 1)		//若插入的元素不在顺序表的表尾
	{
		//把 第i个位置及第i个位置后的元素向后移动一位
		for (k = s1.length - 1; k >= i - 1; k--)
		{
			s1.data[k + 1] = s1.data[k];
		}

		//把 要插入的元素e 赋值给 第i号位置，第i号位置的下标为 i-1
		s1.data[i - 1] = e;
		s1.length++;
		return 1;
	}
}

void printArray(struct SqList s1, int len)
{
	cout << "数组插入元素后：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << s1.data[i] << " ";
	}
}

int main()
{
	struct SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int n = 0; n < s1.length; n++)
	{
		cin >> s1.data[n];
	}

	cout << "数组插入元素前：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.data[i] << " ";
	}

	cout << endl;

	cout << "请输入你要插入的数据元素的位置" << endl;
	int insert;
	cin >> insert;

	cout << "请输入你要插入的数值：" << endl;
	int insertData;
	cin >> insertData;

	int result = ListInsert(s1, insert, insertData);
	cout << result << endl;

	printArray(s1, s1.length);

	cout << endl;

	system("pause");
	return 0;
}
~~~





按书上理解写的

示例：

~~~cpp
#include <iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

struct SqList
{
public:
	ElemType data[MAXSIZE];
	int length;
};

typedef struct SqList SqList;

Status ListInsert(SqList &l, int i, ElemType e)
{
	//开始判断情况
	if (l.length == MAXSIZE)
	{
		return 0;
	}
	if (i < 1 || i > l.length + 1)
	{
		return 0;
	}

	int k;
	//其实可以省去这部分的判断
	if (i <= l.length)
	{
		for (k = l.length - 1; k >= i - 1; k--)
		{
			//移动数据
			l.data[k + 1] = l.data[k];
		}

		/*//插入数据
		l.data[i - 1] = e;
		l.length++;
		return OK;*/
	}

	//插入数据
	l.data[i - 1] = e;
	l.length++;
	return OK;
	//return 0;
}

void printArray(SqList l, int len)
{
	cout << "数组插入元素之后：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << l.data[i] << " ";
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

	cout << "数组插入元素之前：" << endl;
	for (int i = 0; i < s1.length; i++)
	{
		cout << s1.data[i] << " ";
	}

	cout << endl;

	cout << "请输入你要插入的数据元素的位置" << endl;
	int insert;
	cin >> insert;

	cout << "请输入你要插入的数值：" << endl;
	int insertData;
	cin >> insertData;

	int result = ListInsert(s1, insert, insertData);
	cout << result << endl;

	printArray(s1, s1.length);

	cout << endl;

	system("pause");
	return 0;
}
~~~







<h3>问题分析</h3>



在程序运行时，我遇到的问题

1. 插入元素的函数在完成插入成功的操作时，返回的值为乱码，且没有插入成功

![在这里插入图片描述](https://img-blog.csdnimg.cn/cef47fb2033546b9960f9b62aec9e627.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_17,color_FFFFFF,t_70,g_se,x_16#pic_center)




2. 后来我修改了判断的条件 把 i <= l.length 改成 i <= l.length + 1，程序运行正常

![在这里插入图片描述](https://img-blog.csdnimg.cn/70f827b01b5645ff90249612293cd0b3.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_17,color_FFFFFF,t_70,g_se,x_16#pic_center)

> 由此分析，问题可能出现在判断条件上

于是列举问题分析程序运行步骤
![在这里插入图片描述](https://img-blog.csdnimg.cn/663681336cee4be6938764d4e61faef6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




修改程序：

![在这里插入图片描述](https://img-blog.csdnimg.cn/bc944c225e124b7db8da3a4aede7a88d.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_17,color_FFFFFF,t_70,g_se,x_16#pic_center)
> 但是这又引发了我的思考，为什么判断条件改成 i <= l.length + 1 就行了？

于是我又开始分析程序
![在这里插入图片描述](https://img-blog.csdnimg.cn/6e0e0bb309a7481dabfde6fb24dd06a6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

> 至此，我在编写顺序表插入元素中所遇到的问题就是这些了







### 2.3 删除元素



接着刚才的例子，此时后面排队的人群意见都很大，都说怎么可以这样，不管是什么原因，插队就是不行

有本事，找火车站开后门去。就在这时，远处跑来一胖子对着这美女喊，可找到你了，你这骗子，还我钱。

只见这女子二话不说，突然就冲出了队伍，胖子追在其后，消失在人群中。哦，原来她就是倒卖火车票的黄牛

刚才还挺可怜。于是排队的人群，又像蠕虫一样，均向前移动了一步，骂声渐息，队伍又恢复了平静



*这就是线性表的顺序存储结构删除元素的过程*

![在这里插入图片描述](https://img-blog.csdnimg.cn/46b91c73970c48bbb2463c89f38e0a52.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_18,color_FFFFFF,t_70,g_se,x_16#pic_center)






<h3>删除算法的思路</h3>

1. 如果删除位置不合理，抛出异常
2. 去除删除元素
3. 从删除元素位置开始遍历到最后一个元素的位置，分别将他们都向前移动一个位置
4. 表长减1



代码片段：

~~~cpp
//删除元素
//传入顺序表L，删除第i个位置的元素并带回被删除的元素
int deleteElem(SqList& L, int i, int* e)
{
	//还是判断位置的合法性，大于表长或小于1，或者表不存在
	if (L.length == 0)
	{
		cout << "删除失败！请先创建顺序表！" << endl;
		return 0;
	}
	if (i < 1 || i > L.length)
	{
		cout << "删除失败！删除位置不合法！" << endl;
		return 0;
	}

	//带回被删除的元素
	*e = L.data[i - 1];

	int k;	//记录下标
	//括号括起来的是下标
	if (i < L.length)
	{
		for (k = (i - 1); k < (L.length - 1); k++)
		{
			L.data[k] = L.data[k + 1];
		}
	}

	L.length--;	//表长减1
	return 1;
}
void deleteFunction(SqList& L)
{
	int i;
	cout << "请输入你要删除第几号元素：" << endl;
	cin >> i;

	//创建一个恢复变量，用来保存删除的数值
	int recovery;
	deleteElem(L, i, &recovery);
	cout << "被删除的数值是：" << recovery << endl;
}
~~~





自己理解写的

示例：

~~~cpp
#include <iostream>
using namespace std;

#define MAXSIZE 100

struct SqList
{
	int data[MAXSIZE];
	int length;
};

int ListDelete(struct SqList& l, int i, int* e)
{
	//判断顺序表的空位和合法性
	if (l.length == 0)
	{
		return 0;
	}
	if (i < 1 || i > l.length)
	{
		return 0;
	}

	//指向顺序表要删除的位置
	*e = l.data[i - 1];

	int k;				//记录下标
	if (i < l.length)	//删除元素不在表尾
	{
		for (k = i; k < l.length; k++)
		{
			l.data[k - 1] = l.data[k];
		}
	}

	//表长减1
	l.length--;
	return 1;
}

void printArray(struct SqList &l, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << l.data[i] << " ";
	}
}

int main()
{
	struct SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int n = 0; n < s1.length; n++)
	{
		cin >> s1.data[n];
	}

	int deleleteData;
	cout << "请输入你要删除的元素位置：" << endl;
	cin >> deleleteData;

	int result = ListDelete(s1, deleleteData, &deleleteData); //s1.data;
	cout << result << endl;

	printArray(s1, s1.length);

	cout << endl;

	system("pause");
	return 0;
}
~~~







<h3>问题分析</h3>



1. 在执行程序的时候，我发现无论我需要删除第i个位置的元素，最后遍历输出的结果都是 *第i个位置 取代第一个元素*

![在这里插入图片描述](https://img-blog.csdnimg.cn/056706c43d5d431580ebbd946812f814.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_16,color_FFFFFF,t_70,g_se,x_16#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/78a2a60723074d01853d9c0586b4922c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_17,color_FFFFFF,t_70,g_se,x_16#pic_center)




2. 开始调试找出问题，逐语句执行代码段

到目前为止还是正常数值

![在这里插入图片描述](https://img-blog.csdnimg.cn/aecce3df122d464090589fd95093d8f3.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




+ 直到运行到第 28行，底下的数组值发生变化

![在这里插入图片描述](https://img-blog.csdnimg.cn/654daf1a202f473abb3912fd51552390.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




+ 分析时出现问题的行数在 第25行 ~ 第28行之间，故在第25行和28行打2个断点观察数值变化

![在这里插入图片描述](https://img-blog.csdnimg.cn/4ba68f62daf24881a4d1411e95efe32b.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




问题分析：

![在这里插入图片描述](https://img-blog.csdnimg.cn/065743d93a6747728de96726f892f90d.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)


> 故由这个问题可知，我们传入的实参有误，但是我们要先清楚 语句 *e = l.data[i - 1]是用来做什么的



参考以下blog：

[顺序表的删除](https://blog.csdn.net/m0_37036984/article/details/78440754)

[顺序表的删除操作](https://blog.csdn.net/inooll/article/details/105645732)



不难发现，int *e 作用其实就是保存被删除的数值，那么传入的实参其实应该是记录被删除的值的一个整型变量

故，我传入 s1.data 是不对的
![在这里插入图片描述](https://img-blog.csdnimg.cn/ee7eaf32fbd04add84bd063ca1540881.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




按书上理解：

~~~cpp
#include <iostream>
using namespace std;

#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

//1.创建结构体
struct SqList
{
	ElemType data[MAXSIZE];
	int length;
};
typedef struct SqList SqList;

Status ListDelete(SqList &l, int i, ElemType *e)
{
	//1.判断删除位置是否合法
	if (i < 1 || i > l.length)
	{
		return ERROR;
	}

	//用指针 *e保存被删除的元素值
	*e = l.data[i - 1];

	int k;		//记录下标位置
	if (i < l.length)	//如果删除位置不在表尾
	{
		for (k = i; k < l.length; k++)
		{
			l.data[k - 1] = l.data[k];	//把后一个值赋值给前一个位置
		}
	}

	//表长减1
	l.length--;
	return OK;
}

void printArray(SqList &s1, int len)
{
	for (int i = 0; i < len; i++)
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
	for (int n = 0; n < s1.length; n++)
	{
		cin >> s1.data[n];
	}

	int deleleteData;
	cout << "请输入你要删除的元素位置：" << endl;
	cin >> deleleteData;

	int recovery;		//创建一个恢复变量，用来保存删除的数值
	int result = ListDelete(s1, deleleteData, &recovery); //传入s1.data是错误的;
	cout << result << endl;

	printArray(s1, s1.length);

	cout << endl;

	system("pause");
	return 0;
}
~~~









### 2.4 查找元素





<h3>算法步骤：</h3>

1. 从第一个元素起，依次和 e 相比较，若找到与 e 相等的元素 L.elem[i]，则查找成功，返回该元素的序号 i + 1
2. 若查遍整个顺序表都没有找到，则查找失败，返回 0



代码片段（核心部分）：

~~~cpp
int locateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
		{
			cout << "查找成功！元素在" << (i + 1) << "号位置" << endl;
			return 1;
		}
	}
	cout << "查找失败！没有此元素！" << endl;
	return 0;
}
void locateElem(SqList L)
{
	int Elem;
	cout << "请输入你要查找的元素数值：" << endl;
	cin >> Elem;

	locateElem(L, Elem);
}
~~~





示例：

~~~cpp
#include <iostream>
using namespace std;

#define MAXSIZE 100

struct SqList
{
	int data[MAXSIZE];
	int length;
};

int LocateElem(struct SqList s1, int e)
{
	for (int i = 0; i < s1.length; i++)
	{
		//如果找到与输入值相同的元素，则返回下标
		if (e == s1.data[i])
		{
			return i + 1;	//返回下标
		}
	}
	return 0;
}

int main()
{
	struct  SqList s1;

	cout << "请输入你要创建的顺序表长度：" << endl;
	cin >> s1.length;

	cout << "请输入数组的数据元素：" << endl;
	for (int a = 0; a < s1.length; a++)
	{
		cin >> s1.data[a];
	}

	int findElem;
	cout << "请输入你要查找的值：" << endl;
	cin >> findElem;

	int result = LocateElem(s1, findElem);
	if (result == 1)
	{
		cout << "操作成功，位置在第" << result << "号" << endl;
	}
	else
	{
		cout << "查找失败" << endl;
	}

	system("pause");
	return 0;
}
~~~













## 3. 单链表的创建



前面我们讲的线性表的顺序存储结构。他是有缺点的，最大的缺点就是插入和删除时需要移动大量的元素

这显然就需要耗费时间，能不能想办法解决呢？



思路：

我们反正也是要让相邻元素间留有足够的余地，那干脆所有的元素都不要考虑相邻位置了，哪里有空位就到哪里

而只是让每个元素知道它下一个元素的位置在哪里，这样，我们可以在第一个元素时，就知道第二个元素的位置（内存地址）

而找到他；在第二个元素时，再找到第三个元素的位置（内存地址）。这样所有的元素我们就可以通过遍历而找到





+ 参考 blog：

[单链表的创建](https://blog.csdn.net/cprimesplus/article/details/82588179)

[单链表LinkList理解](https://blog.csdn.net/weixin_45870904/article/details/111655514?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-1.no_search_link&spm=1001.2101.3001.4242)

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







为了表示每个数据元素 a1 与其直接后继数据元素 ai + 1之间的逻辑关系，对数据元素 ai 来说，除了存储本身的信息之外

还需要存储一个指示其直接后继的信息（即直接后继的存储位置）。我们把 ==存储数据元素信息的域== 称为 ==数据域== 

把 ==存储直接后继位置的域== 称为 ==指针域==，指针域中存储的信息称作指针或链，这两部分信息组成数据元素 ai 的存储映像，称为**结点 Node**
![在这里插入图片描述](https://img-blog.csdnimg.cn/e99970ed85ae4f14a4784681ad9093f2.png#pic_center)
<h2>单链表的初始化操作：</h2>



自己理解写的

~~~cpp
//1.定义单链表结点的结构体
struct Node
{
	int data;
	struct Node* next;
};

int main()
{
	//声明一个指向单链表第一个节点的指针
	struct Node* L;
	L = new struct Node;	//创建新结点
	L->next = NULL;		//初始化操作

	system("pause");
	return 0;
}
~~~



按书上理解写的：

~~~cpp
//1.定义单链表结点的结构体
struct Node
{
	int data;	//数据域
	struct Node* next;	//指针域，存放后继节点的地址
};

typedef struct Node LNode;
typedef struct Node* Linklist;		//Linklist 相当于 struct Node*

//初始化链表
void InitList(Linklist &L)
{
	L = new LNode;	//创建新结点，包含数据域和指针域
	L->next = NULL;	//新结点的指针域为NULL
}

int main()
{
	//定义链表 L
	Linklist L;		//相当于struct Node* L; 存放的是链表首元素地址

	InitList(L);

	system("pause");
	return 0;
}
~~~









## 4. 单链表的各项操作





初始化操作是创建一个只有头结点的空链表，那么如何创建包括若干结点的链表呢？

创建链表时根据结点插入位置不同，链表的创建方法可分为前插法和后插法。





<h3>参考视频</h3>



+ 先看视频了解原理，再来写代码会理解的更快，up讲的很详细

[【数据结构】链表->头插法](https://www.bilibili.com/video/BV1tE41117id?spm_id_from=333.999.0.0)







### 4.1 头插法





步骤：

1. 创建一个头结点
2. 头结点的指针域置空
3. 创建一个新结点的指针，存放新结点的地址
4. 进入循环，循环条件是 i < 链表的长度，当 i = 链表长度时停止循环
5. 进入循环体后，执行以下语句
   + 创建一个新结点p
   + 新结点的指针域置空
   + 从键盘输入数据
   + 结点p的指针域，指向头结点的后一个结点
   + 头结点的指针指向新结点p
6. 完成头插法





核心代码：

~~~cpp
//创建链表
//传入链表L和链表的长度n
void creatLinkList(LinkList& L, int n)
{
	L = new LNode;	//创建一个头结点
	L->next = NULL;	//头结点的指针域置空

	LNode* p;	//创建一个新结点的指针，存放新结点的地址

	//头插法循环插入元素
	cout << "请输入你要插入的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;		//创建一个新结点p
		p->next = NULL;		//新结点指针域置空

		cin >> p->data;

		p->next = L->next;	//结点p的指针域，指向头结点的后一个结点
		L->next = p;		//头结点的指针指向新结点p
	}
}
void creatLinkList_HFunction(LinkList& L)
{
	cout << "请输入你要创建的链表长度：" << endl;
	int n;
	cin >> n;
	creatLinkList(L, n);
}
~~~







示例：

~~~cpp
#include <iostream>
using namespace std;

//创捷结点的数据结构
struct Node
{
	int data;		//数据域
	struct Node* next;	//指针域
};

typedef struct Node LNode;	//重定义struct Node为LNode，使LNode具有struct Node的功能，功能为结点
typedef struct Node* LinkList; //同理，使LinkList具有struct Node*的功能

//创建链表
void creatLinkList(LinkList &L, int n)
{
	L = new LNode;	//创建一个头结点
	L->next = NULL;	//头结点的指针域置空

	LNode* p;	//创建一个新结点的指针，存放新结点的地址

	//头插法循环插入元素
	cout << "请输入你要插入的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;		//创建一个新结点p
		p->next = NULL;		//新结点指针域置空

		cin >> p->data;

		p->next = L->next;	//结点p的指针域，指向头结点的后一个结点
		L->next = p;		//头结点的指针指向新结点p
	}
}

//遍历链表
void traverseLinkList(LinkList &L)
{
	LinkList p;		//定义一个遍历指针p
	p = L->next;	//指针p指向头结点的后一个结点

	cout << "输出链表：" << endl;
	while (p != NULL)	//p结点遍历时不为空就执行语句
	{
		cout << p->data << " ";
		p = p->next;	//指针后移
	}
}

int main()
{
	LinkList L;	  //链表的头指针

	cout << "请输入你要创建的链表长度：" << endl;
	int n;
	cin >> n;
	creatLinkList(L, n);

	traverseLinkList(L);

	system("pause");
	return 0;
}
~~~









### 4.2 尾插法





<h3>参考视频</h3>

[尾插法创建单链表及链表的遍历](https://www.bilibili.com/video/BV1VE411B7LG)





步骤：

1. 创建头结点

2. 初始化头结点的指针域

3. 定义2个结构体指针，LNode *p、LNode *r

   + `LNode *p`用来存放新结点的地址，`LNode *r`是工作指针，代替L完成尾插法插入元素的操作

   + `LNode *r`工作指针指向头结点

4. 进入到循环体

   + 进入循环，循环条件是 i < 链表的长度，当 i = 链表长度时停止循环
   + 创建新结点，用 p 存放该结点的地址
   + 从键盘输入新结点的数据域
   + 用 ==r工作指针== 把*头结点*的 ==next域== 指向 新结点的地址
   + 指针移动，指向新插入的结点p
   + 新结点的指针域置空

5. 完成尾插法







核心代码：

~~~cpp
//尾插法建立单链表
void creatLinkList2(LinkList& L, int n)
{
	L = new LNode;		//创建头结点
	L->next = NULL;		//初始化头结点的指针域

	LNode* p;	//创建新结点的指针，存放新结点的地址
	LNode* r;	//定义一个指针，代替L完成尾插法插入元素的操作

	r = L;	//r指针指向头结点

	cout << "请输入你要插入的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;		//创建新结点，并用p存放该新结点的地址
		cin >> p->data;

		r->next = p;		//头结点的next域由原来的NULL，指向新结点p
		r = p;				//指针移动，指向新插入的结点p

		p->next = NULL;		//新结点的指针域置空
	}
}
void creatLinkList_FFunction(LinkList& L)
{
	cout << "请输入你要创建的链表长度：" << endl;
	int n;
	cin >> n;
	creatLinkList2(L, n);
}
~~~







示例：

~~~cpp
#include <iostream>
using namespace std;

//创建结点的数据结构
struct Node
{
	int data;			//结点的数据域
	struct Node* next;	//结点的指针域
};

typedef struct Node LNode;	//重定义struct Node为LNode，使LNode具有struct Node的功能，功能为结点
typedef struct Node* LinkList;	//同理，使LinkList具有struct Node*的功能

//尾插法建立单链表
void creatLinkList(LinkList &L, int n)
{
	L = new LNode;		//创建头结点
	L->next = NULL;		//初始化头结点的指针域

	LNode* p;	//创建新结点的指针，存放新结点的地址
	LNode* r;	//定义一个指针，代替L完成尾插法插入元素的操作

	r = L;	//r指针指向头结点

	cout << "请输入你要插入的数据：" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;		//创建新结点，并用p存放该新结点的地址
		cin >> p->data;

		r->next = p;		//头结点的next域由原来的NULL，指向新结点p
		r = p;				//指针移动，指向新插入的结点p

		p->next = NULL;		//新结点的指针域置空
	}

}

void traverseLinkList(LinkList& L)
{
	//创建指针存储首元结点的地址，其作用是遍历
	LNode* p;
	p = L->next;

	cout << "输出链表：" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		//指针后移
		p = p->next;
	}
}

int main()
{
	LinkList L;		//创建头指针

	cout << "请输入你要插入的元素个数：" << endl;
	int n;
	cin >> n;
	creatLinkList(L, n);

	traverseLinkList(L);

	system("pause");
	return 0;
}
~~~













### 4.3 遍历链表



步骤：

1. 定义一个遍历指针 p
2. 指针p指向头结点的后一个结点，也就是首元结点
3. 进入 while循环体
   + 判断条件为：当 p指向的结点地址不为空时，执行循环体语句
   + 输出 当前指针p指向的结点的数据域
   + 把当前结点指针域里存放后继结点的地址赋值给p，使得p指针后移
4. 完成遍历





核心代码：

~~~cpp
//遍历链表
void traverseLinkList(LinkList& L)
{
	LNode* p;		//定义一个遍历指针p
	p = L->next;	//指针p指向头结点的后一个结点

	cout << "输出链表：" << endl;
	while (p != NULL)	//p结点遍历时不为空就执行语句
	{
		cout << p->data << " ";
		p = p->next;	//指针后移
	}
}
~~~













### 4.4 读取元素



在线性表的顺序结构中，我们要计算任意一个元素的存储位置是很容易的。

但在单链表中，由于 第 i 个元素到底在哪？没办法一开始就知道，必须得从头开始找。

因此，对于单链表实现获取 第i个元素 的数据的操作 GetElem，在算法上相对要麻烦一些。



思路：

1. 声明一个结点 p 指向链表中的第一个结点，初始化 j 从 1 开始
2. 当 j < 1 时，就遍历链表，让 p 的指针向后移动，不断指向下一结点，j 累加 1
3. 若到链表末尾 p 为空，则说明 第i个元素不存在
4. 否则查找成功，返回结点 p 的数据





步骤：

1. 定义一个记录下标的变量j
2. 定义一个记录新结点地址的指针，也就是结点指针
3. 让下标计数器从1开始
4. 进入循环体
   + 当p指向的结点地址不为空 且 下标计数器 < 查找目标元素的下标，执行循环体
   + 指针后移
   + 下标计数器自增1
5. 进入判断语句
   + 当指针指向的结点地址为空 或 下标 > 获取元素的下标时（也就是我们 i <= 0）返回错误
   + 结束
6. 用 e带回链表中第i个元素位置的值
7. 结束查找





代码片段：

~~~cpp
//获取元素
//传入单链表，用e返回L中第i个数据元素的值
int GetElem(LinkList L, int i, int* e)
{
	int j;
	LNode* p;	//声明一结点指针p
	p = L->next;	//让p指向链表L的第一个结点（首元结点）
	j = 1;		//j为下标计数器

	//当p不为空，或下标 < 获取位置时，执行循环体
	while (p != NULL && j < i)
	{
		p = p->next;	//指针后移
		j++;
	}

	//当结点p等于空，下标 > 获取元素的位置时，返回错误，元素不存在
	if (p == NULL || j > i)
	{
		cout << "查找失败！元素不存在！" << endl;
		return 0;
	}

	//用e带回链表中第i个元素位置的值
	*e = p->data;
	cout << "查找成功!" << endl;
	return 1;
}
void getFunction(LinkList L)
{
	int i;
	cout << "请输入你要查找的元素位置：" << endl;
	cin >> i;

	int result;
	if (GetElem(L, i, &result) != 0)
	{
		cout << "第" << i << "号位置的元素值为：" << endl;
	}
}
~~~











### 4.5 查找元素





<h3>元素的按值查找</h3>





步骤：

1. 创建一个新的结点指针 `LNode *p`
2. 让 `LNode *p` 指向单链表的首元结点
3. 进入 while循环体
   + 循环体的条件是：当 指针p 指向的结点地址不为空 且 指针p指向的结点的data域不等于 我们要查找的元素值时，执行循环体
   + 循环体语句是：指针p后移
4. 查找成功，返回的是结点的地址 p，查找失败，返回的地址是NULL







代码片段：

~~~cpp
//查找元素
//在带头结点的单链表L中查找值为e的元素
LNode* LocateElem(LinkList L, int e)
{
	LNode* p;
	p = L->next;	//p指向首元结点

	//遍历单链表，当 p不为空 且 p指向的结点的data域不等于e时，执行循环体
	while (p != NULL && p->data != e)
	{
		p = p->next;	//指针后移
	}
	return p;	//查找成功，返回值为e的结点的地址p，查找失败则为NULL
}
void locateFunction(LinkList L)
{
	int elem;
	cout << "请输入你要查找的值：" << endl;
	cin >> elem;

	cout << LocateElem(L, elem);
}
~~~

> 疑问：
>
> 为什么返回值是一个结构体指针？
>
> 答：我们需要返回的是结点的地址，所以函数的返回值必须是结构体指针











### 4.6 插入元素





其实插入元素的算法类似于头插法和尾插法的结合



步骤：

1. 定义一个下标计数器，为后续的循环提供条件
2. 定义两个指针，一个是用来代替L完成插入操作的工作指针p，还有一个是用来存放新结点地址的指针s
3. 把链表的地址赋值给工作指针p，使工作指针p具有L的特性，从而完成插入操作
4. 把下标计数器初始化，从1开始
5. 进入循环体
   + 循环体的条件为：当 工作指针p 访问的结点地址不为空 且 下标 < 插入元素的位置时，执行循环体语句
   + 循环体语句：工作指针指针后移，下标计数器自增1
6. 进入判断：
   + 如果 工作指针p存放的结点地址 为空 或者 下标 > 插入位置时，返回错误，结束插入操作
7. 经过以上语句的判断，如果没有因为不合法位置结束插入操作时，就开始执行插入元素的操作
8. 创建一个新结点，并把新结点的地址赋值给 指针s
9. 把传入的插入数值元素e赋值给新结点s的data域
10. 类似于头插法，先把 新结点的next域指向 工作指针p的后继节点
11. 然后将 工作指针所指的结点的next域 指向 新结点s
12. 插入成功！完成插入操作







核心代码：

~~~cpp
//插入元素
//在L中第i个位置之前插入新的数据元素e，L的长度加1
int insertLinkList(LinkList& L, int i, int e)
{
	int j;

	LNode* p;		//工作指针，代替L完成插入操作
	LNode* s;		//新结点的指针s用来存放新结点的地址

	p = L;
	j = 1;	//下标计数器，从1开始

	//当 指针p指向的结点地址不为空 且 下标 < 插入元素的位置时，执行循环体
	while (p != NULL && j < i)
	{
		p = p->next;	//指针后移
		j++;	//下标计数器自增1
	}

	//如果 指针p为空 或者 下标 > 插入位置时，返回错误
	if (p == NULL || j > i)
	{
		cout << "插入失败！" << endl;
		return 0;
	}

	s = new LNode;

	s->data = e;
	s->next = p->next;
	p->next = s;

	cout << "插入成功！" << endl;
	return 1;
}
void insertFunction(LinkList& L)
{
	int i;
	cout << "请输入你要插入的位置：" << endl;
	cin >> i;

	int elemData;
	cout << "请输入你要插入的元素值：" << endl;
	cin >> elemData;

	insertLinkList(L, i, elemData);
}
~~~





> 验证循环体的循环条件的几种情况：

1. 正常插入

![在这里插入图片描述](https://img-blog.csdnimg.cn/623d5d1e5e674c609d491b69408c41c8.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_19,color_FFFFFF,t_70,g_se,x_16#pic_center)




2. 头部插入

![在这里插入图片描述](https://img-blog.csdnimg.cn/a42b1e465e774cff91af1703113f9a64.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)




3. 插入位置不合法

![在这里插入图片描述](https://img-blog.csdnimg.cn/b746daa33c534d328935657d36b79f9b.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)














### 4.7 删除元素





步骤：

1. 创建下标计数器，记录下标的变化和作为循环的条件
2. 定义两个指针，一个是用来 代替L完成插入操作的工作指针p，还有一个是 用来保存被删除的结点q
3. 把链表的地址给工作指针p，使工作指针拥有L的功能
4. 进入循环条件
   + 当 工作指针p的下一个结点不为空 且 下标 < 删除的位置，执行循环体指针后移，下标计数器自增1
5. 进入判断，当 工作指针p的下一个结点的地址为空 或 下标 > 删除的位置，删除失败，位置不存在！
6. 如果没有执行删除失败语句，则进入到删除操作，把 工作指针p的下一个结点（也就是要删除的结点）地址赋值给 保存删除结点的指针q
7. 工作指针p指向的结点 的 指针域指向 被删除结点的后一个结点
8. 用元素e备份被删除元素的数据域
9. 释放结点q
10. 完成删除操作







代码片段：

~~~cpp
//删除元素
//删除L的第i个数据元素，并用e返回其值，L的长度减1
int deleteElem(LinkList& L, int i, int* e)
{
	int j;

	LNode* p;
	LNode* q;	//保存要删除的结点

	p = L;

	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}

	if (!(p->next) || j > i)	//防止删除位置为0h
	{
		cout << "删除失败！位置不存在！" << endl;
		return 0;
	}
	//前面的部分与插入元素操作一模一样

	q = p->next;
	p->next = q->next;
	*e = q->data;

	delete q;
	cout << "删除成功！第" << i << "号元素已被删除，它的值为：" << *e << endl;
	return 1;
}
void deleteFunction(LinkList& L)
{
	int deleteData;
	cout << "请输入你要删除的元素的位置：" << endl;
	cin >> deleteData;

	int recovery;
	deleteElem(L, deleteData, &recovery);
}
~~~
![在这里插入图片描述](https://img-blog.csdnimg.cn/db1cabfe246e431aa9c317c1dbdbc6c9.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)








### 4.8 整表清空





<h3>清空链表：将所有除头节点以外的存放有数据的节点释放掉</h3>









步骤：

1. 定义两个指针，一个做删除结点的指针p，一个是用于找到当前结点的后继结点的指针q，从而为指针p提供移动的条件
2. 开始时指针p先指向首元结点
3. 进入循环条件
   + 当 指针p指向的结点地址不为空时
   + 指针q指向 指针p的后继节点
   + 删除指针p指向的结点
   + 指针p通过指针q后移
4. 完成删除操作后，头结点指针域置空
5. 完成销毁链表操作





核心代码：

~~~cpp
int clearList(LinkList &L)
{
	LNode* p;	//执行删除操作的指针
	LNode* q;	//用于找到当前结点的后继

	p = L->next;	//指向链表的首元结点
	while (p != NULL)	//当p指向的结点地址不为空时，执行循环体
	{
		q = p->next;	//指针后移
		delete p;	//删除结点p
		p = q;	//指针后移
	}

	L->next = NULL;		//删除所有元素后，头结点的指针域置空
	return 1;
}
~~~

![在这里插入图片描述](https://img-blog.csdnimg.cn/4245bc0c7a69464c94a9e23910e0120a.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
















### 4.9 整表销毁





<h3>销毁链表：将包括头结点在内的所有节点释放掉</h3>







步骤：

1. 定义两个指针，pre、p，一个用来做销毁操作，一个用来做指针后移的操作
2. 指针pre开始时先指向头结点
3. 指针p开始时先指向首元结点
4. 进入循环判断，当 指针p访问的结点地址不为空时，进入循环语句
   + 释放结点 pre
   + 指针pre 通过 指针p 后移
   + 指针p后移
5. 完成上述循环后，链表中还剩下最后一个元素，此时指针pre正指向这个元素，我们对结点pre进行释放
6. 完成销毁操作







核心代码：

~~~cpp
//销毁链表
void destoryLinkList(LinkList& L)
{
	LNode* pre;
	LNode* p;

    pre = L;
	p = L->next;

	//销毁操作
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p->next;	//后移指针
	}
    delete pre;
}
~~~



<h2>清空和销毁的区别：</h2>



1. 销毁的时候，是先销毁了链表的头，然后接着一个一个的把后面的销毁了，这样这个链表就不能再使用了
2. 清空的时候，是先保留了链表的头，然后把头后面的所有的都销毁，最后把头里指向下一个的指针设为空，这样就相当与清空了，但这个链表还在，还可以继续使用













### 4.10 逆置链表





参考视频：

[单链表的原地逆置](https://www.bilibili.com/video/BV1Z54y1U7Tc)







步骤：

1. 定义两个指针，一个是工作指针，一个是方便工作指针p 移动的指针r
2. 先让 工作指针p 指向 首元结点
3. 然后让头结点断开链，指向空
4. 进入循环判断
   + 让指针r 指向 工作指针p的后继结点
   + 让工作指针p 指向 头结点的后一个结点，也就是首元结点
   + 让头结点的指针域 指向 工作指针p
   + 工作指针p 借助 指针r 进行后移操作
5. 完成逆置









核心代码：

~~~cpp
void reverseLinkList(LinkList& L)
{
	LNode* p;	//定义指针
	LNode* r;	//定义指针

	p = L->next;	//指针p存放首元结点的地址
	L->next = NULL;	//头结点断开链

	while (p != NULL)
	{
		r = p->next;	//第一次执行是指针r存放首元结点的后一个结点，第二次执行是指向p之后的结点的指针
		p->next = L->next;	//指针p置空

		L->next = p;
		p = r;		//指针p后移
	}
}
~~~

![在这里插入图片描述](https://img-blog.csdnimg.cn/30312c0c110247619e0d771fd3c65e2e.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_19,color_FFFFFF,t_70,g_se,x_16#pic_center)













### 4.11 链表排序





参考视频：

这位老师讲的非常好，思路也清晰，强烈推荐哈哈哈捡到宝了

[单链表的排序](https://v.youku.com/v_show/id_XMzUwNTg4MzM4MA==)





步骤：

1. 定义3个指针，pre、p、q，这三个指针分别指向 *头结点*、*首元结点的后继结点*、*首元结点的后继结点*的后继
2. 首先让指针p指向首元结点的后继，也就是 `L->next->next`

3. 然后断开 首元结点 与 首元结点的后继 之间的链，构造只含一个结点的有序表，就是有头结点和首元结点的单链表
4. 进入循环判断
   + 当 指针p 指向的结点不为空时，执行循环语句
   + 指针q 指向 指针p的后继
   + 指针pre 指向头结点
   + 进入循环判断
     + 当指针pre 的后继结点不为空 且 指针pre的后继结点的数据域 < 指针p的数据域时，执行循环体
     + 指针pre 后移
   + 结束循环判断后，执行循环语句，将指针p的指针域 指向 指针pre的后继结点
   + 指针pre的指针域 指向 结点p
   + 指针p借助指针q后移
5. 完成排序





核心代码：

~~~cpp
//插入排序链表
void insertSort(LinkList &L)
{
	//定义3个指针 pre, p, q; 分别指向 头结点，遍历指针，后继
	LNode* pre; LNode* p; LNode* q;
	
	p = L->next->next;		//p指向L的第二个数据结点
	L->next->next = NULL;	//构造只含一个结点的有序表，就是有头结点和首元结点

	while (p != NULL)
	{
		q = p->next;	//第一次执行时 指针q 在 指针p 的后一个结点
		pre = L;		//从有序表开头开始比较，pre一直指向头结点

		while (pre->next != NULL && pre->next->data < p->data)	//判断当前值是否小于要插入的值，如果小于pre指针后移，从小到大排列
		{
			pre = pre->next;
		}

		p->next = pre->next;		//pre指针后移
		pre->next = p;
		p = q;
	}
}
~~~

![在这里插入图片描述](https://img-blog.csdnimg.cn/8af2422794a04a64977a2e553d930e36.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

指针pre正指向这个元素，我们对结点pre进行释放
6. 完成销毁操作







核心代码：

~~~cpp
//销毁链表
void destoryLinkList(LinkList& L)
{
	LNode* pre;
	LNode* p;

    pre = L;
	p = L->next;

	//销毁操作
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p->next;	//后移指针
	}
    delete pre;
}
~~~



<h2>清空和销毁的区别：</h2>



1. 销毁的时候，是先销毁了链表的头，然后接着一个一个的把后面的销毁了，这样这个链表就不能再使用了
2. 清空的时候，是先保留了链表的头，然后把头后面的所有的都销毁，最后把头里指向下一个的指针设为空，这样就相当与清空了，但这个链表还在，还可以继续使用













### 4.10 逆置链表





参考视频：

[单链表的原地逆置](https://www.bilibili.com/video/BV1Z54y1U7Tc)







步骤：

1. 定义两个指针，一个是工作指针，一个是方便工作指针p 移动的指针r
2. 先让 工作指针p 指向 首元结点
3. 然后让头结点断开链，指向空
4. 进入循环判断
   + 让指针r 指向 工作指针p的后继结点
   + 让工作指针p 指向 头结点的后一个结点，也就是首元结点
   + 让头结点的指针域 指向 工作指针p
   + 工作指针p 借助 指针r 进行后移操作
5. 完成逆置









核心代码：

~~~cpp
void reverseLinkList(LinkList& L)
{
	LNode* p;	//定义指针
	LNode* r;	//定义指针

	p = L->next;	//指针p存放首元结点的地址
	L->next = NULL;	//头结点断开链

	while (p != NULL)
	{
		r = p->next;	//第一次执行是指针r存放首元结点的后一个结点，第二次执行是指向p之后的结点的指针
		p->next = L->next;	//指针p置空

		L->next = p;
		p = r;		//指针p后移
	}
}
~~~

![在这里插入图片描述](https://img-blog.csdnimg.cn/cebf03c751eb4a87bf8f6aabe294c561.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_19,color_FFFFFF,t_70,g_se,x_16#pic_center)














### 4.11 链表排序





参考视频：

这位老师讲的非常好，思路也清晰，强烈推荐哈哈哈捡到宝了

[单链表的排序](https://v.youku.com/v_show/id_XMzUwNTg4MzM4MA==)





步骤：

1. 定义3个指针，pre、p、q，这三个指针分别指向 *头结点*、*首元结点的后继结点*、*首元结点的后继结点*的后继
2. 首先让指针p指向首元结点的后继，也就是 `L->next->next`

3. 然后断开 首元结点 与 首元结点的后继 之间的链，构造只含一个结点的有序表，就是有头结点和首元结点的单链表
4. 进入循环判断
   + 当 指针p 指向的结点不为空时，执行循环语句
   + 指针q 指向 指针p的后继
   + 指针pre 指向头结点
   + 进入循环判断
     + 当指针pre 的后继结点不为空 且 指针pre的后继结点的数据域 < 指针p的数据域时，执行循环体
     + 指针pre 后移
   + 结束循环判断后，执行循环语句，将指针p的指针域 指向 指针pre的后继结点
   + 指针pre的指针域 指向 结点p
   + 指针p借助指针q后移
5. 完成排序





核心代码：

~~~cpp
//插入排序链表
void insertSort(LinkList &L)
{
	//定义3个指针 pre, p, q; 分别指向 头结点，遍历指针，后继
	LNode* pre; LNode* p; LNode* q;
	
	p = L->next->next;		//p指向L的第二个数据结点
	L->next->next = NULL;	//构造只含一个结点的有序表，就是有头结点和首元结点

	while (p != NULL)
	{
		q = p->next;	//第一次执行时 指针q 在 指针p 的后一个结点
		pre = L;		//从有序表开头开始比较，pre一直指向头结点

		while (pre->next != NULL && pre->next->data < p->data)	//判断当前值是否小于要插入的值，如果小于pre指针后移，从小到大排列
		{
			pre = pre->next;
		}

		p->next = pre->next;		//pre指针后移
		pre->next = p;
		p = q;
	}
}
~~~
![在这里插入图片描述](https://img-blog.csdnimg.cn/f11c513d6ac74fceb80db0f4866681aa.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAdnVsbmVyYWJsZSBtYXJrZXI=,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)

