#include <string>

using namespace std;

// Constants
const float CENT_TO_INCH = 0.394;
const int FOOT_TO_INCH = 12;

//----------------------------------------------------------------//
//	Function prototypes and constants							  //
//----------------------------------------------------------------//

int MainMenu();
int getUserInput();
bool AscendingNumber(int value1, int value2);
void lengthConversion(float centimeterInput, float& footOutput, float& inchOutput);
void rectangleDimension(int widthInput, int heightInput, int& perimeterOutput, int& areaOutput);
