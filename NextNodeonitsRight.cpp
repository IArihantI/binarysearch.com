//
//  NextNodeonitsRight.cpp
//  
//
//  Created by Arihant on 9/6/21.
//

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* tree, int target) {
    if(!tree)
        return tree;
    queue<Tree*> q;
    q.push(tree);
    q.push(NULL);
    while(!q.empty()){
        Tree *temp = q.front();
        q.pop();
        if( temp == NULL){
            if(q.size() != 0)q.push(NULL);
        }
        else if(temp->val == target){
            return q.front();
        }
        else{
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    return NULL;
}
