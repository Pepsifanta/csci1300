// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 7
#include <iostream>
#include <cassert>
#include <iomanip>
#include "Post.h"
#include "User.h"

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
{
  //counter that starts at 0
    int count =0;
    //new variable for input_string length
    int length= input_string.length();
// if the length is equal to zero it will return 0
    if (length==0)
    {
        return 0;
    }
// for loop to go through the input_string
  for(int i=0; i < length; i++)
  {
    // if else statement that if part of the input string is not equal to the separator
    if (input_string[i] != separator )
    {
      //the part of the array becomes the array plus the inputstring that does not equal the separator
        arr[count] = arr[count]+ input_string [i];

    }
    //if the array is equal to the separator 
    if (input_string[i] == separator )
    {
      //count goes up
        count ++;
    }
  }
//if the amount of peices we split up is bigger and cant fit into the array retunr -1
  if (count>= arr_size)
  {
    return -1;
  }
  return count+1;


}

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size)


{

ifstream fin; 


fin.open(file_name);
if (num_posts_stored == posts_arr_size)
  {
    return -2;
  }
else if (!fin.is_open())
{
   
    return -1;
}

string line= "";
 
while (getline(fin, line))
{
 
  string arr[posts_arr_size]; 
  int n = split(line, ',', arr, 4);
  if (line.empty())
  {
    continue;
  }


  if((n>4)||(n<4))
  {
continue;
  }

  

    Post p;
    p.setPostBody(arr[0]);
    p.setPostAuthor(arr[1]);
    p.setPostLikes(stoi(arr[2]));
    p.setPostDate(arr[3]);

    posts[num_posts_stored]=p;

      num_posts_stored +=1;
 if (num_posts_stored == posts_arr_size)
  {
    return num_posts_stored;
  }

  
}
return num_posts_stored;

}

void printPostsByYear(Post post[], string year, int num_posts_stored)
{
//if there is no posts in the input 
    if(num_posts_stored<=0)
    {
        cout<<"No posts are stored"<<endl;
        return;
    }
//variables to check if there are posts for the given year
    bool foundForYear = false;
    int startIndex = 0;
//new string for list of all posts in one gievn year
    string postBodies[num_posts_stored] = {};
//for loop to go through array 
    for(int i = 0; i < num_posts_stored; i++)
    {
        //temparay varaibel that holds the date 
        string temp = post[i].getPostDate();
//if esle to check the year and if it matches 
        if(temp.substr(6,2)==year)
        {
            //to find out where the post in a certain year start 
            if (!foundForYear) {
                startIndex = i;
            }
            //when it turns true that means you found a post for that year 
            foundForYear = true;
            //update the array of post bodies 
            postBodies[i] = post[i].getPostBody();
        }
    }
//if you found posts for that year print the lists of posts 
    if (foundForYear) {
         cout<< "Here is a list of posts for year "<<year<<endl;
         //loops through post bodies array 
         for (int i = startIndex; i < num_posts_stored; i++) {
            //new variable for the bodies
            string body = postBodies[i];
            //to check if the post isn't blank
            if (body.length() <= 0) {
                continue;
            }
            //
            cout << body << endl;
         }
    } else {
        //if there are no matches output 
        cout << "No posts stored for year " << year << endl;
    }
}
//**************** this one is wrong 

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)


{
User temp;

ifstream fin; 


fin.open(file_name);
if (num_users_stored == users_arr_size)
  {
    return -2;
  }
else if (!fin.is_open())
{
   
    return -1;
}

string line= "";
 
while (getline(fin, line))
{
 
  string arr[51]; 
  int n = split(line, ',', arr, max_posts+1);
  if (line.empty())
  {
    continue;
  }
    if(n>users_arr_size)
  {
    continue;
  }

    users[num_users_stored].setUsername(arr[0]);
     users[num_users_stored].setNumPosts(max_posts);
    //*******users[num_users_stored].setNumPosts(n-1);
    // p.setPostBody(arr[0]);
    // p.setPostAuthor(arr[1]);
    // p.setPostLikes(stoi(arr[2]));
    // p.setPostDate(arr[3]);
    for (int i = 1; i<max_posts+1; i++)
    {
       int likes= stoi(arr[i]); 
     users[num_users_stored].setLikesAt(i-1, likes);
    }

    //users[num_users_stored] = temp;
    num_users_stored +=1;
 if (num_users_stored == users_arr_size)
  {
    return num_users_stored;
  }
        
  
}
return num_users_stored;

}

