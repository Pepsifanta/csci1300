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

using namespace std;


int split(string input_string, char separator, string arr[], int arr_size)
{
    // counter that starts at 0
    int count = 0;
    // new variable for input_string length
    int length = input_string.length();
    // if the length is equal to zero it will return 0
    if (length == 0)
    {
        return 0;
    }
    // for loop to go through the input_string
    for (int i = 0; i < length; i++)
    {
        // if else statement that if part of the input string is not equal to the separator
        if (input_string[i] != separator)
        {
            // the part of the array becomes the array plus the inputstring that does not equal the separator
            arr[count] = arr[count] + input_string[i];
        }
        // if the array is equal to the separator
        if (input_string[i] == separator)
        {
            // count goes up
            count++;
        }
    }
    // if the amount of peices we split up is bigger and cant fit into the array retunr -1
    if (count >= arr_size)
    {
        return -1;
    }
    return count + 1;
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

    string line = "";

    while (getline(fin, line))
    {

        string arr[posts_arr_size];
        int n = split(line, ',', arr, 4);
        if (line.empty())
        {
            continue;
        }

        if ((n > 4) || (n < 4))
        {
            continue;
        }

        Post p;
        p.setPostBody(arr[0]);
        p.setPostAuthor(arr[1]);
        p.setPostLikes(stoi(arr[2]));
        p.setPostDate(arr[3]);

        posts[num_posts_stored] = p;

        num_posts_stored += 1;
        if (num_posts_stored == posts_arr_size)
        {
            return num_posts_stored;
        }
    }
    return num_posts_stored;
}

void printPostsByYear(Post post[], string year, int num_posts_stored)
{
    // if there is no posts in the input
    if (num_posts_stored <= 0)
    {
        cout << "No posts are stored" << endl;
        return;
    }
    // variables to check if there are posts for the given year
    bool foundForYear = false;
    int startIndex = 0;
    // new string for list of all posts in one gievn year
    string postBodies[num_posts_stored] = {};
    // for loop to go through array
    for (int i = 0; i < num_posts_stored; i++)
    {
        // temparay varaibel that holds the date
        string temp = post[i].getPostDate();
        // if esle to check the year and if it matches
        if (temp.substr(6, 2) == year)
        {
            // to find out where the post in a certain year start
            if (!foundForYear)
            {
                startIndex = i;
            }
            // when it turns true that means you found a post for that year
            foundForYear = true;
            // update the array of post bodies
            postBodies[i] = post[i].getPostBody();
        }
    }
    // if you found posts for that year print the lists of posts
    if (foundForYear)
    {
        cout << "Here is a list of posts for year " << year << endl;
        // loops through post bodies array
        for (int i = startIndex; i < num_posts_stored; i++)
        {
            // new variable for the bodies
            string body = postBodies[i];
            // to check if the post isn't blank
            if (body.length() <= 0)
            {
                continue;
            }
            //
            cout << body << endl;
        }
    }
    else
    {
        // if there are no matches output
        cout << "No posts stored for year " << year << endl;
    }
}

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

    string line = "";

    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }

        string arr[51];
        int n = split(line, ',', arr, max_posts + 1);
        if (n < 1)
        {
            continue;
        }

        users[num_users_stored].setUsername(arr[0]);
        users[num_users_stored].setNumPosts(n-1);
        //*******users[num_users_stored].setNumPosts(n-1);
        // p.setPostBody(arr[0]);
        // p.setPostAuthor(arr[1]);
        // p.setPostLikes(stoi(arr[2]));
        // p.setPostDate(arr[3]);
        for (int i = 1; i < n; i++)
        {
            int likes = stoi(arr[i]);
            users[num_users_stored].setLikesAt(i - 1, likes);
        }

        // users[num_users_stored] = temp;
        num_users_stored += 1;
        if (num_users_stored == users_arr_size)
        {
            return num_users_stored;
        }
    }
    return num_users_stored;
}

int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    int sus = -1;
    int susser =-1 ;
    //if there are no users stored in user array 
    if (num_posts_stored == 0 || num_users_stored == 0)
    {
    //return -2
        return -2;
    }
   for(int i = 0; i < num_posts_stored;i++)
   {
        if(posts[i].getPostAuthor()== post_author)
        {

            sus = i;
            for(int j = 0; j < num_users_stored; j++)
            {
                if(users[j].getUsername()== username)
                {
                    susser = j; 
                    return users[susser].getLikesAt(sus);
                }
            }

        }

    //break;

   }
 
if((sus==-1)||(susser==-1))
{
    return -3;
}
}

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    if (num_users_stored <= 0)
    {
        cout << "No users are stored in the database" << endl;
        return;
    }

    string matches[num_users_stored] = {};
    int nMatches = 0;

    for (int i = 0; i < num_users_stored; i++)
    {
        User u = users[i];
        string name = u.getUsername();

        int foundWhere = name.find(username_tag);
        //******** ask if I can use this
        // finds the tag in the username FINDS WORD IN STRING
        // reads till end of line then stops
        if (foundWhere != string::npos)
        {
            matches[nMatches] = name;
            nMatches++;
        }
    }

    if (nMatches == 0)
    {
        cout << "No matching user found" << endl;
        return;
    }
    else
    {
        cout << "Here are all the usernames that contain " << username_tag << endl;
        for (int i = 0; i < nMatches; i++)
        {
            cout << matches[i] << endl;
        }
    }
}

 
 
int main()
{
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
        cout << "======Main Menu======" << endl;
        cout << "1. Read Posts " << endl;
        cout << "2. Print Posts By Year" << endl;
        cout << "3. Read Likes" << endl;
        cout << "4. Get Likes " << endl;
        cout << "5. Find users with matching tag" << endl;
        cout << "6. Quit" << endl;
        cin >> menu;
        // use the input to declare first switch
        if ((menu != 1) && (menu != 2) && (menu != 3) && (menu != 4) && (menu != 5) && (menu != 6))
        {
            cout << "Invalid input." << endl;
        }

        // open new switch for what is outputted to the user
        if (menu == 1)
        {
            int post_arr_size = 50;
            string file;
            cout << "Enter a post file name:" << endl;
            cin >> file;

            int sim = readPosts(file, posts, num_posts_stored, post_arr_size);

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

            printPostsByYear(posts, year_input, num_posts_stored);
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

                max = split(get_line, ',', temp, size);
            }
            sim = readLikes(file_n, users, num_users_stored, user_size, max - 1);

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
        temp = getLikes(author, posts, num_posts_stored, user, users, num_users_stored);

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
            findTagUser(tag, users, num_users_stored);
        }
        if (menu == 6)
        {
            cout << "Good bye!" << endl;
            break;
        }
    }
}