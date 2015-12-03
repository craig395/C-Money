#include<string>;

//ISO Code data type
struct ISO4217 {
	std::string alpha;
	std::string numeric;
};

//Unit name data type

struct unitName {
	std::string major;
	std::string minor;
};

//Currency data type
class currency {
private:
	std::string Name;
	ISO4217 currISO;
	unitName currUnitName;
	int displayDecimals;
	std::string displayFormat;

};
