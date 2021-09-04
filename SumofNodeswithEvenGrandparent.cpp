//
//  SumofNodeswithEvenGrandparent.cpp
//  
//
//  Created by Arihant on 9/5/21.
//

#include <stdio.h>
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 int ans;
void dfs(Tree *root, Tree *parent, Tree *grandParent){
    if(!root)
        return;
    if(grandParent && grandParent -> val % 2 == 0)
        ans += root -> val;
    dfs(root -> left, root, parent);
    dfs(root -> right, root, parent);
    
}
int solve(Tree* root) {
    ans = 0;
    dfs(root, NULL, NULL);
    return ans;
}
