#include<iostream>
using namespace std;
class DayOfYear
{
private:
	int num;
public:
	DayOfYear(int date)
	{
		num = date;
	}
	static string  print(int);
	
	int getItegerDay()
	{
		int x;

		if (num >= 1 && num <= 31)
		{
			x = num;
			return x;
		}
		else if (num > 31 && num <= 59)
		{
			x =  num-31;
			return x;
		}
		else if (num > 59 && num <= 90)
		{
			x =  num-59;
			return x;
		}
		else if (num > 90 && num <= 120)
		{
			x =  num-90;
			return x;
		}
		else if (num > 120 && num <= 151)
		{
			x = num-120;
			return x;
		}
		else if (num >= 151 && num <= 181)
		{
			x = num-151;
			return x;
		}
		else if (num > 181 && num <= 212)
		{
			x = num-181;
			return x;
		}
		else if (num > 212 && num <= 243)
		{
			x =num-212;
			return x;
		}
		else if (num > 243 && num <= 273)
		{
			x = num-243;
			return x;
		}
		else if (num > 273 && num <= 304)
		{
			x = num-273;
			return x;
		}
		else if (num > 304 && num <= 334)
		{
			x = num-304;
			return x;
		}
		else if (num > 334 && num <= 365)
		{
			x = num-334;
			return x;
		}

	}

};
 string DayOfYear:: print(int num)
{
	if (num >= 1 && num <= 31)
	{
		return "January";
	}
	else if (num > 31 && num <= 59)
	{
		return "February";
	}
	else if (num > 59 && num <= 90)
	{
		return "March";
	}
	else if (num > 90 && num <= 120)
	{
		return "April";
	}
	else if (num > 120 && num <= 151)
	{
		return "May";
	}
	else if (num >= 151 && num <= 181)
	{
		return "June";
	}
	else if (num > 181 && num <= 212)
	{
		return "July";
	}
	else if (num > 212 && num <= 243)
	{
		return "August";
	}
	else if (num > 243 && num <= 273)
	{
		return "September";
	}
	else if (num > 273 && num <= 304)
	{
		return "October";
	}
	else if (num > 304 && num <= 334)
	{
		return "NOvember";
	}
	else if (num > 334 && num <= 365)
	{
		return "December";
	}
}
int main()
{
	int day;
	cout << "Enter the day:" << endl;
	cin >> day;
	DayOfYear d(day);
	cout << "  DAY  " << day <<" would be  "<< d.print(day)<< d.getItegerDay() << endl;
}