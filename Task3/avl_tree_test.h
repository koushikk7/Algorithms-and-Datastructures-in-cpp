#include "avl_tree.h"

template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::insert(Node* node, const Key& key, const Info& info) {
    if (node == nullptr) {
        return new Node(key, info, nullptr, nullptr, 1);
    }
    if (key < node->key) {
        node->left = insert(node->left, key, info);
    } else if (key > node->key) {
        node->right = insert(node->right, key, info);
    } else {
        // Duplicate keys are not allowed
        throw std::invalid_argument("Duplicate key");
    }

    // Update the height of the ancestor node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Balance the node if it has become unbalanced
    return balance(node);
}
template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::remove(Node* node, const Key& key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        // Node with only one child or no child
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                // No child case
                temp = node;
                node = nullptr;
            } else {
                // One child case
                *node = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            // Copy the inorder successor's data to this node
            node->key = temp->key;
            node->info = temp->info;
            // Delete the inorder successor
            node->right = remove(node->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (node == nullptr) {
        return node;
    }

    // Update the height of the current node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Balance the node if it has become unbalanced
    return balance(node);
}

template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::find(Node* node, const Key& key) const {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}



template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::right_rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}
template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}
template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::balance(Node* node) {
    // Calculate balance factor
    int balance = get_balance(node);

    // If the node is unbalanced, then try out the 4 cases
    // Left Left Case
    if (balance > 1 && get_balance(node->left) >= 0)
        return right_rotate(node);

    // Left Right Case
    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Right Case
    if (balance < -1 && get_balance(node->right) <= 0)
        return left_rotate(node);

    // Right Left Case
    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the node if it's balanced
    return node;
}
template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
template <typename Key, typename Info>
int avl_tree<Key, Info>::height(Node* node) const {
    if (node == nullptr)
        return 0;
    return node->height;
}

template <typename Key, typename Info>
int avl_tree<Key, Info>::get_balance(Node* node) const {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

template <typename Key, typename Info>
void avl_tree<Key, Info>::clear(Node*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

template <typename Key, typename Info>
typename avl_tree<Key, Info>::Node* avl_tree<Key, Info>::copy(Node* node) {
    if (node == nullptr) {
        return nullptr;
    } else {
        Node* newNode = new Node(node->key, node->info, copy(node->left), copy(node->right), node->height);
        return newNode;
    }
}
template <typename Key, typename Info>
void avl_tree<Key, Info>::print_tree(Node* node, int depth) const {
    if (node != nullptr) {
        print_tree(node->right, depth + 1);
        std::cout << std::string(depth * 4, ' ') << node->key << " (" << node->info << ")" << std::endl;
        print_tree(node->left, depth + 1);
    }
}

template <typename Key, typename Info>
void avl_tree<Key, Info>::in_order_traversal(const Node* node, std::vector<std::pair<Key, Info>>& result) {
    if (node != nullptr) {
        in_order_traversal(node->left, result);
        result.emplace_back(node->key, node->info);
        in_order_traversal(node->right, result);
    }
}

