//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *ENTEROS1;
	TMenuItem *CADENAS1;
	TMenuItem *SERIES1;
	TMenuItem *VECTORES1;
	TMenuItem *MATRICES1;
	TMenuItem *factorialn1;
	TMenuItem *potencian1;
	TMenuItem *mayorMenorn1;
	TMenuItem *invertirn1;
	TMenuItem *moverMayorFinal1;
	TMenuItem *sumaBinariaab1;
	TMenuItem *toBinn1;
	TMenuItem *ordenarn1;
	TMenuItem *invertirn2;
	TMenuItem *cantidadPalabrasx1;
	TMenuItem *eliminarVocalesx1;
	TMenuItem *palabraMasLargax1;
	TMenuItem *estaOrdenadon1;
	TMenuItem *eliminarPrimerLetrax1;
	TMenuItem *invertirPalabras1;
	TMenuItem *fibonaccit1;
	TMenuItem *serie1t1;
	TMenuItem *sumaSerien1;
	TMenuItem *serie2n1;
	TMenuItem *sumaSerie2n1;
	TMenuItem *DigitosParesn1;
	TMenuItem *SumaDigitosParesn1;
	void __fastcall factorialn1Click(TObject *Sender);
	void __fastcall potencian1Click(TObject *Sender);
	void __fastcall mayorMenorn1Click(TObject *Sender);
	void __fastcall invertirn1Click(TObject *Sender);
	void __fastcall moverMayorFinal1Click(TObject *Sender);
	void __fastcall sumaBinariaab1Click(TObject *Sender);
	void __fastcall toBinn1Click(TObject *Sender);
	void __fastcall ordenarn1Click(TObject *Sender);
	void __fastcall invertirn2Click(TObject *Sender);
	void __fastcall cantidadPalabrasx1Click(TObject *Sender);
	void __fastcall eliminarVocalesx1Click(TObject *Sender);
	void __fastcall palabraMasLargax1Click(TObject *Sender);
	void __fastcall estaOrdenadon1Click(TObject *Sender);
	void __fastcall eliminarPrimerLetrax1Click(TObject *Sender);
	void __fastcall invertirPalabras1Click(TObject *Sender);
	void __fastcall fibonaccit1Click(TObject *Sender);
	void __fastcall serie1t1Click(TObject *Sender);
	void __fastcall sumaSerien1Click(TObject *Sender);
	void __fastcall serie2n1Click(TObject *Sender);
	void __fastcall sumaSerie2n1Click(TObject *Sender);
	void __fastcall DigitosParesn1Click(TObject *Sender);
	void __fastcall SumaDigitosParesn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
