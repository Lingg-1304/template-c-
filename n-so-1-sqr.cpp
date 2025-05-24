#include <iostream>
#include <string>
using namespace std;
int main()
{
        int k, n;
 
        cin>>k;
        for (int i=0; i<k; i++)
        {
            cin>>n;
            string s = "";
            int temp = 0;
            int j = 1, ji = 1;
            while (j>0)
            {
                s.insert(0, 1, (char)((j+temp)%10+'0')); 
                temp = (j+temp)/10;
                if (j==n) ji = -1;
                j += ji;
            }
        cout<<s<<endl;
        }
    return 0;
}
