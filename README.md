# Proyecto-Zoológico

Realizado por:
* Jeysa Blandon.
* David Salazar.

Este proyecto es una simulación de un zoológico en la cual interactúa el usuario como si fuera el trabajador o dueño del
zoológico, permitiendo crear habitats, agregar animales, ver su información, editar la alimentación de los animales y ejecutar
ciertas acciones básicas de los animales.

>Por medio de este link podrás ver el diagrama del proyecto:
> https://drive.google.com/file/d/1eWW7pKafF00KIkYdeHOdcfIv6BC2STg6/view?usp=sharing

# Funcionamiento del programa

Nuestro programa funciona con 3 clases:

* Clase Zoo = Esta contiene mediante un vector a la clase Habitat.
* Clase Habitat = Esta contiene mediante un mapa a la clase animal.
* Clase Animal = Esta contiene todas las acciones y atributos que le pertenecen al animal.

Estas clases interactúan entre sí para cumplir con las 5 acciones que tiene nuestro proyecto:

* Agregar un habitat.
  : El usuario puede agregar el habitat que desee en el zoológico; para esto se llama al método de la clase Zoo menuAgregarHabitat,
  aquí se le pide al usuario que ingrese el nombre o tipo de habitat que se va a crear, después se le pasa esta información del
  habitat al método de la clase Zoo agregarHabitat y esta lo añade al vector.

* Agregar un animal.
  : El usuario puede agregar un animal al zoológico teniendo en cuenta que el habitat exista; para esto primero se revisa que el
  vector de Habitat no este vacío, teniendo comprobado esto se llama al método de la clase Zoo infoZoologico el cual hace una
  lista de los habitats creados y permitiendo al usuario entrar a un habitat seleccionado, para así, de esta forma guardar
  al animal creado llamando al método de la clase Habitat menuAgregarAnimal que pide la información de los atributos del animal,
  y guarda el animal con el método de la clase habitat al mapa del habitat que se seleccionó.

* Modificar la alimentación del animal.
  : El usuario puede modificar la alimentación del animal ingresando su id, teniendo en cuenta que haya al menos un habitat creado
  y que el animal exista; para esto, teniendo la comprobación de que existe el habitat se llama al método de la clase Zoo 
  buscarAnimalZoologico el cual le pide al usuario la id del animal, retornando su dirección de memoria, si esta dirección es
  diferente a null entonces se llama al método de la clase Animal modificarAlimentacion, en este método se le muestran las 
  2 opciones que tiene el usuario respecto al alimento del animal seleccionado, eliminar o agregar algun alimento, si el usuario
  ingresa la primera opción se llama al método de la clase animal eliminarAlimento que le muestra al usuario la lista de los alimentos
  que tiene el animal y le pide el alimento que quiere eliminar de esa lista y se elimina del vector alimento del animal, por el caso
  contrario, si el usuario selecciona la opción 2 se llama al método de la clase Animal agregarAlimento, que también muestra la lista
  de los alimentos que tiene el animal y le pide que agrege un nuevo alimento teniendo en cuenta el tipo de dieta del animal, se agrega
  al vector alimento del animal y le vuelve a mostrar la lista actualizada.

* Acciones del animal.
  : El usuario puede pedirle a un animal dentro del zoológico que realice una de las acciones básicas permitidas(Comer, Dormir, Jugar),
  para esto primero se hace la comprobación de que haya al menos un habitat en el zoológico, teniendo la comprobación de que existe el 
  habitat se llama al método de la clase Zoo buscarAnimalZoologico el cual le pide al usuario la id del animal, retornando su dirección 
  de memoria, si esta dirección es diferente a null entonces se llama al método de la clase Animal accionAnimal, en el cual se le pide
  al usuario que ingrese el nombre de la acción que va a realizar el animal, si ingresa dormir entra al método de la clase animal 
  dormirAccion, en este método se le pide que ingrese las horas que el animal va a dormir, se comprueba que estas horas ingresadas no
  superen las horas que le quedan al animal por dormir en el día, si se superan el animal no podrá realizar la acción de dormir con esa
  cantidad de horas; si ingresa comer entra al método de la clase Animal comerAccion, el cual le muestra al usuario el tipo de dieta que
  tiene el animal(Carnivoro, herbivoro, omnivoro), también se le muestra la lista de los posibles alimentos, se le pide al usuario que
  escriba el alimento que le va a dar al animal, si este alimento esta dentro de la lista del animal, se le pide al usuario la cantidad en
  kg que se le va a dar al animal de este alimento, se comprueba que esta cantidad ingresada no supere la cantidad que le queda al animal 
  por comer en el día, si se supera la cantidad el animal no podrá realizar la acción de comer con esa cantidad; si ingresa jugar se llama
  al método de la clase Animal jugarAccion, el cual hace la comprobación de si el animal ha jugado en el día o no, si el animal ya jugó
  muestra que no puede realizar esta acción y si aún no ha jugado le muestra al usuario que se acaba de realizar la acción.


* Ver información del zoológico.
  : Le muestra al usuario la lista de los habitats y animales que hay en el zoológico; para esto primero se hace la comprobación de que haya 
  al menos un habitat en el zoológico, teniendo la comprobación de que existe un habitat se llama al método de la clase Zoo infoZoologico,
  que le lista al usuario los habitats que hay hasta el momento en el zoológico y le pide que ingrese el numero del habitat al que desea entrar
  a ver la información de los animales, esto retorna la dirección del Habitat que se selecciono para así llamar al método de la clase Habitat
  verAnimal, en este método se verifica si el Habitat esta vacio, de lo contrario se imprime la información de todos los animales existentes en
  este habitat.

# Evidencia del funcionamiento del programa

<figure>
    <img src="C:\Users\jeysa nahara\Pictures\Evidencia1.png"
         alt="Evidencia de creación del habitat">
    <figcaption>Creación del habitat polar.</figcaption>
</figure>

<figure>
    <img src="C:\Users\jeysa nahara\Pictures\Evidencia2.png"
         alt="Evidencia de creación del animal en un habitat seleccionado">
    <figcaption>Creación del animal y agregarlo al habitat polar.</figcaption>
</figure>
