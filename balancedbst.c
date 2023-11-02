#include <stdio.h>
#include <stdlib.h>

// Structure representing a node of a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print pre-order traversal of a binary tree
void preOrder(struct Node* root) {
   
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to store the in-order traversal of a binary tree to an array
void storeInOrderTraversal(struct Node* root, int inOrderNodes[], int* index) {
    if (root != NULL) {
        storeInOrderTraversal(root->left, inOrderNodes, index);
        inOrderNodes[(*index)++] = root->data;
        storeInOrderTraversal(root->right, inOrderNodes, index);
    }
}

struct Node* convertSortedArrayToBalancedBST(int inOrderNodes[], int start, int end) {
    // Base Case
    if (start > end) {
        return NULL;
    }

    // Middle element of the array forms the node
    int mid = (start + end) / 2;
    struct Node* root = createNode(inOrderNodes[mid]);

    // Elements to the left of the middle element form the left subtree
    root->left = convertSortedArrayToBalancedBST(inOrderNodes, start, mid - 1);
    // Elements to the right of the middle element form the right subtree
    root->right = convertSortedArrayToBalancedBST(inOrderNodes, mid + 1, end);

    // Return root
    return root;
}

struct Node* convertToBalancedBST(struct Node* root) {
    // Create an array
    int inOrderNodes[100]; // You may need to adjust the size based on your input
    int index = 0;
    // Store the in-order traversal in the array
    storeInOrderTraversal(root, inOrderNodes, &index);

    // Make a balanced BST from the sorted array
    return convertSortedArrayToBalancedBST(inOrderNodes, 0, index - 1);
}

int main() {
    // Example 1
    struct Node* root1 = createNode(50);
    root1->left = createNode(23);
    root1->right = createNode(62);
    root1->left->left = createNode(17);
    root1->left->right = createNode(45);
    root1->left->left->left = createNode(3);
    root1->left->right->left = createNode(31);
    root1->left->right->right = createNode(48);
    root1 = convertToBalancedBST(root1);
    printf("Normal Tree : 50 23 62 17 45 3 31 48\n");
    printf("Balanced Tree : ");
    preOrder(root1);
    printf("\n");
    // Example 2
    /*struct Node* root2 = createNode(7);
    root2->right = createNode(8);
    root2->right->right = createNode(9);
    root2 = convertToBalancedBST(root2);
    preOrder(root2);
    printf("\n");
    */
    return 0;
}
