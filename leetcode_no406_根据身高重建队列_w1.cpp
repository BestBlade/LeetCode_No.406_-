/* ------------------------------------------------------------------|
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
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
    //为保证后插入的数不会对前插入的大数影响，将数组倒序排序，但是前面大于等于k的数字依旧按照正序排列
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v){
        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    });
    vector<vector<int>> res;
    for (const auto& x : people) {
        res.insert(res.begin() + x[1], x);
    }
    return res;
}

int main() {
    vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };

    vector<vector<int>> res = reconstructQueue(people);
}
