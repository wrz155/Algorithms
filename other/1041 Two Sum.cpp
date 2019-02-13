/*
给定一个数组arr，和一个整数aim，请返回哪两个位置的数可 以加出aim来。 
例如 arr = {2, 7, 11, 15}，target = 9 返回{0,1}，
因为arr[0] + arr[1] = 2 + 7 = 9 
可以假设每个数组里只有一组答案

*/
/*
思路一：
	要找出哪两个位置的和等于aim，首先要对数组进行排序，并且还要记录排序之前每个元素的index，（本题采用堆排序的思想，时间复杂度较低）。
	然后设置两个指针分别指向头数组和尾数组。如果两指针所指的元素的和大于aim，则让右指针左移；如果两指针所指的元素的和小于aim，则让左指针右移；
	如果相等，则直接返回两指针元素所在的index，循环结束。
时间复杂度：o（nlogn）
空间复杂度：o（n）

思路二：
	用哈希表来存储每次遍历到的key和value。若target-arr[i]的值已经在map中，则直接返回两坐标即可。
时间复杂度：o（n）
空间复杂度：o（n）

*/







void heapInsert(int[] nums, int[] indices, int i) {
	while (i > 0) {
		int p = (i - 1) / 2;
		if (nums[i] <= nums[p]) {
			break;
		}
		swap(nums, indices, i, p);
		i = p;
	}
}

void heapify(int[] nums, int[] indices, int size) {
	int i = 0;
	int left = 1;
	int right = 2;
	int largest;
	while (left < size) {
		largest = nums[left] > nums[i] ? left : i;
		largest = right < size && nums[right] > nums[largest] ? right : largest;
		if (largest == i) {
			break;
		}
			swap(nums, indices, largest, i);
			i = largest;
			left = i * 2 + 1;
			right = i * 2 + 2;
		}
	}

	public void swap(int[] nums, int[] indices, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
		tmp = indices[i];
		indices[i] = indices[j];
		indices[j] = tmp;
	}

}
public void sort(int[] nums, int[] indices) {
	for (int i = 0; i < nums.length; i++) {
		heapInsert(nums, indices, i);
	}
	for (int i = nums.length - 1; i >= 0; i--) {
		swap(nums, indices, 0, i);
		heapify(nums, indices, i);
	}
}

int* twoSum(int arr[], int len, int target) {
	int[] indices = new int[nums.length];
	for (int i = 0; i < indices.length; i++) {
		indices[i] = i;
	}
	sort(arr, indices);
	int l = 0;
	int r = arr.length - 1;
	int sum = 0;
	while (l < r) {
		sum = arr[l] + arr[r];
		if (sum > target) {
			r--;
		}
		else if (sum < target) {
			l++;
		}
		else {
			return new int[] { indices[l], indices[r] };
		}
	}
	return new int[] { -1, -1 };
}