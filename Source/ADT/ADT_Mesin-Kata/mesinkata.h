/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../ADT_MesinKarakter/mesinkarakter.h"

#define NMax 450
#define BLANK ' '
#define ENTER '\n'
#define MARK ';'
#define MARK2 '\0'

typedef struct
{
   char TabWord[NMax+1]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord; // Deklarasi currentWord
extern Word currentCommand;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void startWFile(char *file);
/* I.S. : currentChar dalam file sembarang
   F.S. : Finish = true;
          atau Finish = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void copywFile();
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void igBlankFile();
/* Mengabaikan satu atau beberapa BLANK pada file
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

void advNewlineFile();
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */


void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void advNewline();
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ ENTER atau currentChar = MARK */

void STARTCOMMAND ();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND ();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyCommand ();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void IgnoreDots ();
/* Mengabaikan satu atau beberapa titik
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar ≠ '.' */

boolean isWordEqual(Word a, Word b);
/* Mengembalikan true jika kata a dan b sama */

boolean isCharEqual(Word w1, Word w2); // case insensitive

char* wordToString(Word w);
/* Mengubah kata menjadi string */

void displayWord(Word w);
/* Menampilkan kata  w */

void displayWordNewLine(Word w);

int wordToInt(Word w);
/* Mengubah kata menjadi integer */

int stringLength(char *str);
/* Mengembalikan panjang string */

boolean StrComp(char *str,char *str2);
/*Mengembalikan true jika char str dan str1 sama*/

boolean StrComp2(char *str,char *str2,int x);
// Compare string tapi panjangnya bisa disesuaikan

void CreateWord(Word *w);

void assignWord(Word *w, char arr[], int len);

void SalinSatuKata();

void SalinKalimat();

void ADVKALIMAT();

void ADVSATUKATA();

void Ignoreblanks();

void IgnoreLineNew();

void ResetKalimat() ;

void PasteWord(Word source, Word * dest);

Word takewordsemicolon(Word command, int colon);

void CreateWord2(int length, char * string, Word * w);

boolean IsWordSame(Word w, Word v);

Word takeword(Word command, int ke);

int stringToInt(char* input);

Word SplitCommandWords(Word* kata1);

char* currentWordtoFileName(Word w);

char* currentWordtoFileName2(Word w);

int wordToIntload(Word word) ;


#endif
