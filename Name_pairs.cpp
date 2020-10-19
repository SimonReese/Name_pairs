// Simone Peraro 1216334
// Esercizio 6-bis: Classe Name_Pairs che contiene coppie di nomi, et�
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Name_pairs {

public:
	//Costructor of Name_pairs class
	Name_pairs();

	Name_pairs(vector<string>& name, vector<int>& age);

	//Return the name in position i
	string get_name(int i);

	//Return the age in position i
	int get_age(int i);

	//Returns the size of the names list
	int get_size();

	//Asks to input a list of names
	void read_names();

	//Asks to input a list of ages for each name
	void read_ages();

	//Print the content of name and age vectors
	void print();
	
private:
	//Vector containing a list of names
	vector<string> name;

	//Vector containing a list of ages
	vector<double> age;

	//Sort names in alphabetical order, adjusting ages accordingly
	 void sort();

	//Basic implementation of recursive QuickSort Algorithm
	void quickSort(vector<string>& vect, int left, int right);

	//Swap name and corresponding age from positionA to positionB
	void swap(int indexA, int indexB);

	//Overloading operator==
	bool operator==(Name_pairs& other);

	//Overloading operator!=
	bool operator!=(Name_pairs& other);
};

//Overload operator<< to handle Name_pairs objects
ostream& operator<<(ostream& out, Name_pairs& name);



//Basic testing main
int main() {
	Name_pairs nomi;
	cout << "Riepilogo :\n" << nomi;
	return 0;
}



//Overload operator<< to handle Name_pairs objects
ostream& operator<<(ostream& out, Name_pairs& name) {
	for (int i = 0; i < name.get_size(); i++) {
		out << "(" << name.get_name(i) << ", " << name.get_age(i) << ")" << endl;
	}
	return out;
}

//Costructor of Name_pairs class
Name_pairs::Name_pairs() {
	read_names();
	read_ages();
	sort();

	//Testing operator==
	cout << "Overloading of operator== is working: " << (this == this) << endl;

	//Testing operator!=
	cout << "Overloading of operator!= is working: " << !(this != this) << endl;
}

//Asks to input a list of names
void Name_pairs::read_names() {
	string word = "";
	cout << "Inserisci i nomi separati da un invio. Alla fine digita STOP" << endl;
	while (true) {
		cin >> word;
		if (word == "STOP") {
			break;
		}
		else {
			name.push_back(word);
		}
	}
}

//Asks to input a list of ages for each name
void Name_pairs::read_ages() {
	int temp = 0;
	cout << "Inserisci le eta' per ciascun studente\n";
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << ": ";
		cin >> temp;
		age.push_back(temp);
	}
}

//Returns the size of the names list
int Name_pairs::get_size() {
	if (name.size() == age.size()) {
		return name.size();
	}
	else {
		cout << "Warning: le dimensioni di eta' e nomi non corrispondono !" << endl;
		return name.size();
	}
}

//Return the name in position i
string Name_pairs::get_name(int i) {
	return name[i];
}

//Return the age in position i
int Name_pairs::get_age(int i) {
	return age[i];
}

//Print the content of name and age vectors
void Name_pairs::print() {
	cout << "Riepilogo:\n";
	for (int i = 0; i < name.size(); i++) {
		cout << "(" << name[i] << ", " << age[i] << ")" << endl;
	}
}

//Sort names in alphabetical order, adjusting ages accordingly
void Name_pairs::sort() {
	quickSort(name, 0, name.size() - 1);
}

//Basic implementation of recursive QuickSort Algorithm: the pivot element is the one in the middle. 
//At the end of each recursive call, the pivot element is in his final position,
//with smaller element in its left side and greater element on the right side
void Name_pairs::quickSort(vector<string>& vect, int left, int right) {
	//Condizione di uscita
	if (left == right) { return; }
	if (right < 0) { return; }
	if (left > right) { return; }
	//Selezioniamo un elemento e lo mettiamo in ultima posizione
	int pivot = (left + right) / 2;
	swap(pivot, right);
	int i = left -1;
	for (int j = left; j < right; j++) {
		if (vect[j] < vect[right]) {
			i++;
			swap(i, j);
		}
	}
	//Ho controllato tutti gli elementi. A questo punto, tutti gli elementi < di pivot sono nell'intervallo [left, i]. Quindi pivot va in i+1
	swap(i + 1, right);
	quickSort(vect, left, i);
	quickSort(vect, i + 2, right);
}

//Swap name and corresponding age from positionA to positionB
void Name_pairs::swap(int indexA,int indexB) {
	//Risparmio sullo scambio con sè stesso
	if (indexA == indexB) { return; }
	string tmp = name[indexA];
	name[indexA] = name[indexB];
	name[indexB] = tmp;

	int t = age[indexA];
	age[indexA] = age[indexB];
	age[indexB] = t;
}

//Overloading operator==
bool Name_pairs::operator==(Name_pairs& other) {
	for (int i = 0; i < other.get_size() && i < name.size(); i++) {
		if (other.name[i] != name[i] || other.age[i] != age[i]) {
			return false;
		}
	}
	return true;
}

//Overloading operator!=
bool Name_pairs::operator!=(Name_pairs& other) {
	for (int i = 0; i < other.get_size() && i < name.size(); i++) {
		if (other.name[i] == name[i] && other.age[i] == age[i]) {
			return false;
		}
	}
	return true;
}
