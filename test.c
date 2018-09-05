#define _CRT_SECURE_NO_WARNINGS 1

#include"JudgeWord.h"

int main()
{
	BSTKNode* pRoot;
	InitBSTKNode(&pRoot);
	InsertBSTKNode(&pRoot, "hello");
	InsertBSTKNode(&pRoot, "word");
	InsertBSTKNode(&pRoot, "child");

	printf("%s\n", FindBSTKNode(pRoot, "hello")->_key);
	printf("%s\p", FindBSTKNode(pRoot, "cvu")->_key);

	return 0;
}