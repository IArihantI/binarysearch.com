//
//  Rotateby90.cpp
//  
//
//  Created by Arihant on 9/5/21.
//

#include <stdio.h>
vector<vector<int>> solve(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i; j < matrix.size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
//    return matrix;
    for(int i = 0; i < matrix.size(); i++){
        int x = 0, y = matrix.size() - 1;
        while (x <= y){
            swap(matrix[x++][i], matrix[y--][i]);
        }
    }
    return matrix;
}
