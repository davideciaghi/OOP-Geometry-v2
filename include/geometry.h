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

        const PointArray* arr;  // 
        static int npolygons;  // Per tenere traccia del numero di istanze di Polygon create

        static Point constructorPoints [4];  // Array di punti
        static Point* updateConstructorPoints ( const Point & p1 ,
                                                const Point & p2 ,
                                                const Point & p3 ,
                                                const Point & p4 = Point(0,0));

    public:

        Polygon(const Point points[], const int size);  // Costruttore che inizializza l'array di punti
        Polygon(const PointArray *iarr);  // Costruttore che inizializza l'array di punti passato un altro array di punti
        Polygon(const Polygon &pol);
        ~Polygon();  // Distruttore
        virtual double area() const = 0; // è un metodo virtuale da definire nelle classi che la erediteranno.
        static int getNumPolygons();
        int getNumSides() const;
        const PointArray* getPoints() const;


};


class Rectangle : public Polygon {

    public:

        Rectangle(const Point low_left, const Point up_right);
        Rectangle(const int x1, const int y1, const int x2, const int y2);
        virtual double area() const;

};



class Triangle : public Polygon {

    public:

        Triangle(const Point p1, const Point p2, const Point p3);

        virtual double area() const;

};



#endif // GEOMETRY_H