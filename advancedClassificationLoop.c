#include <stdio.h>
#include <math.h>

//assist function, gets the length of a given number.					
int getLength(int num){					
	int i = 0 ;
	
	while(num >= 1){
		num /= 10 ;
		i++ ;
	}
	return i ;
}

int isPalindrome(int num){
       int last = getLength(num), start = 0 ;
       int digits[last];
      	//setting the digits in the array by the orde				
        for(int i = last-1 ; i >= 0 ; i--){	
		digits[i] = num%10 ;
		num /= 10 ;
	}
	
	last-- ;		
	//check if the last digits cursur and the first digit cursur contains the same digits,			
        while(start <= last){		
        //as long as they are equal, the loop keeps going and returns true, once they unequal, return false.		
                if(digits[start] != digits[last]){	
                        return 0 ;
                }
                //set the pointers to the next digit, getting them towards each other.
                start++ ;				
                last-- ;
        }
        
	return 1 ;
}

int isArmstrong(int num){
	int sum = num, currentDigit, length = getLength(num) ;
	//at every iteration the following actions will happen:
	//*current digit is the lsb of the current number
	//*cut the lsb of the current numberwhile(num >= 1 && sum >= 0)			
	//*decrease the n'th power of the current digit from the original number
	while(num >= 1 && sum >= 0){
		currentDigit = num%10 ;			
		num /= 10 ;				
		sum -= pow(currentDigit, length) ;	
	}
	//if sum == 0, this is an Armstrong number.
	if(sum == 0){					
		return 1 ;
	}
	return 0 ;
			
}
