#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

/// <summary>
/// Squelette d'une classe joueur.  Y a pas grand chose ici, mais c'est tout de m�me la sprite
/// De l'ensemble des animations qui est utilis�e.
///
///QUATRES CONSEILS IMPORTANTS:
///1- Vous aurez le choix entre animer la spriteSheet ou d'int�grer 4 sprites diff�rentes.  Dans ce cas-ci, votre 
///joueur ne devra plus h�riter de sprite
///
///2- Si vous faites plus d'un niveau, le joueur pourrait �tre port�e dans la game et pass� par r�f�rence plut�t que d�truit et cr�e � chaque niveau de jeu.
///
///3- Pour faire changer votre personnage direction, il faudra le "refl�ter dans une direction (reflet == scaling � -1)
///
///4- Si vous utilisez les sprites founis pour le joueur et que vous utilisez le cadre du Rectangle de sprite pour vos collisions, vos collisions seront probablement tr�s �loign�es.
///Votre jouuer pourrait "porter" un rectangle de collsion faisait 32 pixels de large.
///
/// </summary>
namespace platformer
{
	class Joueur : public Sprite
	{
	public:
		Joueur();
		~Joueur();
		void move(const int direction);
		bool init(const int limiteGauche, const int limiteDroite, const String texturePath);
	private:
		static const int TAILLE_RECT = 64;

		Texture texture;

		IntRect persoRect;
		float vitesse = 3;
		float limiteGauche;
		float limiteDroite;
	};
}

