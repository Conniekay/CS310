#include <iostream>
using namespace std;

// Creates favoriteNumber class
class favoriteNumber{
 //Private Members
    private:
        int number;
 //Public Members
    public:
        void sayFavNum() {
            cout << "My Favorite Number Is " << number << "!!" << endl;
        }
        void getFavNum(int newNumber) {
            number = newNumber;
        }
    };
int main()
{
    int favNum;
    cout << "Hello!  What is Your Favorite Number??" << endl;
    cin >> favNum;
 // Initializes myNumber as favoriteNumber Class
    favoriteNumber myNumber;
 // getFavNum and sayFavNum
    myNumber.getFavNum(favNum);
    myNumber.sayFavNum();
}