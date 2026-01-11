#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0

struct RBNode {
    int value;
    int shade;
    struct RBNode *lchild, *rchild, *parent;
};

struct RBNode *treeRoot = NULL;

// Create new node 
struct RBNode* createRBNode(int val) {
    struct RBNode* temp = (struct RBNode*)malloc(sizeof(struct RBNode));
    temp->value = val;
    temp->shade = RED;
    temp->lchild = temp->rchild = temp->parent = NULL;
    return temp;
}

// Left rotation 
void rotateLeftRB(struct RBNode *curr) {
    struct RBNode *child = curr->rchild;
    curr->rchild = child->lchild;

    if (child->lchild != NULL)
        child->lchild->parent = curr;

    child->parent = curr->parent;

    if (curr->parent == NULL)
        treeRoot = child;
    else if (curr == curr->parent->lchild)
        curr->parent->lchild = child;
    else
        curr->parent->rchild = child;

    child->lchild = curr;
    curr->parent = child;
}

// Right rotation 
void rotateRightRB(struct RBNode *curr) {
    struct RBNode *child = curr->lchild;
    curr->lchild = child->rchild;

    if (child->rchild != NULL)
        child->rchild->parent = curr;

    child->parent = curr->parent;

    if (curr->parent == NULL)
        treeRoot = child;
    else if (curr == curr->parent->lchild)
        curr->parent->lchild = child;
    else
        curr->parent->rchild = child;

    child->rchild = curr;
    curr->parent = child;
}

// Fix Red-Black properties 
void fixRBInsert(struct RBNode *node) {
    while (node != treeRoot && node->parent->shade == RED) {

        if (node->parent == node->parent->parent->lchild) {
            struct RBNode *uncle = node->parent->parent->rchild;

            if (uncle != NULL && uncle->shade == RED) {
                node->parent->shade = BLACK;
                uncle->shade = BLACK;
                node->parent->parent->shade = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->rchild) {
                    node = node->parent;
                    rotateLeftRB(node);
                }
                node->parent->shade = BLACK;
                node->parent->parent->shade = RED;
                rotateRightRB(node->parent->parent);
            }
        } else {
            struct RBNode *uncle = node->parent->parent->lchild;

            if (uncle != NULL && uncle->shade == RED) {
                node->parent->shade = BLACK;
                uncle->shade = BLACK;
                node->parent->parent->shade = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->lchild) {
                    node = node->parent;
                    rotateRightRB(node);
                }
                node->parent->shade = BLACK;
                node->parent->parent->shade = RED;
                rotateLeftRB(node->parent->parent);
            }
        }
    }
    treeRoot->shade = BLACK;
}

// Insert node 
void insertRB(int val) {
    struct RBNode *newNode = createRBNode(val);
    struct RBNode *parentPtr = NULL;
    struct RBNode *trav = treeRoot;

    while (trav != NULL) {
        parentPtr = trav;
        if (val < trav->value)
            trav = trav->lchild;
        else
            trav = trav->rchild;
    }

    newNode->parent = parentPtr;

    if (parentPtr == NULL)
        treeRoot = newNode;
    else if (val < parentPtr->value)
        parentPtr->lchild = newNode;
    else
        parentPtr->rchild = newNode;

    fixRBInsert(newNode);
}

// Height calculation 
int treeHeight(struct RBNode* node) {
    if (node == NULL) return 0;
    int lh = treeHeight(node->lchild);
    int rh = treeHeight(node->rchild);
    return (lh > rh ? lh : rh) + 1;
}

// Print specific level 
void printLevelRB(struct RBNode* node, int level, int curr) {
    if (node == NULL) {
        if (curr == level) printf("   ");
        return;
    }
    if (curr == level)
        printf("%d(%s) ", node->value, node->shade == RED ? "R" : "B");
    else {
        printLevelRB(node->lchild, level, curr + 1);
        printLevelRB(node->rchild, level, curr + 1);
    }
}

// Level order traversal 
void levelOrderRB() {
    int h = treeHeight(treeRoot);
    printf("\nLevel Order Traversal:\n");
    for (int i = 0; i < h; i++) {
        printf("Level %d: ", i);
        printLevelRB(treeRoot, i, 0);
        printf("\n");
    }
}

// Inorder traversal 
void inorderRB(struct RBNode *node) {
    if (node != NULL) {
        inorderRB(node->lchild);
        printf("%d(%s) ", node->value,
               node->shade == RED ? "R" : "B");
        inorderRB(node->rchild);
    }
}

int main() {
    int n, input;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        insertRB(input);
    }

    printf("\nInorder Traversal:\n");
    inorderRB(treeRoot);

    levelOrderRB();

    return 0;
}
