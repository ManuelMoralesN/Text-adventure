#include <iostream>
#include "Jugador.h"
#include "Cuarto.h"
#include "commons.h"

const int NUM_CUARTOS = 10;

int main() {
    Jugador guerreroCuauhtemoc("Guerrero Cuauhtemoc");
    Cuarto cuartos[NUM_CUARTOS];

    cuartos[0] = Cuarto("Selva Misteriosa", "Te encuentras en la densa Selva Misteriosa, donde los sonidos de la naturaleza resuenan a tu alrededor. Un Templo Antiguo se vislumbra entre los arboles.", Item("Espada Sagrada", "Una espada forjada con metales ancestrales, capaz de cortar a traves de la oscuridad"), Enemigo("Jaguar", "Un jaguar agil y sigiloso acecha en la selva"));
    cuartos[1] = Cuarto("Cueva de los Espiritus", "Una cueva iluminada por antorchas titilantes. Voces susurrantes llenan el aire, y sientes la presencia de los Espiritus Ancestrales.", Item("Collar de Proteccion", "Un collar bendecido por los Espiritus Ancestrales que otorga proteccion contra maleficios"), Enemigo("Espiritu Vengativo", "Una manifestacion eterea de antiguos agravios"));
    cuartos[2] = Cuarto("Templo Antiguo", "El Templo Antiguo se alza majestuoso frente a ti, sus paredes adornadas con jeroglificos y arte sagrado. Encuentras un Mapa Antiguo que revela la ubicacion del Amuleto de Poder", Item("Mapa Antiguo", "Un pergamino que muestra la ubicacion del Amuleto de Poder"), Enemigo("Guardian del Templo", "Una estatua animada que protege el Templo con ferocidad"));
    cuartos[3] = Cuarto("Sala de las Profecias", "La Sala de las Profecias esta llena de pergaminos que cuentan historias de destinos entrelazados. Un Pergamino Divino destaca entre ellos", Item("Pergamino Divino", "Un mensaje de los dioses que revela secretos ocultos"), Enemigo("Enemigo sin nombre", ""));
    cuartos[4] = Cuarto("Pasadizo Encantado", "Un pasadizo magico con puertas dimensionales. El Zafiro Centelleante en el suelo emite una luz hipnotizante", Item("Zafiro Centelleante", "Una joya magica que canaliza energias dimensionales"), Enemigo("Espectro Dimensional", "Una criatura de las dimensiones mas alla de la comprension"));
    cuartos[5] = Cuarto("Lago de los Espiritus", "Un lago tranquilo habitado por espiritus acuaticos benevolentes. Encuentras una Red de Pesca Espiritual en la orilla", Item("Red de Pesca Espiritual", "Una red magica que atrapa tesoros espirituales"), Enemigo("Enemigo sin nombre", ""));
    cuartos[6] = Cuarto("Jardin de las Flores Divinas", "Flores radiantes que reflejan la luz de la luna. Una Botella de Esencia Floral se destaca entre los petalos", Item("Botella de Esencia Floral", "Un elixir que restaura la vitalidad y atrae la bendicion de las flores"), Enemigo("Enemigo sin nombre", ""));
    cuartos[7] = Cuarto("Montana de los Desafios", "Una montana imponente con senderos empinados. El Rugido del Aguila anuncia la presencia de un Desafio Celestial", Item("Garras del Aguila", "Garras afiladas imbuidas con la fuerza del aguila"), Enemigo("Aguila Celestial", "Un majestuoso aguila que desafia a los intrepidos"));
    cuartos[8] = Cuarto("Callejon de las Sombras", "Un callejon sombrio donde las sombras susurran secretos. Encuentras una Antorcha de Luz para disipar la oscuridad", Item("Antorcha de Luz", "Una antorcha que ahuyenta las sombras y revela verdades ocultas"), Enemigo("Sombra Acechante", "Una entidad de la oscuridad que busca confundir"));
    cuartos[9] = Cuarto("Sala del Desafio Final", "Has llegado a la Sala del Desafio Final, donde Moctezuma aguarda. Prepara tus armas y enfrenta al jefe final en la batalla decisiva", Item("Amuleto de Poder", "Un amuleto que concentra las energias ancestrales para derrotar a Moctezuma"), Enemigo("Moctezuma", "El temible jefe final con poderes ancestrales y sed de desafio"));

    int indiceActual = 0;

    mostrarMensaje("¡Bienvenido, Guerrero Cuauhtemoc!\n"
        "Tu mision es explorar estos lugares misteriosos y recolectar objetos sagrados para derrotar al jefe final, Moctezuma.\n"
        "¡Ten cuidado con los desafios y enemigos en tu camino!\n");

    while (true) {
        cuartos[indiceActual].mostrarInfo();

        if (cuartos[indiceActual].tieneItem() && !guerreroCuauhtemoc.tieneItem(cuartos[indiceActual].getItem().getNombre())) {
            guerreroCuauhtemoc.recogerItem(cuartos[indiceActual].getItem());
            mostrarMensaje("¡Has recogido " + cuartos[indiceActual].getItem().getNombre() + "!");
        }

        mostrarMensaje("Selecciona una direccion (w/a/s/d) para moverte: ");
        char direccion;
        std::cin >> direccion;

        switch (direccion) {
        case 'w':
            if (indiceActual - 3 >= 0) {
                indiceActual -= 3;
                mostrarMensaje("Te mueves hacia el norte.");
            }
            else {
                mostrarMensaje("No puedes ir en esa direccion.");
            }
            break;
        case 'a':
            if ((indiceActual % 3) - 1 >= 0) {
                indiceActual -= 1;
                mostrarMensaje("Te mueves hacia el oeste.");
            }
            else {
                mostrarMensaje("No puedes ir en esa direccion.");
            }
            break;
        case 's':
            if (indiceActual + 3 < NUM_CUARTOS) {
                indiceActual += 3;
                mostrarMensaje("Te mueves hacia el sur.");
            }
            else {
                mostrarMensaje("No puedes ir en esa direccion.");
            }
            break;
        case 'd':
            if ((indiceActual % 3) + 1 < 3) {
                indiceActual += 1;
                mostrarMensaje("Te mueves hacia el este.");
            }
            else {
                mostrarMensaje("No puedes ir en esa direccion.");
            }
            break;
        default:
            mostrarMensaje("Entrada no valida. Usa w/a/s/d.");
            break;
        }

        if (cuartos[indiceActual].tieneEnemigo()) {
            mostrarMensaje("¡Enemigo encontrado! Combate simplificado. ¡Victoria!");
        }

        if (indiceActual == 9) {
            mostrarMensaje("¡Has llegado a la Sala del Desafio Final! Preparate para la batalla contra Moctezuma.");

            
            if (guerreroCuauhtemoc.tieneItem("Espada Sagrada") && guerreroCuauhtemoc.tieneItem("Collar de Proteccion") && guerreroCuauhtemoc.tieneItem("Mapa Antiguo") && guerreroCuauhtemoc.tieneItem("Zafiro Centelleante") && guerreroCuauhtemoc.tieneItem("Red de Pesca Espiritual") && guerreroCuauhtemoc.tieneItem("Botella de Esencia Floral") && guerreroCuauhtemoc.tieneItem("Garras del Aguila") && guerreroCuauhtemoc.tieneItem("Antorcha de Luz")) {
                mostrarMensaje("Con tus objetos sagrados, enfrentas a Moctezuma. La Espada Sagrada brilla con poder, el Collar de Proteccion te resguarda, el Mapa Antiguo revela tacticas, el Zafiro Centelleante desorienta a Moctezuma, la Red de Pesca Espiritual lo atrapa, la Botella de Esencia Floral fortalece tu espiritu, las Garras del Aguila te otorgan destreza, y la Antorcha de Luz disipa las sombras.");
                mostrarMensaje("¡Has derrotado a Moctezuma y completado tu mision con honor!\n"
                    "El espiritu de Cuauhtemoc sonrie desde los cielos, agradecido por tu valentia.");

                mostrarMensaje("¡Fin de la aventura!");
            }
            else {
                mostrarMensaje("Moctezuma te desafia, pero sientes que necesitas mas poder. Explora los cuartos restantes y descubre secretos ocultos para fortalecerte antes de enfrentar al jefe final.");
            }
            break;
        }
    }

    return 0;
}
