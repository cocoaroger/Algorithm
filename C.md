1. <a href="http://www.runoob.com/cprogramming/c-standard-library-ctype-h.html">C语言标准库学习地址</a>
2. <a href="https://www.gnu.org/software/libc/libc.html">C语言源码下载地址</a>
3. <a href="http://home.gna.org/gdsl/">GDSL数据结构源码下载地址</a>
4. <a href="http://libcstl.org/download.html">libcstl数据结构源码下载地址</a>
5. <a href="https://ilcc.gitbooks.io/wiki/content/StyleGuide/Huawei-C/index.html">华为C语言编码规范</a>
6. <a href="http://www.qmailer.net/archives/171.html">C语言编码规范</a>


### 知识点
<a href="http://www.cnblogs.com/hanyonglu/archive/2011/05/07/2039916.html">可变参数使用详解，原文地址</a>

``` 
va_start和va_end使用详解

1. 在C中，当我们无法列出传递函数的所有实参的类型和数目时,可以用省略号指定参数表
void foo(...);
void foo(parm_list,...);

2. 函数参数的传递原理
函数参数是以数据结构:栈的形式存取,从右至左入栈。

3. va_list 是一个字符指针，可以理解为指向当前参数的一个指针，取参必须通过这个指针进行。

4. 获取参数的步骤：
<Step 1> 在调用参数表之前，定义一个 va_list 类型的变量，(假设va_list 类型变量被定义为va_elementlist)；

<Step 2> 然后应该对 va_elementlist 进行初始化，让它指向可变参数表里面的第一个参数，这是通过 va_start 来实现的，第一个参数是 va_elementlist 本身，第二个参数是在变参表前面紧挨着的一个变量,即“...”之前的那个参数；

<Step 3> 然后是获取参数，调用va_arg，它的第一个参数是va_elementlist，第二个参数是要获取的参数的指定类型，然后返回这个指定类型的值，并且把 va_elementlist 的位置指向变参表的下一个变量位置；

<Step 4> 获取所有的参数之后，我们有必要将这个 va_elementlist 指针关掉，以免发生危险，方法是调用 va_end，他是输入的参数 va_elementlist 置为 NULL，应该养成获取完参数表之后关闭指针的习惯。就是让我们的程序具有健壮性。通常va_start和va_end是成对出现。
```

<a href="http://xinklabi.iteye.com/blog/676313">inline用法总结</a>