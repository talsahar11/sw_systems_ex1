#include <stdio.h>
#include <math.h>

//assist function that calculate`s the factorial of a given number.
int factorial(int num){                                  
        int sum = 1 ;
        for(int i = num; i > 1 ; i--){
                sum *= i ;
        }
        return sum ;
}

int isPrime(int num){	
	double sq = sqrt((double)num) ;
        //if num <= 0, its not prime, else if num <= 2, it is prime.
        if(num <= 0){					
                return 0 ;
        }
	else if(num <= 2){
                return 1 ;
        }
	else{
	//let i, for 3 <= i <= sqrt(number), if num % i == 0, then there is a divider and the 		number is not prime,
                for(int i = 2 ; i <= sq ; i++){		
                        if(num % i == 0){		
                                return 0;
                        }
                }
        }
        
	return 1 ;
}

int isStrong(int num){
	int sum = num ;	
	int tempNum = num ;				
	while(num >= 1 && sum > 0){				
		sum -= factorial(num%10) ;
		num /= 10 ;

	}
	//if sum == 0 && num == 0 after the while loop, it is a strong number.
	if(sum == 0 && num == 0){						
		return 1 ;
	}
	return 0 ;
}



