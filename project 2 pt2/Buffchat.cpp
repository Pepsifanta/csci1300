// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 1 - Buffchat Class
#include <iostream>
#include "Buffchat.h"
#include <fstream>
#include "Post.h"
#include "User.h"


using namespace std;

/**
 * Algorithm: Split 
 * 1. stringf for inputline, a separater, and array to fill and an array size 
 * 2. loop to split and fill new array 
 * 3. splits string into diffrent components 
 * Parameters: split(string input_string, char separator, string arr[], int arr_size)
 * Returns: a int
 */

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
  
  Buffchat::Buffchat()
  {
    num_posts_ = 0;
    num_users_ = 0;
  }
            //Parameterized: constructor ARE THERE NONE????
    Buffchat::Buffchat(int num_posts, int num_users)
            {
                num_posts_= num_posts;
                num_users_ = num_users;
            }

            int Buffchat::getPostSize()
            {
                return posts_size_;
            }

            int Buffchat::getUserSize()
            {
                return users_size_;
            }

            int Buffchat::getNumPosts()
            {
                return num_posts_;
            }

            int Buffchat::getNumUsers()
            {
                return num_users_;
            }

        /**
 * Algorithm: readPosts  
 * 1. function will fill an array of Post objects. 
 * 2. reads file  
 * 3. fills up the post setters
 * Parameters: readPosts(string file_name)
 * Returns: a int
 */

    int Buffchat::readPosts(string file_name)

         {

    ifstream fin;

    fin.open(file_name);
    if (num_posts_ == posts_size_)
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

        string arr[posts_size_];
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

        posts_[num_posts_] = p;

        num_posts_ += 1;
        if (num_posts_ == posts_size_)
        {
            return num_posts_;
        }
    }
    return num_posts_;
}

       /**
 * Algorithm: printPostsByYear  
 * 1. takes a string year to find year posts  
 * 2. function will print all posts in the given array of posts that were posted during a given year.  
 * 3. fills up the post setters
 * Parameters: printPostsByYear(string year)
 * Returns: a void (couts)
 */
    void Buffchat::printPostsByYear(string year)
                    {

                    if(num_posts_<=0)
                    {
                        cout<<"No posts are stored"<<endl;
                        return;
                    }
                    //variables to check if there are posts for the given year
                    bool foundForYear = false;
                    int startIndex = 0;
                //new string for list of all posts in one gievn year
                    string postBodies[num_posts_] = {};
                //for loop to go through array 
                    for(int i = 0; i < num_posts_; i++)
                    {
                //temparay varaibel that holds the date 
                string temp = posts_[i].getPostDate();
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
                postBodies[i] = posts_[i].getPostBody();
                }

                }
                //if you found posts for that year print the lists of posts 
                if (foundForYear) {
                cout<< "Here is a list of posts for year "<<year<<endl;
                //loops through post bodies array 
                for (int i = startIndex; i < num_posts_; i++) {
                //new variable for the bodies
                string body = postBodies[i];
                //to check if the post isn't blank
                if (body.length() <= 0) {
                continue;
                }
                //
                cout << body << endl;
                 }
                } 
                 else {
                //if there are no matches output 
                cout << "No posts stored for year " << year << endl;
                }

            }

                 /**
 * Algorithm: readlikes  
 * 1. function will fill an array of User objects and their likes for Posts. 
 * 2. Each line in the file used to fill the array consists of a username followed by a sequence of likes  
 * 3. uses getline to read file and converts 
 * Parameters: readLikes(string file_name)
 * Returns: a int
 */
    int Buffchat::readLikes(string file_name)
    {
    User temp;

    ifstream fin;

    fin.open(file_name);
    if (num_users_ == users_size_)
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
        int n = split(line, ',', arr, 50 + 1);
        if (n < 1)
        {
            continue;
        }

        users_[num_users_].setUsername(arr[0]);
        users_[num_users_].setNumPosts(n-1);
        //*******users[num_users_stored].setNumPosts(n-1);
        // p.setPostBody(arr[0]);
        // p.setPostAuthor(arr[1]);
        // p.setPostLikes(stoi(arr[2]));
        // p.setPostDate(arr[3]);
        for (int i = 1; i < n; i++)
        {
            int likes = stoi(arr[i]);
            users_[num_users_].setLikesAt(i - 1, likes);
        }

        // users[num_users_stored] = temp;
        num_users_ += 1;
        if (num_users_ == users_size_)
        {
            return num_users_;
        }
    }
    return num_users_;
}
    int Buffchat::getLikes(string post_author, string username)
            {
            int sus = -1;
            int susser =-1 ;
            //if there are no users stored in user array 
            if (num_posts_ == 0 || num_users_ == 0)
            {
            //return -2
                return -2;
            }
        for(int i = 0; i < num_posts_;i++)
        {
                if(posts_[i].getPostAuthor()== post_author)
                {

                    sus = i;
                    for(int j = 0; j < num_users_; j++)
                    {
                        if(users_[j].getUsername()== username)
                        {
                            susser = j; 
                            return users_[susser].getLikesAt(sus);
                        }
                    }

                }

            //break;

        }
        
        if((sus==-1)||(susser==-1))
        {
            return -3;
        }
        return 0;
        }
