#include<iostream>
#include<string.h>
//#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

struct productt
{

    int p_quantity;
    int p_price;
    string p_name;
};
struct productt computerr;
struct productt compu[100];
struct productt mobile_phon;
struct productt mob[100];
int mcount,ccount,t=1;

void log_in_system(int n)
{
    int password;
    string username;
    switch(n)
    {
    case 1:
    {
user1:
        cout<<"\nEnter your username :";
        cin>>username;
        if(username.compare("sakib")==0 && n==1)
        {
pass1:
            cout<<"\nEnter your password :";
            cin>>password;
            if(password!=1234)
            {
                cout<<"\nPassword is wrong !!!!>>>>>>Plese enter the correct password:";
                goto pass1;
            }
        }
        else
        {
            printf("\nUsername is wrong !!!!!!>>>>>>Put correct username:\n");
            goto user1;
        }
    }
    break;
    case 2:
    {
user2:
        cout<<"\nEnter your username :";
        cin>>username;
        if(username.compare("afzal")==0 && n==2)
        {
pass2:
            cout<<"Enter your password :";
            cin>>password;
            if(password!=4567)
            {
                cout<<"\nPassword is wrong !!!!>>>>>>>Plese enter the correct password:";
                goto pass2;
            }
        }
        else
        {
            printf("\nUsername is wrong !!!!!!>>>>>>>>Put correct username:\n");
            goto user2;
        }
    }
    break;
    }
}

int Display()
{
    int ch,i=0;
    cout<<"\n\n1. Computer accessories\n2. Mobile accessories\n\nEnter your choice :";
    cin>>ch;
    if(ch==1)
    {
        if(compu[i].p_name.length() == 0)
            cout<<"\nSorry!! No product are available!!!\n";
        else
        {
            cout<<"\n\n-------------          ---------        -----------\n"<<"Product Name\t\tPrice\t \tQuantity\n"<<"---------------          -------        ----------\n";
            while(i<ccount)
            {
                cout<<i+1<<". "<<compu[i].p_name<<"                 "<<compu[i].p_price<<"        "<<compu[i].p_quantity<<endl;
                i++;
            }
            return 1;
        }
    }
    else if(ch==2)
    {
        if(mob[i].p_name.length() == 0)
            cout<<"\nSorry!! No product are available!!!\n";
        else
        {
            cout<<"\n\n-------------          ---------        ----------\n"<<"Product Name\t\tPrice\t \t Quantity\n"<<"---------------          -------        ----------\n";
            while(i<mcount)
            {
                cout<<i+1<<". "<<mob[i].p_name<<"                 "<<mob[i].p_price<<"        "<<mob[i].p_quantity<<endl;
                i++;
            }
            return 2;
        }
    }
}

