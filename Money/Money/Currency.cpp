#include<string>;

//ISO Code data type
class ISO4217 {//TODO: add info on usage
private:
	std::string alpha;
	int numeric;
public:
	ISO4217(std::string alpha, int numeric) {
		this->alpha = alpha;

		if ((numeric >= 0) && (numeric < 1000)) {
			this->numeric = numeric;
		}
		else {
			throw(-1);//TODO: add error number and description
		}
	}

	std::string getAlpha() {//TODO: add info on usage
		return alpha;
	}

	int getNumeric() {//TODO: add info on usage
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


//Unit symbol data type
class unitSymbol {//TODO: add info on usage
private:
	std::string major;
	std::string minor;
public:
	unitSymbol(std::string majorunitSymbol, std::string minorunitSymbol) {
		major = majorunitSymbol;
		minor = minorunitSymbol;
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
	ISO4217 currISO = ISO4217("", 0);
	unitName currUnitName = unitName("", "");
	unitSymbol currUnitSymbol = unitSymbol("", "");
	int displayDecimals;
	displayFormat format = displayFormat(',', '.');
public:
	//Default currency type (GBP)
	currency() {
		name = "Pound Sterling";
		currISO = ISO4217("GBP", 826);
		currUnitName = unitName("pound", "pence");
		currUnitSymbol = unitSymbol("£", "p");
		displayDecimals = 2;
		format = displayFormat(',', '.');
	}

	currency(std::string name, ISO4217 currencyISO, unitName currencyUnitName, unitSymbol currencyUnitSymbol, int displayDecimals, displayFormat format) {
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

class currencyIndex {//TODO: maybe split into index template class and this
public:
	//Creates the initial index with a list of currencies
	currencyIndex() {
		insertNewCurrency(currency("Pound Sterling", ISO4217("GBP", 826), unitName("pound", "pence"), unitSymbol("£","p"), 2, displayFormat(',', '.')));
		//TODO: insert many more currency's
	}

	//Add's a new currency to the index.
	//insertNewCurrency((currency) the new currency object to insert in the index), this returns to values
	void insertNewCurrency(currency newCurrecny) {//TODO: add info on usage
		//Resize array if necessary
		if (currencyCount >= arraySize) {
			increaseArraySize();
		}

		//TODO: update to order inserted currency's by ISO numeric and if turned on add to second array in order of ISO alpha(pointers to original)
		//Add the new currency
		currencyArray[currencyCount] = newCurrecny;
		//Update the currency count
		currencyCount++;
	}

	//Search for currency by ISO number
	currency searchByISOnumberic(std::string id) {//TODO: add info on usage

	}

private:
	const static int initialSize = 50; //Initial size of the array, by default its the number of default items plus 5
	const static int arraySizeStep = 10; //The amount to increase the array size by

	int arraySize = initialSize;
	int currencyCount = 0;
	currency* currencyArray = new currency[initialSize];

	//Increases the size of the array
	//TODO: add more details on usage
	void increaseArraySize() {
		int newArraySize = arraySize + arraySizeStep;
		//TODO: maybe a check for overflow/ check tmpArray for errors.
		//create temporary array to store current items
		currency* tmpArray = new currency[arraySize];

		//Add current items to this array
		for (int i = 0; i < currencyCount; i++) {
			tmpArray[i] = currencyArray[i];
		}

		//Destroy everything in the currency array
		delete[] currencyArray;
		//Set the currency's new size
		currencyArray = new currency[newArraySize];
		
		//Refill the current array
		for (int i = 0; i < currencyCount; i++) {
			currencyArray[i] = tmpArray[i];
		}

		//Clean up tmpArray
		delete[] tmpArray;

		//Update the array size
		arraySize = newArraySize;
	}
};