////////////////////////////////////////////////////////////////////////
    // {
    // int sus;
    // int susser;
    // //if there are no users stored in user array 
    // if (num_posts_ == 0 || num_users_ == 0)
    // {
//     //return -2
//         return -2;
//     }

//    for(int i = 0; i < num_posts_;i++)
//    {
//         if(posts[i].getPostAuthor()== post_author)
//         {

//             sus = i;
//             for(int j = 0; j < num_users_; j++)
//             {
//                 if(users[j].getUsername()== username)
//                 {
//                     susser = j; 
//                     return users[j].getLikesAt(i);
//                 }
//             }

//         }

//    }
 

//     return -3;

// }
////////////////////////////////////////////////
    // {
    //         int sus = -1;
    //         int susser =-1 ;
    //         //if there are no users stored in user array 
    //         if (num_posts_ == 0 || num_users_ == 0)
    //         {
    //             //return -2
    //             return -2;
    //         }
    //         for(int i = 0; i < num_posts_;i++)
    //         {
    //             if(posts_[i].getPostAuthor()== post_author)
    //             {

    //             sus = i;
    //                 for(int j = 0; j < num_users_; j++)
    //                 {
    //                     if(users_[j].getUsername()== username)
    //                     {
    //                         susser = j; 
    //                         return users_[susser].getLikesAt(sus);
    //                     }
    //                 }

    //             }

    // //break;

    //             }
 
    //             if((sus==-1)||(susser==-1))
    //             {
    //                 return -3;
    //             }

    // }
    void Buffchat::findTagUser(string username_tag)
    {
            if (num_users_ <= 0) {
            cout << "No users are stored in the database" << endl;
            return;
            }
            //make variables 
            string matches[num_users_] = {};
            int nMatches = 0;
            // for loop to get usernames 
            for (int i = 0; i < num_users_; i++) {
            User u = users_[i];
            string name = u.getUsername();
        
            int foundWhere = name.find(username_tag);
            //finds the tag in the username FINDS WORD IN STRING 
            //reads till end of line then stops 
            if (foundWhere != string::npos) {
                 matches[nMatches] = name;
                //counter goes up if matches 
                nMatches++;
            }
        }
            //if there are no matches 
            if (nMatches == 0) 
            {
                cout << "No matching user found" << endl;
                return;
            }
            //if there are matches 
            else {
                    cout << "Here are all the usernames that contain " << username_tag << endl;
                        for (int i = 0; i<nMatches; i++) {
                            cout << matches[i] << endl;
                        }
                 }

    }
    /*
     * Algorithm: addPost  
 * 1. The addPost function adds a new post to the posts_ array. 
 * 2. The number of likes for the new post object should be 0.
 * 3.Returns false if the posts array is full
    Returns true if the post is successfully added to the array
 * Parameters: addPost(string post_body, string post_author, string date)
 * Returns: a bool 
 */
    bool Buffchat::addPost(string post_body, string post_author, string date)
    {
        //number of likes in is zero
        Post temp_1 = Post(post_body, post_author, 0, date);
        if(posts_size_ > num_posts_)
        {
            //add to post 
            posts_[num_posts_] = temp_1;
            num_posts_++;
            //loop through array to set stuff 
            for(int i = 0; i < num_users_;i++)
            {
                users_[i].setNumPosts(num_posts_);
                users_[i].setLikesAt(num_posts_ -1, -1);
               
            }
            return true;
        }
        else
        {
            return false;
        }

    }
