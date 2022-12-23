#include "Skaiciavimai.h"


void ivedimas_automatiskai(vector<Studentas>& studentas, int i)
{
    int temp;
    int a = 0;
    studentas[i].vardas(i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    srand(time(0));
    studentas[i].setEgz(rand() % 10 + 1);

    do
    {
        studentas[i].setPaz(rand() % 10 + 1);
        a++;

    } while (a < temp);

    studentas[i].vid_median();
}


void ivedimas_ranka(vector<Studentas>& studentas, int i)
{
    int temp, temp2;
    studentas[i].vardas(i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    for (int a = 0; a < temp; a++) {

        do {
            cin.clear();
            cin.ignore();
            cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
            cin >> temp2;
        } while (temp2 < 0 || temp2 > 10 || cin.fail());
        studentas[i].setPaz(temp2);;

    }

    do {
        cin.clear();
        cin.ignore();
        cout << "Iveskite egzamino pazymi:\n";
        cin >> temp;
    } while (temp < 0 || temp > 10 || cin.fail());
    studentas[i].setEgz(temp);
    studentas[i].vid_median();

}

void rezultatai(std::vector<Studentas> studentai)
{
    char temp;
    sort(studentai.begin(), studentai.end(), comparePagalPav);
    do {
        std::cout << "Jeigu norite, kad studentu galutinis balas butu ju namu darbu mediana iveskite \"M\"\n"
            << "Jeigu norite, kad studentu galutinis balas butu paskaiciuotas pagal formule iveskite \"F\"\n";
        std::cin >> temp;
    } while (temp != 'm' && temp != 'M' && temp != 'f' && temp != 'F');

    switch (temp) {
    case'm':
    case'M':
        std::cout << "\n\n";
        std::cout << std::setw(20) << std::left << "Vardas"
            << std::setw(20) << std::left << "Pavarde"
            << "Galutinis(med.)\n"
            << "-------------------------------------------------------\n";
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << std::setw(20) << std::left << studentai[i].getVard()
                << std::setw(20) << std::left << studentai[i].getPav()
                << std::setw(18) << std::left << studentai[i].getMedian() << std::endl;

        }

        std::cout << "\n\n";

        break;
    case 'f':
    case 'F':

        std::cout << "\n\n";
        std::cout << std::setw(20) << std::left << "Vardas"
            << std::setw(20) << std::left << "Pavarde"
            << "Galutinis(vid.)\n"
            << "-------------------------------------------------------\n";
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << std::setw(20) << std::left << studentai[i].getVard()
                << std::setw(20) << std::left << studentai[i].getPav()
                << std::setw(18) << std::left << studentai[i].getGalut() << std::endl;

        }

        std::cout << "\n\n";

    }
}

void rezultatau_isvedimas_iFaila(vector<Studentas> studentai)
{

    sort(studentai.begin(), studentai.end(), comparePagalPav);
    ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentai.size(); i++)
    {
        output << setw(20) << left << studentai[i].getVard()
            << setw(20) << left << studentai[i].getPav()
            << setw(18) << left << studentai[i].getGalut()
            << studentai[i].getMedian() << endl;

    }
    output << "\n\n";

    
}

void rezultatai_varg_kiet(vector<Studentas> vargsiukai, vector<Studentas> kietiakai) {

    sort(vargsiukai.begin(), vargsiukai.end(), comparePagalPav);
    sort(kietiakai.begin(), kietiakai.end(), comparePagalPav);
    auto start = chrono::high_resolution_clock::now();
    ofstream output;
    output.open("vargsiukai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < vargsiukai.size(); i++)
    {
        output << setw(20) << left << vargsiukai[i].getVard()
            << setw(20) << left << vargsiukai[i].getPav()
            << setw(18) << left << vargsiukai[i].getGalut()
            << vargsiukai[i].getMedian() << endl;

    }

    output << "\n\n";

    ofstream output1;
    output1.open("kietiakai.txt");
    output1 << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < kietiakai.size(); i++)
    {
        output1 << setw(20) << left << kietiakai[i].getVard()
            << setw(20) << left << kietiakai[i].getPav()
            << setw(18) << left << kietiakai[i].getGalut()
            << kietiakai[i].getMedian() << endl;

    }

    output1 << "\n\n";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu isvedimo i du failus laikas : " << diff.count() << endl;
    
}