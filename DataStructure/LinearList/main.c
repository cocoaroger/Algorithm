#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void printString(int first, ...)
{
	va_list va_elementlist;
	va_start(va_elementlist, first);
	int second = va_arg(va_elementlist, int);
	int third = va_arg(va_elementlist, int);
	va_end(va_elementlist);

	printf("%d %d %d\n", first, second, third); 
	return;
}

int main(int argc, char const *argv[])
{
	printString(100, 200, 300);

	return 0;
}