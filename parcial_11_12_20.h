#define MAX_NOMBRE 100
#define MAX_CIUDADES 10

typedef struct ciudad {
    char nombre[MAX_NOMBRE];
    int habitantes;
    struct ciudad* proxima;
    struct ciudad* anterior;
} ciudad_t;

typedef struct mapa {
    ciudad_t* origen;
    ciudad_t* final;
} mapa_t;

/*
* Agregará una ciudad al mapa, justo después de aquella cuyo nombre coincida con el recibido por parámetro.
* Devolverá 0 si pudo agregarla o -1 si no.
* Ejemplo:
* Supongamos que queremos agregar la ciudad Azul luego de la ciudad Roja.
* A su vez, la ciudad Roja tiene como siguiente a la ciudad Verde.
* La ciudad Roja tendrá como siguiente a la ciudad Azul.
* La ciudad Azul tendrá como siguiente a la ciudad Verde.
* La ciudad Azul tendrá como anterior a la ciudad Roja.
* La ciudad Verde tendrá como anterior a la ciudad Azul.
*/
int agregar_ciudad(mapa_t* mapa, ciudad_t* ciudad_nueva, char ciudad_anterior[MAX_NOMBRE]);

/*
* Creará la estructura del mapa reservando la memoria necesaria.
* Devolverá un puntero al mapa creado si pudo agregarla o NULL en caso contrario.
* El mapa se cargará con las ciudades que se reciben por parámetro en el vector.
* La relación entre las ciudades en el TDA mapa debe ser una analogía a la del vector.
* Ejemplo:
* En el vector, la ciudad Azul está en la posición 3, la ciudad Roja en la 4 y la Verde en la 5.
* En la estructura mapa, la ciudad Azul tendrá como siguiente a la Roja.
* La ciudad Roja tendrá como siguiente a la Verde.
* La ciudad Roja tendrá como anterior a la Azul.
* La ciudad Verde tendrá como anterior a la Roja.
*/
mapa_t* crear_mapa(ciudad_t ciudades[MAX_CIUDADES]);

/*
* Intercambiará las ciudades de los extremos del mapa.
* Devolverá 0 si pudo agregarla o -1 si no.
* La ciudad del comienzo de la lista debe quedar al final y la del final debe quedar adelante.
*/
int intercambiar_extremos(mapa_t* mapa);
