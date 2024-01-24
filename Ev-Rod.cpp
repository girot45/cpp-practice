#include <iostream>        
#include <assert.h>       
#include <conio.h>
#include <bitset>
#define B 16   
#define FG 3    
#define N 10000 
   using namespace std;
   string create_evrod (int);
   int decod_evrod (string);
   void test(int);
   // --------------------

int main()
{
   int num, menu;
   string evrod;

   cout << "-------------------------------" << "\n";
   cout << "1) Кодирование кодом Ивэн-Родэ" << "\n";
   cout << "2) Декодирование кода Ивэн-Родэ" << "\n";
   cout << "3) Тестирование" << "\n";
   cout << "------------------------------" << "\n";
   cout << "Введите номер пункта: ";
   cin >> menu;
   assert(menu==1 || menu==2 || menu==3);

   if(menu==1)
   {
      cout << "Введите натуральное число: ";
      cin >> num;
      
      evrod = create_evrod(num);
      assert(num == decod_evrod(evrod));
      cout << "Полученный код: " << evrod << endl;
   }
   else if(menu==2)
      {
         cout << "Введите код Ивэн-Родэ: ";
         cin >> evrod;
         
         num = decod_evrod(evrod);
         assert(evrod == create_evrod(num));
         cout << "Закодированное число: " << num << endl;
      }
      else
         {
            for(num=0; num<=N; num++)
               test(num); 
         }

   cout << "Тест неудачен!";
   getch();
   return 0;
}


string create_evrod (int n)
{
   bitset <B> bit, b_ln;
   string c_evrod="", s_bit="";
   int i, ln;

   if(n<4 && n>=0)
   {
      bit = n;
      for(i=FG-1; i>=0; i--)
         c_evrod += bit[i] + '0';
   }
   else if(n>=4)
   {
      bit = n;
      for(i=B-1, ln=B; bit[i]!=1; i--, ln--);
      for( ; ln>=3; s_bit="")
      {
         for(i=ln-1; i>=0; i--)
            s_bit += bit[i] + '0';
         bit = ln;
         for(i=B-1, ln=B; bit[i]!=1; i--, ln--);
         c_evrod = s_bit + c_evrod;
      }  
      c_evrod += "0";
   }

   return c_evrod;
}


int decod_evrod (string c_evrod)
{
   int ln, n;
   bitset <B> s_bit;

   ln = c_evrod.length();
   if(ln==FG)
   {
      bitset <B> bit(c_evrod);
      ln = bit.to_ulong();
   }
   else if(ln>FG)
   {
      ln = FG;
      while(n>1)
      {
         for(; ln!=0; ln--)
         {
            s_bit[ln-1] = c_evrod[0] - '0';
            c_evrod.erase(0, 1);
         }
         
         ln = s_bit.to_ulong();
         n = c_evrod.length();
      }
   }

   return ln;
}


void test(int n)
{
   int num;
   string evrod;

   evrod = create_evrod(n);
   assert(n == decod_evrod(evrod));
   num = decod_evrod(evrod);
   assert(evrod == create_evrod(num));
   
}