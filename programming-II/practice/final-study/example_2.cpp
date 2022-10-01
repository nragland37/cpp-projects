//****************************************************************************************************

#include <iostream>
#define PI 3.14
using namespace std;

//****************************************************************************************************

int main() {
    cout << "Find the circumference and the area of any circle." << endl;
    cout << "Input the radius(1/2 of diameter) of a circle: ";

    float radius, area, circum;
    cin >> radius;

    circum = 2 * PI * radius;
    area = PI * (radius * radius);

    cout << endl;

    cout << "The area of the circle is: " << area << endl;
    cout << "The circumference of the circle is: " << circum << endl;

    return 0;
}

//****************************************************************************************************