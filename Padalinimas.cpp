#include "Skaiciavimai.h"


void studentu_isskaidymas(vector<Studentas>& studentai, vector<Studentas>& vargsiukai)
{
    auto start = chrono::high_resolution_clock::now();

    copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), vargsiuku_paz);
    studentai.erase(remove_if(studentai.begin(), studentai.end(), vargsiuku_paz), studentai.end());


    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu padalijimo i dvi grupes laikas: " << diff.count() << endl;
}