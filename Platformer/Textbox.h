#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;


namespace platformer
{
	/// <summary>
	/// Textbox de base, pleine de flaws, mais qui fera la job pour ce TP
	/// Notez que on peut l'utiliser aussi comme texte d'information.  Id�alement,
	/// On aurait une structure TexteDeBase comme superclasse avec Label et Textbox
	/// Comme sous-classe.  Ceci dit je suis tr�s serr� dans le temps, alors je livre
	/// vite quelque chose qui marche.
	/// </summary>
	class Textbox
	{
	//DOC DES M�THODES DANS LE .CPP
	public:
		Textbox();
		~Textbox();
		void init(const int longueur, const int limite, const Vector2f position, const Font& font);
		void initInfo(const Vector2f position, const Font& font, const bool estErreur);
		void insererTexte(String leTexte);
		void ajouterChar(const char leChar);
		void retirerChar();
		void dessiner(RenderWindow* const window);
		void selectionner();
		void deSelectionner();
		bool touche(const Vector2i& position);
		String getTexte() const;

	private:
		void ajustementsVisuels();		
		
		/// <summary>
		/// Limite de caract�res que notre textbox tol�re.  Mettez 1 de limite par 20 pixels de largeur de votre boite
		/// Ainsi si vous entrez que des caract�res larges (comme W par exemple), tout va entrer
		/// </summary>
		int limite;
				
		/// <summary>
		/// Graphiquement, la textbox est un simple rectangle.
		/// </summary>
		RectangleShape boite;
		
		/// <summary>
		/// Le texte � afficher.
		/// </summary>
		Text texte;

		
	};
}

