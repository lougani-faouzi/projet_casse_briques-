
#ifndef BRICK_H
#define BRICK_H

#include "window.h"
#include "player.h"

/* ------------ LA CLASSE BRICK ----------------- */

class Brick {
private:
    /* Le nombre de coup qu'il faut pour la casser */
    int resistance;
    /* Le nombre de point qu'elle fait gagner */
    int point;
    int x;
    int y;
    int width;
    int height;
    Color c;

public:
    /* Constructeur par défault */
    Brick();
    /* Constructeur parametré*/
    Brick(int resistance,int point,int x,int y,int w,int h);

    /* Les getteurs */
    int get_resistance() const;
    int get_point() const;

    int get_posX() const;
    int get_posY() const;
    int get_width() const;
    int get_height() const;

    Color get_color() const;

    /*  Les setteurs */
    void set_resistance(int);
    void set_point(int);
    void set_color();

    /* Pour incrementé la valeur de resistance */
    /* La valeur par défault du paramétre est -1 */
    void increment_resistance(int = -1);

    void clear(const Window*) const;
    void print(const Window*) const;
};

/* ------------------- LA CLASSE TAB_BRICK --------------------- */

class Tab_brick {
private:
    Brick* tab;
    /* Nombre de Brique dans le tableau */
    int size;
    /* Espace mémoire alloué*/
    int alloc;

    static Player* player;
public:
    Tab_brick();
    
    Tab_brick(const Tab_brick&);

    Tab_brick& operator=(const Tab_brick&);

    ~Tab_brick();

    /* Ajoute une brique au tableau */
    void add(int resistance,int point,int x,int y,int w,int h);
    void del(int i,const Window* w);
    /* Retourn la brique à la position i*/
    Brick* get_brick(int i = 0);
    int get_size() const;
    void print(const Window*) const;

    static Player* get_player();
    static void set_player(Player*);

};

#endif
