// C program to demonstrate insert operation in binary search tree. 
#include<stdio.h> 
#include<stdlib.h>
 
#define COUNT 5
#include "bst.h"

void deleteTree(struct node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    deleteTree(node->left);  
    deleteTree(node->right);  
      
    /* then delete the node */
    printf("\n Deleting node: %s",node->data);  
    free(node);  
}  
// A utility function to create a new BST node 
struct node *newNode(char *item,int len) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	memset(temp->data,0,sizeof(temp->data));
	memcpy(temp->data,item,len);
	temp->len=len;
	//printf("data:%s",temp->data);
	//temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%s \n", root->data); 
		inorder(root->right); 
	} 
} 
/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, char *key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (strcmp(key,root->data)<0) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (strcmp(key,root->data)>0) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
		memcpy(root->data,temp->data,temp->len);
       // root->data = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
void print2DUtil(struct node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
// Wrapper over print2DUtil() 
void print2Dt(struct node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 
//iterative insert

struct node* insertItr(struct node *root, char *data,int len)
{
	 // Create a new Node containing 
    // the new element 
    struct node* new_node = newNode(data,len); 
  
    // Pointer to start traversing from root and 
    // traverses downward path to search 
    // where the new node to be inserted 
    struct node* x = root; 
  
    // Pointer y maintains the trailing 
    // pointer of x 
  struct  node* y = NULL; 
  
    while (x != NULL) { 
        y = x; 
        if (strcmp(data,x->data)<0){ 
            x = x->left; 
			//printf("\ngoingtoleft");
		}
        else if(strcmp(data,x->data)>0)
		{
            x = x->right; 
		//	printf("goingtoright");
		}
		else
			break;
		
    } 
  //printf("loop finished");
    // If the root is NULL i.e the tree is empty 
    // The new node is the root node 
    if (y == NULL) 
        y = new_node; 
  
    // If the new key is less then the leaf node key 
    // Assign the new node to be its left child 
    else if (strcmp(data,y->data)<0) 
        y->left = new_node; 
  
    // else assign the new node its right child 
    else if(strcmp(data,y->data)>0)
        y->right = new_node; 
  
    // Returns the pointer where the 
    // new node is inserted 
    return y; 
	
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, char *data,int len) 
{ 
	
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(data,len); 

	/* Otherwise, recur down the tree */
	if(strcmp(data,node->data)<0)
			node->left = insert(node->left, data,len); 
	else if (strcmp(data,node->data)>0) 
		node->right = insert(node->right, data,len); 

	/* return the (unchanged) node pointer */
	return node; 
} 
//searching for data

int iterativeSearch(struct node* root, char *data) 
{ 
    // Traverse untill root reaches to dead end 
    while (root != NULL) { 
        // pass right subtree as new tree 
        if (strcmp(data,root->data)>0) 
            root = root->right; 
  
        // pass left subtree as new tree 
        else if (strcmp(data ,root->data)<0) 
            root = root->left; 
        else
            return 1; // if the key is found return 1 
    } 
    return 0; 
} 
// Driver Program to test above functions 
/*int main() 
{ 
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	/*char d[1024];
	char line[1000];
	
	int number;
	struct node *root = NULL; 
	int r;
	memset(line,0,sizeof(line));
	FILE *fp;
	fp=fopen("blockedlist.txt","r");
	//fp=fopen("testbst.txt","r");
	if(fp!=NULL)
	{
		
number=0;
		
		
		do{
		
		r=fgets(line,sizeof(line),fp);
		//printf("%s",line);
		if(line[0]=='#')
			continue;
			trim(line);
		if(root == NULL)
		root = insert(root, line,strlen(line)); 	
		else
			insert(root, line,strlen(line)); 
		
		number++;	
		//if(number>30)
			//break;
			
		}while(r!=NULL);
		
	}
	if(fp!=NULL)
	fclose(fp);
	printf("total:%d\n",number);
	//insert(root, 30); 
	//insert(root, 20); 
	//insert(root, 40); 
	//insert(root, 70); 
	//insert(root, 60); 
	//insert(root, 80); 

	// print inoder traversal of the BST 
	//inorder(root); 
print2D(root);
	
		char q;
		while(q!='q'){
			
			printf("\nenter q:-Quit d:-Delete s:-Search p:-Print2D i:-inorder =");
			scanf("%c",&q);
			switch(q)
			{
				case 's':
				printf("Enter text to search:");
				scanf("%s",d);
				if(iterativeSearch(root,d))
				{
					printf("Found!");
				}
				else
					printf("Not found :(");
				break;
				case 'd':
					printf("\nEnter data to delete:");
					scanf("%s",d);
					if(deleteNode(root,d)==NULL)
						printf("can not delete");
					else
						printf("deleted");
								
				break;
				case 'p':
				
				print2D(root);
				
				break;
				case 'i':
				
				inorder(root);
				break;
				
			}
			
			
	
	
		//	else{
	
	
			//}
		}
	return 0; 
} */
