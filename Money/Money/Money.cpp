#include<string>;
#include"Currency.cpp";

//Money data type
class money {//TODO: add info on usage
private:
	currency moneyCurrency;

public:
	money(currency moneyCurrency = currency()) {
		this->moneyCurrency = moneyCurrency;
	}


};