void add_product()
{
    int ch,cho;
    cout<<"1. Computer accessories\n2. Mobile accessories\n\nEnter your choice :";
    cin>>ch;
    if(ch==1)
    {
level2:
        fstream computer;
        computer.open("computer_details_pro.txt",ios::out|ios::app);
        cout<<"\n\nEnter product name :";
        // getline(cin,computerr.p_name);
        cin>>computerr.p_name;
        computer<<computerr.p_name<< endl;
        cin.ignore();
        computer.close();

        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::app);
        cout<<"\nEnter product price :";
        cin>>computerr.p_price;
        computerprice<< computerr.p_price <<endl;
        cin.ignore();
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::app);
        cout<<"\nEnter product quantity :";
        cin>>computerr.p_quantity;
        c_quan<< computerr.p_quantity <<endl;
        cin.ignore();
        c_quan.close();
        cout<<"\n\n1. Add more\n2. Don't add any more\nEnter your choice :";
        cin>>cho;
        if(cho==1)
            goto level2;
    }
    else if(ch==2)
    {
level22:
        fstream mobile;
        mobile.open("Mobilephone_details_pro.txt",ios::out|ios::app);
        cout<<"Enter product name :";
        getline(cin,computerr.p_name);
        cin>>mobile_phon.p_name;
        mobile<< mobile_phon.p_name << endl;
        cin.ignore();
        mobile.close();

        fstream mobilepri;
        mobilepri.open("Mobilephone_details_pri.txt",ios::out|ios::app);
        cout<<"Enter product price :";
        cin>>mobile_phon.p_price;
        mobilepri<< mobile_phon.p_price <<endl;
        cin.ignore();
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details.txt",ios::out|ios::app);
        cout<<"\nEnter product quantity :";
        cin>>computerr.p_quantity;
        m_quan<< computerr.p_quantity <<endl;
        cin.ignore();
        m_quan.close();
        cout<<"\n\n1. Add more\n2. Don't add any more\nEnter your choice :";
        cin>>cho;
        if(cho==1)
            goto level2;
    }
}
void update_product()
{
    int i,c,ch,uprice,uquan;
    cout<<"\nWhich product do you want to update :\n";
    ch=Display();
    cout<<"\nEnter the choice :";
    cin>>c;
    cout<<"\nEnter updated price :";
    cin>>uprice;
    cout<<"\nEnter updated quantity :";
    cin>>uquan;
    if(ch==1)
    {
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_price<<" are updated to "<<uprice<<">>>>>>>>>>\n";
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_quantity<<" quantity are updated to "<<uquan<<">>>>>>>>>>\n";
        compu[c-1].p_price=uprice;
        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computerprice<< compu[i].p_price << endl;
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            c_quan<< compu[i].p_quantity <<endl;
        cin.ignore();
        c_quan.close();

    }
    else if(ch==2)
    {
        cout<<"\n\n<<<<<<<<<"<<mob[c-1].p_price<<" are updated to "<<uprice<<">>>>>>>>>>\n";
        cout<<"\n\n<<<<<<<<<"<<compu[c-1].p_quantity<<" quantity are updated to "<<uquan<<">>>>>>>>>>\n";
        mob[c-1].p_price=uprice;
        fstream mobilepri;
        mobilepri.open("Mobilephone_details.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobilepri<<mob[i].p_price<<endl;
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            m_quan<< mob[i].p_quantity <<endl;
        m_quan.close();
    }
}
int delet_product()
{
    int i,ch,position;
    ch=Display();
    cout<<"\nWhich product do you want to delete :\n";
    cout<<"\nEnter the choice :";
    cin>>position;
    position=position-1;

    if(ch==1)
    {
        cout<<">>>>>"<<compu[position].p_name<<" are deleted <<<<<<\n";
        for(i=position; i<ccount; i++)
        {
            compu[i].p_name=compu[i+1].p_name;
            compu[i].p_price=compu[i+1].p_price;
            compu[i].p_quantity=compu[i+1].p_quantity;
        }
        ccount=ccount-1;
        return 1;
    }

    else if(ch==2)
    {
        cout<<">>>>>"<<mob[position].p_name<<" are deleted <<<<<<\n";
        for(i=position; i<ccount; i++)
        {
            mob[i].p_name=mob[i+1].p_name;
            mob[i].p_price=mob[i+1].p_price;
            mob[i].p_quantity=mob[i+1].p_quantity;
        }
        mcount=mcount-1;
        return 2;
    }

}

void store_data()
{
    int a,i=0;
    string myText;

    ifstream computerprice("computer_details_pri.txt");
    while(computerprice >> a)
    {
        compu[i].p_price=a;
        i++;
    }
    computerprice.close();
    ccount=i;

    i=0;
    ifstream computer("computer_details_pro.txt");
    while(getline(computer,computerr.p_name))
    {
        compu[i].p_name=computerr.p_name;
        i++;
    }
    computer.close();

    i=0;
    ifstream c_quan("computer_quantity_details.txt");
    while(c_quan >> a)
    {
        compu[i].p_quantity=a;
        i++;
    }
    c_quan.close();

    i=0;
    ifstream mobile("Mobilephone_details_pro.txt");
    while(getline(mobile,mobile_phon.p_name))
    {
        mob[i].p_name=mobile_phon.p_name;
        i++;
    }
    mobile.close();
    mcount=i;

    i=0;
    ifstream mobilepri("Mobilephone_details_pri.txt");
    while(mobilepri >> a)
    {
        mob[i].p_price=a;
        i++;
    }
    mobilepri.close();

    i=0;
    ifstream m_quan("Mobile_quantity_details.txt");
    while(m_quan >> a)
    {
        mob[i].p_quantity=a;
        i++;
    }
    m_quan.close();
}

void update_file(int a)
{
    int i;
    if(a==1)
    {
        fstream computer;
        computer.open("computer_details_pro.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computer<< compu[i].p_name << endl;
        computer.close();

        fstream computerprice;
        computerprice.open("computer_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            computerprice<< compu[i].p_price << endl;
        computerprice.close();

        fstream c_quan;
        c_quan.open("computer_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<ccount; i++)
            c_quan<< compu[i].p_quantity << endl;
        c_quan.close();
    }
    else
    {
        fstream mobile;
        mobile.open("Mobilephone_details_pro.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobile<<mob[i].p_name<<endl;
        mobile.close();

        fstream mobilepri;
        mobilepri.open("Mobilephone_details_pri.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            mobilepri<<mob[i].p_price<<endl;
        mobilepri.close();

        fstream m_quan;
        m_quan.open("Mobile_quantity_details.txt",ios::out|ios::trunc);
        for(i=0; i<mcount; i++)
            m_quan<< mob[i].p_quantity << endl;
        m_quan.close();
    }
}

int sort_display()
{
    int i,k,j,size;
    cout<<"1. Computer accesories\n2. Mobile accesories\nEnter your choice :";
    cin>>k;
    if(k==1)
    {
        size=ccount;
        for(j=0; j<size-1; j++)
        {
            for(i=0; i<size-1-j; i++)
            {
                if(compu[i].p_price>compu[i+1].p_price)
                {
                    swap(compu[i].p_price,compu[i+1].p_price);
                    compu[i].p_name.swap(compu[i+1].p_name);
                    swap(compu[i].p_quantity,compu[i+1].p_quantity);
                }
            }
        }
        cout<<"\n\n-------------          ---------        ----------\n"<<"Product Name\t\tPrice\t   \tQuantity\n"<<"---------------          -------        ----------\n";

        for(i=0; i<size; i++)
            cout<<i+1<<". "<<compu[i].p_name<<"                 "<<compu[i].p_price<<"        "<<compu[i].p_quantity<<endl;

        return 1;
    }
    else
    {
        size=mcount;
        for(j=0; j<size-1; j++)
        {
            for(i=0; i<size-1-j; i++)
            {
                if(mob[i].p_price>mob[i+1].p_price)
                {
                    swap(mob[i].p_price,mob[i+1].p_price);
                    mob[i].p_name.swap(mob[i+1].p_name);
                    swap(mob[i].p_quantity,mob[i+1].p_quantity);
                }
            }
        }
        cout<<"\n\n-------------          ---------        ----------\n"<<"Product Name\t\tPrice\t \t Quantity\n"<<"---------------          -------        ----------\n";

        for(i=0; i<size; i++)
            cout<<i+1<<". "<<mob[i].p_name<<"                 "<<mob[i].p_price<<"        "<<mob[i].p_quantity<<endl;

        return 2;
    }
}

void searchh()
{
    int i,j;
    cout<<"\n\n1. Computer accesories\n2. Mobile accesories\nEnter your choice :";
    cin>>i;
    if(i==1)
    {
        cout<<"\nEnter the product name :";
        cin>>computerr.p_name;
        for(j=0; j<ccount; j++)
        {
            if(computerr.p_name.compare(compu[j].p_name)==0)
            {
                cout<<"\n---------------------\nProduct found !!\nProduct name :"<<compu[j].p_name<<"\nPrice :"<<compu[j].p_price<<"\nQuantity :"<<compu[i].p_quantity<<endl<<endl;
                break;
            }
        }
    }
    else
    {
        cout<<"\n\nEnter the product name :";
        cin>>computerr.p_name;
        for(j=0; j<mcount; j++)
        {
            if(computerr.p_name.compare(mob[j].p_name)==0)
            {
                cout<<"\n----------------------\nProduct found !!\nProduct name :"<<mob[j].p_name<<"\nPrice :"<<mob[j].p_price<<"\nQuantity :"<<mob[i].p_quantity<<endl<<endl;
                break;
            }
        }
        if(j==mcount)
            cout<<"Sorry!!The product is no longer available..\n";
    }
}

int main()
{
    int choice[2],sum=0;
    cout<<"\t\t\t\t\t----------------------------------\n";
    cout<<"\t\t\t\t\tWelcome to Tech source Gadget Shop \n";
    cout<<"\t\t\t\t\t----------------------------------\n\n";
home:
    store_data();
    cout<<"\n\n1. Customer Interface\n2. Manager Interface\n3. Exit\n\nEnter your choice  :";
    cin>>choice[0];
    switch(choice[0])
    {
    case 1:
    {
        if(t==1)
        {
             log_in_system(1);
            t++;
        }
previous1:
        cout<<"\n1. Display Product\n2. Buy product \n3. Search product\n4. Exit\nEnter your choice :";
        cin>>choice[0];
        switch(choice[0])
        {
        case 1:
            cout<<"\n1. Sorted display\n2. Random display\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                sort_display();
            else
                Display();
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
            break;
        case 2:
        {
            sum=0;
            cout<<endl<<endl;
            int i=sort_display();
            cout<<"\n\nWhich product do you want to buy ?  ";
            cin>>choice[0];
            if(i==1 && compu[choice[0]-1].p_quantity>0 ||i==2 && mob[choice[0]-1].p_quantity>0)
            {
                cout<<"\nEnter the quantity :";
                cin>>choice[1];
                if(i==1)
                {
                    sum=sum+(choice[1]*compu[choice[0]-1].p_price);
                    cout<<"\n\n*****Total bill is  :"<<sum<<" BDT\n\n";
                    compu[choice[0]-1].p_quantity=compu[choice[0]-1].p_quantity - choice[1];
                    update_file(1);
                }
                else
                {
                    sum=sum+(choice[0]*mob[choice[0]-1].p_price);
                    cout<<"\n\n*****Total bill is  :"<<sum<<" BDT\n\n";
                    mob[choice[0]-1].p_quantity=mob[choice[0]-1].p_quantity - choice[1];
                    update_file(2);
                }



                fstream p_details;
                p_details.open("Person_details.txt",ios::out|ios::app);
                cout<<"\nEnter your name :";
                cin>>computerr.p_name;
                p_details<<"\n------------Person Details\n--------------\nName :"<< computerr.p_name << endl;
                cout<<"\nEnter your Address :";
                cin>>computerr.p_name;
                p_details<<"\nAddress :"<< computerr.p_name << endl;
                cout<<"\nEnter your Contact number :";
                cin>>computerr.p_name;
                p_details<<"\nContact number :"<< computerr.p_name <<endl;
                if(i==1)
                {
                    p_details<<"\nProduct name :"<< compu[choice[0]-1].p_name<<"\nQuantity :"<<choice[1]<<"\nTotal bill :"<<sum<<endl;
                }
                else
                    p_details<<"\nProduct name :"<< mob[choice[0]].p_name<<"\nQuantity :"<<choice[1]<<"\nTotal bill :"<<sum<<endl;
                cin.ignore();
                p_details.close();

                cout<<"\n\n*****Thanks for purchasing from us*********\n";
            }
            else
                    cout<<"\n\n!!!!Sorry,Sufficient product are not avaiable!!!!!\n";

            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
        }
        break;

        case 3:
            searchh();
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous1;
            break;
        case 4:
            cout<<"\n\n\t***********Thanks for visiting our shop*************\n\n";
            return 0;
            break;
        }
    }
    break;
    case 2:
    {
previous:
        if(t==1)
        {
             log_in_system(2);
            t++;
        }
        cout<<"\n1. Display\n2. Add new product\n3. Product Update\n4. Delete product \n\nEnter your choice  ";
        cin>>choice[0];
        switch(choice[0])
        {
        case 1:
            Display();
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 2:
            add_product();
            store_data();
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 3:
            update_product();
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
            break;
        case 4:
        {
            int d= delet_product();
            update_file(d);
            cout<<"\n\n1. Home page\n2. Previous page\n\nEnter your choice :";
            cin>>choice[1];
            if(choice[1]==1)
                goto home;
            else if(choice[1]==2)
                goto previous;
        }
        break;
        }
    }
    case 3:
        cout<<"\n\n\t***********Thanks for visiting our shop*************\n\n\n";
        return 0;
    }
}
