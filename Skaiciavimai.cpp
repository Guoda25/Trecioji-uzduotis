#include "Lib.h"
#include "Skaiciavimai.h"

bool comparePagalPav(Studentas& x, Studentas& y) {
    if (x.getPav().length() == y.getPav().length())
        return x.getPav() < y.getPav();
    else
        return x.getPav().length() < y.getPav().length();
}

bool vargsiuku_paz(Studentas& x) {

    return x.getGalut() < 5.00;
}
