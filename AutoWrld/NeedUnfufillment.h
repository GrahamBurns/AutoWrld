#pragma once
#include "enums.h"

class NeedUnfufillment {
public:
	int multi;
	int hungerPen = 10;
	int dehydratedPen = 11;
	int exhaustedPen = 15;

	void needUnfufilled(NEEDS need, int multi) {
		this->multi = multi;
		int pens[2];

		switch (need)
		{
		case HUNGER:
			starving(pens);
			break;
		case THIRST:
			dehydrated(pens);
			break;
		case SLEEP:
			exhausted(pens);
			break;
		case OXYGEN:
			exhausted(pens);
			break;
		default:
			break;
		}
	}

     int* starving(int* pens) {
		pens[0] = hungerPen * multi;
		pens[1] = HUNGER;

		return pens;
	}
	void dehydrated(int* pens) {
		pens[0] = hungerPen * multi;
		pens[1] = HUNGER;  
	}
	void exhausted(int* pens) {
		// throw dice to see if the passout
	}

};