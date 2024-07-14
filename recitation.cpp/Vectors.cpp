#include <iostream>
#include <vector>

using namespace std;

vector<float> readvalues(vector<float> v)
{
    
    cout<< "Enter 15 floating point variables: "<<endl;

    float x;

    for(int i = 0; i <15; i++)
    {
        cin >> x;
        v.push_back(x);

    }

    return v;

}

float average(vector<float> v)
{
    float sum = 0.0;
    for(int i =0; i<v.size(); i++)
    {
        sum+= v.at(i);
    }

    float avg = sum/v.size();

    return avg; 

}


void removeLeast(vector<float> v, float avg)
{

    for(int i=0; i <v.size(); i++)
    {
        if(v.at(i)<avg)
        {
            v.erase(v.begin()+ i);
            i--;
        }
    }
    //return v;

}

int main()
{
    vector<float> v;

    v = readvalues(v);

    float avg = average(v);

    cout<< "avg: "<<endl; 

    v = removeLeast(v,avg);

    for(int i=0; i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    return 0;

}