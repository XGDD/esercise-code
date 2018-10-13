public class QuickSort{
    public int GetMiddleIndex(int[] array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[right - 1] < array[mid])
			return right - 1;
		if (array[left] > array[mid])
			return left;
		else
			return mid;
	}
	else
	{
		if (array[right - 1] > array[mid])
			return right - 1;
		if (array[left] < array[mid])
			return left;
		else
			return mid;
	}
}

public void Swap(int left, int right){
	int temp = left;
	left = right;
	right = temp;
}

public int partion_OP(int[] array, int left, int right)
{
	int index = GetMiddleIndex(array, left, right);
	Swap(array[index], array[right - 1]);
	int key = array[right - 1];
	int cur = 0;
	int prev = cur - 1;
	while (cur < right)
	{
		while (array[cur] < key && ++prev != cur)
			Swap(array[cur], array[prev]);
		cur++;
	}
	if (++prev != right - 1)
		Swap(array[prev++], array[right - 1]);
	return prev;
}

public void QuickSort_R(int[] array, int left, int right)
{
	if (left < right)
	{
		//按照基准值将left和right标记区间划分成两部分
		int boundry = partion_OP(array, left, right);
		//排列左半部分
		QuickSort_R(array, left, boundry);
		//排列右半部分
		QuickSort_R(array, boundry + 1, right);
	}
}
public static void main(String[] args){
	int[] array = new int[]{ 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	QuickSort p = new QuickSort();
	p.QuickSort_R(array, 0, 10);
	for(int i = 0; i < 10; i++){
		System.out.print(array[i] + " ");
	}
	System.out.println();
}
}