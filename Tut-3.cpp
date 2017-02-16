#include <iostream>
#include<limits.h>
using namespace std;
 
struct Interval
{
    int low, high;
};
 
struct ITNode
{
    Interval *i;  
    int maximum;
    ITNode *left, *right,*parent;
};
 
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->maximum = i.high;
    temp->left = temp->right = NULL;
    return temp;
};
struct ITNode * lowMin(struct ITNode* current_node)
{
    struct ITNode *current = current_node;
    while (current->left != NULL)
        current=current->left;
	return current;
}

ITNode *insert(ITNode *root,Interval i){
	if(root==NULL){
		return newNode(i);
	}
	if(i.low<(root->i)->low){
		root->left=insert(root->left,i);
	}
	else{
		root->right=insert(root->right,i);
	}
	if(root->maximum<i.high){
		root->maximum=i.high;
	}
	return root;
}

 

bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
void inorder(ITNode *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<"["<<root->i->low<<","<<root->i->high<<"] "<<"maximum = "<<root->maximum<<"\n";
		inorder(root->right);
	}
}
int getmaximum(int p,int q,int r){
	return p>q?(p>r?p:r):(q>r?q:r);
}

ITNode * deleteNode(ITNode *root,Interval x){
	if(root==NULL){
		return NULL;
	}
	if(x.low<(root->i)->low){
		root->left=deleteNode(root->left,x);
	}
	else if(x.low>(root->i)->low){
		root->right=deleteNode(root->right,x);
	}
	else if(x.low==(root->i)->low ){
		if(x.high==(root->i)->high){
			if(root->left==NULL){
				struct ITNode *temp=root->right;
				free(root);
				return temp;
			}
			else if(root->right==NULL){
				struct ITNode *temp=root->left;
				free(root);
				return temp;
			}
			struct ITNode *temp=lowMin(root->right);
			root->i=temp->i;
			root->right=deleteNode(root->right,*(temp->i));
			}
		else{
			root->right=deleteNode(root->right,x);
		}
	}
	root->maximum=getmaximum(root->i->high,((root->left!=NULL)?root->left->maximum:INT_MIN),((root->right!=NULL)?root->right->maximum:INT_MIN));
	return root;
}
 
Interval *SearchInterval(ITNode *root, Interval i)
{
    
    if (root == NULL) return NULL;

    if (doOVerlap(*(root->i), i))
        return root->i;

    if (root->left != NULL && root->left->maximum >= i.low)
        return SearchInterval(root->left, i);
 
    return SearchInterval(root->right, i);
}
 

int main()
{
    
Interval sample[] = {{25, 30}, {16, 26}, {17, 19},{4, 21}, {13, 21}, {30, 40}};
    int length = sizeof(sample)/sizeof(sample[0]);
    ITNode *root = NULL;
    for (int i = 0; i < length; i++)
        root = insert(root,sample[i]);
	cout << "interval tree is:-\n";
    inorder(root);
	Interval test1 = {12,16};
	Interval test2 = {19,25};
    Interval *result1 = SearchInterval(root, test1);
    if (result1 == NULL)
        cout << "\n no matching interval with {12,16}\n";
    else
        cout << "\n {12,16} overlaps with {" <<result1->low << "," <<result1->high << "} \n";
	
	Interval *result2 = SearchInterval(root, test2);
    if (result2 == NULL)
        cout << "\n no matching interval with {19,25}\n";
    else
        cout << "\n {19,25} overlaps with {" <<result2->low << "," << result2->high << "} \n";
        
    Interval del1= {30,40};
    cout << "\n delete interval {30,40}";
    root=deleteNode(root,del1);
    cout << "\n resulting interval tree : \n";
    inorder(root);
   

	return 0;
}