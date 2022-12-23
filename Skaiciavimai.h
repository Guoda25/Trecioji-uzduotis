#include "Lib.h"
#include "tryCatch.h"

class Zmogus {

protected:
    string Vard;
    string Pav;
    int amzius;

public:

    Zmogus() {
        Vard = "";
        Pav = "";
    }

    virtual void setVard(string v) { Vard = v; }
    virtual void setPav(string p) { Pav = p; }
    virtual void setAmz(int a) { amzius = a; }
    string getVard() const { return Vard; }
    string getPav() const { return Pav; }
    int getAmz() const { return amzius; }


};


class Studentas : public Zmogus {
private:
    std::string Vard, Pav;
    std::vector<int> paz;
    int egz;
    float galut;
    float median;

public:

    Studentas() {
    
        paz = { 0 };
        egz = 0;
        galut = 0;
        median = 0;
    }

    ~Studentas() { //I. destructor
        paz.clear();
    }

    Studentas(const Studentas& s) { //II. copy constructor
        Vard = s.Vard;
        Pav = s.Pav;
        egz = s.egz;
        paz = s.paz;
        galut = s.galut;
        median = s.median;
    }

    Studentas& operator=(const Studentas& s) {//III. copy assigment
        if (this == &s) {
            return *this;
        }
        Vard = s.Vard;
        Pav = s.Pav;
        egz = s.egz;
        copy(s.paz.begin(), s.paz.end(), paz.begin());
        galut = s.galut;
        median = s.median;
        return *this;
    }


    //Getters

    string getVard() const { return Vard; }
    string getPav() const { return Pav; }
    int getEgz() const { return egz; }
    float getMedian() const { return median; }
    float getGalut() const { return galut; }


    //Setters

    void setVard(string s) {
        Vard = s;
    }
    void setPav(string s) {
        Pav = s;
    }
    void setEgz(int i) {
        egz = i;
    }
    void setPaz(int i) {
        paz.push_back(i);
    }

    void vid_median()
    {

        int paz_sk = paz.size();
        //suskaiciuoja studento galutini bala:

        galut = accumulate(paz.begin(), paz.end(), decltype(paz)::value_type(0)) / float(paz_sk);
        galut = round((galut * 0.4 + 0.6 * egz) * 100) / 100;


        //surusiuoja studento namu darbu pazymius ir randa mediana

        sort(paz.begin(), paz.end(), [](int& a, int& b) { return a > b; });
        if (paz_sk % 2 == 0)
        {
            median = float((paz.at((paz_sk / 2) - 1) + paz.at((paz_sk / 2))) / 2.0);
        }
        else
        {
            median = float(paz.at(paz_sk / 2));
        }

    }

    void vardas(int i)
    {
        do
        {
            cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
            cin >> Vard;
            cout << endl;
        } while (Vard.length() < 0 || Vard.length() > 25 || tryCatch(Vard) != true);
        do
        {
            cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
            cin >> Pav;
            cout << endl;
        } while (Pav.length() < 0 && Pav.length() > 25 || tryCatch(Pav) != true);

    }

    bool comparePagalPav(const Studentas& x, const Studentas& y) {
        if (x.Pav.length() == y.Pav.length())
            return x.Pav < y.Pav;
        else
            return x.Pav.length() < y.Pav.length();
    }

    bool vargsiuku_paz(const Studentas& x) {

        return x.galut < 5.00;
    }
};


bool comparePagalPav(Studentas& x, Studentas& y);

bool vargsiuku_paz(Studentas& x);
