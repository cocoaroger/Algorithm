#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * 打印多个数字
 * @param first 打印的第一个数
 */
void printInt(int first, ...)
{
	va_list va_elementlist;
	va_start(va_elementlist, first);
	// 获取第二个参数
	int second = va_arg(va_elementlist, int); 
	int third = va_arg(va_elementlist, int);

	va_end(va_elementlist);
	
	// 参数的数量，在编译时无法获取，只能在方法明中说明
	printf("%d %d %d\n", first, second, third); 

	printf("second内存地址：%p\n", &second);
	printf("third内存地址：%p\n", &second);
	return;
}

int main(int argc, char const *argv[])
{
	printInt(100, 100, 300);
	return 0;
}