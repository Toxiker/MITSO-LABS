#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodesInLevel(TreeNode* root, int level) {
    if (root == NULL) return 0;
    if (level == 1) return 1;
    return countNodesInLevel(root->left, level - 1) + countNodesInLevel(root->right, level - 1);
}

int main() {
    setlocale(0, "Ru");
    int n;
    cout << "Введите уровень двоичного дерева: ";
    cin >> n;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int count = countNodesInLevel(root, n);
    cout << "бинарное дерево имеет " << count << " узлов на уровне " << n << endl;

    return 0;
}