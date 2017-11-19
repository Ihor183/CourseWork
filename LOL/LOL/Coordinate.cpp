#include "Coordinate.h"

bool Coordinate :: operator < (const Coordinate &point) const {
	if (x < point.x)
		return true;
	return false;
}

bool Coordinate :: operator == (const Coordinate &point) const {
	if (this->x == point.x && this->y == point.y && this->Wight == point.Wight && this->Height == point.Height)
		return true;
	return false;
}
