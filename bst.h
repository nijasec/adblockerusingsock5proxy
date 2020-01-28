
struct node 
{ 
	int len; 
	char data[1024];
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(char *item,int len) ;
void inorder(struct node *root) ;
struct node * minValueNode(struct node* node);
struct node* deleteNode(struct node* root, char *key) ;
void print2DUtil(struct node *root, int space);
// Wrapper over print2DUtil() 
void print2D(struct Node *root) ;
struct node* insert(struct node* node, char *data,int len);
int iterativeSearch(struct node* root, char *data) ;
