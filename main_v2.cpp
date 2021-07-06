#include <iostream>
#include <stdexcept>

#include "geometry.h"


using namespace std;


int main () {

    // p1 is now marked as const
    const Point p1 (11 , 3);
    cout << "p1: " << p1.as_string() << endl;
        
    // p2 is normal
    Point p2 (12 , 7);
    cout << "p2: " << p2.as_string() << endl;

    // other variables are not used anymore, we create the corresponding Points on the fly
    
    PointArray pa;

    cout << pa.as_string() << endl;

    pa.push_back(p1);    
    cout << pa.as_string() << endl;

    pa.push_back(p2);    
    cout << pa.as_string() << endl;

    // now I can directly create a Point here:
    pa.push_back(Point(13 , 2));  
    cout << pa.as_string() << endl;


    pa.insert(0, Point(14 , 5)); 
    cout << pa.as_string() << endl;

    pa.insert(4, Point(15 , 5)); 
    cout << pa.as_string() << endl;



    try {
        pa.insert(-1, Point(15 , 5));
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };

    try {
        pa.insert(6, Point(15 , 5));
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };

    pa.remove(0);
    cout << pa.as_string() << endl;

    pa.remove(3);
    cout << pa.as_string() << endl;

    try {
        pa.remove(3);
    } catch (std::invalid_argument& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };


    
    PointArray pa2 = pa;

    pa2.push_back(Point(16 , 8));

    cout << "pa: " << pa.as_string() << endl;
    cout << "pa2: " << pa2.as_string() << endl;

    const PointArray cpa = pa;
    cout << "cpa: " << cpa.as_string() << endl;
    
    //Point* p_point = cpa.get(0);       // non si può serve dichiararlo   const Point*   perché cpa è const
    const Point* cp_point = cpa.get(0);  // ok posso prenderlo con il metodo get e cp_point è const
    // cp_point->set_x(200);             // non posso perchè cp_point è un puntatore const e il metodo  set_x  non è marcato const

    
    Point* mp_point = pa.get(0);         // in questo caso posso perché pa non è const
    mp_point->set_x(100);  
    cout << "mutated point at index 0 of pa: " << mp_point->as_string() << endl;    

    cout << "pa: " << pa.as_string() << endl;
    cout << "pa2: " << pa2.as_string() << endl;




    cout << " ------  POLYGONS" << endl;



    //Polygon pol()  // can't, abstract class
    
    cout << "Polygon::getNumPolygons(): " << Polygon::getNumPolygons() << endl;   // getNumPolygons è un metodo legato alla classe e conta il 
                                                                                  // numero di istanze create -> STATIC


    Polygon* ppol1;  // Puntatori alla classe Polygon, che è una classe astratta
    Polygon* ppol2;  

    Rectangle rect(Point(11,0), Point(22,50));  // Recrtangle è una classe 
    
    cout << "Polygon::getNumPolygons(): " << Polygon::getNumPolygons() << endl;  // Numero di istanze create

    ppol1 = &rect;
    cout << "rect getNumSides: " << ppol1->getNumSides() << endl;
    cout << "rect getPoints(): " << ppol1->getPoints()->as_string() << endl;
    cout << "rect area: " << ppol1->area() << endl;
    
    // ppol1->getPoints()->get(0)->set_x(100);  // shoudln't compile!
    
    Rectangle rect2 = rect;

    // rect2.getPoints()->get(0).set_x(100);  // shoudln't compile!

    { 
        cout << "---- Rectangle inside a block" << endl;
        Rectangle rect3(50,60,70,80);
    } // gets destroyed here

    cout << "----  Triangle" << endl;
    Triangle trng(Point(0,0), Point(0,10), Point(20,0));

    cout << "Polygon::getNumPolygons(): " << Polygon::getNumPolygons() << endl;
    
    ppol2 = &trng;
    cout << "triangle getNumSides: " << ppol2->getNumSides() << endl;
    cout << "triangle getPoints(): " << ppol2->getPoints()->as_string() << endl;
    cout << "triangle area: " << ppol2->area() << endl;    






    return 0;
};