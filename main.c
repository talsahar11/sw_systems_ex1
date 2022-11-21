#include <stdio.h>
#include "NumClass.h"
int main(){
	int numbers[4][10000] ;
	int currentNumber, toRange ;
	while(scanf("%d%d", &currentNumber, &toRange) != 2){
		char c ;
		scanf("%c", &c) ;
	}
	
	int primeIndex = 0, strongIndex = 0, armstrongIndex = 0, palindromeIndex = 0 ;
	while(currentNumber <= toRange){
		if(isArmstrong(currentNumber)){
			numbers[0][armstrongIndex++] = currentNumber ;
		}
		if(isPalindrome(currentNumber)){
			numbers[1][palindromeIndex++] = currentNumber ;
		}	
		if(isPrime(currentNumber)){
			numbers[2][primeIndex++] = currentNumber ;
		}
		
		if(isStrong(currentNumber)){
			numbers[3][strongIndex++] = currentNumber ;
		}
		
		currentNumber++ ;
	}
	int i ;
	printf("The Armstrong numbers are:") ;
	for(i = 0 ; i < armstrongIndex ; i++){
		printf(" %d", numbers[0][i]) ;
	}	
	printf("\nThe Palindromes are:") ;
	for(i = 0 ; i < palindromeIndex ; i++){
		printf(" %d", numbers[1][i]) ;
	}
	printf("\nThe Prime numbers are:") ;
	for(i = 0 ; i < primeIndex ; i++){
		printf(" %d", numbers[2][i]) ;
	}
	printf("\nThe Strong numbers are:") ;
	for(i = 0 ; i < strongIndex ; i++){
		printf(" %d",numbers[3][i]) ;
	} 
}

