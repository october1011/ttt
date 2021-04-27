#pragma once



#define CHK_DOT(x, sz) ((x) >= 0 && (x) < (sz))
#define POINT_ITEM(a, r, c) (*((*(a + r)) + c))

int winchk(Field& field, PLAYER c);



char getval(PLAYER** array, const int row, const int col) {
	return POINT_ITEM(array, row, col);
}
void setval(PLAYER** array, const int row, const int col, PLAYER value) {
	POINT_ITEM(array, row, col) = value;
}
int isvalid(Field& field, int x, int y) {
	return CHK_DOT(x, field.szX) && CHK_DOT(y, field.szY);
}
int isempty(Field& field, int x, int y) {
	return getval(field.map, y, x) == EMPTY;
}

int aiwinchk(Field& field) {
    for (int y = 0; y < field.szY; y++) {
        for (int x = 0; x < field.szX; x++) {
            if (isempty(field, x, y)) {
                setval(field.map, y, x, AI);
                if (winchk(field, AI))
                    return 1;
                setval(field.map, y, x, EMPTY);
            }
        }
    }
    return 0;
}

int humwinchk(Field& field) {
    for (int y = 0; y < field.szY; y++) {
        for (int x = 0; x < field.szX; x++) {
            if (isempty(field, x, y)) {
                setval(field.map, y, x, HUMAN);
                if (winchk(field, HUMAN)) {
                    setval(field.map, y, x, AI);
                    return 1;
                }
                setval(field.map, y, x, EMPTY);
            }
        }
    }
    return 0;
}

