

#include <iostream>
using namespace std;
unsigned __int8 x1111;
unsigned __int16 x1, x11, x2, x22, x3, x33, result, result1, result2, result3 , sum = 0;
unsigned __int32 n;
__int16 ti3[] = { 10,20,5,5 }, ti4[1024];


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
    }

    cout << "result NWD: " << x11 << "\nNWW: " << x22 << endl;

}

void zadanie2() {

    cout << "enter n1 and n2:" << endl;
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

        rowne :
        mov result1, BX
            xor AX, AX
            xor BX, BX
            mov AX, x1
            mov BX, x2
            add AX, BX
            mov result, AX
            jmp koniec

            rozne : xor bx, bx
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

            koniec :
    }

    cout << "result sum:\n" << result << "\n-\n" << result1 << "\n albo \n" << result3 << "\n--\n" << result1 << endl;

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
    cout << "result: \n" << result << "\n--\n" << result1 << endl;


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
    __int16 klop[] = { 4, 4, 5, 6, 4 };
    __int16 sum = 0;

    __asm {
        xor AX, AX
        xor BX, BX
        xor CX, CX
        xor DX, DX
        mov DX, 5 // to przez co dzielimy
        mov CX, [klop]//liczba zmiennych 
        inc[klop]// skok na pierwszy index z (4)
        powrot:mov BX, sum // suma do BX (0)
        mov AX, [klop]// 4 do akUmulatorA
        div DX // dzielenie pierwszej liczby przez 5
        cmp AX, 0 // czy jest podzielny przez 5?
        jne added // jezeli nie to sum =+ ax
        endAdded : cmp CX, 0 // - kilkaść liczb
        je koniec
        dec CX
        inc[klop]
        jmp powrot

        added : add BX, AX // 
        jmp endAdded

        koniec : mov x22, BX
    }
    cout << x22 << endl;

}

void zadanie3() {
    __int16 stosz[] = { 0,2,3,0,0,5 };

    cout << " liczby: " << stosz << endl;
    __int16 sum = 0;
    __asm {
        xor bx, bx
        xor ax, ax
        xor dx, dx
        xor cx, cx
        mov dx, 6
 powrot:mov ax, [stosz]
        add bx, ax
        inc stosz
        xor ax, ax
        cmp dx, 0
        je koniecSum
        dec dx
        jmp powrot


        koniecSum:mov AX, bx
        mov bx, 6
        div bx
        mov result1, AX
        mov result2, AH
        jmp koniec 

        koniec:
    }
    cout << result1<< "," << result2 << endl;
}

void zadanie4() {
    
        cout << "1 czynnik:" << endl;
        cin >> x1 >> x11;

        cout << "2 czynnik:" << endl;
        cin >> x2 >> x22;

        cout << "3 czynnik:" << endl;
        cin >> x3 >> x33;
    
        __asm {

            //suma
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

          rowne:mov result1, BX
                xor AX, AX
                xor BX, BX
                mov AX, x1
                mov BX, x2
                add AX, BX
                mov result, AX
                jmp koniec

                rozne : xor bx, bx
                xor AX, AX
                pop AX//11ax
                mov BX, x22
                powrot : cmp AX, BX
                jb zmiana
                jne powrot1

         zmiana:mov DX, AX
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

                koniec :
                xor DX, DX
                push AX//1ax//x11+x22
                push AX//2ax
                push AX//3ax
                push BX//1bx//x1+x2

                mov BX, x33
                mov CX, BX
                cmp BX, AX
                je rowne
                jne rozne

          rowne:mov result1, BX
                xor AX, AX
                xor BX, BX
                pop BX//11
                mov AX, BX
                xor BX, BX
                mov BX, x3
                add AX, BX
                mov result, AX
                jmp koniec

                rozne : xor bx, bx
                xor AX, AX
                pop AX//11ax
                mov BX, x22
                powrot : cmp AX, BX
                jb zmiana
                jne powrot1

         zmiana:mov DX, AX
                mov AX, BX
                mov BX, DX
                xor DX, DX
                jmp powrot1

        powrot1:sub AX, BX
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

        koniec:

        }


}


int main()
{

   //zadanie3();//integer overflow
   // zadanie5();//integer overflow
   // zadanie2();
   //zadanie1();

}

