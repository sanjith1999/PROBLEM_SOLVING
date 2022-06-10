#include <iostream>

using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL) {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    } else if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root != NULL) {
        if (root->key > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->key < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->key == key) {
            // Case 1 : if the tree has no braches
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }

                // Case 2.1 : if the left branch is only available
            else if (root->right == NULL) {
                struct node *temp = (struct node *) malloc(sizeof(struct node));
                temp = root->left;
                free(root);
                return temp;
            }
                // Case 2.2 : if the right branch is only available
            else if (root->left == NULL) {
                struct node *temp = (struct node *) malloc(sizeof(struct node));
                temp = root->right;
                free(root);
                return temp;
            }

                // Case 3 : if the root has both branches
            else {
                struct node *predecessor;
                struct node *temp = (struct node *) malloc(sizeof(struct node));

                predecessor = root->left;
                while (predecessor->right != NULL) {
                    predecessor = predecessor->right;
                }
                temp = predecessor;
                temp->right = root->right;
                temp->left = root->left;
                free(root);
                return temp;
            }
        }
    }
    return NULL;
}

bool BST(node *root, int first_right, int first_left) {
    if (root == NULL)
        return true;
    node *left = root->left, *right = root->right;

    if (left == NULL && right == NULL)
        return true;

    if ((left != NULL && (first_right != -1 && first_right >= left->key || root->key <= left->key)) ||
        (right != NULL && (first_left != -1 && first_left <= right->key || root->key >= right->key)))
        return false;

    return ((left == NULL) || BST(left, first_right, root->key)) &&
           ((right == NULL) || BST(right, root->key, first_left));
}

bool checkBST(node *root) {
    if (root == NULL)
        return true;
    return (root->left == NULL || BST(root->left, -1, root->key)) &&
           (root->right == NULL || BST(root->right, root->key, -1));
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}