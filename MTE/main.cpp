//
//  main.cpp
//  MTE
//
//  Created by Thomas Kristan on 07.11.20.
//

#include <iostream>
using namespace std;

int main() {
    int terms1 = 0;
    int terms2 = 0;
    int variables = 0;
    
    cout << "This program multiplies two multivariate polynomials. (max. 5 variables)" << endl;
    cout << " Amount of variables:";
    cin >> variables;
    while (variables > 5){
        cout << " Too many variables! (max. 5)" << endl << " Amount of variables: ";
        cin >> variables;
    }
    
    cout << "1st POLYNOMIAL:" << endl;
    cout << " Amount of terms (monomials): ";
    cin >> terms1;
    int poly1 [terms1][variables+1];
    for (int i = 0; i<terms1; i++){
        for (int j = 0; j<variables+1; j++) {
            poly1[i][j]=0;
        }
    }
    for (int row=0; row<terms1; row++) {
        cout << " Coefficient of term nr." << row+1 << ": ";
        cin >> poly1[row][0];
        for (int col=0; col<variables; col++) {
            char variable = 'a';
            cout << " Exponent of variable " << static_cast<char>(variable + col) << ": ";
            cin >> poly1[row][col+1];
        }
    }
    
    cout << "2nd POLYNOMIAL:" << endl;
    cout << " Amount of terms (monomials): ";
    cin >> terms2;
    int poly2 [terms2] [variables+1];
    for (int i = 0; i<terms2; i++){
        for (int j = 0; j<variables+1; j++) {
            poly2[i][j]=0;
        }
    }
    for (int row=0; row<terms2; row++) {
        cout << " Coefficient of term nr." << row+1 << ": ";
        cin >> poly2[row][0];
        for (int col=0; col<variables; col++) {
            char variable = 'a';
            cout << " Exponent of variable " << static_cast<char>(variable + col) << ": ";
            cin >> poly2[row][col+1];
        }
    }
    
    
    int prodPoly [terms1 * terms2][6];
    for (int i = 0; i<terms1 * terms2; i++){
        for (int j = 0; j<6; j++) {
            prodPoly[i][j]=0;
        }
    }
    //multiplying the coefficients
    int tmp = 0;
    for (int row1=0; row1<terms1; row1++) {
        for (int row2=0; row2<terms2; row2++) {
            prodPoly[tmp][0] = poly1[row1][0] * poly2[row2][0];
            tmp++;
        }
    }
    
    //multiplying the variables
    for (int col=1; col<variables+1; col++) {
        tmp=0;
        for (int rows1=0; rows1<terms1; rows1++) {
            for (int rows2=0; rows2<terms2; rows2++) {
                prodPoly[tmp][col] = poly1[rows1][col] + poly2[rows2][col];
                tmp++;
            }
        }
    }

    // checking if terms can be cancelled out / polynomial can be simplified
    for (int checkRow=0; checkRow < (terms1 * terms2); checkRow++) {
        for(int row = (checkRow+1) ; row < (terms1 * terms2); row++) // rows to compare checkRow to
        {
            int flag = 0 ;
            for(int col = 1 ; col < variables +1; col++) //number of columns
            {
                // break if even a single element doesn't match. Don't check for the remaining elements.
                if(prodPoly[checkRow][col] != prodPoly[row][col])
                {
                flag = 1 ;
                break ;
                }
            }
            if(!flag) //rows are equal
            {
                prodPoly[checkRow][0] = prodPoly[checkRow][0] + prodPoly[row][0];
                prodPoly[row][0] = 0;
            }
        }
    }
    
    cout << endl << "PRODUCT OF THE TWO POLYNOMIALS:" << endl;
    for (int row=0; row<(terms1*terms2); row++) {
        if (prodPoly[row][0] == 0){
            continue;
        }
        cout << prodPoly[row][0];
        if (prodPoly[row][1] != 0){
            cout << "a^" << prodPoly[row][1];
        }
        if (prodPoly[row][2] != 0){
            cout << "b^" << prodPoly[row][2];
        }
        if (prodPoly[row][3] != 0){
            cout << "c^" << prodPoly[row][3];
        }
        if (prodPoly[row][4] != 0){
            cout << "d^" << prodPoly[row][4];
        }
        if (prodPoly[row][5] != 0){
            cout << "e^" << prodPoly[row][5];
        }
        cout << " + ";
        
    }
    cout<<"0" << endl << endl;
    
    
    return 0;
}

