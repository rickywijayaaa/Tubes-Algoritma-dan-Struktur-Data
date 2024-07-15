#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord; // Deklarasi currentWord
Word currentCommand;

void IgnoreBlanks(){ 
    while (currentChar==BLANK || currentChar==ENTER){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar==BLANK){
        EndWord=true;
    }else{
        EndWord=false;
        ADVWORD();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void ADVWORD(){
    IgnoreBlanks () ;
    if (currentChar == MARK && !EndWord) {
        EndWord = true ;
    }else {
        CopyWord() ;
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i=0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) &&(currentChar != ENTER)){
        if (i<NMax){
            currentWord.TabWord[i] = currentChar ;
            i++;
        }ADV();
    }currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void startWFile(char *file){
    finish=false; 
    StartFile(file);
    copywFile();
}
/* I.S. : currentChar dalam file sembarang
   F.S. : Finish = true;
          atau Finish = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void copywFile(){
    int i=0; 
    while(currentChar!=ENTER && !finish){
        currentWord.TabWord[i]=currentChar;
        i++;
        advFile();
    }if (i>NMax){
        currentWord.Length = NMax;
    }else{
        currentWord.Length = i;
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void igBlankFile(){
    while(currentChar==BLANK){
        advFile();
    }
}
/* Mengabaikan satu atau beberapa BLANK pada file
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

void advNewlineFile(){
    Word EMPTY = {"", 0};
    currentWord=EMPTY;
    if(currentChar == ENTER){
        EndWord = false;
        advFile();
        copywFile();
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */


void advNewline(){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == ENTER){
        advFile();
        copywFile();
    }
}
/* I.S. : currentChar sembarang
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTCOMMAND () {
    Word empty = {"",0};
    currentCommand = empty;
    START();
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        ADVCOMMAND();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void ADVCOMMAND () {
    IgnoreDots();
    if (currentChar == ENTER && !EndWord) {
        EndWord = true;
    } else {
        CopyCommand();
        IgnoreDots();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyCommand () {
    int i;
    i = 0;
    while ((currentChar != MARK) && (currentChar != ENTER)) {
        if (i < NMax) {
            currentCommand.TabWord[i] = currentChar;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}
void IgnoreDots() {
    while (currentChar == BLANK || currentChar == '.') {
         advTerminal();
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
boolean isWordEqual(Word a, Word b) { 
    boolean cek=true;
    if (a.Length!=b.Length){
        return false;
    }else {
        for (int i=0;i<a.Length;i++){
            if (a.TabWord[i]!=b.TabWord[i]){
                cek=false;
            }
        }return cek;
    }
}

/*Fungsi yang mengembalikan true jika w1 = w2 dengan case insensitive*/
boolean isCharEqual(Word w1, Word w2){ // case insensitive
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] >= 65 && w1.TabWord[i] <= 90) w1.TabWord[i] += 32;
        if (w2.TabWord[i] >= 65 && w2.TabWord[i] <= 90) w2.TabWord[i] += 32;
        if (w1.TabWord[i] != w2.TabWord[i]) return false;
    }
    return true;
}

/* Mengembalikan true jika kata a dan b sama */
char* wordToString(Word word)
{
    char *str = (char *)malloc(sizeof(char) * word.Length);
    for (int i = 0; i < word.Length; i++)
    {
        str[i] = word.TabWord[i];
        if (i == word.Length - 1)
        {
            str[i + 1] = '\0';
        }
    }
    return str;
}
void displayWord(Word w)
{
    int i;
    for(i = 0; i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
}
/* Menampilkan kata  w */

int wordToInt(Word word) {
    int num, i;
    
    num = 0;

    for (i = 0; i < word.Length; i++)
    {
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num;
}
int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int panjangStr(char *str) // yang diakhiri enter
{
    int i = 0;
    while (str[i] != '\n')
    {
        i++;
    }
    return i;
}
boolean StrComp(char *str,char *str2){ 
    boolean cek=true;
    if (stringLength(str)!= stringLength(str2)){
        return false;
    }else{
        for (int i=0;i<stringLength(str);i++){
            if(str[i]!=str2[i]){
                cek=false;
            }
        }
    }return cek;
}

boolean StrComp2(char *str,char *str2,int x){ 
    boolean cek=true;
    for (int i=0;i<x;i++){
        if(str[i]!=str2[i]){
            cek=false;
        }
    }
    return cek;
}

void CreateWord(Word * w){
    w->Length = 0;
}

/*Word w sembarang*/
void assignWord(Word *w, char arr[], int len){
    CreateWord(w);
    for (int i = 0; i < len; i++){
        w->TabWord[i] = arr[i];
    }
    w->Length = len;
}
void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreLineNew()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == ENTER)
    {
        ADV();
    }
}


void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreLineNew();
    if (currentChar == BLANK) {
        EndWord = true;
    } else {
        EndWord = false;
        SalinSatuKata();
    }
}

