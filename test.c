#include"MatchBrackets.h"

int main()
{
	Stack s;
	int sz = 0;
	StackInit(&s);
	char a[] = "(())abc{[(])}";//左右括号次序匹配不正确
	char b[] = "(()))abc{[]}";//右括号多于左括号
	char c[] = "(()()abc{[]}";//左括号多于右括号
	char d[] = "(())abc{[]()}";//左右括号匹配正确

	sz = strlen(c);

	MatchBrackets(&s, sz, c);

	return 0;
}