class myArray
{
public:
myArray(int a, int b);
myArray(int ALength);
int& operator[] (const int index);

private:
int* list;
int length;
int indexStart;
int indexEnd;

};