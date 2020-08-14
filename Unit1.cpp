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

Cardinal factorial(byte n) {
	Cardinal f;
	if (n == 0) {
		f = 1;
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
 0 < n < 10
 auxPotencia(2) => 22
 auxPotencia(3) => 333
 auxPotencia(4) => 4444
 */
Cardinal auxPotencia(byte n) {
	return (int)(pow(10, n) - 1) / 9 * n;
}

Cardinal potencia(Cardinal n) {
	Cardinal p;
	if (n < 10) {
		p = auxPotencia(n);
	}
	else {
		p = potencia(n / 10);
		Cardinal d = auxPotencia(n % 10);
		p = p * (int)pow(10, n % 10) + d;
	}
	return p;
}

void __fastcall TForm1::potencian1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("Potencia", "nro", ""));
	Cardinal f = potencia(n);
	ShowMessage(f);
}

byte digitoMayorMenor(Cardinal n) {
	byte m;
	if (n < 10) {
		m = n * 11;
	}
	else {
		m = digitoMayorMenor(n / 10);
		byte d = n % 10;
		if (d < m % 10) {
			m = (m / 10) * 10 + d;
		}
		if (d > m / 10) {
			m = d * 10 + m % 10;
		}
	}
	return m;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::mayorMenorn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("DigitoMayorMenor", "nro", ""));
	byte m = digitoMayorMenor(n);
	ShowMessage(m);
}

// ---------------------------------------------------------------------------

byte cantidadDigitos(Cardinal n) {
	byte c;
	if (n == 0) {
		c = 1;
	}
	else {
		c = (int)log10(10 * n);
	}
	return c;
}

void invertir(Cardinal &n) {
	if (n > 9) {
		Cardinal d = n % 10;
		n /= 10;
		invertir(n);
		n = d * (int)pow(10, cantidadDigitos(n)) + n;
	}
}

void __fastcall TForm1::invertirn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("invertir", "nro", ""));
	invertir(n);
	ShowMessage(n);
}

// ---------------------------------------------------------------------------
void moverMayorFinal(Cardinal &n) {
	if (n > 9) {
		byte d = n % 10;
		n /= 10;
		moverMayorFinal(n);
		if (n % 10 > d) {
			n = (n / 10) * 100 + d * 10 + n % 10;
		}
		else {
			n = n * 10 + d;
		}
	}
}

byte digitoMayor(Cardinal n) {
	byte d;
	if (n < 10) {
		d = n;
	}
	else {
		d = digitoMayor(n / 10);
		if (n % 10 > d) {
			d = n % 10;
		}
	}
	return d;
}

void eliminarDigito(Cardinal &n, byte d, bool &elimino) {
	if (n > 0) {
		byte p = n % 10;
		n /= 10;
		eliminarDigito(n, d, elimino);
		if (elimino) {
			n = n * 10 + p;
		}
		else {
			if (p == d) {
				elimino = true;
			}
			else {
				n = n * 10 + p;
			}
		}
	}
}

byte sumaDigitosBinarios(byte a, byte b) {
	return (a + b) / 2 * 10 + (a + b) % 2;
}

Cardinal sumaBinaria(Cardinal a, Cardinal b, byte c = 0) {
	Cardinal s;
	byte d = sumaDigitosBinarios(a % 10, b % 10);
	d = (d / 10) * 10 + sumaDigitosBinarios(d % 10, c);
	if (a < 2 && b < 2) {
		s = d;
	}
	else {
		s = sumaBinaria(a / 10, b / 10, d / 10);
		s = s * 10 + d % 10;
	}
	return s;
}

