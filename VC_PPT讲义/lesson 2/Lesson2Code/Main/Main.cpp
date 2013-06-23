#include <iostream>
#include "Animal.h"
#include "Fish.h"
#include <stdlib.h>

using namespace std;

void fn(Animal *pAn)
{
	pAn->breathe();
}


void main()
{
	//Animal an;
	//an.eat();

//	an.breathe();
	Fish fh;
	Animal *pAn;
	pAn=&fh;
	fn(pAn);
	system("pause");

}
