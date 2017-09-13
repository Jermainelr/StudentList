#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main () {

  //Initialize the RGN
  srand(time(NULL));
  char yOrN;
  
	//Multi Game Loop
        do {
	  
	  // Generate Number Between 0 and 100
	  int num = rand() % 101;
	  int count = 0;
	  int input = 0;
	  
	  // Single Game Loop
	  do {
	    
	    count++;
	    
	    //Prompt the User to Guess	    
	    cout << "Guess a Number between 1 and 100" << endl;	    
	    cin >> input;

	    if (input > num) {
	      cout << "Guess was too High!" << endl;
	    }
	    else if(input < num) {
	      cout << "Guess was too Low!" << endl;
	    }
	  }
	  
	  while (num != input);
	  
	        //Prompt the User to see if They Want to Keep Playing
	        cout << "You Guessed Correctly after " << count << " Guesses!" << endl;
	        cout << "Do you Wanna Play Again?" << endl;
	        cin >> yOrN;
        }
	
	while (yOrN == 'y');
}
     
	
       
	      
	    
	    
	  
# GuessingGame
