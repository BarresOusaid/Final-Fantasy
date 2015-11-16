#ifndef Entity_H
#define Entity_H

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Entity{
 
public:
 		
 		Entity();
        virtual ~Entity();
 		
        // caractéristiques de l'entité
        enum Stats
        {
            LEVEL,
            EXP,
            GIL,
            MAGLEVEL,
            HP,
            MP,
            HPMAX,
            MPMAX,
            STR,
            AGL,
            INT,
            STA,
            ATK,
            ACC,
            DEF,
            EVA,
            MDEF,
            STATSCOUNT
        };

        // actions entity can take in battle
        enum Actions
        {
            NONE,
            ATTACK,
            MAGIC,
            ITEM,
            FLEE,
            DEFEND,
            COUNT
        };
    

        // Tour d'action
        struct Turn {
          
			// actions à effectuées
			Actions action;
        
			// sélectionne la cible
			int target;
        
			// id de l'action (spellID/itemID)
			int actionID;
        };
    
		void setTurn(Turn t);
		void resetTurn();
		Turn getTurn() const;

        // met en place un attributs
        void setAttributes(Stats s, int val);

        // altérations d'états
        enum Status
        {
            KO = 1,
            POISON,
            DARKNESS,
            SILENCE,
            STONE,
            ZOMBIE,
            STOP
        };

        //
    
        // vérifie si l'entité à une altération d'état
        bool hasStatus(unsigned int status);
    
        // met/enlève des atlérations d'états, retourne vrai en cas de succès
        bool setStatus(unsigned int status);
        bool removeStatus(unsigned int status);
    
        // ajoute une quantité de HP/MP, retourne la quantité ajouté
        int addHP(int amount);
        int addMP(int amount);
    
        // affiche le changement le plus récent des HP/MP
        void renderHPMPChange();
    
        // met/récupère le nom de l'entité
        void setName(std::string n);
        std::string getName() const;
    
        // récupère la dimension du sprite de l'entité
        int getSpriteDim();
    
        // change la cible sans changer l'action
        void setTarget(int target);
    
        // attaque la cible selectionnée au prochain tour
        void attack(int target);


protected:

    // attributs de l'entité
    int attributes[17];
    
    // position x, y affichée
    int renderx, rendery;
    
    // dimension de sprite de l'entité
    int spriteDim;
    
    // clignote dès que l'entité clignote
    unsigned int animateTicks;

    // bit altération d'états
    int statusBits;


private:

    // nom de l'entité
    std::string name;
    
    sf::Font twenty;
    
    // tour de l'entité
    Turn turn;
    
    // changement à afficher dans les HP/MP
    int change;
    
    // clignote losque le texte est affichée
    unsigned int textTicks;
    
    // couleur actuelle pour afficher le texte
    enum TextColors
    {
        WHITE,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        PURPLE
    };
    int textColor;
    
 };
 #endif