void ADVKALIMAT(){
    IgnoreLineNew();
    Ignoreblanks();
    if (currentChar == MARK2) {
        EndWord = true;
    } else {
        EndWord = false;
        SalinKalimat();
    }
}

void SalinSatuKata() {
    ResetKalimat();  
    int i = 0 ;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        currentWord.TabWord[i] = currentChar;
        i += 1;
        ADV();
    }
    currentWord.Length = i;
}

void SalinKalimat() {
    ResetKalimat(); 
    int i = 0;
    while ((currentChar != MARK2) && (currentChar != ENTER) && (currentChar != EOF))
    {
        currentWord.TabWord[i] = currentChar;
        i+= 1;
        ADV();
    }
    currentWord.Length = i;
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(currentWord.TabWord); i++) {
        currentWord.TabWord[i] = '\0';
        currentWord.Length = 0;
    }
}

void PasteWord(Word source, Word * dest) {
    (*dest).Length = 0;

    for (int i = 0; i < source.Length; i++) {
        (*dest).TabWord[i] = source.TabWord[i];
        (*dest).Length++;
    }
}

Word takewordsemicolon(Word command, int colon){
    Word w;
    int i = 0;
    int j = 0;
    

    while (j != colon-1 && i < command.Length){
        if (command.TabWord[i] == ';'){
            j++;
        }
        i++;
        if (i == command.Length){
            j++;
        }
    }
    boolean chek = false;
    int length = 0;
    while (i < command.Length && !chek){
        if(command.TabWord[i] == ';'){
            chek = true;
        }
        else{
            w.TabWord[length] = command.TabWord[i];
            length++;
            i++;
        }
    }
    w.Length = length;
    return w;
}


void displayWordNewLine(Word w) {
    if (w.Length == 0) {
        printf("Kosong\n");
    }
    else {
        for (int i = 0; i < w.Length; i++) {
            printf("%c", w.TabWord[i]);
        }
        printf("\n");
    }
}

boolean IsWordSame(Word w, Word v) {
    boolean IsSame = true;
    if (w.Length != v.Length) {
        IsSame = false;
    }
    else {
        int i = 0;
        while (IsSame && i < w.Length) {
            if (w.TabWord[i] != v.TabWord[i]) {
                IsSame = false;
            }
            i++;
        }
    }
    return IsSame;
}


void CreateWord2(int length, char * string, Word * w) {
    (*w).Length = 0;
    for (int i = 0; i < length; i++) {
        (*w).TabWord[i] = * string;
        (*w).Length++;
        string++;
    }
}

Word takeword(Word command, int ke)
{
	Word w;
	int i = 0;
	int j = 0;
	while (j != ke - 1 && i < command.Length)
	{
		if (command.TabWord[i] == ' ')
		{
			j++;
		}
		i++;
		if (i == command.Length)
		{
			j++;
		}
	}
	boolean cek = false;
	int length = 0;
	while (i < command.Length && !cek)
	{
		if (command.TabWord[i] == ' ')
		{
			cek = true;
		}
		else
		{
			w.TabWord[length] = command.TabWord[i];
			length++;
			i++;
		}
	}
	w.Length = length;
	return w;
}



int stringToInt(char* input){
    return (input - "0");
}

Word SplitCommandWords(Word* kata1){
    Word kata2;
    int i = 0;
    while ((i < (*kata1).Length) && ((*kata1).TabWord[i] != ' ')){
        i++;
    }
    int x1 = i;

    int j = i + 1;
    i = 0;
    while ((j < (*kata1).Length) && ((*kata1).TabWord[j] != ' ')){
        (kata2).TabWord[i] = (*kata1).TabWord[j];
        i++;
        j++;
    } 

    (kata2).Length = i;
    return kata2;
}

char* currentWordtoFileName(Word w) {
    // char * file_name = "../save/saved1.txt";
    int folder_length = 7;
    char * folder = "./save/";
    char * s;
    s = (char *)malloc(sizeof(char) * (folder_length + w.Length -4));

    for (int i = 0; i < folder_length; i++) {
        s[i] = folder[i];
    }

    int j =5;
    for (int i = 0; i < w.Length-4; i++) {
        s[i+folder_length] = w.TabWord[j];
        j++;
    }
    s[w.Length + folder_length-4] = '\0';
    return s;
}

char* currentWordtoFileName2(Word w) {
    // char * file_name = "../save/saved1.txt";
    int folder_length = 7;
    char * folder = "./save/";
    char * s;
    s = (char *)malloc(sizeof(char) * (folder_length + w.Length ));

    for (int i = 0; i < folder_length; i++) {
        s[i] = folder[i];
    }

    for (int i = 0; i < w.Length; i++) {
        s[i+folder_length] = w.TabWord[i];
        
    }
    s[w.Length + folder_length] = '\0';
    return s;
}


int wordToIntload(Word word) {
    int num, i;
    
    num = 0;

    for (i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i]>='0' && word.TabWord[i] <= '9'){
            num = num * 10 + (word.TabWord[i] - '0');
        }
    }
    return num;
}