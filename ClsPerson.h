#pragma once
#include "iostream"
using namespace std;
class ClsPerson
{
private:
    string _ID, _Phone, _FirstName, _Email, _SecondName;
public:
    //fill the private members with the parameters of the constructor
    ClsPerson(string Id, string Phone, string Email, string FirstName, string LastName)
    {
        _ID = Id;
        _Phone = Phone;
        _Email = Email;
        _FirstName = FirstName;
        _SecondName = LastName;

    }
    void SendEmail(string Subject, string Email)
    {
        cout << "email has been sent to the : " << _Email << "\n subject : " << Subject << "\n Email " << Email << endl;
    }
    void SendSms(string sms)
    {
        cout << "sms has been sent to the : " << _Phone << "\n Sms :" << sms << endl;
    }
    //void print()
    //{
    //    cout << "INFO\n\n";
    //    cout << "_________________________________________\n";
    //    cout << "id = " << _ID << endl;;
    //    cout << "First Name = " << _FirstName << "\n";
    //    cout << "Phone = " << _Phone << "\n";
    //    cout << "Last Name = " << _SecondName << "\n";
    //    cout << "Email Address = " << _Email << "\n";
    //    cout << "_________________________________________\n";



    //}
    void SetEmail(string SetEmail)
    {
        _Email = SetEmail;
    }
    void SetPhone(string SetPhone)
    {
        _Phone = SetPhone;
    }
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetSecondName(string LastName)
    {
        _SecondName = LastName;
    }
    void SetId(string Id)
    {
        _ID = Id;
    }

    string FullName()
    {
        return _FirstName + " " + _SecondName;
    }
    string Id()
    {
        return _ID;
    }
    string FirstName()
    {
        return _FirstName;
    }
    string SecondName()
    {
        return _SecondName;
    }
    string Email()
    {
        return _Email;
    }
    string phone()
    {
        return _Phone;
    }

};


