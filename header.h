//
// Created by Ugo WAREMBOURG on 05/11/2023.
//

#ifndef HEADER_H
#define HEADER_H

/**
 * @file header.h
 * @brief Ce fichier d'en-tête contient les déclarations des fonctions et des classes utilisées dans le programme principal.
 */

// Fonction pour afficher la table de multiplication d'un chiffre donné.
void afficherTableMultiplication(int chiffre);

// Fonction pour analyser un fichier texte et compter les lignes, les mots, les lettres et les occurrences de lettres.
auto analyseTextFromFile();

// Classe représentant un rectangle textuel.
class TextRectangle {
public:
    // Constructeur avec la largeur et la hauteur du rectangle.
    TextRectangle(int width, int height);

    // Méthode pour imprimer les caractéristiques du rectangle.
    void print();

    // Méthode pour dessiner la zone intérieure du rectangle avec un caractère donné.
    int drawArea(const char& pattern);

    // Méthode pour dessiner le périmètre du rectangle avec un caractère donné.
    int drawPerimeter(const char& pattern);

private:
    int width;
    int height;

    // Méthode privée pour calculer l'aire du rectangle.
    int getArea() const;

    // Méthode privée pour calculer le périmètre du rectangle.
    int getPerimeter() const;
};

#endif

