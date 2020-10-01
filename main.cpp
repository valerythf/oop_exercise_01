#include <iostream>
#include <cmath>
using namespace std;

class Angle
{
private:
	int degrees;
	int minutes;
public:
	void input_angle() //ввод угла
	{
		cout << "degrees:";
		cin >> degrees;
		cout << endl << "minutes: ";
		cin >> minutes;
		cout << endl;
	}
	void correction() {   // округление лишних минут до градусов при ситуации >60 минут или <0 минут
		if (minutes >= 60) { degrees += minutes / 60; minutes %= 60; };
		if (minutes < 0) { degrees -= 1 + (-1 * minutes / 60); minutes = 60 + minutes; };
		if (degrees*minutes < 0) { cout << "wrong input"; };
	}
	double get_d() {
		return degrees;
	}

	double get_m() {
		return minutes;
	}

	friend double normalize(Angle angle) //приведение к десятичной форме
	{
		angle.correction();
		return(angle.degrees + angle.minutes / 60);
	}
	friend double to_radians(Angle angle)  // перевод в радианы
	{
		angle.correction();
		return(angle.degrees * 3.1415 / 180 + angle.minutes * 3.1415 / 10800);
	}

	void to_360()  // приведение к диапазону 0-360
	{
		correction();
		if (minutes < 0) {
			degrees--;
			minutes += 60;
		}
		if (degrees > 0)
			degrees %= 360;
		else
			degrees = degrees % 360 + 360;
		correction();
	}

	void addition(Angle angle) {  //сложение
		correction();
		angle.correction();
		degrees += angle.degrees;
		minutes += angle.minutes;
		correction();
	}
	void subtraction(Angle angle) {  //сложение
		correction();
		angle.correction();
		degrees -= angle.degrees;
		minutes -= angle.minutes;
		if (degrees < 0) { degrees += 360; };
		correction();
	}
	void division_num(int divider) {  // деление на число
		double new_deg, new_min;
		new_deg = int((static_cast<double>(degrees) + static_cast<double>(minutes) / 60) / divider);
		new_min = (static_cast<double>(degrees) + static_cast<double>(minutes) / 60) / divider - new_deg;
		degrees = new_deg;
		minutes = new_min * 60;
		correction();
	}
	friend int compare_angles(Angle a1, Angle a2)  // сравнение углов
	{
		double m1 = normalize(a1);
		double m2 = normalize(a2);
		if (m1 < m2) return -1;
		else if (m1 > m2) return 1;
		else return 0;
	}
	friend double sinus(Angle a1)         // тригонометрические функцию
	{
		return sin(to_radians(a1));
	}
	friend double cosinus(Angle a1)
	{
		return cos(to_radians(a1));
	}
	friend double tangens(Angle a1)
	{
		return tan(to_radians(a1));
	}
};

int main()
{
	int point = 1, divider;
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
			cout << "Angle " << angle1.get_d() << "d" << angle1.get_m() << "m  in radians is: " << to_radians(angle1) << " rad;" << endl;
		}
		if (point == 2) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "Angle " << angle1.get_d() << "d" << angle1.get_m() << "m  in range 0-360 is: ";
			angle1.to_360();
			cout << angle1.get_d() << "d" << angle1.get_m() << "m" << endl;
		}
		if (point == 3) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			cout << "input angle 2: \n";
			angle2.input_angle();
			cout << angle1.get_d() << "d" << angle1.get_m() << "m  +  " << angle2.get_d() << "d" << angle2.get_m() << "m  =  ";
			angle1.addition(angle2);
			cout << angle1.get_d() << "d" << angle1.get_m() << "m" << endl;
		}
		if (point == 4) {
			cout << "input angle 1: \n";
			angle1.input_angle();
			cout << "input angle 2: \n";
			angle2.input_angle();
			cout << angle1.get_d() << "d" << angle1.get_m() << "m  -  " << angle2.get_d() << "d" << angle2.get_m() << "m  =  ";
			angle1.subtraction(angle2);
			cout << angle1.get_d() << "d" << angle1.get_m() << "m" << endl;
		}
		if (point == 5) {
			cout << "input angle : \n";
			angle1.input_angle();
			cout << "input divider: \n";
			cin >> divider;
			cout << angle1.get_d() << "d" << angle1.get_m() << "m  /  " << divider << " = ";
			angle1.division_num(divider);
			cout << angle1.get_d() << "d" << angle1.get_m() << "m" << endl;
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
