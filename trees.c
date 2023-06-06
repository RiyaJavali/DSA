#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//FILE *fptrip, *fptrop;
//this function will return the new node with the given value
struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if(root == NULL)
        return getNewNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if(root->key < val)
        root->right = insert(root->right,val);
    /*
     * if given val is smaller than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root->key >= val)
        root->left = insert(root->left,val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

/*
 * it will print the tree in ascending order
 * we will discuss about it in the upcoming tutorials
 */
void inorder(struct node *root,FILE *file)
{
    if(root == NULL)
        return;
    inorder(root->left,file);
    fprintf(file,"%d ->",root->key);
    inorder(root->right,file);
}

// Preorder traversal
void preorderTraversal(struct node* root,FILE *file)
{
  if (root == NULL) return;
  fprintf(file,"%d ->", root->key);
  preorderTraversal(root->left,file);
  preorderTraversal(root->right,file);
}

// Postorder traversal
void postorderTraversal(struct node* root,FILE *file)
{
  if (root == NULL) return;
  postorderTraversal(root->left,file);
  postorderTraversal(root->right,file);
  fprintf(file,"%d ->", root->key);
}

void generateRandomNumbersToFile(const char *filename, int count, int range)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Unable to create the file.\n");
        return;
    }

    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < count; i++)
    {
        int randomNumber = rand() % range;
        fprintf(file, "%d\n", randomNumber);
    }

    fclose(file);
}

struct node *insertFromFile(struct node *root, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return root;
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF)
    {
        root = insert(root, num);
    }

    fclose(file);
    return root;
}


int main()
{
    int n;
    struct node *root = NULL;

    generateRandomNumbersToFile("random_numbers.txt", 10, 100);

    // Insert numbers from the file into the binary search tree
    root = insertFromFile(root, "random_numbers.txt");
    // Open output files for each traversal
    FILE *inorderFile = fopen("inorder.txt", "w");
    FILE *preorderFile = fopen("preorder.txt", "w");
    FILE *postorderFile = fopen("postorder.txt", "w");

    // Perform traversals and write the output to respective files
    clock_t start,end;
    double total;
    start=clock();
    inorder(root, inorderFile);
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    //fprintf(inorderFile,"time: %f",total);

    start=clock();
    preorderTraversal(root, preorderFile);
    end=clock();
    total=(double)(end-start)*(1000000)/CLOCKS_PER_SEC;
    //fprintf(preorderFile,"time: %f",total);

    start=clock();
    postorderTraversal(root, postorderFile);
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    //fprintf(postorderFile,"time: %f",total);

    // Close the output files
    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);
    return 0;
}
