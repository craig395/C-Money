#include<string>;

//ISO Code data type
class ISO4217 {//TODO: add info on usage
private:
	std::string alpha;
	std::string numeric;
public:
	ISO4217(std::string alpha, std::string numeric) {
		this->alpha = alpha;
		this->numeric = numeric;
	}

	std::string getAlpha() {//TODO: add info on usage
		return alpha;
	}

	std::string getNumeric() {//TODO: add info on usage
		return numeric;
	}
};

//Unit name data type

class unitName {//TODO: add info on usage
private:
	std::string major;
	std::string minor;
public:
	unitName(std::string majorUnitName, std::string minorUnitName) {
		major = majorUnitName;
		minor = minorUnitName;
	}

	std::string getMajor() {//TODO: add info on usage
		return major;
	}

	std::string getMinor() {//TODO: add info on usage
		return minor;
	}
};

//Display info
class displayFormat {
private:
	char hundredsSeparator;
	char decimalSeparator;
public:
	displayFormat(char hundredsSeparator, char decimalSeparator) {
		this->hundredsSeparator = hundredsSeparator;
		this->decimalSeparator = decimalSeparator;
	}

	char getHundredsSeparator() {//TODO: add info on usage
		return hundredsSeparator;
	}

	char getDecimalSeparator() {//TODO: add info on usage
		return decimalSeparator;
	}

};

//Currency data type
class currency {//TODO: add info on usage
private:
	std::string name;
	ISO4217 currISO = ISO4217("", "");
	unitName currUnitName = unitName("", "");
	int displayDecimals;
	displayFormat format = displayFormat(',', '.');
public:
	currency(std::string name, ISO4217 currencyISO, unitName currencyUnitName, int displayDecimals, displayFormat format) {
		this->name = name;
		currISO = currencyISO;
		currUnitName = currencyUnitName;
		this->displayDecimals = displayDecimals;
		this->format = format;
	}

	std::string getName() {//TODO: add info on usage
		return name;
	}

	ISO4217* getcurrencyISO(){//TODO: add info on usage
		return &currISO;
	}

	unitName* getUnitNames() {//TODO: add info on usage
		return &currUnitName;
	}

	int getDisplayDecimals() {//TODO: add info on usage
		return displayDecimals;
	}

	displayFormat* getFormat() {//TODO: add info on usage
		return &format;
	}
};
