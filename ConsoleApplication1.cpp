#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <ctime>
#include "ClsPeriod.h"
#include "ClsString.h"
#include "MyDate.h"
#include "ClsUtil.h"
#include "ClsBankClient.h"
#include "ClsMainScreen.h"
#include "IsInputValid.h"
#include "ClsLogin.h"
using namespace::std;
int main()
{
  //  ClsMainScreen::ShowMainMenu();
   while (ClsLogin::Login())
    {
       ClsLogin::Login();
    }

    //cout << ClsUtil::decryption("lolo");
    system("pause>0");
    return 0;
}