void __fastcall TForm1::moverMayorFinal1Click(TObject * Sender) {
	Cardinal n = StrToInt(InputBox("invertir", "nro", ""));
	byte d = digitoMayor(n);
	bool elimino = false;
	eliminarDigito(n, d, elimino);
	n = n * 10 + d;
	// moverMayorFinal(n);
	ShowMessage(n);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::sumaBinariaab1Click(TObject *Sender) {
	Cardinal a = StrToInt(InputBox("Suma Binario", "A :", ""));
	Cardinal b = StrToInt(InputBox("Suma Binario", "B :", ""));
	Cardinal s = sumaBinaria(a, b);
	ShowMessage(s);
}
// ---------------------------------------------------------------------------

String w = "0123456789ABCDEF";

String DecimalBaseK(Cardinal n, byte k) {
	String s;
	if (n < k) {
		s = String(w[n + 1]);
	}
	else {
		s = DecimalBaseK(n / k, k) + w[n % k + 1];
	}
	return s;
}

void __fastcall TForm1::toBinn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("Decimal", "nro :", ""));
	byte k = StrToInt(InputBox("Base", "nro :", ""));
	String s = DecimalBaseK(n, k);
	ShowMessage(s);
}

// ---------------------------------------------------------------------------
void moverMenorFinal(Cardinal &n) {
	if (n > 9) {
		byte d = n % 10;
		n /= 10;
		moverMenorFinal(n);
		if (n % 10 < d) {
			n = (n / 10) * 100 + d * 10 + n % 10;
		}
		else {
			n = n * 10 + d;
		}
	}
}

void ordenar(Cardinal &n) {
	if (n > 9) {
		moverMenorFinal(n);
		byte d = n % 10;
		n /= 10;
		ordenar(n);
		n = n * 10 + d;
	}
}

void __fastcall TForm1::ordenarn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("Ordenar", "nro :", ""));
	ordenar(n);
	ShowMessage(n);
}

// ---------------------------------------------------------------------------
void invertir(String &x) {
	int n = x.Length();
	if (x != "") {
		if (n > 1) {
			wchar_t a = x[1];
			wchar_t b = x[n];
			x.Delete(n, 1);
			x.Delete(1, 1);
			invertir(x);
			x = String(b) + x + a;
		}
	}
}

void __fastcall TForm1::invertirn2Click(TObject *Sender) {
	/*
	 ""  =>      ""
	 a   =>      a
	 ab  =>      ba
	 abc =>      cba


	 x = abcd
	 a,d
	 x = cb
	 =>  d-cb-a
	 --------
	 x = bc
	 b,c
	 => c-""-b
	 --------
	 x = ""
	 x = "a"
	 */
	String x = InputBox("Invertir", "cad :", "");
	invertir(x);
	ShowMessage(x);
}

// ---------------------------------------------------------------------------
byte contarPalabras(String x) {
	byte c;
	if (x == "") {
		c = 0;
	}
	else if (x.Length() == 1) {
		c = 0;
		if (x[1] != ' ') {
			c++;
		}
	}
	else {
		c = 0;
		if (x[1] != ' ' && x[2] == ' ') {
			c++;
		}
		x.Delete(1, 1);
		c += contarPalabras(x);
	}
	return c;
}

void __fastcall TForm1::cantidadPalabrasx1Click(TObject *Sender) {
	/*
	 if (x[i] != ' ' y x[i+1] == ' ')
	 c++
	 x = hola_mundo_ ?? => 2
	 */
	String x = InputBox("ContarPalabras", "cad :", "");
	byte c = contarPalabras(x);
	ShowMessage(c);
}

// ---------------------------------------------------------------------------
bool esVocal(wchar_t z) {
	/*
	 z = m   >> w.Pos(z) = 0
	 z = p   >> w.Pos(z) = 0
	 z = A   >> w.Pos(z) = 6
	 z = a   >> w.Pos(z) = 1
	 */
	String w = "aeiouAEIOU";
	return w.Pos(z) > 0;
}

void eliminarVocales(String &x) {
	if (x != "") {
		wchar_t z = x[1];
		x.Delete(1, 1);
		eliminarVocales(x);
		if (!esVocal(z)) {
			x = String(z) + x;
		}
	}
}

