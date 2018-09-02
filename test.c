#include"ComplexLinkList.h"

void ComplexLinkList_test()
{
	Node node1, node2, node3, node4;

	node1.data = 1;
	node1.next = &node2;
	node1.random = &node3;

	node2.data = 2;
	node2.next = &node3;
	node2.random = &node1;

	node3.data = 3;
	node3.next = &node4;
	node3.random = &node3;

	node4.data = 4;
	node4.next = NULL;
	node4.random = NULL;

	pNode ret = CopyComplexLinkList(&node1);

}

int main()
{
	ComplexLinkList_test();

	return 0;
}