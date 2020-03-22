# LeapRover

Un simple auto con Arduino, con control mediante gestos o una app(android)

## Materiales / LeapRover

1. Arduino Uno.

2. 4X 18650 baterias.

3. Porta pilas 18650.

4. Regulador 9v.

5. Adafruit Motor Shield.

6. Jumpers.

7. Bluetooth HC-06.

8. Auto a control remoto viejo.

9. Interruptor On/Off.

10. Disipador para regulador.

11. Computador con bluetooth.

12. LeapMotion (El corazon del proyecto).

Si tienes los materiales adelante con la documentacion y instalacion.

## Instalacion

Lo primero es registrarse en.

[Leap Motion developers]([https://developer.leapmotion.com/#101](https://developer.leapmotion.com/#101)

Aca es muy importante que todo el proyecto y codigo lo trabaje con la version del sdk **2.3.1**, tan solo es necesario instalar la leapHome, esto nos instalara los drivers del sensor y ademas nos habilitara el servicio.

El codigo Lo trabaje en processing ya que esto es lo mas cercano a arduino y no fue tan largo el camino de dominarlo tiendo en cuenta la experiencia en arduino

asi que es importante tener instalado [processing]([https://processing.org/](https://processing.org/), el otro recurso que fue muy util, ya que muchas veces la documentacion de Leap motion developer era muy tecnica fue este blog que explica como accerder a los datos de leap motion con processing con un codigo muy sensillo que puedes revisar desde [Leap Motion para processing]([http://michaelkipp.de/interaction/leap.html](http://michaelkipp.de/interaction/leap.html)

Luego teniendo instalado LeapHome y la libreria instalada en processing, puede correr el codigo **x_z** del repositorio, cargar su codigo al arduino y controlar su Rover como un X-men

## Codigo Processing

El codigo de processing que se encuentra en el repositorio, fue una segunda prueba que realize directamente con el bluetooth de mi computadora. el codigo recoge los valores **X** - **Z** desde el leap motion y con esto cree condiciones que al cumplirse envian el dato mediante bluetooth al Rover para que este se mueva.

## Codigo Arduino

El codigo de arduino es capaz de funcionar tanto con la app, como con el codigo de processing este codigo fue construido en base a la **adafruit shield motor** y el codigo contiene estas caracteristicas.

1. Control de velocidad (Solo en APP)

2. Mover el Rover hacia adelante, atras, izquiera y derecha

## Rover

El Rover fue construido en base a un antiguo auto a control remoto, pero sin el control :c, es por esto que agregue un arduino y le volvi a dar vida al auto.

El codigo hace uso de 3 motores ya que este antiguo auto contaba con traccion 4x4 y el tercer motor era el encargado para el control de la direccion

## App

La aplicacion fue desarrollada en app inventor, al ejecutarla solicita los permisos para vincularse con Rover y la sencilla app tiene la posibilidad.

1. Control de la velocidad Aumentar y disminuir 

2. Control de movimiento Libre

## Proximos pasos

Hice un par de pruebas extrayendo otros valores que hacen mas facil el manejo del auto, que pronto subire

1. Desarrollar mejor la interfaz del auto en processing

2. Aprovechar el control de la velocidad en processing

3. Cambiar de placa a una con wifi para eliminar del mapa al bluetooth

4. Mejorar el Codigo (probablemente pasar a p5.js o algo similar)

y por supuesto mejorar y agregar mas documentacion.
