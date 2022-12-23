#include "Skaiciavimai.h"
using namespace std;

void failo_nuskaitymas(vector<Studentas>& studentai, int* pazymiu_sk)
{
    string s;
    string name = "studentai10000.txt.txt";
    //const char* path = "C:/Users/Guoda/Desktop/studentai10000.txt.txt";
    Studentas studentas;
    studentai.push_back(studentas);
    int i = 0;
    int temp;
    ifstream myFile;
    string line;
    myFile.open(name);
    try {
        if (!myFile)
            throw "NEPAVYKO ATIDARYTI FAILO!\n";
    }
    catch (const char* txtException) {
        cout << txtException;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {
            if (myFile.eof()) {
                studentai.pop_back();
                break;
            }
            myFile >> s;
            studentai[i].setVard(s);
            myFile >> s;
            studentai[i].setPav(s);
            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                studentai[i].setPaz(temp);
            }
            myFile >> temp;
            studentai[i].setEgz(temp);
            studentai.push_back(studentas);
            i++;
        }
    }
    myFile.close();

    for (int a = 0; a < studentai.size(); a++) {
        studentai[a].vid_median();
    }

}

void failo_nuskaitymas1(vector<Studentas>& studentai, int x, int* pazymiu_sk) {

    string s;
    auto start = chrono::high_resolution_clock::now();
    string name = "studentai_" + to_string(x) + string(".txt");
    Studentas studentas;
    studentai.push_back(studentas);
    int i = 0;
    int temp;
    ifstream myFile;
    string line;
    myFile.open(name);
    try {
        if (!myFile)
            throw "NEPAVYKO ATIDARYTI FAILO!\n";
    }
    catch (const char* txtException) {
        cout << txtException;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {
            if (myFile.eof()) {
                studentai.pop_back();
                break;
            }
            myFile >> s;
            studentai[i].setVard(s);
            myFile >> s;
            studentai[i].setPav(s);
            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                studentai[i].setPaz(temp);
            }
            myFile >> temp;
            studentai[i].setEgz(temp);
            studentai.push_back(studentas);
            i++;
        }
    }
    myFile.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    std::cout << "Failo is " << x << " studentu nuskaitymo laikas : " << diff.count() << endl;

    for (int a = 0; a < studentai.size(); a++) {
        studentai[a].vid_median();
    }

    //for (int a = 0; a < studentai.size(); a++) {
    //    vid_median(studentai, a, *pazymiu_sk);
    //}
}