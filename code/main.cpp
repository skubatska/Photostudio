#include "header.h"
#include <windows.h>

table_client TABLE_CLIENT;
table_services TABLE_SERVICES;
table_representative TABLE_REPRESENTATIVE;
table_order TABLE_ORDER;

int main(int argc, char* argv[])
{
    system("chcp 1251 >nul");
    setlocale(LC_ALL, "Ukr");
    cout<<"                             =====PHOTO STUDIO=====\n\n";

    while(1)
    {
        cout <<"\n\tКлiєнти|1|, Послуги|2|, Представники|3|, Замовлення|4|, Вийти|5|" << endl;
        int inC;
        cin >> inC;
        switch(inC)
        {
        case 1:
            TABLE_CLIENT.menu();
            break;
        case 2:
            TABLE_SERVICES.menuServices();
            break;
        case 3:
            TABLE_REPRESENTATIVE.menu_representatives();
            break;
        case 4:
            TABLE_ORDER.menuOrder();
            break;
        case 5:
            return 0;
            // break;
        }
    }

    return 0;
}
