#include <iostream>
bool wordcheck;

}
int main() {
  char word[] = {'c', 'o', 'd', 'e'};
  //^enter word here^//
  int charsize = sizeof(char);
  int wordsize = sizeof(word);
  int numofletters = (wordsize/charsize);
  std::cout << "There are " << numofletters << " letters" << std::endl;
  
  int bodyparts = 6;
  double incorrectguesses = 0;
  int correctguesses = 0;
  bool wordguessed = false;
  bool wordguessedcheck = false;
  bool incorrectguessmade = false;
  bool correctguessmade = false;
  char correctletterguess[numofletters];
  bool letterused = false;
  
  for(int guesses = 0; incorrectguesses < bodyparts; guesses++){
    correctguessmade = false;
    
    if (incorrectguessmade == true){
      incorrectguessmade = false;
      incorrectguesses = incorrectguesses + 1;
      std::cout << "The guess was incorrect" << std::endl;
      std::cout << "You have made " << incorrectguesses << " incorrect guesses so far" << std::endl;
      std::cout << "You have " << bodyparts - incorrectguesses << " incorrect guesses left so far" << std::endl;
    }
    
    if (wordguessed == false){
      std::cout << "Enter a letter or guess the word" << std::endl;
    char letter;
    std::cin >> letter;
      
    for(int wordcheck = 0; wordcheck <= numofletters; wordcheck++){
      if (letter == word[wordcheck]){
        correctguesses = correctguesses + 1;
        std::cout << "The guess was the " << wordcheck+1 << " letter in the word" << std::endl;
        char correctletterguess[wordcheck+1];
        incorrectguessmade = false;
        correctguessmade = true;
      }
        
      else{
        if(correctguessmade == false){
        incorrectguessmade = true;
          }
      }
      
      if (correctguesses == numofletters){
        wordguessed = true;
      }
      }
    }
      
    else{
      if(wordguessedcheck == false){
        std::cout << "You correctly guessed the word" << std::endl;
        std::cout << "You took " << guesses << " tries to guess the word";
        wordguessedcheck = true;
        }
      else{
        return 0;
      }
    }
  }
  }
