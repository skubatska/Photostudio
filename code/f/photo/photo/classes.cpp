#include "header.h"

void Client::getCl() //функція для виведення на екран даних про клієнта
{
    cout<<"\n\tIм'я:           "<<fNameC<<"\n\tПрiзвище:       "<<lNameC<<"\n\tEmail:          "<<emC<<"\n\tНомер телефону: "<<nC<<endl;
}

void Client::zdClient() //функція яка вводитьз клаві
{
    cout << "\tВведiть данi про клiєнта\n";
    cout << "\tIм'я: ";
    cin >> fNameC;
    cout << "\tПрiзвище: ";
    cin >> lNameC;
    cout << "\tEmail: ";
    cin >> emC;
    cout << "\tНомер: ";
    cin >> nC;
    message();
}

void Client::write_to_file(ofstream &file)
{
    file<<fNameC<<"\t"<<lNameC<<"\t"<<emC<<"\t"<<nC<<endl;
}

void Client::read_from_file(ifstream &file)
{
    file >> fNameC >> lNameC >> emC >> nC;
}


void table_client::print_all_clients()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getCl(); /*cout<<endl;*/
    }
}

void table_client::add_new_client()
{
    Client temp;
    temp.zdClient();
    vec.push_back(temp);
}

int table_client::search_client(bool mozhna_povernutus)
{
    string firstNameC;
    string lastNameC;
    int id=-1;
    while(true)
    {
        cout << "\n\tIм'я: ";
        cin >> firstNameC;
        cout << "\tПрiзвище: ";
        cin >> lastNameC;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getfNameC()==firstNameC)&&(vec[i].getlNameC()==lastNameC))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\tКлієнта не знайдено. Спробуйте ще раз." << endl;
                continue;
            }
            cout<<"\tКлієнта не знайдено. Спробуйте ще раз |1|, або поверніться в попереднє меню |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_client::poshuk()
{
    int id;
    id=search_client();
    if(id!=-1)vec[id].getCl();
}

void table_client::edit_client()
{
    int id;
    id=search_client();
    if(id!=-1)vec[id].zdClient();
}

void table_client::delete_client()
{
    int id;
    id=search_client();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\tКлiєнта видалено" <<endl;
    }
    else cout << "\tКлієнта не видалено" <<endl;
}

void table_client::write_clients_to_file()
{
    ofstream fClient("client1.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fClient);//для кожного елемента викликати функцію яка записує у файл
    fClient.close();
}

void table_client::read_clients_from_file()
{
    ifstream fClient("client1.txt");
    if(fClient.is_open())
    {
        Client temp;
        while(!fClient.eof())
        {
            temp.read_from_file(fClient);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //видалення останнього об'єкта, бо його дублює
        fClient.close();
    }

}

void table_client::menu()
{
    while(1)
    {
        cout <<"\n\tВивести всiх клiєнтiв------>|1|\n\tЗнайти клiєнта------------->|2|\n\tДодати клiєнта------------->|3|\n\tРедагувати данi про клiєнта>|4|\n\tВидалити клiєнта----------->|5|\n\tВийти---------------------->|6|" << endl;
        int inC;
        cin >> inC;
        switch(inC)
        {
        case 1:
            print_all_clients();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_client();
            break;
        case 4:
            edit_client();
            break;
        case 5:
            delete_client();
            break;
        case 6:
            return;
        }
    }
}


void Representative::getRl() //функція для виведення на екран даних про клієнта
{
    cout<<"\n\tIм'я:           "<<fNameR<<"\n\tПрiзвище:       "<<lNameR<<"\n\tEmail:          "<< emR<<"\n\tНомер телефону: "<<nR<<"\n\tПаспортнi данi: "<<pdR<<"\n\tАдрес:          "<<adR<<"\n\tПосада:         "<<pR<<"\n\tЗарплата:       "<<sR<<endl<<endl;
}

void Representative::zdRepresentative() //функція яка вводитьз клаві
{
    cout << "\n\tВведiть данi про представника фотосалону\n";
    cout << "\tIм'я: ";
    cin >> fNameR;
    cout << "\tПрiзвище: ";
    cin >> lNameR;
    cout << "\tEmail: ";
    cin >> emR;
    cout << "\tНомер: ";
    cin >> nR;
    cout << "\tПаспортнi данi: ";
    cin >> pdR;
    cout << "\tАдрес: ";
    cin >> adR;
    cout << "\tПосада: ";
    cin >> pR;
    cout << "\tЗарплата: ";
    cin >> sR;
    message();
}

void Representative::write_to_file(ofstream &file)
{
    file<<fNameR<<"\t"<<lNameR<<"\t"<<emR<<"\t"<<nR<<"\t"<<pdR<<"\t"<<adR<<"\t"<<pR<<"\t"<<sR<<endl;
}
void Representative::read_from_file(ifstream &file)
{
    file >> fNameR >> lNameR >> emR >> nR >> pdR >> adR >> pR >> sR;
}


void table_representative::print_all_representatives()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getRl(); /*cout<<endl;*/
    }
}

