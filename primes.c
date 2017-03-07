//Sam Symmes
//March 6th 2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int args, char * argc[]){
  if(args !=3){ //if person inputed too many arguments, exit
    printf("invalid syntax\nCommand: Primes Bars\n");
  }
  else if(atoi(argc[1])==0 || atoi(argc[2])==0){ //if two inputs were not numbers, exit
    printf("invalid syntax\nCammand: Primes Bars\n");
  }
  else{
    double percent = 0.0; //percent complete running
    int primes = atoi(argc[1]); //number of primes to find
    int bars = atoi(argc[2]); //number of bars requested
    int i=6; //iterator for number to check if is prime
    int j=3; //iterator for how many primes were found
    int k; //iterator for which prime we're checking to see if "i" is equal to
    int * primeNums=malloc(sizeof(int)*primes); //list of primes
    primeNums[primes]=-1; //end of list of primes
    primeNums[0]=2; //putting in the first couple primes
    primeNums[1]=3;
    primeNums[2]=5;
    while(primeNums[j+1]!=-1){ //while we haven't found as many as desired
      k=0;
      while(primeNums[k]*primeNums[k]<i){ //check from the first prime in the list up to the square root of the number we're checking
	if(i % primeNums[k] == 0){ //if the number is divisible by this prime, "i" is not prime
	  break;
	}
	if(primeNums[k+1]*primeNums[k+1]>i){ //if we got through on the last loop, "i" is prime
	  percent = 100*(double)j/(double)primes;
	  primeNums[j]=i; //add "i" to the list
	  if(j%1000==0){ //every 1000 primes, tell the user the progress
	    printf("%.2f%\n",percent);
	  }
	  j++;
	}
	k++;
      }
      i++;
    }
    int increment = primeNums[j-1]/bars; //find increment between bars
    int bracket = increment;
    int * numInBrac = malloc(sizeof(int)*bars); //how many are in each bracket
    k=0;
    for(i=0;i<bars;i++){ //loop through the bars
      numInBrac[i]=0;
      while(1==1){
	if(primeNums[k]<bracket){ //add numbers to the bracket until you hit the end of the bracket
	  numInBrac[i]++;
	  k++;
	}
	else{ //increment the bracket up and start over
	  bracket += increment;
	  break;
	}
      }
    }
    int maxBrac = 0;
    for(i=0;i<bars;i++){
      if(numInBrac[i]>maxBrac){
	maxBrac=numInBrac[i];
      }
    }
    bracket=increment;
    for(i=0;i<bars;i++){ //print the bracket bounds
      printf("\n%d-%d: %d ",bracket-increment,bracket,numInBrac[i]);
      bracket += increment;
    }
    for(i=0;i<bars;i++){ //print the histogram's bars
      printf("\n");
      for(k=0;k<((50*numInBrac[i])/maxBrac);k++){
	printf("|");
      }
    }
    printf("\n");
  }
}
