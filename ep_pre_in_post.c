#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura do no da arvore
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Funcao para criar um novo no
Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funcao para pesquisar o i­ndice de um elemento em uma lista
int searchIndex(char *arr, int start, int end, char value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

int preIndex = 0;

// Funcao para construir a arvore a partir dos formatos pre-ordem e in ordem
Node *buildTree(char *preorder, char *inorder, int inStart, int inEnd)
{

    if (inStart > inEnd)
        return NULL;

    Node *newNode = createNode(preorder[preIndex++]);

    if (inStart == inEnd)
        return newNode;

    int inIndex = searchIndex(inorder, inStart, inEnd, newNode->data);

    newNode->left = buildTree(preorder, inorder, inStart, inIndex - 1);
    newNode->right = buildTree(preorder, inorder, inIndex + 1, inEnd);

    return newNode;
}

// Funcao para imprimir o percurso pre-ordem da arvore
void printPostorder(Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c", node->data);
}

int main()
{

    int c;

    scanf("%d", &c);

    int i, length;

    for (i = 0; i < c; i++)
    {
        scanf("%d", &length);

        char *preorder = malloc(sizeof(char) * length);
        char *inorder = malloc(sizeof(char) * length);

        scanf("%s %s", preorder, inorder);

        preIndex = 0;

        Node *root = buildTree(preorder, inorder, 0, length - 1);

        printPostorder(root);
        printf("\n");
    }

    return 0;
}
