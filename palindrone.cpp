//Program made by Jermaine Lara
//9/25/17
//Program compares user input with its backwards counterpart to see if it's a palindrone.

#include <iostream>
#include <cstring>

using namespace std;
// can use <cstring> strcmp strlen and strcpy can't use strings!

int main()
{
  
  char input[81];
  char cleanInput[81];
  char backwardsInput[81];

  //Get user input
  cin.get(input,81);

  //Remove punctuation and whitespaces
  int j=0;
  for(int i=0; i<81; i++) {
    if(input[i] !=' ' && input[i] !=',' && input[i] !='!'
       && input[i] !=':' && input[i] !=';' && input[i] !='?'
       && input[i] !='"' &&input[i] !='.') {
      cleanInput[j] = input[i];
      j++;
    }
  }

  //Convert to lowercase
  int length = strlen(cleanInput);
  for (int i =0; i< length; i++) {
    if(cleanInput[i] >='A' && cleanInput[i] <= 'Z') {
      cleanInput[i] +=32;
    }
  }

  //Create a backwards input array
  for(int i=0; i<length; i++) {
    backwardsInput[length - i -1] = cleanInput[i];
  }
  backwardsInput[length] = 0;
  
  //Compare the clean input and the backwards input
  if(strcmp(cleanInput,backwardsInput) == 0) {
  cout <<"Palindrone." << endl;
} else {
  cout <<"Not a Palindrone." << endl;
 }
      
  
}

