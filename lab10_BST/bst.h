#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node{
	int data;
	struct Node *left_child;
	struct Node *right_child;
};

/* өгөгдсөн data утга бүхий шинэ Node үүсгэж буцаана */
struct Node *create_node(int data)
{
	struct Node *n=(struct Node *)malloc(sizeof(struct Node));
	n->data=data;
	n->left_child = NULL;
	n->right_child = NULL;
	return n;
}
/* өгөгдсөн дэд модыг устгах */
void delete_tree(struct Node *n){
	if(n!=NULL){
		delete_tree(n->left_child);
		delete_tree(n->right_child);
		free(n);
		n=NULL;
	}
}

/* root-ийн зааж буй дэд модноос x тоог хайн, олдсон node-ийн хаягийг буцаана.
   Олдохгүй бол null утгыг буцаана.
 */
struct Node* find(struct Node *root, int d)
{
	if(root == NULL||root->data == d)
		return root;
	if(root->data<d)
		return find(root->right_child, d);
	return find(root->left_child, d);
}
/* root-ийн зааж буй зангилаагаар үндсээ хийсэн модны өндрийг буцаана */
int height(struct Node *root)
{
	if(root==NULL)
		return 0;
	else{
		int left = height(root->left_child);
		int right = height(root->right_child);
		if(left>right)
			return (left+1);
		else
			return right+1;
	}
	/* Энд өндрийг олох үйлдлийг хийнэ */
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модонд d утгыг орууж шинээр үүссэн дэд модыг буцаана */
struct Node* insert(struct Node* root, int d)
{
	if(root==NULL){
		return create_node(d);
	}else if(root->data<d)
		root->right_child = insert(root->right_child,d);
	else
		root->left_child = insert(root->left_child, d);
	return root;
	
	/* Энд оруулах үйлдлийг хийнэ үү */
}
struct Node* min(struct Node* root){
	struct Node* current = root;			//root iig hadgalah temp uusgene
	while(current->left_child != NULL)		//zuun taliin hamgiin zahiin huuhdiig current butsaana
		current = current->left_child;
	return current;							
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модоос d утгыг устгаж шинээр үүссэн дэд модыг буцаана */
struct Node* removes(struct Node* root, int d)
{
	if(root == NULL)				//root huuhedgui bol root-iig butsaana
		return root;
	if(d<root->data)			//haij baigaa utga rootiin utgaas baga bol zuun talaas haina
		root->left_child = removes(root->left_child, d);
	else if(d>root->data)		//haij baigaa utga rootiin utgaas baga bol baruun talaas haina
		root->right_child = removes(root->right_child, d);
	else{						//haij baigaa utga oldson bol
		if(root->left_child == NULL){		//zuun taldaa huuhedgui bol baruun huuhdiig uuriinhuu orond butsaana
			struct Node *temp = root->right_child;
			free(root);
			return temp;
		}
		else if(root->right_child==NULL){	//baruun taldaa huuhedgui bol zuun huuhdiig uuriinhuu orond butsaana
			struct Node *temp = root->left_child;
			free(root);
			return temp;
		}
		struct Node *temp = min(root->right_child);		//hoer taldaa huuhedtei bol baruun huuhdiin hamgiin baga utgiig temp-d onoon
		root->data = temp->data;						//rootiin utgad ugnu
		root->right_child = removes(root->right_child, temp->data);	//baruun huuhdiig recursiveeer dahin ustgana
	}
}
/* root-ийн зааж буй Tree-г in-order-оор хэвлэ */
void inorder(struct Node *root)
{
	if(root!=NULL){
		inorder(root->left_child);
		printf("%d ", root->data);
		inorder(root->right_child);
	}
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
}
#endif
