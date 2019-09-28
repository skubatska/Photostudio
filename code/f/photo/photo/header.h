#include <iostream>
#include<fstream>
#include<cstdlib>   //бібліотека для exit
#include <vector>
using namespace std;



class Client //клас
{
private: // специфікатор доступу private
    string fNameC,
           lNameC,
           emC,
           nC;
public: // специфікатор доступу public
    string getfNameC()
    {
        return fNameC;
    }
    string getlNameC()
    {
        return lNameC;
    }
    void message() // функція (метод класу), яка виводить повідомлення на екран
    {
        cout << "\tДанi збережено!\n\n";
    }
    void getCl(); //функція для виведення на екран даних про клієнта
    void zdClient(); //функція яка вводитьз клаві

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_client
{
public:
    vector <Client> vec;
    void print_all_clients();

    void add_new_client();

    int search_client(bool mozhna_povernutus=true);

    void poshuk();

    void edit_client();

    void delete_client();

    void write_clients_to_file();

    void read_clients_from_file();

    void menu();
    table_client()
    {
        read_clients_from_file();   //конструктор
    }
    ~table_client()
    {
        write_clients_to_file();   //деструктор
    }
};

class Representative //клас
{
private: // специфікатор доступу private
    string fNameR,  //ім'я
           lNameR,  //прізвище
           adR,     //адреса
           pR,      //посада
           emR,     //email
           pdR,     //паспортні дані
           nR,      //номер телефону
           sR;      //зарплата
public: // специфікатор доступу public
    string getfNameR()
    {
        return fNameR;
    }
    string getlNameR()
    {
        return lNameR;
    }
    void message() // функція (метод класу), яка виводить повідомлення на екран
    {
        cout << "\tДанi збережено!\n\n";
    }
    void getRl(); //функція для виведення на екран даних про клієнта

    void zdRepresentative(); //функція яка вводитьз клаві

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_representative
{
public:
    vector <Representative> vec;
    void print_all_representatives();

    void add_new_representative();

    int search_representative(bool mozhna_povernutus=true);

    void poshuk();
    void edit_representative();

    void delete_representative();

    void write_representatives_to_file();

    void read_representatives_from_file();

    void menu_representatives();
    table_representative()
    {
        read_representatives_from_file();   //конструктор
    }
    ~table_representative()
    {
        write_representatives_to_file();   //деструктор
    }
};

class Services //клас
{
private: // специфікатор доступу private
    string services;
    int    price;
public: // специфікатор доступу public
    string getServices()
    {
        return services;
    }

    void message() // функція (метод класу), яка виводить повідомлення на екран
    {
        cout << "\tДанi збережено!\n\n";
    }
    void getSer(); //функція для виведення на екран даних про клієнта
    void zdServices(); //функція яка вводитьз клаві

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_services
{
public:
    vector <Services> vec;
    void print_all_services();

    void add_new_services();

    int search_services(bool mozhna_povernutus=true);

    void poshuk();

    void edit_services();

    void delete_services();

    void write_services_to_file();

    void read_services_from_file();

    void menuServices();
    table_services()
    {
        read_services_from_file();   //конструктор
    }
    ~table_services()
    {
        write_services_to_file();   //деструктор
    }
};

extern table_client TABLE_CLIENT;
extern table_services TABLE_SERVICES;
extern table_representative TABLE_REPRESENTATIVE;


class Order/*: public Client, public Representative, public Order*/
{
private:
    string orderData,      //дата замовлення
           dataOfIssue;    //дата видачі замовлення
    int client_id, representative_id, service_id;
    /*Тут має бути ім я прізвище клієнта та представника
    і назва фотосесії
    */

public: // специфікатор доступу public
    string getOrderData()
    {
        return orderData;
    }

    void message() // функція (метод класу), яка виводить повідомлення на екран
    {
        cout << "\tДанi збережено!\n\n";
    }
    void getOrder(); //функція для виведення на екран даних про клієнта
    void zdOrder(); //функція яка вводитьз клаві
    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_order
{
public:
    vector <Order> vec;

    void print_all_orders();
    void add_new_orders();

    int search_orders();

    void poshuk();

    void edit_orders();

    void delete_orders();

    void write_orders_to_file();

    void read_orders_from_file();

    void menuOrder();
    table_order()
    {
        read_orders_from_file();   //конструктор
    }
    ~table_order()
    {
        write_orders_to_file();   //деструктор
    }
};
