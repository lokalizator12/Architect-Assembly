

#include <iostream>
using namespace std;
unsigned __int16 x1, x11, x2, x22, result;
unsigned __int16 result1, result2, result3;

void zadanie1() {
    cout << "enter n1 and n2:";
    cin >> x1 >> x2;
    __asm {
        //nww
        xor bx, bx
        xor AX, AX
        mov AX, x1
        push AX
        mov BX, x2
        mov CX, BX
        powrot : cmp AX, BX
        jb zmiana
        jne powrot1

        zmiana :
        mov DX, AX
            mov AX, BX
            mov BX, DX
            xor DX, DX
            jmp powrot1

            powrot1 : sub AX, BX
            cmp AX, 0
            jne powrot
            mov x11, BX
            jmp NWW

            NWW : pop AX
            mul CX
            div BX
            mov x22, AX

            //yesEnd: 
    }

    cout << "result NWD: " << x11 << "\nNWW: " << x22 << endl;

}

  void zadanie2a() {
    
     cout << "enter n1 and n2:"<< endl;
     cin >> x1 >> x11 >> x2 >> x22;
    __asm {
       
       xor DX, DX
       xor AX, AX
       xor BX, BX
       mov AX, x11
       push AX//1ax
       push AX//2ax
       push AX//3ax
       
       mov BX, x22
       mov CX, BX
       cmp BX, AX
       je rowne
       jne rozne

       rowne: 
       mov result1, BX
       xor AX, AX
       xor BX, BX
       mov AX, x1
       mov BX, x2
       add AX, BX
       mov result, AX
       jmp koniec

    rozne: xor bx, bx
           xor AX, AX
           pop AX//11ax
           mov BX, x22
           powrot : cmp AX, BX
           jb zmiana
           jne powrot1

           zmiana :
           mov DX, AX
           mov AX, BX
           mov BX, DX
           xor DX, DX
           jmp powrot1

           powrot1 : sub AX, BX
           cmp AX, 0
           jne powrot
           mov x11, BX
           jmp NWW

           NWW : pop AX//22ax
           mul CX
           div BX
           mov result1, AX
           push AX//nww
           div CX
           mov CX, x2
           mul CX
           mov BX, AX // 14
           mov result2, AX//7
           pop AX
           pop CX
           div CX
           mov CX, x1
           mul CX
           add AX, BX
           mov result3, AX//6
           
        continu: 



       koniec:
       //yesEnd: 
    }

    cout <<"result sum:\n" << result <<"\n-\n"<< result1 <<"\n albo \n" << result3 << "\n--\n" << result1 << endl;
}

  void zadanie2b() {
      cout << "enter n1 pomnozony przez n2:" << endl;
      cin >> x1 >> x11 >> x2 >> x22;

          
      __asm {
          
          xor AX, AX
          xor BX, BX
          xor CX, CX
          mov AX, x11 
          mov BX, x22
          mul BX
          mov result1, AX
          xor AX, AX
          xor BX, BX
          mov AX, x1
          mov BX, x2
          mul BX
          mov result, AX
      }

      cout <<"result: \n"<< result << "\n--\n" << result1 << endl;
  }
  
  void zadanie2c() {
      cout << "enter n1 pomnozony przez n2:" << endl;
      cin >> x1 >> x11 >> x2 >> x22;

      __asm {
          xor AX, AX
          xor BX, BX
          mov AX, x1
          mov BX, x22
          mul BX
          mov result, AX
          xor AX, AX
          xor BX, BX
          mov AX, x11
          mov BX, x2
          mul BX
          mov result1, AX

      }
      cout << "result: \n" << result << "\n--\n" << result1 << endl;
  }

  void zadanie5() {
      unsigned __int16 x4;
      
      unsigned __int16 x3 = 0;
      __int16 n = 4;
      __int16 klop[] = { 4, 5, 6, 4 };
      __int16 sum = 0;
          
          __asm {

             xor AX, AX
             xor BX, BX
             xor CX, CX
             xor DX,DX
             mov DX, 5
             mov CX, n
      powrot:mov BX, sum
             mov AX, [klop]
             div DX
             cmp AX, 0
             jne added
    endAdded:cmp CX, 0
             je koniec
             dec CX
             inc [klop]
             jmp powrot

       added:add BX, AX
             jmp endAdded

       koniec:mov x22, BX
          } 
          cout << x22 << endl;
      
  }

  void zadanie3() {
      __int16 stosz[] = {0,2,3,0,0,5}; 

      __int16 sum = 0;
      __asm {
          xor bx, bx
          xor ax, ax
          xor dx, dx
          xor cx, cx
          mov dx, 6
          mov bx, 0
          mov ax, [stosz]
          add bx, ax
          mov ax, [stosz+1]
          add bx, ax
          mov ax, [stosz+2]
          add bx, ax
          mov ax, [stosz+3]
          add bx, ax
          mov sum, bx
          
      }
      cout << sum;
  }
  
int main()
{
    zadanie3();
    //TEST();
    //zadanie5();//integer overflow
    //zadanie2c();
   // zadanie2b();
   // zadanie2a();
    //zadanie1();

}

