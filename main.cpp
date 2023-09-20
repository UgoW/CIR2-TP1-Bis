#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>

void afficherTableMultiplication(int chiffre) {
    std::cout << "Table de multiplication pour " << chiffre << " :" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << chiffre << " x " << i << " = " << (chiffre * i) << std::endl;
    }
}

auto analyseTextFromFile() {
    std::ifstream fichier("../fichier.txt");

    if (!fichier) {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }

    std::string ligne;
    int nombreDeLignes = 0;
    int nombreDeMots = 0;
    int nombreDeLettres = 0;
    std::map<char, int> occurrencesLettres;

    while (std::getline(fichier, ligne)) {
        nombreDeLignes++;

        std::istringstream iss(ligne);
        std::string mot;

        while (iss >> mot) {
            nombreDeMots++;
            nombreDeLettres += mot.size();
            for (char& c : mot) {
                c = tolower(c);
                if (isalpha(c)) {
                    occurrencesLettres[c]++;
                }
            }
        }
    }

    std::cout << "Nombre de lignes : " << nombreDeLignes << std::endl;
    std::cout << "Nombre de mots : " << nombreDeMots << std::endl;
    std::cout << "Nombre de lettres : " << nombreDeLettres << std::endl;

    std::cout << "Occurrences de chaque lettre de l'alphabet :" << std::endl;
    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        std::cout << lettre << ": " << occurrencesLettres[lettre] << std::endl;
    }

    fichier.close();
    return 0;
}

class TextRectangle {
private:
    int width ;
    int height;

public:
    //Setter
    void setWidth(int width) {
        if (width > 0 && width < 10) {
            this->width = width;
        }
    }
    void setHeight(int height) {
        if (height > 0 && height < 10) {
            this->height = height;
        }
    }
    //Getter
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }

    TextRectangle(int width, int height) {
        setWidth(width);
        setHeight(height);
    }

    int getArea() {
        return width * height;
    }
    int getPerimeter() {
        return 2 * (width + height);
    }
    void print() {
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
    }

    int drawArea(const char& pattern) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << pattern;
            }
            std::cout << std::endl;
        }
        return 0;
    }

    int drawPerimeter(const char& pattern) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    std::cout << pattern;
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }

};

int main() {
    int choix;
    std::cout << "Exercice 1 ou Exercice 2 ? (1, 2, 3 ou 4) : ";
    std::cin >> choix;

    if (choix == 1) {
        int a;
        int b;
        std::cout << "Entrez une valeur : ";
        std::cin >> a;
        std::cout << "Entrez une autre valeur : ";
        std::cin >> b;
        std::cout << "Résultat : " << a + b << std::endl;
    } else if (choix == 2) {
        int chiffre;

        std::cout << "Entrez un chiffre entre 1 et 9 : ";
        std::cin >> chiffre;

        if (chiffre < 1 || chiffre > 9) {
            std::cout << "Chiffre hors de la plage valide." << std::endl;
            return 1;
        }

        afficherTableMultiplication(chiffre);
    } else if (choix == 3) {
        analyseTextFromFile();
    } else if (choix == 4) {
        int width;
        int height;
        char pattern;

        std::cout << "Entrez la largeur du rectangle : ";
        std::cin >> width;
        std::cout << "Entrez la hauteur du rectangle : ";
        std::cin >> height;
        std::cout << "Entrez le caractère de remplissage : ";
        std::cin >> pattern;
        TextRectangle rect(width, height);
        rect.print();
        rect.drawArea(pattern);
        rect.drawPerimeter(pattern);

        return 0;
    }
    else {
        std::cout << "Choix invalide." << std::endl;
        return 1;
    }

    return 0;
}




