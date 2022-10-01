//****************************************************************************************************

#include <iostream>
using namespace std;

//****************************************************************************************************

int main() {
    const float pi = 3.14;
    float radius, area, circum;

    cout << "Find the circumference and the area of any circle." << endl;
    cout << "Input the radius(1/2 of diameter) of a circle: ";

    cin >> radius;

    circum = 2 * pi * radius;
    area = pi * (radius * radius);

    cout << endl;

    cout << "The area of the circle is: " << area << endl;
    cout << "The circumference of the circle is: " << circum << endl;

    return 0;
}

//****************************************************************************************************