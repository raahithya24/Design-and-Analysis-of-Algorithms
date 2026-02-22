#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};
struct Node* createNode(char data, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}
void sort(struct Node* arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j]->freq > arr[j+1]->freq) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void printCodes(struct Node* root, int code[], int top, int *weightedSum) {
    if(root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1, weightedSum);
    }
    if(root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1, weightedSum);
    }
    if(root->left == NULL && root->right == NULL) {
        printf("%c : ", root->data);
        for(int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf(" (Length = %d)\n", top);
        *weightedSum += root->freq * top;
    }
}
int main() {
    char input[200];
    int freq[256] = {0};
    struct Node* nodes[256];
    int count = 0;
    int totalFreq = 0;
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    for(int i = 0; i < len; i++) {
        if(input[i] != ' ' && input[i] != '\n') {
            freq[(int)input[i]]++;
            totalFreq++;
        }
    }
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            nodes[count++] = createNode((char)i, freq[i]);
        }
    }
    int n = count;
    while(n > 1) {
        sort(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode =
            createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;
        nodes[1] = nodes[n - 1];
        n--;
    }
    struct Node* root = nodes[0];
    int code[MAX];
    int weightedSum = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, code, 0, &weightedSum);
    float avgLength = (float)weightedSum / totalFreq;
    printf("\nTotal Frequency = %d\n", totalFreq);
    printf("Average Code Length = %.3f bits\n", avgLength);
    return 0;
}