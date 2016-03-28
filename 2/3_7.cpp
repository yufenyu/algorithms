#include <iostream>
using namespace std;
int main()//是否是O(nlgn)
{
    int A[8] = {3, 4, 6, 8, 9, 11, 12, 15};
    for(int k = 0; k < 8; k++)
        cout << A[k] << " ";
    cout << endl;
    cout << "please enter a sum :\n";
    int sum;
    cin >> sum;
    int key;
    for(int j = 0; j < 8; j++)
    {
        key = sum - A[j];
        for(int i = j + 1; i < 8; i++)
        {
            if(A[i] == key)
                cout << A[j] << " " << A[i] << endl;
        }
    }
    return 0;

}
