# Lenguaje Natural vs Lenguaje de Programación

Antes de meternos de lleno al resto de lecciones, creo que es conveniente entender que es un *lenguaje* en general (al menos de manera informal), no solo  C++, sino cualquier lenguaje que utilicemos. A groso modo, podemos decir que un *lenguaje* es una herramienta para expresar y dejar por escrito los pensamientos humanos. 

Usamos el lenguaje para hablar, escribir, leer, escuchar y también para pensar. A lo largo de nuestra vida, al menos un lenguaje nos acompaña siempre: nuestra lengua materna, que aprendemos casi de manera natural desde pequeños. Incluso, muchas personas aprenden otros idiomas por decisión propia, ya sea por ocio o por necesidad laboral.

Los lenguajes que empleamos para comunicarnos con otras personas se llaman *lenguajes naturales*. Estas surgieron a lo largo de muchos siglos y continúan cambiando con el tiempo. A excepción de los lenguajes creados artificialmente, como el *alto valyrio* de las obras de George R. R. Martin o el quenya, que es el idioma de los elfos en el universo de Tolkien, su evolución ocurre de manera espontánea, casi sin intervención directa de sus hablantes.

Sin embargo, también existen lenguajes cuyo origen y desarrollo han estado, y en muchos casos siguen estando, determinados por necesidades específicas. Su evolución depende por completo del control de grupos organizados, como comités internacionales o equipos de trabajo. La estructura de estos lenguajes está regulada por estándares internacionales y, aunque muchas personas puedan entenderlas, su función principal no es facilitar la comunicación cotidiana entre seres humanos.

Entre estos lenguajes se encuentran los *lenguajes de programación*. Seguramente ya conoces este concepto. Un lenguaje de programación se rige por un conjunto de reglas mucho más estrictas y menos flexibles que las de un lenguaje natural. Por ejemplo, esas reglas establecen qué símbolos (letras, números, signos de puntuación y otros) pueden utilizarse. A esta parte se le llama *léxico*. Otro conjunto de reglas determina cómo deben organizarse correctamente esos símbolos; eso corresponde a la *sintaxis*. Además, es necesario interpretar el significado de cada instrucción, y a eso se le conoce como *semántica*.

Todo programa que escribamos debe estar libre de errores léxicos, sintácticos y semánticos; de lo contrario, no podrá ejecutarse o generará resultados incorrectos. Y seguro te toparás con este tipo de errores, porque equivocarse es humano, y justamente las personas somos quienes escribimos los programas.

Quizá te preguntes por qué necesitamos usar un lenguaje de programación, y esa es una excelente pregunta. Intentemos responderla.


## Lenguaje Máquina 

Un ordenador, incluso uno muy avanzado desde el punto de vista técnico, no posee inteligencia por sí mismo. Podría compararse con un perro muy bien entrenado: solo responde a un conjunto limitado de órdenes previamente establecidas. Y, a veces, igual que un perro, simplemente deja de responder y se “apaga”. Las instrucciones que reconoce son bastante básicas. Podemos imaginar órdenes como: “toma este número, súmalo con otro y guarda el resultado”.

El conjunto de comandos que una computadora conoce se llama lista de instrucciones, y con frecuencia se abrevia como I. L. (por sus siglas en inglés). Según el modelo, los ordenadores pueden tener listas de instrucciones de distinto tamaño, e incluso instrucciones completamente diferentes.

En realidad, ese I. L. constituye un alfabeto propio, conocido como *lenguaje de máquina*. Es la forma más elemental y directa de comunicarse con una computadora; se podría decir que es su lengua nativa. De hecho, es posible escribir programas directamente en lenguaje máquina usando instrucciones muy simples. Sin embargo, esta forma de programación resulta lenta, agotadora y muy propensa a errores. En los primeros años de la informática, era la única opción disponible, y pronto quedaron claras sus limitaciones.

Programar en lenguaje máquina exige conocer a fondo el *hardware* y la estructura interna del ordenador. Por eso, si se cambia a una máquina con un diseño distinto, los conocimientos del programador pueden dejar de servir por completo. Además, los programas creados para un equipo pueden volverse inútiles si el nuevo sistema utiliza otra forma de representación. En otras palabras, un programa hecho para un tipo específico de computadora puede no funcionar en otra. A esto se suma que los programas escritos en lenguaje máquina son muy difíciles de entender incluso para programadores con experiencia. También su desarrollo toma mucho tiempo y suele ser costoso y complicado.

