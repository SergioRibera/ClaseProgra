#define MAX 100

class Clase{
    private:
        // 
        //  Arreglo
        //  Array
        //  Conjunto (Math, Alg)
        //  Matriz unidireccionales
        //
        int v1[MAX]; 
        // 0 = 100
        // 1 = 200
        // n = 1000
        int m; // Cantidad de elementos en el arreglo

        void rellenarArreglo();
    public:
        // Caracteristicas Publicas
        Clase(void);
        ~Clase(void);

        void invertirVector();

        // Getters
        int getElement(int index);
        void getElements();

        // Setters
        void setElement(int index, int value);
};
