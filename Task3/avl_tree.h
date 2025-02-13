#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename Key, typename Info>
class avl_tree {

    struct Node {
        Key key;
        Info info;
        Node* left;
        Node* right;
        int height;

        Node(const Key& k, const Info& i, Node* l, Node* r, int h)
                : key(k), info(i), left(l), right(r), height(h) {}
    };

public:
    avl_tree() : root(nullptr) {}

    avl_tree(const avl_tree& src) : root(copy(src.root)) {}

    ~avl_tree() {
        clear(root);
    }

    avl_tree& operator=(const avl_tree& src) {
        if (this != &src) {
            clear(root);
            root = copy(src.root);
        }
        return *this;
    }

    // Interface methods:
    void insert(const Key& key, const Info& info) {
        root = insert(root, key, info);
    }

    void remove(const Key& key) {
        root = remove(root, key);
    }

    bool contains(const Key& key) const {
        return find(root, key) != nullptr;
    }

    void print_tree() const {
        if (root == nullptr) std::cout << "The tree is empty\n";
        else print_tree(root);
    }

    Info& operator[](const Key& key) {
        Node* node = find(root, key);
        if (!node) throw std::range_error("Key not found");
        return node->info;
    }

    const Info& operator[](const Key& key) const {
        Node* node = find(root, key);
        if (!node) throw std::range_error("Key not found");
        return node->info;
    }

    bool is_empty() const { return root == nullptr; }
    size_t size() const { return get_size(root); }
    void clear() { clear(root); root = nullptr; }

    // Additional methods
    static std::vector<std::pair<Key, Info>> maxinfo_selector(const avl_tree<Key, Info>& tree, unsigned int cnt){
        std::vector<std::pair<Key, Info>> result, nodes;
        in_order_traversal(tree.root, nodes);
        // Assuming 'Info' supports less than comparison, we sort descendingly
        std::sort(nodes.begin(), nodes.end(), [](const std::pair<Key, Info>& a, const std::pair<Key, Info>& b) {
            return a.second > b.second;
        });
        // Take the first 'cnt' elements from the sorted vector
        for (size_t i = 0; i < cnt && i < nodes.size(); ++i) {
            result.push_back(nodes[i]);
        }
        return result;

    };
    static avl_tree<std::string, int> count_words(std::istream& is){
        avl_tree<std::string, int> word_count;
        std::string word;
        while (is >> word) {
            if (const Info* existing_info = word_count.find_info(word)) {
                // Use const_cast to increment the value since find_info returns a pointer to const
                const_cast<Info&>(*existing_info)++;
            } else {
                word_count.insert(word, 1);
            }
        }
        return word_count;
    };

    // Method to safely find info without throwing an exception
    const Info* find_info(const Key& key) const {
        Node* node = find(root, key);
        if (node != nullptr) {
            return &(node->info);
        } else {
            return nullptr; // Return nullptr if the key is not found
        }
    }

    // Accessor for the root node (for testing purposes)

    bool is_balanced() const {
        int height = 0;
        return is_balanced_util(root, height);
    }
    bool validate_bst_property() const {
        return validate_bst_property_util(root, nullptr, nullptr);
    }


private:
    Node* root;

    // Helper methods for AVL Tree:
    Node* insert(Node* node, const Key& key, const Info& info);
    Node* remove(Node* node, const Key& key);
    Node* find(Node* node, const Key& key) const;
    void print_tree(Node* node, int depth = 0) const;
    Node* copy(Node* node);
    void clear(Node*& node);
    int height(Node* node) const;
    int get_balance(Node* node) const;
    Node* right_rotate(Node* y);
    Node* left_rotate(Node* x);
    Node* balance(Node* node);
    Node *minValueNode(Node *node);
    static void in_order_traversal(const Node* node, std::vector<std::pair<Key, Info>>& result);
    size_t get_size(Node* node) const {
        if (node == nullptr) {
            return 0;
        } else {
            return 1 + get_size(node->left) + get_size(node->right);
        }
    }


    bool is_balanced_util(const Node* node, int& height) const {
        if (node == nullptr) {
            height = -1;
            return true;
        }

        int left_height = 0, right_height = 0;
        bool left = is_balanced_util(node->left, left_height);
        bool right = is_balanced_util(node->right, right_height);

        height = std::max(left_height, right_height) + 1;

        if (std::abs(left_height - right_height) <= 1)
            return left && right;
        else
            return false;
    }
    bool validate_bst_property_util(const Node* node, const Key* min, const Key* max) const {
        if (node == nullptr) return true;
        if ((min && node->key <= *min) || (max && node->key >= *max)) return false;
        return validate_bst_property_util(node->left, min, &node->key) &&
               validate_bst_property_util(node->right, &node->key, max);
    }

};

#endif // AVL_TREE_H
