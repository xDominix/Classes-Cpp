#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"
/*
#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists()
*/


int Fraction::removedFractions_ = 0;

Fraction::Fraction(int x,int y,const string& name):fractionName{name}
{
    numerator= x;
    if(y==invalidDenominatorValue)  denominator=defaultDenominatorValue;
    else denominator=y;
}

void Fraction::load(std::istream& is)
{
    char buffer[256];
    long size;

    is.seekg(0,is.end);
    size=is.tellg();
    is.seekg(0);

    memset(buffer,32,sizeof(buffer ));

    is.read (buffer,size);

    char* subchar_array = strtok(buffer, "/");
    numerator = atoi(subchar_array);
    subchar_array = strtok(NULL, ":");
    denominator=atoi(subchar_array);
}

void Fraction::save(std::ostream& os) const 
{
    std::string str;
    str.append(std::to_string(numerator));
    str.append("/");
    str.append(std::to_string(denominator));
    
    os.write (str.c_str(),str.size());
}