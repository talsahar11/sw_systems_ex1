#include <stdio.h>
#include <math.h>

//get the length of a given number (additional helper function).	
int getLength(int num){								
	int i = 0 ;
	while(num >= 1){
		num /= 10 ;
		i++ ;
	}
	return i ;
}

int isPalindromeRecursive(int num, int length){
	//firstDigit == lsb of the current number, lastDigit == msb of the current num.
	int firstDigit = num % 10, lastDigit = (int)(num/pow(10,length-1))%10 ;		
	//stop term, if the number length <= 1, it is a palindrome.
	if(length <= 1){								
		return 1;								
	}								
	//stop term, if the first digit and last digit unequal return false.
	if(firstDigit != lastDigit){							
                return 0 ;
        }
        //recursive call, on the next call, the lsb of the number will be removed,
        //length-2 for that lsb, and for the lastDigit to get the next digit.
	return isPalindromeRecursive(num/10,length-2) ;				
}											


int isArmstrongRecursive(int num, int length, int sum){					
	//stop-term: if sum == 0 && num == 0 this is an Armstrong number.
	if(sum == 0 && num == 0){							
		return 1 ;					
	}
	//stop-term: if num == 0 && sum != 0 this is not an Armstrong number.
	//stop-term: if sum < 0, it is not an Armstrong number.
	if(num == 0 || sum < 0){							
		return 0 ;								
	}
	//the original number is being decreased by the n'th power of the current digit,
	sum -= pow(num%10, length) ;							
										
	//recursive call: cut the lsb of the number and pass the original length, and 		//the current sum.								
	return (isArmstrongRecursive(num/10, length, sum));				
											
}

//assist function for the recursion.
int isPalindrome(int num){                                                           
        return isPalindromeRecursive(num, getLength(num)) ;
}

//assist function for the recursion.
int isArmstrong(int num){								
	return isArmstrongRecursive(num, getLength(num), num) ;	
}



