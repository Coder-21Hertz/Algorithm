/*
 * ����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
 * ���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
 * ����Լ���������� 0 ֮�⣬��������������㿪ͷ��
 */

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it;
        for(it = digits.end()-1; it >= digits.begin(); it--){
        	*it = *it + 1;
			if(*it > 9)
        		*it = 0;
			else
				return digits;
		}
		*digits.begin() = 0;
		digits.insert(digits.begin(), 1);
		return digits;
    }
};

int main()
{
	vector<int> vi{1,9};
	Solution a;
	vector<int> vi1 = a.plusOne(vi);
	
	for(auto it = vi1.begin(); it != vi1.end(); ++it)
		cout << *it << endl;
}
