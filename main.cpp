#include <iostream>
#include <cmath>
using namespace std;

class Angle
{
private:
	int degrees;
	int minutes;
public:
	double get_d() {
		return degrees;
	}

	double get_m() {
		return minutes;
	}

	void input_angle() //ввод угла
	{
		cout << "degrees:";
		cin >> degrees;
		cout << endl << "minutes: ";
		cin >> minutes;
		cout << endl;
	}

	double normalize() //приведение к десятичной форме
	{
		return(degrees + minutes / 60);
	}
	double to_radians()  // перевод в радианы
	{
		return(degrees * 3.1415 / 180 + minutes * 3.1415 / 10800);
	}

	void to_360()  // приведение к диапазону 0-360
	{
		if (minutes < 0) {
			degrees--;
			minutes += 60;
		}
		if (degrees > 0)
			degrees %= 360;
		else
			degrees = degrees % 360 + 360;
		if (minutes >= 60) { degrees += minutes / 60;  minutes %= 60; }
	}

	void addition() {          //сложение
		Angle angle2;
		cout << "input angle 2: " << endl;
		angle2.input_angle();
		degrees += angle2.get_d();
		minutes += angle2.get_m();
		if (minutes >= 60) { degrees -= minutes / 60;  minutes %= 60; }
	}
	void subtraction() {     //вычитание
		Angle angle2;
		cout << "input angle 2: " << endl;
		angle2.input_angle();
		degrees -= angle2.get_d();
		minutes -= angle2.get_m();
		if (minutes >= 60 or minutes <= -60) { degrees -= minutes / 60;  minutes %= 60; }
		if (minutes < 0) { degrees -= 1 + (-1 * minutes / 60); minutes = 60 + minutes; };
	}
	void division_num() {      // деление на число
		int divider;
		cout << "input divider: " << endl;
		cin >> divider;
		degrees /= divider;
		minutes /= divider;
		if (minutes >= 60) { degrees += minutes / 60;  minutes %= 60; }
	}
	friend int compare_angles(Angle a1, Angle a2)  // сравнение углов
	{
		double m1 = a1.normalize();
		double m2 = a2.normalize();
		if (m1 < m2) return -1;
		else if (m1 > m2) return 1;
		else return 0;
	}
	friend double sinus(Angle a1)         // тригонометрические функцию
	{
		return sin(a1.to_radians());
	}
	friend double cosinus(Angle a1)
	{
		return cos(a1.to_radians());
	}
	friend double tangens(Angle a1)
	{
		return tan(a1.to_radians());
	}
};

int main()
{
	int point = 1;
	Angle angle1, angle2;
	cout << "Menu:\n";
	cout << "1. Convert to radians.\n";
	cout << "2. Convert to range 0-360.\n";
	cout << "3. Addition\n";
	cout << "4. Subtraction\n";
	cout << "5. Devision by number\n";
	cout << "6. Compare angles.\n";
	cout << "7. Sin\n";
	cout << "8. Cos\n";
	cout << "9. Tg\n";
	cout << "10. Exit.\n";

	while (point) {
		cout << "Select menu item:\n";
		cin >> point;
		if (point == 1) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "Angle " << angle1.get_d() << " d; " << angle1.get_m() << " m;  in radians is: " << angle1.to_radians() << " rad;" << endl;
		}
		if (point == 2) {
			cout << "input angle : \n";
			angle1.input_angle();
			angle1.to_360();
			cout << "Angle in range 0-360 is: " << angle1.get_d() << " d; " << angle1.get_m() << " m;" << endl;
		}
		if (point == 3) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			angle1.addition();
			cout << "Result of their addition is: " << angle1.get_d() << " d; " << angle1.get_m() << " m;" << endl;
		}
		if (point == 4) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			angle1.subtraction();
			cout << "Result of their substraction is: " << angle1.get_d() << " d; " << angle1.get_m() << " m;" << endl;
		}
		if (point == 5) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			angle1.division_num();
			cout << "Result of their division is: " << angle1.get_d() << " d; " << angle1.get_m() << " m;" << endl;
		}
		if (point == 6) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			cout << "input angle 2: \n";
			angle2.input_angle();
			if (compare_angles(angle1, angle2) == 1) {
				cout << "angle 1  >  angle 2 \n";
			}
			else if (compare_angles(angle1, angle2) == -1) {
				cout << "angle 1  <  angle 2 \n";
			}
			else {
				cout << "angle 1  is equal to angle 2 \n";
			}
		}
		if (point == 7) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "sin(angle) = " << sinus(angle1) << endl;
		}
		if (point == 8) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "cos(angle) = " << cosinus(angle1) << endl;
		}
		if (point == 9) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "tg(angle) = " << tangens(angle1) << endl;
		}
		if (point == 10) { break; }
		if (point > 10 || point <= 0) { cout << "error, enter correct number\n"; }
	}
}
