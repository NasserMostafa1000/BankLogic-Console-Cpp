#include <iostream>
#include <string>
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsCurrency.h"

class ClsFindCurrency : private ClsTheStaticScreen {
    static void _PrintCurrency(ClsCurrency& CurrencyTOPrint) {
        std::cout << "currency name : " << CurrencyTOPrint.GetTheCurrencyName() << std::endl;
        std::cout << "currency Code : " << CurrencyTOPrint.GetTheCurrencyCode() << std::endl;
        std::cout << "currency Rate : " << CurrencyTOPrint.GetTheRate() << std::endl;
    }

public:
    static void FindCurrency() {
        ClsTheStaticScreen::PrintMinuScreen("find currency menu \n");
        ClsCurrency CurrencyToFind = ClsCurrency::GetEmptyObject();
        short Number = IsInputValid::ReadNumberBetween1<short>("search by country [1] search by code[2]", 1, 2);

        if (Number == 1) {
            std::string CountryName = IsInputValid::ReadLine("please enter the country Name\n");

            while (!ClsCurrency::IsCurrencyIsAlreadyExistsByCountry(CountryName))
            {
                CountryName = IsInputValid::ReadLine("please enter right country Name, this is not found\n");
            }

            CurrencyToFind = ClsCurrency::FindByCountry(CountryName);
            _PrintCurrency(CurrencyToFind);
        }
        else {
            std::string CountryCode = IsInputValid::ReadString("please enter the country Code\n");

            while (!ClsCurrency::IsCurrencyIsAlreadyExistsByCode(CountryCode)) {
                CountryCode = IsInputValid::ReadString("please enter right country Code, this is not found\n");
            }

            CurrencyToFind = ClsCurrency::FindByCode(CountryCode);
            _PrintCurrency(CurrencyToFind);
        }

        // الآن يمكنك استخدام CurrencyToFind كما تحتاج
        // على سبيل المثال: _PrintCurrency(CurrencyToFind);
    }
};

