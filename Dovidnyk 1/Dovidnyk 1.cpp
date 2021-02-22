//Author: Bohdan Levkiv

#include <iostream>
#include <string>

using namespace std;

class Contact
{
    string m_Name;
    string m_Owner;
    string m_PhoneNum;
    string m_Adress;
    string m_TypeOfWork;
    friend class Dovidnyk;
public:
    Contact()
    {
        m_Name[0] = '\0';
        m_Owner[0] = '\0';
        m_PhoneNum[0] = '\0';
        m_Adress[0] = '\0';
        m_TypeOfWork[0] = '\0';
    }
    Contact(string name, string owner, string num, string adress, string type) : m_Name{name}, m_Owner{owner}, m_PhoneNum{num}, m_Adress{adress}, m_TypeOfWork{type}{}
};

class Dovidnyk
{
    int m_Size;
    Contact* m_User;
 public:
    Dovidnyk()
    {
        m_Size = 0;
        m_User = new Contact[m_Size];
    }
    ~Dovidnyk()
    {
        delete[] m_User;
        m_User = nullptr;
    }

    void addContact(string name, string owner, string num, string adress, string type)
    {
        Contact* arr = new Contact[m_Size+1];
        for (int i = 0; i < m_Size; i++)
        {
            arr[i] = m_User[i];
        }
        Contact temp(name, owner, num, adress, type);
        arr[m_Size] = temp;
        m_Size++;
        delete[] m_User;
        m_User = arr;
    }

    void SearchByName(string search)
    {
        for (int i = 0; i < m_Size; i++)
        {
            if (m_User[i].m_Name == search)
            {
                cout << "There is company with name " << search <<", it`s number in list is :"<< i + 1 << endl;
            }
        }
    }

    void SearchByOwner(string search)
    {
        for (int i = 0; i < m_Size; i++)
        {
            if (m_User[i].m_Owner == search)
            {
                cout << "There is company with owner " << search << ", it`s number in list is :" << i + 1 << endl;
            }
        }
    }

    void SearchByPhoneNumber(string search)
    {
        for (int i = 0; i < m_Size; i++)
        {
            if (m_User[i].m_PhoneNum == search)
            {
                cout << "There is company with phone number " << search << ", it`s number in list is :" << i + 1 << endl;
            }
        }
    }

    void SearchByWorkType(string search)
    {
        for (int i = 0; i < m_Size; i++)
        {
            if (m_User[i].m_TypeOfWork == search)
            {
                cout << "There is company with type of work" << search << ", it`s number in list is :" << i + 1 << endl;
            }
        }
    }

    void PrintAll()
    {
        for (int i = 0; i < m_Size; i++)
        {
            cout << i + 1 << " Contact: " << endl;
            cout << "Name of company: " << m_User[i].m_Name << endl;
            cout << "Owner: " << m_User[i].m_Owner << endl;
            cout << "Phone number: " << m_User[i].m_PhoneNum << endl;
            cout << "Adress: " << m_User[i].m_Adress << endl;
            cout << "Type of work: " << m_User[i].m_TypeOfWork << endl;
        }
    }
};

int main()
{
    Dovidnyk dovidnyk;

    bool work = true;
    int choice = 0;
    string name, owner, num, adress, type;

    cout << "Just added this cout and that`s all!" << endl;

    /*while (work)
    {
        cout << "Choose operation: " << endl;
        cout << "1-Add contact,2-Print, 3-Search by name, 4-Search by owner, 5-Search by phone number, 6-Search by work type, 7-exit" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Name of the company ";
            getline(cin, name);
            cout << "Enter Name of the owner ";
            getline(cin, owner);
            cout << "Enter Phone number ";
            getline(cin, num);
            cout << "Enter Adress ";
            getline(cin, adress);
            cout << "Enter Type of work ";
            getline(cin, type);
            dovidnyk.addContact(name, owner, num, adress, type);
        }break;
        case 2:
        {
            dovidnyk.PrintAll();
        }break;
        case 3:
        {
            cout << "Enter Name to search ";
            getline(cin, name);
            dovidnyk.SearchByName(name);
        }break;
        case 4:
        {
            cout << "Enter Name of the owner to search ";
            getline(cin, owner);
            dovidnyk.SearchByOwner(owner);
        }break;
        case 5:
        {
            cout << "Enter Phone number to search ";
            getline(cin, num);
            dovidnyk.SearchByPhoneNumber(num);
        }break;
        case 6:
        {
            cout << "Enter Type of work to search";
            getline(cin, type);
            dovidnyk.SearchByWorkType(type);
        }break;
        default: 
        {
            work = false;
        }
        }
    }*/
}