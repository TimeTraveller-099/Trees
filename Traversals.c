#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createBSTNode(Tree *root, int data)
{
    // Create a NODE, Set its DATA
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        return newNode;

    // If the VALUE is already present, return the TREE as it is.
    if (root->data == data)
        return root;

    // Left Insertion
    if (data < root->data)
        root->left = createBSTNode(root->left, data);
    else
        root->right = createBSTNode(root->right, data);

    // Return the current ROOT
    return root;
}

// Traversals
void preorder(Tree *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Tree *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    Tree *tree = NULL;
    tree = createBSTNode(tree, 38);
    tree = createBSTNode(tree, 14);
    tree = createBSTNode(tree, 8);
    tree = createBSTNode(tree, 56);
    tree = createBSTNode(tree, 45);
    tree = createBSTNode(tree, 82);
    tree = createBSTNode(tree, 70);
    tree = createBSTNode(tree, 23);
    tree = createBSTNode(tree, 18);

    preorder(tree);
    printf("\n");

    inorder(tree);
    printf("\n");

    postorder(tree);
}
