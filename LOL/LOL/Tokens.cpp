#include "Tokens.h"

Tokens::Tokens() { }
Tokens::~Tokens() { }

ifstream& operator >> (ifstream &ifs, Tokens &obj)
{
	Coordinate temp;
	obj.itokens = obj.tokens.begin();
	for (int i = 0; i < 6; i++) {

		ifs >> temp.x;
		ifs >> temp.y;
		ifs >> temp.Wight;
		ifs >> temp.Height;
		ifs >> temp.vec2f1;
		ifs >> temp.vec2f2;

		obj.tokens[temp] = false;
	}

	return ifs;
}

void Tokens::getToken(int* a, int* b, int* c, int* d, double* e, double* f) {
	Coordinate temp;
	temp.x = *a;
	temp.y = *b;
	temp.Wight = *c;
	temp.Height = *d;
	int i = 0;

	for (itokens = tokens.begin(); itokens != tokens.end(); itokens++) {
		if ((*itokens).first == temp && (*itokens).second == true) {
			i++;
			tokens[temp] = false;

			if ((++itokens) == tokens.end()) {
				for (itokens = tokens.begin(); itokens != tokens.end(); itokens++) {
					if ((*itokens).second == false) {
						(*itokens).second = true;
						*a = (*itokens).first.x;
						*b = (*itokens).first.y;
						*c = (*itokens).first.Wight;
						*d = (*itokens).first.Height;
						*e = (*itokens).first.vec2f1;
						*f = (*itokens).first.vec2f2;

						break;
					}
				}
				break;
			}
			else {
				int count = 0;
				map<Coordinate, bool>::iterator it;
				for (it = itokens; it != tokens.end(); it++) {
					if ((*it).second == false) {
						(*it).second = true;
						*a = (*it).first.x;
						*b = (*it).first.y;
						*c = (*it).first.Wight;
						*d = (*it).first.Height;
						*e = (*it).first.vec2f1;
						*f = (*it).first.vec2f2;
						count++;
						break;
					}
				}

				if (count == 0) {
					for (it = tokens.begin(); it != itokens; it++) {
						if ((*it).second == false) {
							(*it).second = true;
							*a = (*it).first.x;
							*b = (*it).first.y;
							*c = (*it).first.Wight;
							*d = (*it).first.Height;
							*e = (*it).first.vec2f1;
							*f = (*it).first.vec2f2;

							break;
						}
					}

					break;
				}
			}
			break;
		}
	}
	if (i == 0) {
		bool flag = false;
		itokens = tokens.begin();
		while (!flag && itokens != tokens.end()) {
			if ((*itokens).second == false) {
				(*itokens).second = true;
				*a = (*itokens).first.x;
				*b = (*itokens).first.y;
				*c = (*itokens).first.Wight;
				*d = (*itokens).first.Height;
				*e = (*itokens).first.vec2f1;
				*f = (*itokens).first.vec2f2;

				flag = true;
			}
			else
				itokens++;
		}
	}
}