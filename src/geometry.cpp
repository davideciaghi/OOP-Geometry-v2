
#include <geometry.h>
#include "iostream"
#include <string>


using namespace std;


Point::Point(const int u, const int v) : x(u) , y(v) {}; // x e y le metto const così da non poterle modificare all'interno del costruttore


string Point::as_string() const {  // Mettendo const dico che il metodo non va a modificare i parametri dell'istanza
  
    string str = "(" + to_string(this->x) + "," + std::to_string(this->y) + ")";
    return str;
};

int Point::get_x() const {
    return this->x;
};

int Point::get_y() const {
    return this->y;
};

void Point::set_x(const int x){  // Il metodo non è cost perchè deve appunto modificare x dell'itanza
    this->x = x;
};

void Point::set_y(const int y){ // Il metodo non è cost perchè deve appunto modificare y dell'itanza
    this->y = y;
};



PointArray::PointArray() {  // Cstruttore di default

    this->size;
    this->points = NULL; // Crea un array di dimensione 0
}


PointArray::PointArray(const Point points[], const int size) {  // Costruttore con argomenti

    if (size < 0) {
        throw std::invalid_argument("Size is a negative number");
    } else if (size == 0) {
        this->points = NULL;
    } else {
        this->size = size;
        this->points = new Point[size];

        for (int i=0; i<size; i++) {
            this->points[i] = points[i];
        }
    }  
}


PointArray::PointArray(const PointArray& pv) : PointArray(pv.points, pv.size) {  // Costruttore copia

    cout << "DEBUG: copy constructor" << endl;
} 



PointArray::~PointArray() { // Distruttore

    cout << "DEBUG: PointArray destructor." << endl;
    delete [] this->points;
}


void PointArray::resize(int n) {

    cout << "DEBUG: resizing from" << this->size << "to" << n << endl;

    if (n < 0) {
        throw std::invalid_argument("Negative size !");
    } else if (n == 0) {
        delete [] this->points;
        this->points = NULL;
    } else {
        Point* old_points = this->points;
        this->points = new Point[n];

        for (int i = 0; i < std::min(n, this->size); i++) {

            this->points[i] = old_points[i];
        }
        this->size = n;
        delete [] old_points;
    }
}




string PointArray::as_string() const {

    string str = string("size: ") + to_string(this->size) + string(" points:");

    for (int i=0; i < this->size; i++) {
        str += "    " + this->points[i].as_string();
    }
    return str;
}



void PointArray::push_back(const Point &p){

    cout << "DEBUG: pushing back: " << p.as_string() << endl;

    resize(this->size + 1);
    this->points[this->size - 1] = p;
}



void PointArray::insert(const int pos, const Point &p) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    } else if(pos > this->size) {
        throw std::invalid_argument("Position bigger than size");
    } else {
        resize(this->size + 1);

        for (int i = this->size-1; i > pos; i--) {
            this->points[i] = this->points[i-1];
        }
        this->points[pos] = p;
    }
}


void PointArray::remove(int pos) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    } else if(pos >= this->size) {
        throw std::invalid_argument("Position bigger than size");
    } else {
        for (int i = pos; i < this->size; i++) {
            this->points[i] = this->points[i+1];
        }
        resize(this->size -1);
    }
}


int PointArray::get_size() const {
    return this->size;
}


void PointArray::clear() {
    resize(0);
}


Point * PointArray::get(const int pos) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    } else if(pos >= this->size) {
        throw std::invalid_argument("Position bigger than size");
    } else {
        return &(this->points[pos]);
    }
}


const Point * PointArray::get(const int pos) const {  // Metodo get con punto non mutabile

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    } else if(pos >= this->size) {
        throw std::invalid_argument("Position bigger than size");
    } else {
        return &(this->points[pos]);
    }
}




unsigned int Polygon::npolygons = 0;


Polygon::Polygon(const Point points[], const int size) {  // Costruttore di Polygon

    if (size <= 3)  {
        throw std::invalid_argument("Size < 3");
    }
    this->arr = new PointArray(points, size);
    this->npolygons += 1;  // Incremento il numero di istanze create
}

Polygon::~Polygon() {

    delete this->arr;
    this->npolygons -= 1;
    // BISOGNA AGGIUNGERE COSE
}


Polygon::Polygon(const PointArray& iarr) {  // Costruttore che prende un PointArray dall'eseterno

    if (iarr.get_size() < 3) {
        throw std::invalid_argument("Size < 3");
    }
    this->arr = &iarr;
    this->npolygons += 1;
}


Polygon::Polygon(const Polygon& pol) {  // Costruttore copia
    this->arr = new PointArray(*pol.arr);
    this->npolygons += 1;
}


virtual double area() const = 0;  // è un metodo virtuale da definire nelle classi che la erediteranno.



static int Polygon::getNumPolygons() {

    return Polygon::npolygons;
}

int Polygon::getNumSides() const {

    this->arr->get_size();
}


int Polygon::PointArray* getPoints() const {

    return this->arr;

}





Point constructorPoints [4];  // Array di punti
 
Point * Polygon::updateConstructorPoints ( const Point & p1 , const Point & p2, const Point & p3 , const Point & p4 = Point (0 ,0) ) {
   constructorPoints [0] = p1;
   constructorPoints [1] = p2;
   constructorPoints [2] = p3;
   constructorPoints [3] = p4;
 
   return constructorPoints ;
}


// Chiamo il costruttore del padre:
Regtangle::Rectangle(const Point low_left, const Point up_right) : Polygon{

        {updateConstructorPoints(
            Point(34,24),
            Point(34,24),
            Point(34,24),
            Point(34,24))}, 4 
    }






