/* ------------------------------------------------------------------|
�����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

ע�⣺
����������1100�ˡ�

ʾ��

����:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

���:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/queue-reconstruction-by-height
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	˫ָ�뷨
*
*	ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
*	�ڴ����ģ�8.1 MB, ������ C++ �ύ�л�����81.94%���û�
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    //Ϊ��֤�������������ǰ����Ĵ���Ӱ�죬�����鵹�����򣬵���ǰ����ڵ���k���������ɰ�����������
    sort(people.begin(), people.end(), [](vector<int> u, vector<int> v){
        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    });
    vector<vector<int>> res;
    for (auto x : people) {
        res.insert(res.begin() + x[1], x);
    }
    return res;
}

int main() {
    vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };

    vector<vector<int>> res = reconstructQueue(people);
}