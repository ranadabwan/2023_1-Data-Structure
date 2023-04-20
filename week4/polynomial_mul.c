#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#define BUFFSIZE 1024
#define MAX_EXP 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct poly_ {
	int coeffs[MAX_EXP + 1]; //the number
	int check[MAX_EXP + 1]; //the power
} poly;


//clearing all the powers and numbers to 0
//we take the poly and set it to 0
void clearPoly(poly* A) {
	int i;
	for (i = 0; i < MAX_EXP + 1; i++) {
		A->check[i] = 0;
		A->coeffs[i] = 0;
	}
}

//creating poly to all the values that are equal to 0
//we define a new poly with the values equal to 0
poly createPoly(void) {
	poly res;
	int i;
	for (i = 0; i < MAX_EXP + 1; i++) {
		res.check[i] = 0;
		res.coeffs[i] = 0;
	}

	return res;
}



void printPoly_impl(poly A, char* buffer) {
	int isFirst = 1;
	int noTermFlag = 1;
	int i;
	for (i = MAX_EXP; i >= 0; i--) {
		char buffTemp[BUFFSIZE] = ""; //defined to nothing
		if (A.check[i] == 1) { 
			noTermFlag = 0; 
			if (isFirst == 1 || A.coeffs[i] < 0) { //to check the coeff if its neg  
				sprintf(buffTemp, "%dx^%d", A.coeffs[i], i); //to create a string with temp buff to that its adding %d then giving the power and the power can only be pos
				strcat(buffer, buffTemp); //to concat the global buffer and the temp buff we have created
				isFirst = 0;
			}
			else if (A.coeffs[i] > 0) { //if pos val
				sprintf(buffTemp, "+%dx^%d", A.coeffs[i], i);
				strcat(buffer, buffTemp);
			}
		}
	}

	if (noTermFlag == 1) {  
		sprintf(buffer, "0");
	}
}

void printPoly(poly A) {
	char buffer[BUFFSIZE] = "";
	printPoly_impl(A, buffer); //print all the val to A
	printf(buffer);
}

void addTerm(poly* A, int exp, int coeff) {
	if (A->check[exp] == 1) {
		A->coeffs[exp] += coeff; //check if the exp exists or not if it exists then it will add ot the prev value
	}
	else if (A->check[exp] == 0) { //if its a new poly
		A->check[exp] = 1; //theres a valid exp at this position
		A->coeffs[exp] = coeff; //add the new value to it
	}

	if (A->coeffs[exp] == 0) { //if the exp val or power is 0 it will not be used for other expression like print or etc
		A->check[exp] = 0;
	}
}

poly multiPoly(poly A, poly B) {
	poly res = createPoly();
	int i, j;
	for (i = 0; i < MAX_EXP + 1; i++) {
		if (A.check[i] != 1) continue; 
		for (j = 0; j < MAX_EXP + 1; j++) {
			if (B.check[j] != 1) continue;

			addTerm(&res, i + j, A.coeffs[i] * B.coeffs[j]);
		}
	}

	return res;
}

int main() {
	
	poly A, B;

	
	A = createPoly();
	B = createPoly();
	
	
    addTerm(&A, 1, 1);
    addTerm(&A, 0, 1);
    //addTerm(&A, 2, 0);
    
    printf("poly A: ");
    printPoly(A);
    printf("\n");

    addTerm(&B, 1, 1);
    addTerm(&B, 0, -1);
    printf("poly B: ");
    printPoly(B);
    printf("\n");

    printf("A*B: ");
    printPoly(multiPoly(A, B));


	return 0;
}