/**
 * Algorithm: printPopularPosts  
 * 1. function prints the requested number of posts with the highest likes for the given year. 
 * 2. If the number of posts stored in the array is 0 (or less than 0), print "No posts are stored" 
 * 3. If there are less than the requested number(count) of posts matching the given year, print 
 * "There are fewer than <count> posts for year <year>. Top <actual_number> posts for <year>" followed
 *  by each post (number of likes: content of post) on a new line
 * Parameters: printPopularPosts(int count, string year)
 * Returns: a void
 */
    void Buffchat::printPopularPosts(int count, string year)
    {
        Post arr[num_posts_];
        //counter to compare with user given count 
        int oh= 0;

        if(num_posts_ == 0)
        {
            cout<<"No posts are stored"<<endl;
        }

        else
        {

        for(int i= 0; i< num_posts_; i++)
        {
            //finds all the posts that are in that year from the file 
            string temp= posts_[i].getPostDate();

            if(temp.substr(temp.length() - 2, 2) == year)
            {
                arr[oh]=posts_[i];
                //my counter goes up for how many posts their are in that year
                oh++;
            }
        }

    if(oh> count )
    {
        while(oh > count)
        {
            //least index
            int least= 0;
            //least likes/first like 
            int likes= arr[0].getPostLikes();

            for(int i = 0; i < oh; i++)
            {
                //temp to compare the likes 
                int temp2=arr[i].getPostLikes();
//to find the smallest likes 
                if(temp2 < likes)
                {
                    likes= temp2;
                    least= i;

                }

            }
    //to populate the array 
            for(int j = least; j < oh ; j++)
            {
                arr[j]=arr[j+1];
            }
                //remove the posts with the least likes 
            oh--;

        }
    }
    
   
    if(oh == 0)
    {
        cout<<"No posts stored for year "<<year<<endl;
    }
    // else if(oh>=count)
    // {
    //     cout<<"Top "<<count<< " posts for year " << year <<endl;
    // }
      else if(oh<count)
    {
        cout<<"There are fewer than " <<count<< " posts for year " <<year<<". Top " <<oh<< " posts for year " <<year <<endl;
          for (int i = 0; i < oh; i++ )
        {
            cout << arr[i].getPostLikes() << " likes: " << arr[i].getPostBody()<<endl;
        }
    }

    else if(oh>=count)
    {
        cout<<"Top "<<count<< " posts for year " << year <<endl;
        for (int i = 0; i < oh; i++ )
        {
            cout << arr[i].getPostLikes() << " likes: " << arr[i].getPostBody()<<endl;
        }
    }
        }



    }
    /**
 * Algorithm: findLeastActiveUser  
 * 1. The findLeastActiveUser function returns the user with the least activity recorded
 * 2. Viewer with the most -1
 * 3. Return an empty User object if there are no users stored in the database
 * Parameters: findLeastActiveUser() NOTHING 
 * Returns: a user (has to use getuser to output )
 */
    User Buffchat::findLeastActiveUser()
    {
        int counter=0;
        int max= 0;
        int ind= 0; 
        User user1= User();

        if(num_users_==0)
        {
            // cout<<"There are no users stored."<<endl;
            return user1;
        }

        for(int i=0; i<num_users_;i++)
        {
            counter=0;
            for(int j=0; j<num_posts_;j++)
            {
                if(users_[i].getLikesAt(j)==-1)
                {
                    counter ++;
                }
            }

            if(counter>max)
            {
                max=counter ;
                ind=i;
            }



        }
        return users_[ind];


    }
       /**
 * Algorithm: countUniqueLikes  
 * 1. The countUniqueLikes function returns the number of users who liked the posts posted by the author in question. 
 * 2. Viewer with the most -1
 * 3. Return an empty User object if there are no users stored in the database
 * Parameters: countUniqueLikes(string post_author)
 * Returns: an int how many diffrent users liked the post 
 */
    int Buffchat::countUniqueLikes(string post_author)
            {
                if(num_posts_==0 || num_users_==0)
                {
                    return -2;
                }
                // bool tuu= true;
                int view= 0;
                int count= 0;
                bool tuu= false ;
                for(int i=0; i<num_posts_;i++)
                {
                    if(posts_[i].getPostAuthor()== post_author)
                    {
                        for(int j=0; j<num_users_;j++)
                        {
                            if(users_[j].getLikesAt(i)>=0)
                            {
                                //if equal to 0 that means they viewed it but did not like
                                if(users_[j].getLikesAt(i)>0)
                                {
                                    count ++;
                                }
                                view++;
                                // tuu=true ;
                            }
                            
                            
                    }
                }
               
                

            }
           //tuu=true
             if( view==0)
                {
                    return -1;
                }
            return count;
        }


            //return number of users that liked a users post 
            //find author 
            //iterate through post array to find author 
            //once found you go through users array to find how many 
            //if they liked it >0 