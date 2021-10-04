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

![image-20211002123713629](E:\笔记\数据结构与算法\image\image-20211002123713629.png)









### 2.2 插入元素



刚才我们也谈到，这里的时间复杂度为 O(1)。我们现在来考虑，如果我们要实现 ListInsert(*L, i, e)

即在线性表中的第 i 个位置插入新元素e，应该如何操作？



举个例子，我们在春运时去买火车票，大家都在排队排的好好的，这时来了一个美女，对着队伍中排在第三位的你说

“大哥，求求你帮帮忙，我家母亲又病，我得急着回去看她，这队伍这么长，你可否让我排在你的前面？” 你心一软

就同意了。这时，你必须后退一步，否则她是没办法进到队伍里面来的。这可不得了，后面的人像蠕虫一样

全部都得后退一步。骂声四起，但后面的人也不清楚这加塞是怎么回事，没什么办法。



<img src="E:\笔记\数据结构与算法\image\image-20211002130612766.png" alt="image-20211002130612766" style="zoom:80%;" />

<h2>插入算法的思路</h2>



+ 如果插入位置不合理，抛出异常
+ 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量
+ 从最后一个元素开始向前遍历到第 i 个位置，分别将他们都向后移动一个位置
+ 将要插入的元素填入位置 i 处
+ 表长加1



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

<img src="E:\笔记\数据结构与算法\image\image-20211002155310434.png" alt="image-20211002155310434" style="zoom:80%;" /> 



2. 后来我修改了判断的条件 把 i <= l.length 改成 i <= l.length + 1，程序运行正常

<img src="E:\笔记\数据结构与算法\image\image-20211002155544096.png" alt="image-20211002155544096" style="zoom:80%;" /> 

> 由此分析，问题可能出现在判断条件上

于是列举问题分析程序运行步骤

![00974abd95](E:\笔记\数据结构与算法\image\00974abd95.png)



修改程序：

<img src="E:\笔记\数据结构与算法\image\image-20211002171030983.png" alt="image-20211002171030983" style="zoom:80%;" /> 



> 但是这又引发了我的思考，为什么判断条件改成 i <= l.length + 1 就行了？

于是我又开始分析程序

![image-20211002172649460](E:\笔记\数据结构与算法\image\image-20211002172649460.png)



> 至此，我在编写顺序表插入元素中所遇到的问题就是这些了







### 2.3 删除元素



接着刚才的例子，此时后面排队的人群意见都很大，都说怎么可以这样，不管是什么原因，插队就是不行

有本事，找火车站开后门去。就在这时，远处跑来一胖子对着这美女喊，可找到你了，你这骗子，还我钱。

只见这女子二话不说，突然就冲出了队伍，胖子追在其后，消失在人群中。哦，原来她就是倒卖火车票的黄牛

刚才还挺可怜。于是排队的人群，又像蠕虫一样，均向前移动了一步，骂声渐息，队伍又恢复了平静



*这就是线性表的顺序存储结构删除元素的过程*

<img src="E:\笔记\数据结构与算法\image\image-20211002174003398.png" alt="image-20211002174003398" style="zoom:80%;" /> 





<h3>删除算法的思路</h3>

1. 如果删除位置不合理，抛出异常
2. 去除删除元素
3. 从删除元素位置开始遍历到最后一个元素的位置，分别将他们都向前移动一个位置
4. 表长减1



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

<img src="E:\笔记\数据结构与算法\image\image-20211002235823857.png" alt="image-20211002235823857" style="zoom:80%;" /> 



<img src="E:\笔记\数据结构与算法\image\image-20211002235934565.png" alt="image-20211002235934565" style="zoom:80%;" /> 



2. 开始调试找出问题，逐语句执行代码段

到目前为止还是正常数值

![image-20211003000254022](E:\笔记\数据结构与算法\image\image-20211003000254022.png)



+ 直到运行到第 28行，底下的数组值发生变化

![image-20211003000624372](E:\笔记\数据结构与算法\image\image-20211003000624372.png)



+ 分析时出现问题的行数在 第25行 ~ 第28行之间，故在第25行和28行打2个断点观察数值变化

![image-20211003001500898](E:\笔记\数据结构与算法\image\image-20211003001500898.png)



问题分析：

![image-20211003002957776](E:\笔记\数据结构与算法\image\image-20211003002957776.png)

> 故由这个问题可知，我们传入的实参有误，但是我们要先清楚 语句 *e = l.data[i - 1]是用来做什么的



参考以下blog：

[顺序表的删除](https://blog.csdn.net/m0_37036984/article/details/78440754)

[顺序表的删除操作](https://blog.csdn.net/inooll/article/details/105645732)



不难发现，int *e 作用其实就是保存被删除的数值，那么传入的实参其实应该是记录被删除的值的一个整型变量

故，我传入 s1.data 是不对的

![image-20211003100433698](E:\笔记\数据结构与算法\image\image-20211003100433698.png)



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

![image-20211003111245246](E:\笔记\数据结构与算法\image\image-20211003111245246.png)





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





### 4.1 头插法



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













### 4.2 单链表的读取



在线性表的顺序结构中，我们要计算任意一个元素的存储位置是很容易的。

但在单链表中，由于 第 i 个元素到底在哪？没办法一开始就知道，必须得从头开始找。

因此，对于单链表实现获取 第i个元素 的数据的操作 GetElem，在算法上相对要麻烦一些。



思路：

1. 声明一个结点 p 指向链表中的第一个结点，初始化 j 从 1 开始

2. 当 j < 1 时，就遍历链表，让 p 的指针向后移动，不断指向下一结点，j 累加 1
3. 若到链表末尾 p 为空，则说明 第i个元素不存在
4. 否则查找成功，返回结点 p 的数据

