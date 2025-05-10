#pragma once
#include "iostream"
#include"ClsPerson.h"
class ClsEmployee
{
private:
    string _FirstName, _SecondName, _Id, _Address, _EmailAddress, _Phone, _Salary,
        _Department;
public:


    //declare the constructor
    ClsEmployee(string firstName, string SecondName, string Id, string Phone, string Email, string Address, string Department, string salary)
    {

        _FirstName = firstName;
        _SecondName = SecondName;
        _Id = Id;
        _Phone = Phone;
        _EmailAddress = Email;
        _Address = Address;
        _Department = Department;
        _Salary = salary;
    }
    //property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    string GetSecondName()
    {
        return _SecondName;
    }
    string GetId()
    {
        return _Id;
    }
    string GetEmailAddress()
    {
        return _EmailAddress;
    }
    string GetAddress()
    {
        return _Address;
    }
    string GetPhone()
    {
        return _Phone;
    }
    string GetSalary()
    {
        return _Salary;
    }
    string GetFullName()
    {
        return _FirstName + " " + _SecondName;
    }
    string GetDepartment()
    {
        return _Department;
    }
    //property set
    void SetFristName(string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetSecondName(string SecondName)
    {
        _SecondName = SecondName;
    }
    void SetEmailAddress(string EmailAddress)
    {
        _EmailAddress = EmailAddress;
    }
    void SetAddress(string Address)
    {
        _Address = Address;
    }
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    void SetSalary(string Salary)
    {
        _Salary = Salary;
    }
    void GetDepartment(string Department)
    {
        _Department = Department;
    }
    void SendEmail(string Body)
    {
        cout << "your Email :\n " << Body << "\n successfully sent to the : " << _EmailAddress << endl;
    }
    void SendSms(string Body)
    {
        cout << "yor sms has :\n" << Body << "\n successfully sent to the : " << _Phone << endl;
    }
    void Print()
    {
        cout << "\nEmployee Info \n";
        cout << "_________________________________________\n";
        cout << " Id " << _Id << endl;
        cout << " First name : " << _FirstName << endl;
        cout << " Second name : " << _SecondName << endl;
        cout << " Full name : " << GetFullName() << endl;
        cout << " Email Address : " << _EmailAddress << endl;
        cout << " Address :" << _Address << endl;
        cout << " phone : " << _Phone << endl;
        cout << " Department : " << _Department << endl;
        cout << " Salary : " << _Salary << endl;
        cout << "_________________________________________\n";
    }
};


