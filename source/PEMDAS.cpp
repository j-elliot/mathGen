//pemdas class
#include <iostream> // 'cause always this
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <string>   // For string stuff

using namespace std;

class PEMDAS
{

  //first number is numerator, multiplicand, addend, minuend
  int x;

  //second number is denominator, multiplier, addend, subtrahend
  int y;

public:

  //constructor without and with defined seed
  PEMDAS(){

    srand(time(0));  // Initialize random number generator.

  }
  PEMDAS(int seed){

    srand(seed);  // Initialize random number generator.

  }

  int addInt(int xLow, int xHigh, int yLow, int yHigh)
  {

    x = (rand() % (xHigh - xLow)) + xLow;
    y = (rand() % (yHigh - yLow)) + yLow;

    string probText = to_string(x) + " + " + to_string(y) + " = ";
    cout << probText;

    int solution = x + y;

    string solutionText = probText + to_string(solution);

    return solution;

  }

};

//unit test
int main(){

  int sol;
  int input;
  char escape;

  //instantiate an object
  PEMDAS testDas;

  cout << "Please define the upperbound of the first addend: ";
  cin >> input;
  int xUp = input;

  cout << "Please define the lowerbound of the first addend: ";
  cin >> input;
  int xLow = input;

  cout << "Please define the upperbound of the second addend: ";
  cin >> input;
  int yUp = input;

  cout << "Please define the lowerbound of the second addend: ";
  cin >> input;
  int yLow = input;

  cout << "\n";

  while(true){

    //cin >> escape;
    cin.get();
    if (escape == 'q'){
      return 0;}

    sol = testDas.addInt(xLow, xUp, yLow, yUp);

    //cin >> escape;
    cin.get();
    if (escape == 'q'){
      return 0;}

    cout << sol;

    cout << "\n";

  }

  return 0;

}
