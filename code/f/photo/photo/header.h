#include <iostream>
#include<fstream>
#include<cstdlib>   //�������� ��� exit
#include <vector>
using namespace std;



class Client //����
{
private: // ������������ ������� private
    string fNameC,
           lNameC,
           emC,
           nC;
public: // ������������ ������� public
    string getfNameC()
    {
        return fNameC;
    }
    string getlNameC()
    {
        return lNameC;
    }
    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getCl(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdClient(); //������� ��� �������� ����

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
        read_clients_from_file();   //�����������
    }
    ~table_client()
    {
        write_clients_to_file();   //����������
    }
};

class Representative //����
{
private: // ������������ ������� private
    string fNameR,  //��'�
           lNameR,  //�������
           adR,     //������
           pR,      //������
           emR,     //email
           pdR,     //�������� ���
           nR,      //����� ��������
           sR;      //��������
public: // ������������ ������� public
    string getfNameR()
    {
        return fNameR;
    }
    string getlNameR()
    {
        return lNameR;
    }
    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getRl(); //������� ��� ��������� �� ����� ����� ��� �볺���

    void zdRepresentative(); //������� ��� �������� ����

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
        read_representatives_from_file();   //�����������
    }
    ~table_representative()
    {
        write_representatives_to_file();   //����������
    }
};

class Services //����
{
private: // ������������ ������� private
    string services;
    int    price;
public: // ������������ ������� public
    string getServices()
    {
        return services;
    }

    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getSer(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdServices(); //������� ��� �������� ����

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
        read_services_from_file();   //�����������
    }
    ~table_services()
    {
        write_services_to_file();   //����������
    }
};

extern table_client TABLE_CLIENT;
extern table_services TABLE_SERVICES;
extern table_representative TABLE_REPRESENTATIVE;


class Order/*: public Client, public Representative, public Order*/
{
private:
    string orderData,      //���� ����������
           dataOfIssue;    //���� ������ ����������
    int client_id, representative_id, service_id;
    /*��� �� ���� �� � ������� �볺��� �� ������������
    � ����� �������
    */

public: // ������������ ������� public
    string getOrderData()
    {
        return orderData;
    }

    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getOrder(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdOrder(); //������� ��� �������� ����
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
        read_orders_from_file();   //�����������
    }
    ~table_order()
    {
        write_orders_to_file();   //����������
    }
};
