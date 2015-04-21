# cpp-coders-juego

C++ Coders: Raiders of the lost class


Proyecto de videojuego libre con OpenGL

Tomás Lorenzo Henriques Vázquez		tl.henriques@alumnos.upm.es

Jaime Lledó Gonzálvez			        jaime.lledo.gonzalvez@alumnos.upm.es

DESCRIPCIÓN GENERAL

  Nuestra propuesta trata de un juego en tercera persona en el que el jugador maneja un personaje, que puede moverse por la pantalla, disparar e interactuar con el entorno. 
  El objetivo del juego es eliminar a los enemigos de cada pantalla y procurando no recibir daño de estos, llegando al final de cada nivel al enfrentamiento con un enemigo jefe más poderoso. La vista del juego es cenital, por lo que se ve desde arriba tanto al personaje que manejamos como a los enemigos, así como los límites de la pantalla, los obstáculos o barreras, etc. 
  La principal mecánica del juego es el disparo. Al ser la vista cenital, se establece que el jugador puede disparar apretando el botón izquierdo del ratón, apuntando hacia el lugar en el que esté situado el cursor, y que se moverá por la pantalla con las teclas “W”, “A”, “S” y “D”. El personaje puede recoger mejoras para sus disparos, como daño mejorado o más rango, así como ataques secundarios o especiales, que pueden encontrarse por la pantalla o conseguirse al eliminar a enemigos. Los enemigos pueden atacar a distancia (con disparos) o cuerpo a cuerpo, dependiendo del tipo que sean.
  Se empleará un sistema de puntuación en el que cada enemigo eliminado proporcione puntos según su tipo o dificultad, además de poder encontrar objetos especiales que proporcionen puntuación extra. Los niveles deberán completarse a contrarreloj, otorgandose al final de cada nivel un bonus de puntuación según el tiempo restante.


NIVELES

  Se considera en un principio la creación de tres niveles diferentes, compuestos por diferentes salas, terminando cada nivel con el enfrentamiento contra un “boss” final. Las salas son cuadradas y cuentan cada una con puertas (de 1 a 4) para cambiar de salas, en ellas puede haber: diferentes tipos de obstáculos, tanto franqueables (precipicios, verjas) como infranqueables (rocas, muros); diversos objetos que el personaje deberá encontrar para poder continuar o que proporcionen puntuación extra; enemigos de diversas características que intentarán destruir al personaje mediante ataques a distancia o cuerpo a cuerpo.

PERSONAJES Y ENEMIGOS

  El personaje principal es un robot llamado [...] (no tenemos nombre aún), que al enterarse de que los nuevos robots de la Clase C++ han sido reprogramados para no obedecer las leyes de la robótica y acabar con los humanos decide enfrentarse a ellos antes de que puedan salir de la fábrica a sembrar el caos. Para ello, nuestro protagonista deberá recuperar los fragmentos de código dispersos necesarios para reconstruir la clase AsimovAI, y así restaurar a los robots a su funcionamiento original.
  Se pretende dotar a los distintos personajes de movimiento animado en sus extremidades y en los objetos que porten, poniendo especial énfasis en el personaje principal que controla el jugador.

ARMAS

  El arma principal del que dispone el jugador es su brazo-cañón, que dispara al estilo de una metralleta. En principio parece un arma simple, pero gracias a las mejoras el arma evoluciona a lo largo del juego. Los enemigos pueden ir armados con armas de disparo más o menos similares a las del protagonista o sin ellas, en este último caso su método de ataque puede ser de cuerpo a cuerpo o bien kamikaze, explotando en contacto con el jugador.

OBJETOS

  Los objetos que el jugador puede recoger son de diversas clases, y se distinguirán por su forma y color:(
    -Objetos de mejora: proporcionan una ventaja al jugador. Aparecerán de manera aleatoria al matar a un enemigo. La lista completa de mejoras es:[
	      -Vida extra: el jugador recibe una oportunidad extra si lo matan para completar el juego.
        -Mayor velocidad: el jugador se mueve más rápido, por lo que puede completar antes las salas y esquivar mejor.
        -Ratio de disparo: el jugador dispara más balas por segundo.
        -Daño: los disparos del jugador infligen más daño a los enemigos.
        -Invulnerabilidad: los enemigos no pueden herir al jugador durante un periodo.]
    -Objetos de misión: son aquellos que tienen que ser recogidos para poder pasar de nivel. Estos objetos son fijos, es decir, se encontrarán en el mismo lugar en todas las partidas.
   -Objetos de puntuación: son objetos que al recogerlos el jugador, le otorgan un número de puntos. No tienen efecto sobre la jugabilidad, solo sobre el tablero de puntuación.)

INTERFAZ Y JUGABILIDAD

  En la pantalla se visualizará una vista aérea del área a completar. La cámara enfocará al centro de la habitación si esta cabe en pantalla, si no, estará centrada en el jugador. Se considerará que la cámara pueda efectuar ligeros movimientos en orden de poder apreciar mejor el entorno 3D del juego. En pantalla también se tendrá un indicador del tiempo total de juego, de la puntuación hasta ese momento, de las mejoras que tenga activas y un contador de vidas que le quedan al jugador; así como una tabla en la que aparecerán los objetos que posee el jugador y los que le quedan por conseguir para poder finalizar el nivel. 
  El jugador controlará el movimiento de su personaje mediante las teclas WASD mientras que con el puntero del ratón marcará el lugar hacia el que apunta el personaje y con el clic izquierdo disparará. Se considerará el uso de la tecla ESPACIO para efectuar saltos si se incluyen obstáculos tales como precipicios. El menú de pausa se desplegará pulsando ESC.


GRÁFICOS Y SONIDO

  Se pretende aplicar a todos los elementos del juego texturas planas o con transparencias. Los distintos elementos del juego estarán construidos mediante primitivas geométricas simples para conformar formas complejas, por ejemplo, un cilindro rematado en sus bases por conos. Para los sonidos se empleará una librería externa que permita reproducir varios sonidos al mismo tiempo (la música de fondo y los diferentes efectos de sonido, de disparos por ejemplo).

PUNTUACIÓN

  El jugador obtendrá puntos por cada enemigo que elimine, objeto de puntuación que encuentre y obstáculo que destruya. Cada enemigo, objeto y obstáculo tienen asociadas una puntuación correspondiente. Dado que se juega contrarreloj, al final de cada nivel el jugador obtendrá un bonus de puntuación proporcional al tiempo que le reste.

CARACTERÍSTICAS FUTURAS

  Más niveles, objetos y enemigos
   / Mapa del nivel
   / Modo vista en primera persona
   / Gráficos 3D más detallados