void table_representative::add_new_representative()
{
    Representative temp;
    temp.zdRepresentative();
    vec.push_back(temp);
}

int table_representative::search_representative(bool mozhna_povernutus)
{
    string firstNameR;
    string lastNameR;
    int id=-1;
    while(true)
    {
        cout << "\n\tIм'я: ";
        cin >> firstNameR;
        cout << "\tПрiзвище: ";
        cin >> lastNameR;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getfNameR()==firstNameR)&&(vec[i].getlNameR()==lastNameR))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\tПредставника не знайдено. Спробуйте ще раз." << endl;
                continue;
            }
            cout<<"\tПредставника не знайдено. Спробуйте ще раз |1|, або поверніться в попереднє меню |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_representative::poshuk()
{
    int id;
    id=search_representative();
    if(id!=-1)vec[id].getRl();
}

void table_representative::edit_representative()
{
    int id;
    id=search_representative();
    if(id!=-1)vec[id].zdRepresentative();
}

void table_representative::delete_representative()
{
    int id;
    id=search_representative();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\tПредставника видалено" <<endl;
    }
    else cout << "\tПредставника не видалено" <<endl;
}

void table_representative::write_representatives_to_file()
{
    ofstream fRepresentative("Representatives.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fRepresentative);//для кожного елемента викликати функцію яка записує у файл
    fRepresentative.close();
}

void table_representative::read_representatives_from_file()
{
    ifstream fRepresentative("Representatives.txt");
    if(fRepresentative.is_open())
    {
        Representative temp;
        while(!fRepresentative.eof())
        {
            temp.read_from_file(fRepresentative);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //видалення останнього об'єкта, бо його дублює
        fRepresentative.close();
    }

}

void table_representative::menu_representatives()
{
    while(1)
    {
        cout <<"\tВивести всiх представникiв------>|1|\n\tЗнайти представникiв------------>|2|\n\tДодати представеикiв------------>|3|\n\tРедагувати данi про представника>|4|\n\tВидалити представника----------->|5|\n\tВийти--------------------------->|6|" << endl;
        int inR;
        cin >> inR;
        switch(inR)
        {
        case 1:
            print_all_representatives();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_representative();
            break;
        case 4:
            edit_representative();
            break;
        case 5:
            delete_representative();
            break;
        case 6:
            return;
        }
    }
}


void Services::getSer() //функція для виведення на екран даних про клієнта
{
    cout<<"\n\tПослуга:    "<<services<<"\n\tЦiна:       "<<price<<endl;
}
void Services::zdServices() //функція яка вводитьз клаві
{
    cout << "\tВведiть данi про послугу\n";
    cout << "\tПослуга: ";
    cin >> services;
    cout << "\tЦiна: ";
    cin >> price;
    message();
}
void Services::write_to_file(ofstream &file)
{
    file<<services<<"\t"<<price<<endl;
}
void Services::read_from_file(ifstream &file)
{
    file >> services>>price;
}


void table_services::print_all_services()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getSer(); /*cout<<endl;*/
    }
}

void table_services::add_new_services()
{
    Services temp;
    temp.zdServices();
    vec.push_back(temp);
}

int table_services::search_services(bool mozhna_povernutus)
{
    string services;
    int id=-1;
    while(true)
    {
        cout << "\n\tПослуга: ";
        cin >> services;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getServices()==services))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\tПослугу не знайдено. Спробуйте ще раз." << endl;
                continue;
            }
            cout<<"\tПослугу не знайдено. Спробуйте ще раз |1|, або поверніться в попереднє меню |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_services::poshuk()
{
    int id;
    id=search_services();
    if(id!=-1)vec[id].getSer();
}

void table_services::edit_services()
{
    int id;
    id=search_services();
    if(id!=-1)vec[id].zdServices();
}

void table_services::delete_services()
{
    int id;
    id=search_services();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\tПослугу видалено" <<endl;
    }
    else cout << "\tПослугу не видалено" <<endl;
}

