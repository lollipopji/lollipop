#include <iostream>
#include <bitset>
#include <string>
#include <limits>

using namespace std;

int main()
{
    bitset<numeric_limits<unsigned long>::digits>n(1e7);
    cout<<n<<endl;
    bitset<numeric_limits<unsigned short>::digits>n1(267);
    cout<<n1<<endl;
    n1.set(15);
    cout<<n1<<endl;
    if(n1.test(2))
        cout<<"has been set to 1"<<endl;
    return 0;
}

