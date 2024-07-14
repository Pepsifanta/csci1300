
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void RemoveWords(str, string stopwords)
{

  x <- unlist(strsplit(str, " "))
  paste(x[!x %in% stopwords], collapse = " ")
}

removeWords(str, stopwords);

int main()
{
 
str <- c("I have zero a accordance");

stopwords = c("a", "able", "about", "above", "abst", "accordance", "yourself",
"yourselves", "you've", "z", "zero")

x <- unlist(strsplit(str, " "))

x <- x[!x %in% stopwords]

paste(x, collapse = " ")



}