void table_services::write_services_to_file()
{
    ofstream fServices("Services.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fServices);//для кожного елемента викликати функцію яка записує у файл
    fServices.close();
}

void table_services::read_services_from_file()
{
    ifstream fServices("Services.txt");
    if(fServices.is_open())
    {
        Services temp;
        while(!fServices.eof())
        {
            temp.read_from_file(fServices);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //видалення останнього об'єкта, бо його дублює
        fServices.close();
    }
}

void table_services::menuServices()
{
    while(1)
    {
        cout <<"\n\tВивести всi послуги-------->|1|\n\tЗнайти послугу------------->|2|\n\tДодати послугу------------->|3|\n\tРедагувати данi про послугу>|4|\n\tВидалити послугу----------->|5|\n\tВийти---------------------->|6|" << endl;
        int inC;
        cin >> inC;
        switch(inC)
        {
        case 1:
            print_all_services();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_services();
            break;
        case 4:
            edit_services();
            break;
        case 5:
            delete_services();
            break;
        case 6:
            return;
        }
    }
}


void Order::getOrder() //функція для виведення на екран даних про клієнта
{
    cout<<"\n\tДата замовлення:        "<<orderData<<"\n\tДата видачі замовлення: "<<dataOfIssue<<endl;
    cout<<"\tIм'я клiєнта:           " << TABLE_CLIENT.vec[client_id].getfNameC()
        << "\n\tПрiзвище клiєнта:       " << TABLE_CLIENT.vec[client_id].getlNameC() << endl;
    cout<<"\tIм'я представника:      " << TABLE_REPRESENTATIVE.vec[representative_id].getfNameR()
        << "\n\tПрiзвище представника:  " << TABLE_REPRESENTATIVE.vec[representative_id].getlNameR() << endl;
    cout<<"\tПослуга:                " << TABLE_SERVICES.vec[service_id].getServices() << endl;
}
void Order::zdOrder() //функція яка вводитьз клаві
{
    cout << "\tВведiть данi про замовлення\n";
    cout << "\tДата замовлення: ";
    cin >> orderData;
    cout << "\tДата видачi замовлення: ";
    cin >> dataOfIssue;
    cout << "\tВведiть данi про клiєнта";
    client_id=TABLE_CLIENT.search_client(false);
    cout << "\tВведiть данi про представника";
    representative_id=TABLE_REPRESENTATIVE.search_representative(false);
    cout << "\tВведiть данi про послугу";
    service_id=TABLE_SERVICES.search_services(false);

    message();
}
void Order::write_to_file(ofstream &file)
{
    file<<orderData<<"\t"<<dataOfIssue<<"\t"<<client_id<<"\t"<<representative_id<<"\t"<<service_id<<endl;
}
void Order::read_from_file(ifstream &file)
{
    file >> orderData>>dataOfIssue>>client_id>>representative_id>>service_id;
}


void table_order::print_all_orders()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getOrder(); /*cout<<endl;*/
    }
}

void table_order::add_new_orders()
{
    Order temp;
    temp.zdOrder();
    vec.push_back(temp);
}

int table_order::search_orders()
{
    string orderData;
    int id=-1;
    while(true)
    {
        cout << "\n\tДата замовлення: ";
        cin >> orderData;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getOrderData()==orderData))id=i;
        }
        if(id==-1)
        {
            cout<<"\tЗамовлення не знайдено. Спробуйте ще раз |1|, або поверніться в попереднє меню |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_order::poshuk()
{
    int id;
    id=search_orders();
    if(id!=-1)vec[id].getOrder();
}

void table_order::edit_orders()
{
    int id;
    id=search_orders();
    if(id!=-1)vec[id].zdOrder();
}

void table_order::delete_orders()
{
    int id;
    id=search_orders();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\tЗамовлення видалено" <<endl;
    }
    else cout << "\tЗамовлення не видалено" <<endl;
}

void table_order::write_orders_to_file()
{
    ofstream fOrder("Order.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fOrder);//для кожного елемента викликати функцію яка записує у файл
    fOrder.close();
}

void table_order::read_orders_from_file()
{
    ifstream fOrder("Order.txt");
    if(fOrder.is_open())
    {
        Order temp;
        while(!fOrder.eof())
        {
            temp.read_from_file(fOrder);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //видалення останнього об'єкта, бо його дублює
        fOrder.close();
    }
}

void table_order::menuOrder()
{
    while(1)
    {
        cout <<"\n\tВивести всi замовлення-------->|1|\n\tЗнайти замовлення------------->|2|\n\tДодати замовлення------------->|3|\n\tРедагувати данi про замовлення>|4|\n\tВидалити замовлення----------->|5|\n\tВийти------------------------->|6|" << endl;
        int inO;
        cin >> inO;
        switch(inO)
        {
        case 1:
            print_all_orders();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_orders();
            break;
        case 4:
            edit_orders();
            break;
        case 5:
            delete_orders();
            break;
        case 6:
            return;
        }
    }
}
