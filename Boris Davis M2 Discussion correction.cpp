 /*
          Student Name: Boris Davis
          Date: 9/4/2024
          File Name: M2 DIscussion with errors
           */


          #include <iostream>
          #include <string>

          using namespace std;


          int main()
          {
              string weather;

              // Asks the user for the weather //

              cout << "How is the weather today? (raining, sunny, or clear): ";
              cin >> weather;

              // Respond based on weather //

              if (weather == "raining")
                  cout << "You should use an umbrella, otherwise you may be soaked!" << endl;
              else if (weather == "sunny")
                  cout << "Have a good day!" << endl;
              else if (weather == "clear")
                  cout << "Have a good day!" << endl;
              else
                  cout << "That weather type is not recognized." << endl;


              return 0;
          }