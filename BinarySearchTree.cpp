#include <iostream>
#define end "\n"
using namespace std;
bool c= false;
class node{
public:
    int data;
    int height;
    node* left;
    node* right;
    node(){
        data=0;
        height=0;
        left= nullptr;
        right= nullptr;
    }
    explicit node(int input){
        data=input;
        height=0;
        left= nullptr;
        right= nullptr;
    }
};
class implement{
private:
    node* root;
public:
    implement(){
        root= nullptr;
    }
    bool isEmpty(){
        return root== nullptr;
    }
    bool makeEmpty(){
        return root= nullptr;
    }
    int height(node* h){
        return h== nullptr ?-1 : h->height;
    }
    int max(int lhs, int rhs){
        return lhs>rhs ? lhs : rhs;
    }
    void insert(int input){
        root=insert(root, input);
    }
    node* insert(node * r, int input){
        if(r== nullptr) r=new node(input);
        else if(input<r->data){
            r->left=insert(r->left, input);
            if(height(r->left)-height(r->right)==2){
                r=(input<r->left->data) ? rotateWithLeftChild(r) : doubleWithLeftChild(r);
            }
        } else if(input>r->data){
            r->right=insert(r->right, input);
            if(height(r->right)-height(r->left)==2){
                r=(input>r->right->data) ? rotateWithRightChild(r) : doubleWithRightChild(r);
            }
        }
        r->height=max(height(r->left), height(r->right));
        return r;
    }
    node* rotateWithLeftChild(node* k2){
        node* k1=k2->left;
        k2->left=k1->right;
        k1->right=k2;
        k2->height=max(height(k2->left), height(k2->right));
        k1->height=max(height(k1->left), height(k1->right));
        return k1;
    }
    node* rotateWithRightChild(node* k1){
        node* k2=k1->right;
        k1->right=k2->left;
        k2->left=k1;
        k1->height=max(height(k1->left), height(k1->right));
        k2->height=max(height(k2->left), height(k2->right));
//        return k2;
    }
    node* doubleWithLeftChild(node* k3){
        k3->left=rotateWithRightChild(k3->left);
        return rotateWithLeftChild(k3);
    }
    node* doubleWithRightChild(node* k1){
        k1->right=rotateWithLeftChild(k1->right);
        return rotateWithRightChild(k1);
    }
    node* findMin(node* root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    node* Delete(int input){
        return Delete(root, input);
    }
    node* Delete(node* r, int input){
        c=search(root, input);
        if(root== nullptr) return root;
        else if(input<r->data) r->left=Delete(r->left, input);
        else if(input>r->data) r->right=Delete(r->right, input);
        else{
            if(r->left== nullptr && r->right== nullptr){
                delete r;
                r= nullptr;
                return r;
            }
            else if(r->left== nullptr){
                node* temp=r;
                r=r->right;
                delete temp;
                return r;
            }
            else if(r->right== nullptr){
                node* temp=r;
                r=r->left;
                delete temp;
                return r;
            } else{
                node* temp=findMin(r->right);
                r->data=temp->data;
                r->right=Delete(r->right, temp->data);
            }
        }
        return r;
    }
    bool search(int input){
        return search(root, input);
    }
    bool search(node* r, int input){
        bool found=false;
        while(r!=nullptr && !found){
            int rval=r->data;
            if(input<rval) r=r->left;
            else if(input>r->data) r=r->right;
            else{
                found=true;
                break;
            }
            found=search(r, input);
        }
        return found;
    }
    node* rootVal(){
        cout<<"Value of Stored At root is : " ;
        if(root!= nullptr) cout<<root->data<<" ";
        cout<<endl;
    }
    int nodeCount(){
        return nodeCount(root);
    }
    int nodeCount(node* r){
        if(r== nullptr) return 0;
        else{
            int count=1;
            count+=nodeCount(r->left);
            count+=nodeCount(r->right);
            return count;
        }
    }
    void inorder(){
        inorder(root);
    }
    void postorder(){
        postorder(root);
    }
    void preorder(){
        preorder(root);
    }
    void inorder(node* r){
        if(r!=nullptr){
            inorder(r->left);
            cout<<r->data<<" ";
            inorder(r->right);
        }
    }
    void preorder(node* r){
        if(r!=nullptr){
            cout<<r->data<<" ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    void postorder(node* r){
        if(r!= nullptr){
            postorder(r->left);
            postorder(r->right);
            cout<<r->data<<" ";
        }
    }
};
int main(){
    implement obj;
    int testcases=0;
    cin>>testcases;
    while(testcases){
        cout<<"Enter Number of Node "<<end;
        int nodes;
        cin>>nodes;
        int ref=0;
	cout<<"Enter Value of Each Input\n"<<endl;
        while(ref++!=nodes){
            int input=0;
            cin>>input;
            obj.insert(input);
        }
        obj.preorder();
	cout<<endl;
        obj.inorder();
	cout<<endl;
        obj.postorder();
	cout<<endl;
        cout<<"Enter Element you want to search"<<endl;
        int input=0;
        cin>>input;
        obj.search(input);
        cout<<"Element you want to delete"<<endl;
        cin>>input;
        obj.Delete(input);
    }
    return 0;
}