Todo esto hace necesaria una especie de puente entre el lenguaje humano y el lenguaje de la computadora. Ese puente también es un lenguaje: un medio intermedio que permita trabajar tanto a las personas como a las máquinas. A este se le conoce como *lenguaje de programación de alto nivel*.

Este tipo de lenguaje se parece, en cierta medida, a una lengua natural, porque usa símbolos, palabras y reglas que los humanos pueden comprender. Gracias a él, una persona puede expresar instrucciones complejas para una computadora de forma mucho más clara.

Quizá te preguntes cómo logra la computadora entender programas escritos así. La respuesta no es animarla a obedecer, sino traducir el programa a lenguaje máquina. Y esa traducción puede hacerla otra computadora, lo que vuelve el proceso rápido y eficiente.

Esto tiene una gran ventaja: no es necesario aprender muchos lenguajes de máquina distintos. Basta con conocer un lenguaje de programación de alto nivel. Si existe un traductor adecuado para una computadora determinada, el programa podrá ejecutarse sin problema. Dicho de otro modo, un programa escrito en un lenguaje de alto nivel puede convertirse en distintos lenguajes de máquina, lo que permite que funcione en varias computadoras. A eso se le llama portabilidad.


## Compilación

La traducción de la que hablamos la realiza un programa especializado llamado *compilador*. El proceso de pasar de un lenguaje de alto nivel a lenguaje máquina recibe el nombre de *compilación*.

Ahora bien, volvamos al proceso de crear un programa. Ya sabemos que la tarea principal consiste en escribirlo siguiendo las reglas del lenguaje de programación elegido. Ese programa, que en realidad es texto, se conoce como *código fuente* o simplemente *fuente*, y el archivo que lo contiene se llama *archivo fuente*.

Para redactar el código fuente, se necesita un *editor de texto* que permita trabajar con texto plano. Por eso, un procesador de texto como Microsoft Word no es la mejor opción; un editor sencillo, como el Bloc de notas (o en nuestro caso, Visual Studio Code), resulta más adecuado. El código se guarda en un archivo cuyo nombre conviene relacionar con su contenido. Por ejemplo, en C++ es común usar la extensión `.cpp`; así, si el programa se llama `Hola_mundo`, lo más lógico sería guardarlo como `Hola_mundo.cpp`. En algunas plataformas pueden emplearse otras extensiones, como `cc`, `cp`, `cxx`, `c++` o incluso `C`. Lo recomendable es revisar la documentación del compilador que se esté usando.

Después, el código fuente debe ser compilado. Para ello, se ejecuta un compilador apropiado y se le indica en qué lugar se encuentra el archivo que se desea traducir a lenguaje máquina. El compilador analiza el código y determina si hay errores en la escritura del programa. Si encuentra alguno, lo señalará. Esto no significa que “corrija” el programa por sí mismo; simplemente detecta problemas evidentes. Por ejemplo, si se intenta sumar dos números usando `#` en lugar de `+`, el compilador advertirá el error. En cambio, si se escribe `-` donde en realidad se quería usar `+`, el compilador no puede adivinar la intención del programador. Es decir, no piensa por nosotros, y eso también es parte del proceso.

Si el compilador no detecta errores, genera un archivo que contiene el programa ya traducido a lenguaje máquina. A este archivo se le llama normalmente `archivo ejecutable`. Su nombre puede variar según el compilador y el sistema operativo. Por ejemplo, en muchos sistemas Unix/Linux el archivo generado por defecto suele llamarse `a.out`, mientras que en Windows normalmente se crea un archivo con el mismo nombre que el archivo fuente, pero con extensión `.exe` en lugar de `.cpp`.

Claro está, el proceso real puede ser más complejo. Un programa grande puede estar dividido en varios archivos fuente, incluso en docenas de ellos. También puede ocurrir que el programa sea desarrollado por un equipo completo, en cuyo caso dividir el código en varios archivos resulta prácticamente imprescindible. Entonces, la compilación suele dividirse en dos etapas: primero se compila cada parte del código fuente para traducirla a lenguaje máquina, y después se realiza una unión o enlace de todos esos fragmentos en un solo producto final. A esa fase se le llama `enlazado`, y el programa que la realiza se conoce como `enlazador (linker)`.

¿Y para qué se usa más comúnmente C++? Principalmente para el desarrollo de programas orientados a objetos, especialmente aplicaciones grandes y complejas, sobre todo las que funcionan en entornos gráficos. Además, aprender C++ puede ser muy útil si después se quiere estudiar lenguajes como C# o Java. Muchos de los conceptos que maneja C++ son comunes a otros lenguajes orientados a objetos, ya que es uno de los más antiguos dentro de esta categoría.