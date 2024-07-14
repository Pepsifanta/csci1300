// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 8- put everything together
#include <fstream>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "Post.h"
#include "User.h"
#include "Buffchat.h"

using namespace std;
int split2(string input_string, char separator, string arr[], int arr_size)
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
    int num_sep=0;
for (int i = 0; i < input_string.length(); i++)
{
  if(input_string[i]==separator)
  {
  num_sep++;
  }
}
if (num_sep>=arr_size)
{
  return -1;
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

int main()
{
Buffchat b;

    // make variable for all the sections
    int temp =0; 
    int menu = 0;
    int total_posts = 0;
    int total_users = 0;
    int num_posts_stored = 0;
    int num_users_stored = 0;
    string file_n;
    ifstream fin;
    User users[50];
    Post posts[50];

    bool end = true;
    while (end = true)
    {
        	
// ======Main Menu=====
// 1. Read posts
// 2. Print Posts By Year
// 3. Read Likes
// 4. Get Likes
// 5. Find users with matching tag
// 6. Add a new post
// 7. Print popular posts for a year
// 8. Find least active user
// 9. Find unique likes for a post author
// 10. Quit
        cout << "======Main Menu=====" << endl;
        cout << "1. Read posts " << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes " << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Add a new post" << endl;
        cout << "7. Print popular posts for a year" << endl;
        cout << "8. Find least active user" << endl;
        cout << "9. Find unique likes for a post author" << endl;
        cout << "10. Quit" << endl;
        cin >> menu;
        // use the input to declare first switch
        if ((menu != 1) && (menu != 2) && (menu != 3) && (menu != 4) && (menu != 5) && (menu != 6) && (menu != 7) && (menu != 8) && (menu != 9) && (menu != 10))
        {
            cout << "Invalid input" << endl;
        }

        // open new switch for what is outputted to the user
        if (menu == 1)
        {
            int post_arr_size = 50;
            string file_name;
            cout << "Enter a post file name:" << endl;
            cin >> file_name;

            int sim = b.readPosts(file_name);

            if (sim == -1)
            {
                cout << "File failed to open. No posts saved to the database." << endl;
            }
            if (sim == -2)
            {
                cout << "Database is already full. No posts were added." << endl;
                num_posts_stored = 50;
            }
             if (sim == post_arr_size)
            {
                cout << "Database is full. Some posts may have not been added." << endl;
                num_posts_stored = 50;
            }
            if (sim >= 0 && sim < 50)
            {
                cout << "Total posts in the database: " << sim << endl;

                num_posts_stored = sim;
            }
        }
       if (menu == 2)
        {

            string year_input;
            cout << "Enter the year(YY):" << endl;
            cin >> year_input;

            b.printPostsByYear(year_input);
        }
        if (menu == 3)
        {
            string file_n;
            cout << "Enter a user file name:" << endl;
            cin >> file_n;
            int user_size = 50;
            int max = 0;
            int sim = 0;
            int size = 51;
            ifstream fin(file_n);

            if (!fin.fail())
            {
                string get_line;
                string temp[size];
                getline(fin, get_line);

                max = split2(get_line, ',', temp, size);
            }
            sim = b.readLikes(file_n);

            if (sim == -1)
            {
                cout << "File failed to open. No users saved to the database." << endl;
            }
            else if (sim == -2)
            {
                cout << "Database is already full. No users were added." << endl;
               // total_users = user_size;
            }
            else if (sim == 50)
            {
                num_users_stored=sim;
                cout << "Database is full. Some users may have not been added." << endl;
                
            }
            else
            {
                num_users_stored=sim;
                cout << "Total users in the database: " << num_users_stored << endl;

            }
        }
        if (menu == 4)
        {
            string author;
            cout << "Enter a post author:" << endl;
            cin >> author;
            string user;
            cout << "Enter a user name:" << endl;
            cin >> user;
        temp = b.getLikes(author, user);

            if (temp == 0)
            {
                cout << user << " has not liked the post posted by " << author << endl;
            }
            else if (temp == -1)
            {
                cout << user << " has not viewed the post posted by " << author << endl;
            }
            else if (temp == -2)
            {
                cout << "Database is empty." << endl;
            }
            else if (temp == -3)
            {
                cout << user << " or " << author << " does not exist."<<endl;
            }
            else 
            {
                cout<<user<< " liked the post posted by " <<author<<" "<<temp<<" times "<<endl;
            }
        }
        if (menu == 5)
        {
            string tag;
            cout << "Enter a tag:" << endl;
            cin >> tag;
            b.findTagUser(tag);
        }
         if (menu == 6)
        {
            string body;
            cout << "Enter a post body: " << endl;
            cin >> body;

            string author;
            cout << "Enter a post author: " << endl;
            cin >> author;

            string date;
            cout << "Enter a date(mm/dd/yy): " << endl;
            cin >> date;
            temp = b.addPost(body, author, date);

            if (temp == 1)
            {
                cout<< author<<"'s post added successfully"<<endl;
            }
            else if (temp == false)
            {
                cout<< "Database is already full. "<<author<<"'s post was not added."<<endl;
            }
           
        }
          if (menu == 7)
        {
            int posts ;
            cout << "Enter the number of posts: " << endl;
            cin >> posts ;
            string year ;
            cout << "Enter the year(YY): " << endl;
            cin >> year ;

            b.printPopularPosts(posts, year); 
           
        }
          if (menu == 8)
        {
            User hi = b.findLeastActiveUser();
            int name = b.getNumUsers();
            if (name < 1 )
            {
                cout<< "There are no users stored."<<endl;
            }
            else
            {
                cout<< hi.getUsername() << "is the least active user"<<endl;
            }
           
        }
          if (menu == 9)
        {
             string author ;
            cout << "Enter a post author: " << endl;
            cin >> author ;
           
           temp=b.countUniqueLikes(author); 
           if (temp > 0)
           {
            cout<<"The posts posted by "<< author<< " have been liked by "<< temp  << " unique users."<<endl;
           }
            if (temp == 0)
           {
            cout<<"The posts posted by " <<author<< " have received 0 likes so far."<<endl;
           }
            if (temp == -1)
           {
            cout<<"The posts posted by " <<author<< " have not been viewed by anyone."<<endl;
           }
            if (temp == -2)
           {
            cout<<"Database is empty."<<endl;
           }
           
        }
        if (menu == 10)
        {
            cout << "Good bye!" << endl;
            break;
        }
    }
}