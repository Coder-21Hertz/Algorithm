/*
 * ����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ�
 * �����Ƴ���������³��ȡ���Ҫʹ�ö��������ռ䣬�������ԭ���޸�������
 * �鲢��ʹ�� O(1) ����ռ����������ɡ�
 * Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
 * �������� nums = [0,1,2,2,3,0,4,2], val = 2,
 * ����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��
 * ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	//˫ָ�룬�Լ��ķ���
	int removeElement(vector<int> &nums, int val)
	{
		if (nums.empty())
			return 0;
		vector<int>::iterator end = nums.end() - 1;

		for (vector<int>::iterator it = nums.begin(); it < end; ++it)
		{
			while (*end == val)
			{
				if (end == it)
					return end - nums.begin();
				--end;
			}

			if (*it == val)
			{
				*it = *end;
				--end;
			}
		}
		if (*end == val)
			--end;
		return end - nums.begin() + 1;
	}

	//˫ָ�룬����ָ��
	int removeElement_2(vector<int> &nums, int val)
	{
		vector<int>::iterator it1 = nums.begin();
		vector<int>::iterator it2 = nums.begin();

		for (; it2 != nums.end(); ++it2)
		{
			if (*it2 != val)
			{
				*it1 = *it2;
				++it1;
			}
		}
		return it1 - nums.begin();
	}
};

int main()
{
	vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	Solution a;
	// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
	int len = a.removeElement_2(nums, 2);

	// �ں������޸�����������ڵ������ǿɼ��ġ�
	// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << endl;
	}
}
