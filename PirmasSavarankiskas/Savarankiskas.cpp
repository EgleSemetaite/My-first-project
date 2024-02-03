// PirmasSavarankiskas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mylib.h"

int minimum(int a, int b) {
    return a < b ? a : b;
}
//
//	//Konstruktorius
//Student::Student() {    // 1 konstruktorius
//		cout << "Data declarated"; // kintamasis uzpildytas
//	}
Student::Student(string N, string S, vector <int> H, int E) { // 2 konstruktorius 
		Name = N; Surname = S;
		HW=H;
		Exam = E;
		Rezult('v');
	}
	//Priskyrimo-kopijavimo operatorius
Student& Student::operator = (const Student& A) { //Student& kintamasis kuris grazinamas, adresas 
		if (this == &A) return *this;
		Name = A.Name; Surname = A.Surname;
		HW=A.HW;
		Exam = A.Exam;
		Rez = A.Rez; //kopijuojamas apskaiciuotas rezultatas
		return *this; //graziname kintamaji atgal i programa (rodykle *this rodo i pati elementa)
	}
	//Kopijavimo konstruktorius, negrazina jokiu reiksmiu
Student::Student(const Student& A) {   // studentas per nuoroda gauna atitink. elemet ir jo duom. nukopijuojami i jau sukurta laikina kintamaji
		Name = A.Name; Surname = A.Surname;
		HW=A.HW;
		Exam = A.Exam;
		Rez = A.Rez;
	}
	//Destruktorius - atlaisvina atminti
Student::~Student() {
		Name.clear();
		Surname.clear();
		HW.clear();
		Exam = 0;
		Rez = 0;
	}
	//vidurkio skaiciavimas
//float Student:: Vid() {
//		return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size();
//		//susumuoja turimus elementus, suma prasideda nuo 0, programa suzino kiek yra kintamuju ir juos panaikiname
//	}
//	//mediana
//float Student::Med() {
//		std::sort(HW.begin(), HW.end());
//		int n = HW.size() / 2;
//		return
//			(n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
//
//	}
void Student:: Rezult(char pas) {

	if (pas == 'v') { Rez = 0.4 * this->Vid() + 0.6 * Exam; }
	else { Rez = 0.4 * this->Med() + 0.6 * Exam; }
	}


void Student::printas() {
	cout << Name << " ; " << Surname << " ; ";
	for (auto& i : HW) cout << i << " | "; //tiesiogiai prieinama prie kintamojo ir nereikia jo kopijuoti
	cout << Exam << " | ";
	cout <<"Rezultatas= " <<Rez<< endl;

}

std::ostream& operator<<(std::ostream& out, const Student& A) {
	out << A.Name << " ; " << A.Surname << " ; ";
	for (auto& i : A.HW) cout << i << " | "; 
	out << A.Exam << " | ";
	out << "Rezultatas= " << A.Rez << endl;
	return out;
}
std::istream& operator>>(std::istream& in, Student& a) { //veikia ir su cin ir su ivestim is failu
	in >> a.Name;
	in >> a.Surname;
	for (int i = 0; i < 6; i++) {
		int k;
		in >> k; a.HW.push_back(k);
	}
	in >> a.Exam;
	a.Rezult('v');
	return in;
}
void bufer_nusk(std::string read_vardas, std::string write_vardas) {
	std::vector<std::string> splited;
	std::string eil;
	std::stringstream my_buffer;

	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;

	std::ifstream open_f(read_vardas);
	my_buffer << open_f.rdbuf();
	open_f.close();

	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Failo nuskaitymas i buferi uztruko: " << diff.count() << " s\n";

	start = std::chrono::high_resolution_clock::now();

	while (!my_buffer.eof()) {
		std::getline(my_buffer, eil);
		splited.push_back(eil);
	}

	diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Buferio padalijimas i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

	start = std::chrono::high_resolution_clock::now();

	std::string outputas = "";
	for (std::string& a : splited) {
		if (a.compare(splited.back()) != 0) {
			outputas += a + "\r\n";
		}
		else {
			outputas += a;
		}
	}

	splited.clear();
	diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Eiluciu vektoriaus konvertavimas i viena eilute uztruko: " << diff.count() << " s\n";

	start = std::chrono::high_resolution_clock::now();

	std::ofstream out_f(write_vardas);
	out_f << outputas;
	out_f.close();

	diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Failo irasymas per viena eilute uztruko: " << diff.count() << " s\n";

	diff = std::chrono::high_resolution_clock::now() - st;
	std::cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}
float Student::Vid() const {
	return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size();
}

float Student::Med() const {
	std::vector<int> sortedHW = HW;
	std::sort(sortedHW.begin(), sortedHW.end());

	int n = sortedHW.size() / 2;
	return (n % 2 == 1) ? sortedHW[n] / 1.0 : (sortedHW[n] + sortedHW[n + 1]) / 2.0;
}


//Konstruktorius
Student::Student() {    // 1 konstruktorius
//	cout << "Data declarated"; // kintamasis uzpildytas
}



