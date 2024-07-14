// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 7
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

bool isValidNote(string user_input)
{
  // store true or false in valid
  bool valid = false;
  // if the user input is length of 2 long, one letter and one number, continue
  if (user_input.length() == 2)
  {
    // if the first user input letter is the following valid will be true (1).
    if (user_input[0] == 'A' || user_input[0] == 'B' || user_input[0] == 'C' || user_input[0] == 'D' || user_input[0] == 'E' || user_input[0] == 'F' || user_input[0] == 'G')
    {
      valid = true;
    }
    // if user input for the letter was not the above it will be false and not continue
    else
    {
      valid = false;
      // if false it will return false and not continue
      return valid;
    }
  }
  // if the second part of user input is equal to the following numbers, valid will be true
  if (user_input[1] == '0' || user_input[1] == '1' || user_input[1] == '2' || user_input[1] == '3' || user_input[1] == '4' || user_input[1] == '5' || user_input[1] == '6' || user_input[1] == '7' || user_input[1] == '8' || user_input[1] == '9')
  {
    valid = true;
  }
  else
  {
    valid = false;
    return valid;
  }
  return valid;
}
bool isValidTune(string user_input)

{
  // start bool as true
  bool valid = true;
  // if the user input length is less then 2 its false
  if (user_input.length() < 2)
  {
    valid = false;
  }
  // for loop to check user input, every two
  for (int i = 0; i < user_input.length(); i += 2)
  {
    // since bool is originally true it will stay true
    // go to if statement that says if the user input doesnt pass isValidNote for every two substrings it is false
    if (!isValidNote(user_input.substr(i, 2)))
    {
      valid = false;
    }
  }
  return valid;
}
int numValidNotes(string user_input)
{
  // new varaiable "agree" starts at 0
  int agree = 0;
  int valid = true;

  // for loop if the user input length is greater then or equal to i, i adds one
  for (int i = 0; i <= user_input.length(); i++)
  {
    // new varaible user_in for holding the value of the substring for user_input, between i and 2
    string user_in = user_input.substr(i, 2);
    // if using previous isValidNote function is true agree goes up one
    if (isValidNote(user_in) == true)
    {
      // everytime they match or is correct to function isValidNote agree variable adds/ goes up by one
      agree++;
    }
  }
  // output how manytimes they match or output agree
  return agree;
}
double tuneSimilarity(string tune1, string tune2)
{

  // for similarity = (number of matching notes / total number of notes)
  //+ number of matching notes with matching pitches
  //- number of different notes with different pitches
  double match_note = 0;
  double similarity = 0;
  // total amount of notes using numValNotes function
  int total_note = numValidNotes(tune1);
  int match_match = 0;
  int different_different = 0;

  // if the two tune lengths don't equal eachother return 0
  if (tune1.length() != tune2.length())
  {
    return 0;
  }
  // for loop that goes through the tune length by 2 so it checks pairs
  for (int j = 0; j < tune1.length(); j += 2)
  {
    // if the tune note matches the tune note
    if (tune1[j] == tune2[j])
    {
      // match note goes up by 1
      match_note += 1;
      // if tune1 pitch matches tune2 pitch
      if (tune1[j + 1] == tune2[j + 1])
      {
        // number of matching notes with matching pitches (match_match) goes up by 1
        match_match++;
      }
    }
    // otherwise if the tune pitches don't match and the tune notes also dont match
    else if (tune1[j + 1] != tune2[j + 1])
    {
      // number of different notes with different pitches add up by 1 each time
      different_different++;
    }
  }
  // caulculate similarity with equation from github
  similarity = match_note / total_note + match_match - different_different;
  // return similarity results
  return similarity;
}
double bestSimilarity(string inputTune, string targetTune)
{
  // variable for the length of targetTune (shorter fragment)
  int length_tune = targetTune.length();
  // if the inputTun length is shorter then targetTune length then return 0
  if (inputTune.length() < targetTune.length())
  {
    return 0;
  }
  // variable for best similarity
  // use the past function to check similarity
  // plug in targetTune(tune1) and substring of inputTune (tune2) to the function
  double best_sim = tuneSimilarity(targetTune, inputTune.substr(0, length_tune));
  // j has to be less then the legth of inputTune subtracted by targetTune so it doesn't calculate outside of the inputTune length
  //+=2 so it compares two by two
  //+1 because j goes under otherwise
  for (int j = 0; j < inputTune.length() - targetTune.length() + 1; j += 2)
  {
    // substring of inputTune that starts at j and is the length of targetTune
    string input_sub = inputTune.substr(j, length_tune);
    double similarity = tuneSimilarity(targetTune, input_sub);
    // each time the similarity is the greatest it replaces variable best_sim
    if (similarity > best_sim)
    {
      // sim replaces best_sim with the highest sim
      best_sim = similarity;
    }
  }
  return best_sim;
}
void printTuneRankings(string tune1, string tune2, string tune3, string targetTune)
{

  // string tunes [3];

  // double best_2;
  // double best_match;
  double match_1 = bestSimilarity(tune1, targetTune);
  double match_2 = bestSimilarity(tune2, targetTune);
  double match_3 = bestSimilarity(tune3, targetTune);

  if ((match_1 > match_2) && (match_1 > match_3))
  {
    if (match_3 > match_2)
    {
      cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
    }
    else
    {
      cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
    }
  }
  else if ((match_2 > match_1) && (match_2 > match_3))
  {

    if (match_3 > match_1)
    {
      cout << "1) Tune 2, 2) Tune 3, 3) Tune 1" << endl;
    }
    else
    {
      cout << "1) Tune 2, 2) Tune 1, 3) Tune 3" << endl;
    }
  }
  else if ((match_3 > match_1) && (match_3 > match_2))
  {

    if (match_2 > match_1)
    {
      cout << "1) Tune 3, 2) Tune 2, 3) Tune 1" << endl;
    }
    else
    {
      cout << "1) Tune 3, 2) Tune 1, 3) Tune 2" << endl;
    }
  }
  else if ((match_1 == match_3) && (match_1 > match_2))
  {
    cout << "1) Tune 1, 2) Tune 3, 3) Tune 2" << endl;
  }
  else
  {
    cout << "1) Tune 1, 2) Tune 2, 3) Tune 3" << endl;
  }
}
// how to write the main function
int main()
{
  cout<<fixed<<setprecision(2);
  while (true)
  {
    //variables 
  string inputTune = "";
  int menu1;
//output menu to user
  cout << "--- Menu ---" << endl;
  cout << "1. Calculate similarity between two tunes." << endl;
  cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
  cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
  cout << "4. Exit. " << endl;
  cout << "Please enter your choice (1 - 4):" << endl;
  cin >> menu1;
//if user input is not equal to any of the options (1,2, 3 or 4) it is invalid
  while ((menu1 != 1) && (menu1 != 2) && (menu1 != 3) && (menu1 != 4))
  {
    //loop so it reprints and prompts the user again 
    cout << "Invalid Input." << endl;
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit. " << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> menu1;
  }
  // how to check for invalid inputs using functions
  //if user input is 1 for calculating similarity between two tunes
  if (menu1 == 1)
  {
    // prompt user for tune input
    string tune1;
    cout << "Please enter the first tune:" << endl;
    cin >> tune1;
    //use isValidTune function to check user input for validity
     while (isValidTune(tune1) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune1;
    }
  //prompt for second user input tune to calc similarity
    string tune2;
    cout << "Please enter the second tune:" << endl;
    cin >> tune2;
    // use isValidTune to check tune validity
    while (isValidTune(tune2) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune2;
    }
  // store answer using past function
    double sim = tuneSimilarity(tune1, tune2);
//output to user the score
    cout << "The similarity score is " << sim << endl;
  }
  //if the user requested 2 from menu 
  else if (menu1 == 2)
  {
    //prompt user for input 
    cout << "Please enter the input tune:" << endl;
    cin >> inputTune;
    //use function in while loop to check if user input is valid
    while (isValidTune(inputTune) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> inputTune;
    }
    // prompt user for target tune
    string targetTune;
    cout << "Please enter the target tune:" << endl;
    cin >> targetTune;
//use isValidTune to check if input is valid 
    while (isValidTune(targetTune) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> targetTune;
    }
    // use bestSim to calculate
    double best_sim = bestSimilarity(inputTune, targetTune);
    cout << "The best similarity score is: " << best_sim << endl;
  }
  //if user input 3 to print in order
  else if (menu1 == 3)
  {
    //prompt user for first tune input
    string tune1;
    cout << "Please enter the first tune:" << endl;
    cin >> tune1;
    //use isValidTune to check tune validity
      while (isValidTune(tune1) == false)
    {
      //if invalid reprompt user
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune1;
    }
    //prompt user for second tune
    string tune2;
    cout << "Please enter the second tune:" << endl;
    cin >> tune2;
    //use same thing to check for validity
      while (isValidTune(tune2) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune2;
    }
    //prompt user for thrid tune and also check for validity
    string tune3;
    cout << "Please enter the third tune:" << endl;
    cin >> tune3;
      while (isValidTune(tune3) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune3;
    }
    //then a target tune to compare the input tunes with
    string target_tune;
    cout << "Please enter the target tune:" << endl;
    cin >> target_tune;
  //also check target tune
    while (isValidTune(target_tune) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> target_tune;
    }
//output to user the product best match to least match 
    printTuneRankings(tune1, tune2, tune3, target_tune);
  }
  //if user inouts 4 they can leave the code and the menu
  else if(menu1 == 4)
    {
      //state goodbye to user and return 0
      cout << "Goodbye!" << endl;
      return 0;
    }
  }
}
