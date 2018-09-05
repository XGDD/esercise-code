#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTreeNodeKV.h"

int main()
{
	BSTNKV* pRoot;
	InitBSTNKV(&pRoot);
	InsertBSTNKV(&pRoot, "hello", "���");
	InsertBSTNKV(&pRoot, "world", "����");
	InsertBSTNKV(&pRoot, "child", "����");

	//DestroyBSTNKV(&pRoot);
	DelectBSTNKV(&pRoot, "world");

	printf("%s\n", FindBSTNKV(pRoot, "hello")->_data._value);
	printf("%s\n", FindBSTNKV(pRoot, "world")->_data._value);



	return 0;
}