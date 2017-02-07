#include <stdlib.h>
#include <stdio.h>
/**
   【规则1】用malloc或new申请内存之后，应该立即检查指针值是否为NULL。防止使用指针值为NULL的内存。

　　【规则2】不要忘记为数组和动态内存赋初值。防止将未被初始化的内存作为右值使用。

　　【规则3】避免数组或指针的下标越界，特别要当心发生“多1”或者“少1”操作。

　　【规则4】动态内存的申请与释放必须配对，防止内存泄漏。

　　【规则5】用free或delete释放了内存之后，立即将指针设置为NULL，防止产生“野指针”。

 */


/**
 * 验证有没有分配到内存
 * @param object 被验证的对象
 */
void valideAllocateObject(void* object)
{
	if (object == NULL)
	{
		fprintf(stderr, "%s\n", "错误信息 - 内存不足，该对象没分配到内存");
	}
}