#include <iostream>

class FrequencyTree {
private:
    struct TreeNode {
        int value;
        int frequency;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : value(val), frequency(1), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void insert(TreeNode*& node, int value) {
        if (!node) {
            node = new TreeNode(value);
        } else if (value < node->value) {
            insert(node->left, value);
        } else if (value > node->value) {
            insert(node->right, value);
        } else {
            node->frequency++;
        }
    }

    void printInOrder(TreeNode* node) {
        if (node) {
            printInOrder(node->left);
            std::cout << node->value << " " << node->frequency << std::endl;
            printInOrder(node->right);
        }
    }

public:
    FrequencyTree() : root(nullptr) {}

    void addValue(int value) {
        insert(root, value);
    }

    void printValues() {
        printInOrder(root);
    }
};

int main() {
    
    FrequencyTree ftree;
    ftree.addValue(2);
    ftree.addValue(2);
    ftree.addValue(2);
    ftree.addValue(1);
    ftree.addValue(1);
    ftree.printValues();

    return 0;
}
