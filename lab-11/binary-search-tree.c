#include <stdio.h>
#include <stdlib.h>


struct NODE {
    int key;
    struct NODE* left;
    struct NODE* right;
};


typedef struct NODE node;

node* createNode(int key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}


node* insert(node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}


// Function to find the minimum value node in a BST
node* findMin(node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}


node* deleteNode(node* root, int key) {
    if (root == NULL) return root;

    // If the key is smaller than the root's key, go left
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key is larger than the root's key, go right
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // If the key is the same as the root's key, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the in-order successor (smallest in the right subtree)
        node* temp = findMin(root->right);

        // Copy the in-order successor's content to this node
        root->key = temp->key;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void inorderTraversal(node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}


void preorderTraversal(node* root) {
    if (root) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void postorderTraversal(node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}


int main() {
    node* root = NULL;
    int choice, key;

    do {
        printf("1. Insert\t2. Delete\n3. Inorder Traversal\t4. Preorder Traversal\t5. Postorder Traversal\n6. Exit\t> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key inserted successfully!\n");
                break;

            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}