void __fastcall TForm1::eliminarVocalesx1Click(TObject *Sender) {
	/*
	 ""  ==>     ""
	 "a" ==>     ""
	 "hola " =>   "hl "

	 x = ho_
	 c = h
	 c??esVocal
	 x=h_
	 ----------------
	 x = o_
	 c = o
	 c??esVocal
	 => x=_
	 ----------------
	 x = _
	 c = _
	 c??esVocal
	 => x=_
	 ----------------
	 x = ""
	 */
	String x = InputBox("EliminarVocales", "cad :", "");
	eliminarVocales(x);
	ShowMessage(x);
}

// ---------------------------------------------------------------------------
String palabraMasLarga(String x) {
	int n = x.Length();
	String palMax = "";
	if (n > 0) {
		int p = x.LastDelimiter(" ");
		String pal = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		palMax = palabraMasLarga(x);
		if (pal.Length() > palMax.Length()) {
			palMax = pal;
		}
	}
	return palMax;
}

void __fastcall TForm1::palabraMasLargax1Click(TObject *Sender) {
	/*
	 ""      =>  ""
	 hola    =>  hola
	 pedro mundo  =>  mundo
	 //
	 n = 10
	 p = 5
	 x = hola_mundo
	 p+1 = 6
	 n-p = 5
	 pal = mundo

	 x.setLength(4);
	 => x = hola
	 n = 4
	 x = hola mundo
	 x.setLength(3)  =>  x = hol
	 x.setLength(2)  =>  x = ho
	 x.setLength(1)  =>  x = h
	 x.setLength(0)  =>  x =
	 */
	String x = InputBox("Palabra+Larga", "cad :", "");
	String p = palabraMasLarga(x);
	ShowMessage(p);
}

// ---------------------------------------------------------------------------
bool estaOrdenadoAsc(Cardinal n) {
	bool h;
	if (n < 10) {
		h = true;
	}
	else {
		byte d = n % 10;
		n /= 10;
		// h = estaOrdenadoAsc(n) && !(n%10 > d);
		h = estaOrdenadoAsc(n);
		if (n % 10 > d) {
			h = false;
		}
	}
	return h;
}

bool estaOrdenadoDesc(Cardinal n) {
	bool h;
	if (n < 10) {
		h = true;
	}
	else {
		byte d = n % 10;
		n /= 10;
		// h = estaOrdenadoAsc(n) && !(n%10 > d);
		h = estaOrdenadoDesc(n);
		if (n % 10 < d) {
			h = false;
		}
	}
	return h;
}

void __fastcall TForm1::estaOrdenadon1Click(TObject *Sender) {
	/*
	 1234
	 1   =>  true
	 213 =>  false
	 123 =>  true
	 12  => true

	 n = 123
	 ---------------
	 n = 12
	 d = 3
	 h = true
	 if  d >= n %10
	 h = true
	 else
	 false
	 ---------------
	 n = 1   => true

	 */
	Cardinal n = StrToInt(InputBox("EstaOrdenado", "cad :", ""));
	bool ordenado = estaOrdenadoAsc(n) || estaOrdenadoDesc(n);
	ShowMessage(ordenado ? "true" : "false");
}
// ---------------------------------------------------------------------------

void eliminarPrimerLetra(String &x) {
	byte n = x.Length();
	if (n > 0) {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		eliminarPrimerLetra(x);
		if (w != "") {
			w.Delete(1, 1);
		}
		x = x + " " + w;
	}
}

void __fastcall TForm1::eliminarPrimerLetrax1Click(TObject *Sender) {
	String x = InputBox("Eliminar1erLetra", "cad :", "");
	eliminarPrimerLetra(x);
	ShowMessage(x);
}
// ---------------------------------------------------------------------------

void invertirPalabras(String &x) {
	byte n = x.Length();
	if (n > 0) {
		byte p = x.LastDelimiter(" ");
		String w = x.SubString(p + 1, n - p);
		x.SetLength(p - 1);
		invertirPalabras(x);
		invertir(w);
		x = x + " " + w;
	}
}

