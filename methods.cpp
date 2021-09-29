#include "pch.h"
#include "class.h"
#include <string>

using namespace std;

//Composition - произведениме 
//Novel - роман
//Story - повесть
//Tale - рассказ
//Verse - стихотворение
//Poem - поема

string WriteComposition(Composition composition)
{
	switch (composition)
	{
	case Novel: return "Novel";
	case Story: return "Story";
	case Tale: return "Tale";
	case Verse: return "Verse";
	case Poem: return "Poem";
	}
	return "Error";
}

int Book::idPlus = 0;

Book::Book() : ID(idPlus++), Composition(Novel), Year(0) {}

Book::Book(const char* Title, const Composition composition, const int year) : ID(idPlus++), Composition(composition), Year(year)
{
	strcpy_s(cosnt_cast<char*>(this->Title), strlen(Title) + 1, Title);
	this->Year = year;
}

void Book::Clone(const Book& book)
{
	Year = book.Year;
}

void Book::SetYear(int year)
{
	Year = year;
}

char* Book::GetTitle() const
{
	char* temporary = new char[strlen(Title) + 1];
	strcpy(temporary, Title);
	return temporary;
}


Book& Book::operator = (const Book& book)
{
	if (this != &book)
	{
		Clone(book);
	}
	return *this;
}

bool Book ::operator == (const Book& book)
{
	if ((this->GetComposition()) == (book.GetComposition()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator << (ostream& out, Book& book)
{
	out << "Title of your book: " << book.GetTitle() << "ID of your book: " << book.GetID() << "Type of Composition: " << book.GetComposition() << "Year of your book: " << book.GetYear() << endl;
	return out;
}

Translation::Translation(const char* Title, const Composition composition, const int year, const char* language) : ID(idPlus++), Composition(composition), Year(year), Language(language) {}