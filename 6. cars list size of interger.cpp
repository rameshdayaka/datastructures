#include <iostream>
using namespace std;

int main()
{


string cars[5] = {"volvo", "toyato", "ford", "tsla", "honda"};
int n = sizeof(cars)/sizeof(string);
for(int i;i<n;i++)
{
    cout << cars[i]<<"\n";
}

}
