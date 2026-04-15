#include <stdio.h>
#include <stdlib.h>

// Structure for decision tree node
struct node {
    char question[100];
    struct node *yes;
    struct node *no;
    int isLeaf;
    char result[100];
};

// Function to create a new node
struct node* createNode(char question[], int isLeaf, char result[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (isLeaf == 1) {
        strcpy(newNode->result, result);
        newNode->isLeaf = 1;
        newNode->yes = NULL;
        newNode->no = NULL;
    } else {
        strcpy(newNode->question, question);
        newNode->isLeaf = 0;
        newNode->yes = NULL;
        newNode->no = NULL;
    }

    return newNode;
}

// Function to traverse decision tree
void decision(struct node* root) {
    struct node* temp = root;

    while (temp != NULL) {

        // If leaf node, print result
        if (temp->isLeaf == 1) {
            printf("\nDecision: %s\n", temp->result);
            return;
        }

        char answer;
        printf("%s (y/n): ", temp->question);
        scanf(" %c", &answer);

        if (answer == 'y' || answer == 'Y') {
            temp = temp->yes;
        } else {
            temp = temp->no;
        }
    }
}

int main() {
    // Creating nodes
    struct node* root = createNode("Is temperature > 30?", 0, "");

    struct node* hot = createNode("", 1, "Turn on AC");
    struct node* normal = createNode("", 1, "No AC needed");

    // Linking nodes
    root->yes = hot;
    root->no = normal;

    // Run decision system
    printf("Decision Making System\n");
    decision(root);

    return 0;
}
