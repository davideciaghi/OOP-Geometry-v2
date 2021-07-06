#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;


class Point {

    private:

        int x;
        int y;

    public:
        
        Point(const int x=0, const int y=0); // Costruttore che se non gli si passa
                                 //  inizializza x e y = 0.
        string as_string() const; 
        int get_x() const;
        int get_y() const;
        void set_x(const int x);
        void set_y(const int y);

};



class PointArray {

    private:

        int size; // Dimensione dell'array
        Point* points; // Puntatore points che punta alla classe Point

    protected:

        void resize(int n);

    public:

        PointArray(); // Costruttore di default
        PointArray(const Point points[], const int size); // Costruttore
        PointArray(const PointArray& pv); // Costruttore copia
        ~PointArray();
        string as_string() const;
        void push_back(const Point &p); // Metto const const al parametro perché dichiarato tale nel main, il quale non deve essere modificato
        void insert(const int pos, const Point &p);
        void remove(int pos);
        int get_size() const;
        void clear();

        Point * get(const int pos);
        
        const Point * get(const int pos) const;  // La get che è const e quindi che non modifica l'istanza, ci restituisce un puntatore 
                                                 // che è const e non può essere modificato successivamente.

};



class Polygon {  // è una classe

    protected:

        const PointArray * arr;  // 
        static unsigned int npolygons;  // Per tenere traccia del numero di istanze di Polygon create

    public:

        Polygon(const Point points[], const int size);
        ~Polygon();
        Polygon(const PointArray& iarr);
        Polygon(const Polygon& pol);
        static int getNumPolygons();
        int getNumSides() const;
        int PointArray* getPoints() const;


};


class Rectangle : public Polygon {

    public:

        Rectangle(const Point p1, const Point p2) {
        Point * updateConstructorPoints ( const Point & p1 , const Point & p2, const Point & p3 , const Point & p4 = Point (0 ,0));
        Rectangle(const Point lowleft, const Point upright):    
        Polygon{

        {updateConstructorPoints(
            Point(34,24),
            Point(34,24),
            Point(34,24),
            Point(34,24))}, 4 
        }



}


#endif // GEOMETRY_H