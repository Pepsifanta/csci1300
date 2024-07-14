#include <iostream>

using namespace std;
//stock is what you have currently, amount is what you take away
double fertilize(double stock, double amount) 
{
 
if (amount>stock)
{
    cout<<"Error:not enough fertilizer" <<endl;
    return stock;
}
else 
{
    return stock- amount;
}

}

double restock(double stock, double amount)
{
    return stock+amount;  
}

int main ()
{
double stock;
   
    cout << "how much you you have in stock" << endl;
    cin >> stock;

      if ( stock <= 0) 
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    else
    {
      double amount;
   
    cout << "what is your amount" << endl;
    cin >> amount; 
    if (amount <0 )
    {
      fertilize  
    } 
    else (amount < 0)
    {
        
    }
    }

    cout << restock(stock, amount) << endl;


}
   