int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    if (num_posts_stored == 0 || num_users_stored == 0)
        return -2;

    bool foundPostAuthor = false; // note to self u can prob remove this soon

    User who;
    bool foundUser = false;
    for (int i = 0; i < num_users_stored; i++) {
        User SUSpect = users[i];
        string name = SUSpect.getUsername();
        if (name == username) {
            foundUser = true;
            who = SUSpect;
            break;
        }
    }

    if (!foundUser)
        return -3;

    for (int i = 0; i < num_posts_stored; i++)
    {
        Post p = posts[i];
        string author = p.getPostAuthor();
        if (author == post_author) {
            // found first post by specific author in array
            foundPostAuthor = true;
            
            // go through whos likes
            int nLikes = who.getLikesAt(i);
            return nLikes;
        } 
    }
    
    if (!foundPostAuthor)
    {
        return -3;
    }

}

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    if (num_users_stored <= 0) {
        cout << "No users are stored in the database" << endl;
        return;
    }

    string matches[num_users_stored] = {};
    int nMatches = 0;

    for (int i = 0; i < num_users_stored; i++) {
        User u = users[i];
        string name = u.getUsername();
        
        int foundWhere = name.find(username_tag);
        //******** ask if I can use this 
        //finds the tag in the username FINDS WORD IN STRING 
        //reads till end of line then stops 
        if (foundWhere != string::npos) {
            matches[nMatches] = name;
            nMatches++;
        }
    }

    if (nMatches == 0) {
        cout << "No matching user found" << endl;
        return;
    } else {
        cout << "Here are all the usernames that contain " << username_tag << endl;
        for (int i = 0; i<nMatches; i++) {
            cout << matches[nMatches] << endl;
        }
    }
}

int main()
{
  cout<<fixed<<setprecision(2);
  while (true)
  {
    //variables 
  string input = "";
  int menu1;
//output menu to user
  cout << "======Main Menu======" << endl;
  cout << "1. Read Posts " << endl;
  cout << "2. Print Posts By Year" << endl;
  cout << "3. Read Likes" << endl;
  cout << "4. Get Likes " << endl;
  cout << "5. Find users with matching tag" << endl;
  cout << "6. Quit" << endl;
  cin >> menu1;

  while ((menu1 != 1) && (menu1 != 2) && (menu1 != 3) && (menu1 != 4)&& (menu1 != 5)&& (menu1 != 6))
  {
 
    cout << "Invalid Input." << endl;
  cout << "======Main Menu======" << endl;
  cout << "1. Read Posts " << endl;
  cout << "2. Print Posts By Year" << endl;
  cout << "3. Read Likes" << endl;
  cout << "4. Get Likes " << endl;
  cout << "5. Find users with matching tag" << endl;
  cout << "6. Quit" << endl;
    cin >> menu1;
  }
  if (menu1 == 1)
  {
    
    string file;
    cout << "Enter a post file name:" << endl;
    cin >> file;
  
     while (readPosts(file, posts, num_posts_stored, post_arr_size) == -1)
    {
      cout << "File failed to open. No posts saved to the database." << endl;
     
    }
     while (readPosts(file, posts, num_posts_stored, post_arr_size) == -2)
    {
      cout << "Database is already full. No posts were added." << endl;
      
    }
        while (readPosts(file, posts, num_posts_stored, post_arr_size) == post_arr_size)
    {
      cout << "Database is full. Some posts may have not been added." << endl;
    
    }

    int sim = readPosts(file, posts, num_posts_stored, post_arr_size);

    cout << "Total posts in the database:" << sim << endl;
  }
 
  else if (menu1 == 2)
  {
  
    cout << "Enter the year(YY):" << endl;
    cin >> input;
  
    while (printPostsByYear(post, year, num_posts_stored) == )
    {
      cout << "" << endl;
      cin >> input;
    }
 
    string targetTune;
    cout << "Please enter the target tune:" << endl;
    cin >> targetTune;
 
    while (isValidTune(targetTune) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> targetTune;
    }
 
    double best_sim = bestSimilarity(inputTune, targetTune);
    cout << "The best similarity score is: " << best_sim << endl;
  }

  else if (menu1 == 3)
  {
    
    string tune1;
    cout << "Please enter the first tune:" << endl;
    cin >> tune1;
  
      while (isValidTune(tune1) == false)
    {
    
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune1;
    }

    string tune2;
    cout << "Please enter the second tune:" << endl;
    cin >> tune2;
   
      while (isValidTune(tune2) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune2;
    }

    string tune3;
    cout << "Please enter the third tune:" << endl;
    cin >> tune3;
      while (isValidTune(tune3) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> tune3;
    }
   
    string target_tune;
    cout << "Please enter the target tune:" << endl;
    cin >> target_tune;

    while (isValidTune(target_tune) == false)
    {
      cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
      cin >> target_tune;
    }

    printTuneRankings(tune1, tune2, tune3, target_tune);
  }

  else if(menu1 == 4)
    {
      //state goodbye to user and return 0
      cout << "Goodbye!" << endl;
      return 0;
    }
  }
}
