#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const {
        const Node* current = &root;
        for (const auto& key : node) {
            auto it = current->children.find(key);
            if (it == current->children.end()) {
                return false; // Key not found
            }
            current = &(it->second);
        }
        return true; // All keys found
    }

    void Insert(const std::vector<std::string>& node) {
        Node* current = &root;
        for (const auto& key : node) {
            current = &(current->children[key]);
        }
    }

    void Delete(const std::vector<std::string>& node) {
        Node* current = &root;
        std::vector<Node*> path;
        for (const auto& key : node) {
            auto it = current->children.find(key);
            if (it == current->children.end()) {
                return; // Node not found, nothing to delete
            }
            path.push_back(current);
            current = &(it->second);
        }

        // Delete the node and its parent links
        path.back()->children.erase(node.back());
        for (int i = path.size() - 2; i >= 0; --i) {
            if (path[i]->children.size() == 0) {
                path[i - 1]->children.erase(node[i]);
            } else {
                break; // Stop if a non-empty subtree is found
            }
        }
    }
};

int main() {
    Tree tree;

    // Insert nodes
    tree.Insert({"folder1", "subfolder1"});
    tree.Insert({"folder1", "subfolder2"});
    tree.Insert({"folder2", "subfolder1"});

    // Test Has function
    std::cout << "Has(folder1): " << (tree.Has({"folder1"}) ? "true" : "false") << std::endl;
    std::cout << "Has(folder1/subfolder1): " << (tree.Has({"folder1", "subfolder1"}) ? "true" : "false") << std::endl;
    std::cout << "Has(folder2/subfolder2): " << (tree.Has({"folder2", "subfolder2"}) ? "true" : "false") << std::endl;

    // Test Delete function
    tree.Delete({"folder1", "subfolder1"});
    std::cout << "After deleting folder1/subfolder1, Has(folder1/subfolder1): " << (tree.Has({"folder1", "subfolder1"}) ? "true" : "false") << std::endl;

    return 0;
}