void __fastcall TForm1::invertirPalabras1Click(TObject *Sender) {
	String x = InputBox("Invertir Palabras", "cad :", "");
	invertirPalabras(x);
	ShowMessage(x);
}

// ---------------------------------------------------------------------------
Cardinal fibonacci(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return t;
}

void __fastcall TForm1::fibonaccit1Click(TObject *Sender) {
	Word t = StrToInt(InputBox("Invertir Palabras", "cad :", ""));
	Cardinal fibo = fibonacci(t);
	ShowMessage(fibo);
}
// ---------------------------------------------------------------------------

Cardinal serie1(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = serie1(n - 1);
		if (n % 2 == 0) {
			t *= 2;
		}
		else {
			t++;
		}
	}
	return t;
}

void __fastcall TForm1::serie1t1Click(TObject *Sender) {
	Word n = StrToInt(InputBox("Invertir Palabras", "cad :", ""));
	Cardinal t = serie1(n);
	ShowMessage(t);
}

// ---------------------------------------------------------------------------
Cardinal sumaSerie(Word n) {
	Cardinal s;
	if (n < 2) {
		s = 0;
	}
	else {
		s = sumaSerie(n - 1);
		s += (n - 1)*2;
	}
	return s;
}

void __fastcall TForm1::sumaSerien1Click(TObject *Sender) {
	Word n = StrToInt(InputBox("Invertir Palabras", "cad :", ""));
	Cardinal s = sumaSerie(n);
	ShowMessage(s);
}

// ---------------------------------------------------------------------------
Cardinal serie2(Word n) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		t = serie2(n - 1) * 2 + 1;
	}
	return t;
}

void __fastcall TForm1::serie2n1Click(TObject *Sender) {
	Word n = StrToInt(InputBox("Invertir Palabras", "cad :", ""));
	Cardinal s = serie2(n);
	ShowMessage(s);
}

// ---------------------------------------------------------------------------
Cardinal sumaSerie2(Word n, Cardinal &s) {
	Cardinal t;
	if (n < 2) {
		t = n;
	}
	else {
		if (n % 3 == 0) {
			t = sumaSerie2(n - 1, s) + 2;
		}
		else if (n % 3 == 1) {
			t = sumaSerie2(n - 1, s) + 1;
		}
		else {
			t = sumaSerie2(n - 1, s) * 2;
		}
		if (t % 2 == 0) {
			s += t;
		}
	}
	return t;
}

void __fastcall TForm1::sumaSerie2n1Click(TObject *Sender) {
	Word n = StrToInt(InputBox("Suma Serie2", "cad :", ""));
	Cardinal s = 0;
	Cardinal t = sumaSerie2(n, s);
	ShowMessage(s);
}

// ---------------------------------------------------------------------------
byte cantidadPares(Cardinal n) {
	byte c;
	if (n < 10) {
		c = (n % 2 == 0) ? 1 : 0;
	}
	else {
		c = cantidadPares(n / 10) + cantidadPares(n % 10);
	}
	return c;
}

void __fastcall TForm1::DigitosParesn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("Cantidad Digitos Pares", "cad :", ""));
	byte c = cantidadPares(n);
	ShowMessage(c);
}

// ---------------------------------------------------------------------------
Word sumaPares(Cardinal n) {
	Word s;
	if (n < 10) {
		s = (n % 2 == 0) ? n : 0;
	}
	else {
		s = sumaPares(n / 10) + sumaPares(n % 10);
	}
	return s;
}

void __fastcall TForm1::SumaDigitosParesn1Click(TObject *Sender) {
	Cardinal n = StrToInt(InputBox("Cantidad Digitos Pares", "cad :", ""));
	Word s = sumaPares(n);
	ShowMessage(s);
}
// ---------------------------------------------------------------------------
