

#include <iostream>
using namespace std;
unsigned __int16 x1, x11, x2, x22, result;
unsigned __int16 result1, result2, result3;
  void zadanie2() {
    
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

  void zadanie1() {
      cout << "enter n1 and n2:";
      cin >> x1 >> x2;
      __asm {
          //nww
          xor bx,bx
          xor AX, AX
          mov AX, x1
          push AX
          mov BX, x2
          mov CX, BX
   powrot:cmp AX, BX
          jb zmiana
          jne powrot1

          zmiana: 
          mov DX, AX
          mov AX, BX
          mov BX, DX
          xor DX, DX
          jmp powrot1

   powrot1:sub AX, BX
          cmp AX, 0
          jne powrot
          mov x11, BX
          jmp NWW

      NWW:pop AX
          mul CX
          div BX
          mov x22, AX
          
          //yesEnd: 
      }

      cout << "result NWD: " << x11 <<"\nNWW: " << x22 << endl;
  
  }

int main()
{
    

    zadanie2();
    //zadanie1();

}

