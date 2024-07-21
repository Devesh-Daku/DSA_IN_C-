
#include "./BSTclass.h"

class AVLNode : public Node {
  public:
    int height = 0;
    AVLNode(int key) {
        this->data = key;
    }
    AVLNode(int key , int h){
        this->data = key;
        this->height = h;
    }
    int NodeHeight(AVLNode *p);
};

class AVLTree : protected BinSearchTree {
    public: 
      AVLNode* Insert(AVLNode* , int ); 
};

int AVLNode :: NodeHeight( AVLNode* p) {
    int hl , hr;
    hl = p && p->lft ? p->lft->height // pending avl tree 
}
AVLNode* AVLTree :: Insert( AVLNode *p, int key){
  AVLNode *t ;
    if(p==NULL){
        t = new AVLNode(key , 1);
        return t;
    }
    if(key<p->data) p->lft = RInsert(key, p->lft);
    else if ( key > p->data) p->rht = RInsert(key , p->rht);

  
    return p;
}