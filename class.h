#pragma once
#define _CRT_SECURE_NO_WARNING
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Composition - произведениме 
//Novel - роман
//Story - повесть
//Tale - рассказ
//Verse - стихотворение
//Poem - поема

enum Composition { Novel, Story, Tale, Verse, Poem };
string WriteComposition(Composition composition);

class Book
{
protected:
	const char* Title;
	const int ID;
	Composition composition;
	int Year;
	Book();
	void Clone(const Book& book);
	//void Erase();
public:
	static int idPlus;
	
	Book(const char* Title, const Composition composition, const int year);

	void SetYear(int year);

	int GetYear() const { return Year; }
	char* GetTitle() const;
	int GetID() const { return ID; }
	Composition GetComposition() const { return composition; }

	void SetTitile(char*);
	void SetComposition(Composition comp) { composition = comp; }

	virtual Book& operator = (const Book&);
	bool operator == (const Book& book);

	friend ostream& operator << (ostream& out, Book& book);
};

class Translation : public Book
{
private:
	char* Language;
public:
	Translation(const char* Title, const Composition composition, const int year, const char* language);
	explicit Translation(const Book& book);

	char* GetLanguage() const;

	virtual Translation& operator = (const Translation&);
	bool operator == (Book& book);

	friend ostream operator << (ostream& out, Translation& book);
};
