#include <iostream>
bool wordcheck;


int main() {
  char word[] = {'e', 'x', 'a', 'm', 
'p', 'l', 'e'};
  //^enter word here^//
  int charsize = sizeof(char);//Checking size of character in OS
  int wordsize = sizeof(word);//Checking size of word
  int numofletters = (wordsize/charsize);//Finding number of letters
  std::cout << "There are " << numofletters << " letters" << std::endl;//Displaying number of letters
  
  int bodyparts = 6;
  int guesses = 0;
  int incorrectguesses = 0;
  int correctguesses = 0;
  bool wordguessed = false;
  bool incorrectguessmade = false;
  bool correctguessmade = false;
  char correctletterguess[numofletters];
  bool letterused = false;
  char incorrectletterguess[bodyparts];
  //^Almost all variables being set
  
  for(int forguesses = 0; incorrectguesses < bodyparts && wordguessed == false; forguesses++){
    correctguessmade = false;
    letterused = false;
    if (incorrectguessmade == true){
      incorrectguessmade = false;
      incorrectguesses = incorrectguesses + 1;
      std::cout << "The guess was incorrect" << std::endl;
      std::cout << "You have made " << incorrectguesses << " incorrect guesses so far" << std::endl;
      std::cout << "You have " << bodyparts - incorrectguesses << " incorrect guesses left" << std::endl << std::endl;
    }//Checking if Incorrect guess was made
    
    if (incorrectguesses < bodyparts){
      std::cout << "Enter a letter or guess the word" << std::endl;
    char letter;
    std::cin >> letter;//Taking letter/word input
      
    for(int letterusedcheck = 0; letterusedcheck < numofletters; letterusedcheck++){
      if (letter == correctletterguess[letterusedcheck]){
        letterused = true;
      }
      if (letter == incorrectletterguess[letterusedcheck]){
        letterused = true;
      }
    }//Checking to see if the letter has been used before
      
    for(int wordcheck = 0; wordcheck <= numofletters && letterused == false; wordcheck++){//Checks if letter was marked as used, if not checks all letters to look for match
      if (letter == word[wordcheck]){//checks if letter exists in word
        correctguesses = correctguesses + 1;
        std::cout << "The guess was the " << wordcheck+1 << " letter in the word" << std::endl << std::endl;
        correctletterguess[wordcheck] = letter; //adding letter to used letters
        incorrectguessmade = false;
        correctguessmade = true;
      } 
        
      else{
        if(correctguessmade == false){
        incorrectguessmade = true;
        incorrectletterguess[incorrectguesses+1] = letter;
          } //marking letter as incorrect and adding to incorrect guesses
      }
      
      if (correctguesses == numofletters && incorrectguesses < bodyparts){
        wordguessed = true;//checks how many letters have been guessed and if the word has been guessed without the body being completed, if all letters have been guessed tells that the word has been guessed
      }
      }
    }
    guesses = forguesses;
  }
  if(wordguessed == true){
    std::cout << "You correctly guessed the word" <<   std::endl;
    std::cout << "The word was ";
    for(int letterdisplayed = 0; letterdisplayed < numofletters; letterdisplayed++){//looping to display every letter in word
      std::cout << word[letterdisplayed];
    }
    std::cout << std::endl << "You took " << 1 + guesses << " tries to guess the word";
  }
  if( incorrectguesses >= bodyparts){
    std::cout << "You failed to guess the word" << std::endl;
    std::cout << "The word was ";
    for(int letterdisplayed = 0; letterdisplayed < numofletters; letterdisplayed++){//looping to display each letter in word
      std::cout << word[letterdisplayed];
    }
    }
        return 0;
}