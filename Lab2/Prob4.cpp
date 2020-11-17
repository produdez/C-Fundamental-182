#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
main()
{
    ifstream data;
    data.open("prod.info",ifstream::in);
    string line;
    string code[5];
    string prodName[5];
    float price[5];
    int quantity[5];
    int number=0;
    if (data)
    {
    getline(data,line);
    while(!data.eof())
    {
        data>>code[number]>>prodName[number]>>price[number]>>quantity[number];
        number++;
    }
#ifdef DEBUG
 for (int i=0;i<number;i++)
 {
    cout<<setw(5)<<code[i]<<setw(20)<<prodName[i]<<setw(20)<<price[i]<<setw(20)<<quantity[i]<<"\n";
 }
#endif // DEBUG
     data.close();
     int buy_quan;
     string buy_code;
     cout<<"Input the product code and quantity : ";
     cin>>buy_code>>buy_quan;
    bool in_data=false;
     while(!cin.good()||buy_quan==0||!in_data)
     {
         while(!cin.good())
         {
             cout<<"Error Input\n";
             cout<<"Input again: ";
             cin.clear();
             cin.ignore(1000,'\n');
             cin>>buy_code>>buy_quan;
         }
         while(buy_quan==0)
         {
             cout<<"You cant buy nothing!\n Input quantity again:";
             cin.ignore(1000,'\n');
             cin>>buy_quan;
              while(!cin.good())
         {
             cout<<"Error Input\n";
             cout<<"Input again: ";
             cin.clear();
             cin.ignore(1000,'\n');
             cin>>buy_quan;
         }
         }
         for (int i=0; i<number;i++)
         {
             if(buy_code==code[i])
             {
                 in_data=true;
             }
         }
         if (!in_data)
         {
             cout<<"Your product does not exist in our database:\n Please Input again: ";
             cin.clear();
             cin.ignore(1000,'\n');
             cin>>buy_code>>buy_quan;
        }
    }

  for (int x=0; x<number;x++)
  {
      if(buy_code==code[x])
      {
          if (quantity[x]==0)
          {
              cout<<"Out of Stock!! \n";
          }else if(buy_quan>quantity[x])
          {
              cout<<"Not enough product available for your purchase!!\n Only "<<quantity[x]<<" left..!";
          }else
          {
              cout<<"Product available for purchase!!\n";
              cout<<"You have bought: "<<buy_quan<<"\n";
              cout<<"Product price tag: "<<price[x]<<"\n";
              cout<<"Total bill: "<<price[x]*buy_quan<<"\n";
          }
      }
  }
    }else {cout<<"Cant read file data opened!";}




}
