#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int key;
    struct AVLNode *lc, *rc;
    int ht;
};

int maximum(int x, int y) {
    return (x > y) ? x : y;
}

int getHeight(struct AVLNode *ptr) {
    if (ptr == NULL)
        return 0;
    return ptr->ht;
}

struct AVLNode* createNode(int value) {
    struct AVLNode* temp = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    temp->key = value;
    temp->lc = temp->rc = NULL;
    temp->ht = 1;
    return temp;
}

struct AVLNode* rotateRight(struct AVLNode* parent) {
    struct AVLNode* child = parent->lc;
    struct AVLNode* temp = child->rc;

    child->rc = parent;
    parent->lc = temp;

    parent->ht = maximum(getHeight(parent->lc), getHeight(parent->rc)) + 1;
    child->ht = maximum(getHeight(child->lc), getHeight(child->rc)) + 1;

    return child;
}

struct AVLNode* rotateLeft(struct AVLNode* parent) {
    struct AVLNode* child = parent->rc;
    struct AVLNode* temp = child->lc;

    child->lc = parent;
    parent->rc = temp;

    parent->ht = maximum(getHeight(parent->lc), getHeight(parent->rc)) + 1;
    child->ht = maximum(getHeight(child->lc), getHeight(child->rc)) + 1;

    return child;
}

int balanceFactor(struct AVLNode* ptr) {
    if (ptr == NULL)
        return 0;
    return getHeight(ptr->lc) - getHeight(ptr->rc);
}

struct AVLNode* insertAVL(struct AVLNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->key)
        root->lc = insertAVL(root->lc, value);
    else if (value > root->key)
        root->rc = insertAVL(root->rc, value);
    else
        return root;

    root->ht = 1 + maximum(getHeight(root->lc), getHeight(root->rc));

    int bf = balanceFactor(root);

    if (bf > 1 && value < root->lc->key)
        return rotateRight(root);

    if (bf < -1 && value > root->rc->key)
        return rotateLeft(root);

    if (bf > 1 && value > root->lc->key) {
        root->lc = rotateLeft(root->lc);
        return rotateRight(root);
    }

    if (bf < -1 && value < root->rc->key) {
        root->rc = rotateRight(root->rc);
        return rotateLeft(root);
    }

    return root;
}

// Level Order 
void displayLevelOrder(struct AVLNode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct AVLNode* q[100];
    int front = 0, rear = 0, level = 0;

    q[rear++] = root;

    printf("\nLevel Order Traversal:\n");

    while (front < rear) {
        int count = rear - front;
        printf("Level %d: ", level++);

        for (int i = 0; i < count; i++) {
            struct AVLNode* curr = q[front++];
            printf("%d ", curr->key);

            if (curr->lc)
                q[rear++] = curr->lc;
            if (curr->rc)
                q[rear++] = curr->rc;
        }
        printf("\n");
    }
}

void printAVLTree(struct AVLNode* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printAVLTree(root->rc, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d", root->key);

    printAVLTree(root->lc, space);
}

int main() {
    struct AVLNode* treeRoot = NULL;

    int dataList[] = {157, 110, 147, 122, 149, 151, 111, 141, 112, 123, 133, 117};
    int size = sizeof(dataList) / sizeof(dataList[0]);
    printf("values: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", dataList[i]);
        treeRoot = insertAVL(treeRoot, dataList[i]);
    }

    printf("\n");
    displayLevelOrder(treeRoot);

    printf("\nTree Structure:\n");
    printAVLTree(treeRoot, 0);

    if (balanceFactor(treeRoot) >= -1 && balanceFactor(treeRoot) <= 1)
        printf("\nTree is AVL balanced\n");
    else
        printf("\nTree is NOT balanced\n");

    return 0;
}
