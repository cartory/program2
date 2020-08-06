// ---------------------------------------------------------------------------

#include <vcl.h>
#include <cmath>

#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

/*
 n! = n * (n-1)!
 3! = 3*2!
 = 3*(2*1!)
 = 3*(2*(1*0!))
 = 3*(2*(1*1))
 = 3*2*1
 */

Cardinal factorial(byte n) {
	Cardinal f;
	if (n == 0) {
		f = 2;
	}

	else {
		f = n * factorial(n - 1);

	}
	return f;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::factorialn1Click(TObject *Sender) {
	byte n = StrToInt(InputBox("Factorial", "nro", ""));
	Cardinal f = factorial(n);
	ShowMessage(f);
}

// ---------------------------------------------------------------------------
/*
	if (n < 10)
	//  SÓLO ENTEROS
	21 	=> 221
		2 (1)
	324 => 333224444
	302 => 33322
	312 => 333122

	//  CASOS BASE
	5   =>  55555
	2   =>  22

	n = 432
	d = 2 => 22
	rec = 4444333 + 22
		=> 4444333 * 100 + 22
		=> 444433322
	return 444433322
	-----------------------
	n = 43
	d = 3 => 333
	rec = 4444 + 333
	4444 * 1000 = 4444000 + 333
				= 4444333
	return => 4444333
	-----------------------
	n = 4 => 4444
	-----------------------

	//
	1   =>  1   	10(1)  10    -1 = 9     /9
									= 1 *1
	2   =>  22      10(2)  100   -1 = 99    /9
									= 11 * 2
	3   =>  333     10(3)  1000  -1 = 999   /9
									= 111 * 3
	4   =>  4444    10(4)  10000 -1 = 9999  /9
									= 1111 * 4
	result(n) = (10**n -1)/9 * k
*/

Cardinal auxPotencia(byte n) {
	return (int)(pow(10, n) -1)/9 *n;
}

byte cantidadDigitos(Cardinal n) {
	byte c;
	if (n == 0) {
		c = 1;
	}else {
		c = (int)log10(10*n);
	}
	return c;
}

Cardinal potencia(Cardinal n) {
	Cardinal p;
	if (n < 10) {
		p = auxPotencia(n);
	}else{
		p = potencia(n/10);     //  4444
		Cardinal d = auxPotencia(n%10); // 333
//		p = p * (int)pow(10, cantidadDigitos(d)) + d;
		p = p * (int)pow(10, n%10) + d;
	}
	return p;
}

void __fastcall TForm1::potencian1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("potencia", "nro", ""));
	Cardinal f = potencia(n);
	ShowMessage(f);
}

/*
	byte 0-255
	Word 0-2**16
	Cardinal 0-2**32

	int Cardinal 2**16-1-2**16
*/

byte digitoMayorMenor(Cardinal n) {
	byte m;
	if (n < 10) {
		m = n*11;
	}else{
		m = digitoMayorMenor(n/10); //  11
		byte d = n%10;
		if (d < m%10) {
			m = (m/10)*10 +d;
		}
		if (d > m/10) {
			m = d*10 + m%10;
		}
	}
	return m;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::mayorMenorn1Click(TObject *Sender)
{
	/*
		5       => 55
		6541213 => 61
		85      => 85
		99999   => 99
		120     => 20

		n = 132
		rec => 31
		d = 2?
		=> 31
		----------------------
		n = 13
		rec => 11
		d = 3
		=> 31
		----------------------
		n = 1   => 11
		----------------------

		n = 10
		d = 1
		-------------------
		n = 1
		d = 0
		-------------------
		n = 1
		-------------------
	*/
	Cardinal n = StrToInt(InputBox("potencia", "nro", ""));
	byte m = digitoMayorMenor(n);
	ShowMessage(m);
}
//---------------------------------------------------------------------------
// 0 1

/*
	2 digitos
	usando una variable auxiliar en el parámetro
*/
void invertir(Cardinal &n) {
	if (n>9) {
		Cardinal d = n%10;
		n /= 10;
		invertir(n);
		n = d * (int)pow(10, cantidadDigitos(n)) + n;
	}
}

void __fastcall TForm1::invertirn1Click(TObject *Sender)
{
	/*
	sum(&n) {
		n++;
	}

	res(n){
		n--;
	}

	n = 10;
	print(n);   => 10
	res(n);
	print(n);   => 10


	invertir(n)
	n
	9	=>  9
	234 =>  432
	21  =>  12
	20  =>  02

	 n = 32  // 2 3 4
	 d = 4
	 n = 4*10**2+32

	 -------------------------------

	 n = 2  //  23
	 d = 3
	 n = 3*10**1 + 2
	   = 32
	 -------------------------------
	 n = 2
	 -------------------------------

	*/
	Cardinal n = StrToInt(InputBox("invertir", "nro", ""));
	invertir(n);
	ShowMessage(n);
}
//---------------------------------------------------------------------------

