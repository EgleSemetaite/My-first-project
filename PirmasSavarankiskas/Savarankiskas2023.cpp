#include "mylib.h"


int main()
{
    std::vector<Student> Group;

    std::string file_name = "kursiokai.txt";

    // atnaujinta vieta bufer_nusk kvietimui
    bufer_nusk("kursiokai.txt", "output.txt");

    std::ifstream input_file(file_name);

    // Patikrinkite, ar failas sėkmingai atidarytas
    if (!input_file.is_open()) {
        std::cerr << "Error: Negalima atidaryti failo." << std::endl;
        return 1;
    }

   

    // nuskaityti duomenis į group vector'ius
    Student student;
    try {
        while (input_file >> student) {
            std::cerr << "Nuskaityta: " << student << std::endl;  // Pridėtas išvedimas
            Group.push_back(student);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Uždarykite failą
    input_file.close();

    // isrusiuoti studentus pagal varda
    std::sort(Group.begin(), Group.end(), [](const Student& a, const Student& b) {
        return a.GetName() < b.GetName();
        });

    // Printinti header
    std::cout << std::setw(15) << "Name" << std::setw(10) << "Surname" << std::setw(20) << "Galutinis (Vid.)"
        << std::setw(20) << "Galutinis (Med.)" << std::endl;

    std::cout << std::setfill('-') << std::setw(65) << "-" << std::setfill(' ') << std::endl;

    // Printinti studento duomenis
    for (const auto& duom : Group) {
        std::cout << std::setw(15) << duom.GetName() << std::setw(10) << duom.GetSurname()
            << std::setw(20) << std::fixed << std::setprecision(2) << duom.Vid()
            << std::setw(20) << std::fixed << std::setprecision(2) << duom.Med() << std::endl;
    }
   
    return 0;
}
	//for (int i = 0; i < 3; i++) {
	//	Student Laikinas;
	//	string laikS;
	//	/*vector <int>Vec;
	//	cout << "Iveskite varda: ";
	//	cin >> laikS; Laikinas.SetName(laikS);
	//	cout << "Iveskite pavarde: ";
	//	cin >> laikS; Laikinas.SetSurname(laikS);
	//	cout << "Kiek namu darbu buvo semestre? ";
	//	int ndNr; 	cin >> ndNr;
	//	for (int i = 0; i < ndNr; i++)
	//	{
	//		int pazym;
	//		cout << "Iveskite " << i + 1 << " pazymi: ";
	//		cin >> pazym; Vec.push_back(pazym);
	//	}
	//	Laikinas.SetHW(Vec); Vec.clear();
	//	cout << "Koks egzamino pazymys?"; cin >> ndNr;
	//	Laikinas.SetExam(ndNr);
	//	Laikinas.Rezult('v'); */

	//	cin >> Laikinas;
	//	Group.push_back(Laikinas);
	//	Laikinas.~Student();

	//	
	//}
	//for (auto& duom : Group) cout<<duom;

	//system("pause");

	
