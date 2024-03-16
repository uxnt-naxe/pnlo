
# tc+编程语言代码
```
import stdio

int main() = 
{
  printf("Hello Wrold")
  result = 0
}
```

### 注释风格
注释完全和C++一致
```
/**/ //
```
### import 导入

```
//导入单个模块
import 模块名

//导入多个模块
import
{
    模块名1
    模块名2
    模块名3
    //以下同理
}
```

> 注：
> 1. 模块名可以省略后缀名
> 2. 模块名可以省略路径（不用./name，直接name）
> 3. 模块名就是模块文件名
> 4. 路径或名字直接有空格要加双引号包围

example:
```
//导入io模块
import io

//导入多个模块
import
{
    mod1
    mod2
}
```
### 基础运算符

如+，-，*，/，%
和C++一样，不多赘述

### 对象

使用0初始化对象

对象定义：
```
//一般形式：

类型 名字   //不用打分号！！

//数组
类型 名字[数量]      //数量可以动态！
类型[数量] 名字
```

example:
```
int a
//相当于
//int a = 0

//对象不能重名
float b[10]

//还可以这样
int
{
    v1
    v2
    v3
}

//const修饰代表常量
const int ci
ci = 10      //Error！
```

### 函数

函数一律使用函数对象

```
返回值类型 函数名(参数列表) =
{
    //函数体

    //返回值void，则result直接退出
    result
    //返回值非void，则result赋值给返回值
    result = 10       //示例
}

//函数对象可以重名 （重载）
```

example:
```

int add(int a, int b) =
{
    result = a + b
}

//函数可以修改函数体

add = 
{
    result = a - b  //只是示例
}

//函数也可以用const修饰

/*const放前面是返回值是常量*/
const int const func() =       /*const放后面是函数是常量*/
{
    //...
}

func = {}   //Error！

函数默认初始化为 {}
```

### main函数

main函数是程序的入口，所以main函数是必须的
main函数的返回值类型是int
main函数的参数列表是空（一般情况）
main函数的返回值是程序的退出码

```
int main() =
{
    //...
    result = 0      //0代表程序正常退出
}
```

### using 声明对象

using声明对象，就是告诉编译器存在一个对象（不管有没有定义）
声明后就可以使用该对象，如果使用时对象不存在，则报错

```
using 类型 对象名
```

该用法用的更多的是作为函数声明

example:
```
using int a

//因为main和a是同时定义的，所以a是存在的，当main被系统调用时，a已经被定义了

//函数体内的内容相当于计划，使用声明的对象没问题，但调用相当于执行计划，则必须要看对象存不存在

int main() = 
{
    a = 10      //right!
    result = 0
}

int a
```
