//pemdas class
#include <iostream> // 'cause always this
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <string>   // For string stuff

using namespace std;

class PEMDAS
{

  int x;//first number is numerator, multiplicand, addend, minuend
  int y;//second number is denominator, multiplier, addend, subtrahend
  int xLow; //lowerbound of the x variable
  int xHigh;//upperbound of the x variable
  int yLow;//lowerbound of the y variable
  int yHigh;//upperbound of the y variable

public:

  //constructor without and with defined seed
  PEMDAS(){

    srand(time(0));  // Initialize random number generator.

  }
  PEMDAS(int seed){

    srand(seed);  // Initialize random number generator.

  }

  void setXLow(int w){
    xLow = w;
  }
  void setXHigh(int w){
    xHigh = w;
  }
  void setYLow(int w){
    yLow = w;
  }
  void setYHigh(int w){
    yHigh = w;
  }

  int addInt()
  {

    x = (rand() % (xHigh - xLow)) + xLow;
    y = (rand() % (yHigh - yLow)) + yLow;

    string probText = to_string(x) + " + " + to_string(y) + " = ";
    cout << probText;

    int solution = x + y;

    string solutionText = probText + to_string(solution);

    return solution;

  }

  int subInt()
  {

    x = (rand() % (xHigh - xLow)) + xLow;
    y = (rand() % (yHigh - yLow)) + yLow;

    string probText = to_string(x) + " - " + to_string(y) + " = ";
    cout << probText;

    int solution = x - y;

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
  testDas.setXHigh(input);

  cout << "Please define the lowerbound of the first addend: ";
  cin >> input;
  testDas.setXLow(input);

  cout << "Please define the upperbound of the second addend: ";
  cin >> input;
  testDas.setYHigh(input);

  cout << "Please define the lowerbound of the second addend: ";
  cin >> input;
  testDas.setYLow(input);

  cout << "\n";

  while(true){

    //cin >> escape;
    cin.get();
    if (escape == 'q'){
      return 0;}

    sol = testDas.subInt();

    //cin >> escape;
    cin.get();
    if (escape == 'q'){
      return 0;}

    cout << sol;

    cout << "\n";

  }

  return 0;

}
