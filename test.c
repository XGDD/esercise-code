#include"MatchBrackets.h"

int main()
{
	Stack s;
	int sz = 0;
	StackInit(&s);
	char a[] = "(())abc{[(])}";//�������Ŵ���ƥ�䲻��ȷ
	char b[] = "(()))abc{[]}";//�����Ŷ���������
	char c[] = "(()()abc{[]}";//�����Ŷ���������
	char d[] = "(())abc{[]()}";//��������ƥ����ȷ

	sz = strlen(c);

	MatchBrackets(&s, sz, c);

	return 0;
}