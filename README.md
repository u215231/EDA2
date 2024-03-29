# Projecte d'una Xarxa Social. EDA II
___

#### Marc Bosch, Zhiyuan Lai i Yuxiang Jiang

## LLISTA DE CONTINGUTS

1) Introducció
2) Objectius
3) Solució

## INTRODUCCIÓ

El projecte d’aquest trimestre era el de dissenyar un prototip d’una xarxa social funcional en grup. 
Era un repte desafiant on es requeria implementar molts conceptes treballats a les classes de teoria.
En el nostre cas, ens vam inspirar amb les xarxes socials populars que hi ha avui en dia, com Twitter o Instagram.

La guia de la pràctica de l’Aula Global ens va ser de gran ajuda, ja que va definir el nostre punt de partida i què havíem de fer 
durant el trimestre. Un cop llegida la guia, vam emprendre el projecte. 

El primer pas va ser definir les estructures de dades de la xarxa (Network, User, Dictionary) i el menú principal amb les funcions que havia de tenir una xarxa social:
permetre afegir usuaris, enllistar els usuaris i operar com a un usuari específic.
De mica en mica, vam anar creant la resta de submenús i vam anar afegint funcionalitats més complexes, per 
exemple, les dedicades a la interacció entre usuaris o les de tractament de dades de fitxers. 
En alguns casos, amb cada nova funcionalitat afegida, havíem de revisar les funcions prèviament definides
perquè el programa funcionés, cosa que ens va fer dedicar-nos-hi moltes hores. 
Finalment, en acabar codi, vam millorar la impressió per pantalla del programa i vam 
posar-li un nom a la xarxa social, anomenant-la ZhiYuMarc (les nostres inciails).

En el programa hem prioritzat una "estètica de codi" de les següents característiques. 
Hem utiltizat pocs comentaris o comentaris molt sintètics per a facilitzar la lectura del codi;
molts comentaris dificulten la lectura de les funcions i només hem considerat de col·locar-los en punts en el codi és poc comprensiu. 
L'informe ja s'encarrega d'explicar el funcionament del codi.
Hem fet servir noms de funcions i de variables relativament llargs, que complementen el fet d'utilitzar pocs comentaris.
També, hem fet ús de constants per a saber quins valors numèrics o de text utilitzem en cada funció. 
Per acabar, hem fet funcions, molt específiques i modulades en diversos fitxers; així es poden agrupar segons la part del programa que es dediquen a solucionar.


## OBJECTIUS  

### Objectius Obligatoris

Hem assolit els següents els objectius obligatoris:

Llistes: 
N'hi ha moltes al llarg del treball i la gran majoria són dinàmiques (no hem fet llistes enllaçades). 
Una d'elles, la principal de la xarxa social, és la de Network, que dins conté una llista amb els usuaris, entre d'altres. 
Cada nou usuari que s’inserta, s’afegeix a aquesta llista.

Pila: 
L'hem implementada en una de les funcions que es mostra quan operas com a usuari específic (Send friend request to 
random user), aquesta funció l’explicarem més tard, és un dels objectius desitjables.

Cua: 
L’hem implementada per la llista de sol·licituds de cada usuari. Les funcions que es mostra quan operas com a 
usuari específic (Send friend request i Manage friend request) utilitzen la llista de sol·licituds, aquestes dues 
funcions l’explicarem més endavant, formen part dels objectius obligatoris.

Diccionari: 
L'hem implementat dins de Network, com a densenvolupadors (CEO) de la nostra xarxa social,
ens interessa saber quins són els temes més parlats entre els nostres usuaris i volem contar quantes vegades s’ha utilitzat cada paraula.   

Algoritmes d'Ordenament: 
Els que hem empleat són Merge Sort i Selective Sort. El MergeSort, que aplica la funció de Merge, 
el fem servir per a ordenar la llista d’usuaris del Network dins de la funció de Sort Network.
Sort Network ens permet ordenar la llista d’usuaris del Network per qualsevol
altre atribut de les dades de l'usuari (nom, edat, email, ciutat i hobbies). A més, quan la llista ja ha estat ordenada,
ja no la torna a ordenar. El SelectiveSort, d'altra banda, el fem servir per ordenar el diccionari, ens interessa
les 10 paraules més utilitzades i no cal ordenar tot el diccionari, només ordenar els 10 primers elements.

Algoritmes de Cerca: 
Els dos algoritmes de cerca implementats han estat Linear Search i Binary Search, 
focalitzats en cercar a través de llistes de cadenes (strings).
Un exemple on s'aplica Linear Search és la llista d’amics; abans d’enviar-li sol·licitud d’amistat a algú, primer recorrem
la llista d’amics per veure si ja eren amics. D'altra banda, funció Binary Search s'aplica dins de la funció de Search Network. 
Aquesta conté la funció de Sort Network per a ordenar la llista d'usuaris alfabèticament sempre abans d'aplicar la cerca binària.
La cerca binària l'utilitzem per a buscar dins la llista, atributs específics d'un usuari (per exemple, un nom).

Inserir un nou Usuari: 
Demanar un nom, una edat, un email, una ciutat i cinc hobbies. El nom, l'edat, 
l’email i la ciutat han de complir una sèrie de requisits per a ser vàlids; si no són vàlids, el programa demanarà que 
es tornin a introduir. Si tots els atributs són vàlids, el nou usuari s’afegirà a la llista d’usuaris (Llista dinámica) 
i també quedará guardada en un fitxer extern .CSV (objectiu desitjable). Les variables utilitzats són strings 
principalment perquè els atributs (nom, edat, email…) també són strings. Les estructures de dades utilitzades són Network i 
User. Les funcions es troben principalment en el fitxer 1.new_user.c, hi ha algunes funcions auxiliars com 
expandUser (fe un realloc) es troben en els fitxers network_data_control.c i network_file_control.c.

Enllistar Usuaris: Imprimir els usuaris per pantalla, la manera com s’imprimeix per pantalla és especial, té un format semblant a una 
taula. Les variables utilitzades són ints. Les estructures de dades usades són Network i User. Les funcions es 
troben principalment en el fitxer 2.list_users.c.

Operar com a Usuari Específic: Introduir el nom de l'usuari qui volem operar. El programa buscarà 
el nom, si el troba, s’imprimeix per pantalla que s’ha inicialitzat correctament i es mostrarà un submenú. 
A part d’inicialitzar com a usuari, hi ha l'opció d’inicialitzar com a CEO (introdueix “CEO” per consola). El CEO té un 
submenú especial. Les variables utilitzats són ints i strings. Les estructures de dades utilitzades són Network i User. 
Les funcions es troben principalment en el fitxer 3.operate_user.c.

Un cop que estem operant com a usuari específic, tenim tres opcions, cada una d’aquestes opcions s’especialitza en una 
tasca diferent. La primera ocpció és sobre les sol·licituds d’amistat (fitxer 31.manage_request.c); 
la segona, sobre els amics (fitxer 32.manage_friends.c), i la tercera, sobre les les publicacions (fitxer 33.manage_posts.c).

Enviar Sol·licituds d’Amistats: Introduir el nom de l’usuari qui volem enviar sol·licitud. 
El programa farà una sèrie de comprovacions, com per exemple, el nom de l’usuari qui volem enviar sol·licitud no pot 
coincidir amb el nom de l’usuari que hem inicialitzat. Si passa per les comprovacions correctament, s’enviarà la 
sol·licitud d'amistat i s’imprimirà per pantalla que s’ha enviat correctament. Les variables utilitzats son ints, 
strings i llista de string. Les estructures de dades utilitzades son Network i User. Les funcions es troben 
principalment en el 31.manage_requests.c, hi ha algunes funcions auxiliars com expandStringArray que es troben en els 
fitxers network_data_control.c.

Enviar Sol·licitud d’Amistats a Tres Persones Aleatòries: 
Aquí, hem aprofitat la funció anterior, ja que fan els codis semblants per afegir als altres usuaris. 
La única diferència és que en aquesta part és que hem de triar 3 usuaris desconeguts que no estan afegits en la llista d'mics de la persona que està connectat. 
Podem decidir si volem enviar la solicitud o no a aquestes persones. 
Ho hem fet de la següent manera. Hem posat una variable int i un bucle if-else. 
Amb aquesta variable int, podem saber si estem utilitzant l'opció de enviar solicitud aleatori o 
decidit. I segons aquesta variable int, amb el bucle if-else actuar de forma diferent. 
En aquesta opció, hem creat 4 funcions noves, 3 que tenen la funcionalitat de crear i modificar la estructura de stack, 
i fer servir per emmagatzemar els 3 usuaris random i l’altra serveix per buscar quines 3 usuaris són. 
Aquestes funcions adicionals també es poden trobar en 31.manage_request.c i network_data_control.h.

Administrar Sol·licituds d’Amistats: 
Per aconseguir-lo, hem implementat vàries funcions i vàries opcions diferents. 
Una funció per imprimir la cua de sol·licituds de més antics als més recents. 
Una funció serveix per donar l’opció d'acceptar a una solicitud concreta o rebutjar-lo. 
Com que en C11 no existeix la estructura booleana, doncs fem servir dues constants que indiquen un número en concret, 
i si la opció introduït no fossi aquestes dues constants, doncs demana a l'usuari que segueix introduint.
La tercera funció, serveix per fer tots els canvis necessaris després d'acceptar a una solicitud. 
Bàsicament és afegir a l’usuari actual al la llista d’amics de la persona que va enviar la solicitud, i viceversa.
Aquestes funcions es poden trobar en 31.manage_request.c i utilitzant les estructures definides en 
network_data_control.h.

Fer una Publicació Nova: 
Es demanarà a l’usuari introduir el contingut de la publicació. Les 
variables utilitzats son string i llista de string. La estructura de dada utilitzada és el User. Les funcions es troben 
principalment en el 33.manage_post.c,  hi ha algunes funcions auxiliars com expandStringArray que es troben en els 
fitxers network_data_control.c. 

Enllistar les Publicacions d'un Usuari: 
Es fa a través de la funció de listStringArray() a manage_posts.c.
S’informarà l’usuari si té alguna publicació o no. 
Si té publicacions, s’imprimirà per pantalla les publicacions de més recent a més antic. 
Les variables que hem utilitzat son int i llista de string. La variable who (int) s’utilitza per saber si les publicacions que volem 
imprimir son de l’usuari especific que hem inicialitzat o són publicacions dels seus amics. Tenim una funció que és 
llistar les publicacions dels amics (objectiu desitjable), per aquesta raó és necessari la variable who. 
L'estructura de dada que hem utilitzat és el User. Les funcions es troben principalment en el 33.manage_post.c.

### Objectius Desitjables

Llegir i Escriure Dades d’un fitxer extern: 
En un fitxer CSV tenim escrits una taula amb les dades dels usuaris: nom,
edat, correu, ciutat i cinc hobbies. La funció de llegir les dades (read) s'implementa abans d'executar el menú i 
la d'escriure (append) s'implementa un cop afegim un nou usuari. Les funcions es troben al fitxer network_file_control.c.

Enllistar les Publicacions d’un Amic: 
Es demanarà a l’usuari introduir el nom de l'amic qui vol buscar
les publicacions. Si no troba l’amic, avisarà l’usuari per pantalla. Les publicacions s’imoprimirà de més recents a
més antics. Aquest objectiu utilitza la funció list_string stack, que explicarem més endavant. Aquestes funcions es
poden trobar en 32.manage_friend.c.

### Objectius Lliures

Suprimir una Publicació: 
L’usuari podrà triar la publicació que vol eliminar introduïnt el
número de la publicació. Si no té cap publicacions o la publicació que vol eliminar no existeix, s’informarà a
l’usuari per la consola. La variable utilitzat és una llista de string on conté les publicacions. Les funcions es
troben principalment en el 33.manage_post.c


Veure la Meva Llista d’Amics: 
S’imprimeix per pantalla els amics de l’usuari específic. Les variables
que utilitza són string i llista de string Aquestes funcions es poden trobar en 32.manage_friend.c.

Suprimir un Amic: 
L’usuari podrà triar l’amic que vol eliminar introduïnt el nom. Si no té cap amic
o l’amic que vol eliminar no existeix, s’informarà a l’usuari per la consola.
La variable utilitzat és una llista de string on conté els amics. Les funcions es troben principalment en el
32.manage_friend.c


## SOLUCIÓ

### Arquitectura del Sistema

Missatge de benvinguda a la xarxa. 
Se'ns inicialitza la Network i se'ns llegeix el fitxer CSV amb les dades dels usuaris.

Se'ns desplega el MENÚ PRINCIPAL. Hem de triar entre tres opcions.

- [1] INSERIR UN NOU USUARI. Per entrada de consola, se'ns demana un nom d'usuari, una edat, un correu, una ciutat i cinc aficions o hobbies.
  Les aficions són els únics atributs que poden ser buits, la resta han de tenir contenir algun caràcter.
  Tant el nom d'usuari com el correu són els atributs que no han d'existir prèviament a la llista d'usuaris. 
  El correu ha de tenir un domini vàlid (els dominis s'importen d'un fitxer) del tipus ".com" o ".cat" i ha de tenir un 
  arroba abans del domini. L'edat ha de ser un caràcter del tipus numèric. Totes les dades s'introdueixen a Network->User->Data.
  En acabar la tasca, tornem al menú principal. L'usuari nou també s'actualitza al fitxer CSV.<br/><br/> 

- [2] ENLLISTAR ELS USUARIS EXISTENTS.  Ens diu la quantitat d'usuaris que hi ha i totes les dades dels usuaris s'imprimeixen en cinc columnes: 
  el nom, l'edat, el correu, la ciutat i els cinc hobbies.
  Perquè s'imprimeixin en columnes proporcionals, es mira la longitud màxima dels atributs d'una columna i s'imprimeixen 
  espais en blanc per a compensar atributs d'una longitud més curta. Els hobbies s'imprimeixen un al costat de l'altre i separant-se amb punt i coma,  ja que s'interessa veure'ls agrupats. <br/><br/>

- [3] OPERAR AMB UN USUARI ESPECÍFIC. Se'ns demana d'escriure el nom d'un usuari. <br/><br/>

  - Si el nom és "CEO", entrem al MENÚ DEL DESENVOLUPADOR, un menú ocult. <br/><br/>
      
      - [1] BUSCAR LES 10 PARAULES MÉS UTILITZADES. Mitjançant el diccionari, ens imprimeix per pantalla les 10 paraules més recurrents de les publicacions dels usuaris. <br/><br/>
      - [2] BANEJAR UN USUARI. Ens demana un nom d'un usuari i, si existeix a la llista general dels usuaris i no està ja banejat, el col·loca a la llista dels usuaris banejats. <br/><br/>
      - [3] DESBANEJAR UN USUARI. Ens demana un nom d'usuari i, si existeix dins dels banejats, ens l'elimina d'aquesta llista. <br/><br/>
      - [4] ENLLISTAR ELS USUARIS BANEJATS. Ens imprimeix tots els usuaris banejats. <br/><br/>
      - [0] TORNAR AL MENÚ PRINCIAPL. <br/><br/>

  - Si el nom és el d'un usuari banejat, ens imprimeix el missatge que l'usuari no pot accedir a administrar el seu compte. Se li pregunta 
      si vol visualitzar o no els Termes d'Ús de la xarxa, que es llegeixen del fitxer Social_Network_File.txt. <br/><br/>

  - Si el nom és el d'un usuari no banejat, entrem al menú d'OPERAR AMB UN USUARI ESPECÍFIC. <br/><br/>
   
     - [1] GESTIONAR LES SOL·LICITUDS. Entrem en un submenú. Hem de triar entre tres ocpions. <br/><br/>
  
       - [1] ENVIAR SOL·LICITUD A UN USUARI ESCOLLIT. Ens demana escriure el nom d'un usuari. Si l'usuari existeix, se'ns afegirà el nostre nom a la llista sol·licituds de l'altre usuari. <br/><br/>
       - [2] ENVIAR SOL·LICITUD A TRES USUARIS ALEATORIS. La màquina ens escull aleatòriament tres usuaris dins la llista. Nosaltres triem si enviar o no sol·licitud a cadascun d'aquests tres usuaris dient sí o no. <br/><br/>
       - [3] ACCEPTAR O DENEGAR LES SOL·LICITUDS PENDENTS. Visualitzem les sol·licituds rebudes de la més antiga a la més nova, ja que són una cua. Si l'acceptem, l'usuari que ens ha enviat sol·licitud apareixierà a la nostra llista d'amics i l'altre també ens veurà a nosaltres com a amic. <br/><br/>
       - [0] TORNAR AL MENÚ D'OPERAR AMB UN USUARI ESPECÍFIC. <br/><br/>
   
     - [2] GESTIONAR ELS AMICS. Entrem en un submenú. Hem de triar entre tres ocpions. <br/><br/>
      
       - [1] VEURE LA MEVA LLISTA D'AMICS. S'imprimeixen els nostres amics, del primer afegit fins l'últim.  <br/><br/>
       - [2] VEURE LES PUBLICACIONS D'UN AMIC. Se'ns demana el nom d'un amic i, si aquest el tenim a la llista d'amics i té publicacions fetes, s'imprimeixen les seves publicacions per pantalla.  <br/><br/>
       - [3] ELIMINAR UN AMIC. Eliminem un usuari que és amic nostre. Quan accedim a l'altre usuari, ja no ens veurà a nosaltres com a amic.  <br/><br/>
       - [0] TORNAR AL MENÚ D'OPERAR AMB UN USUARI ESPECÍFIC. <br/><br/>
      
     - [3] GESTIONAR LES PUBLICACIONS. Entrem en un submenú. Hem de triar entre tres ocpions. <br/><br/>
      
       - [1] FER UNA NOVA PUBLICACIÓ. Escribim una nova publicació per consola i es desa dins dels Posts de l'usuari. <br/><br/>
       - [2] ENLLISTAR TOTES LES PUBLICACIONS. Se'ns imprimeixen per pantalla totes les nostres publicacions, de la més vella a la més nova. <br/><br/>
       - [3] ELIMINAR UNA PUBLICACIÓ. Eliminem el post que escollim. Hem de donar un número de publicació, que és correspon amb un índex dins l'estructura dels posts, i aleshores se'ns eliminarà. <br/><br/>
       - [0] TORNAR AL MENÚ D'OPERAR AMB UN USUARI ESPECÍFIC. <br/><br/>

     - [0] TORNAR AL MENÚ PRINCIPAL. <br/><br/>

  - En cas contrari, no entrem a cap d'aquestes opcions esmentades i retornem atomàticament al menú principal. <br/><br/>

- [0] SORTIR DEL PROGRAMA.

Després d'aquí, se'ns alliberen els espais de memòria de totes l'estructura de Network i les seves subestructures i llistes: 
Users (Data, Posts, Requests & Friends), Dictionary (Elements) & Banned Users. Finalitza l'execució del programa.

### Gestió d'Errors

Els errors d'entrada de l'usuari els controlem de vàries formes. 

Els errors més bàsics són els de les opcions numèriques (enters), les quals et fan escollir d'una opció d'entre tantes. 
Són el tipus d'opcions que es troben en els menús: el principal, el d'operar amb l'usuari, etc. 
Aquestes opcions ens podrien donar error si l'entrada no fos un enter, per això vam crear un fitxer anomenat option_utils.c 
encarregat només de validar-les. Aquest fitxer té la funció Read Int, la qual llegeix un enter 
i en cas que no es doni una correcta correspondència de lectura, ens farà el farà repetir. La funció Flush Input, també 
del fitxer, s'aplica a Read Int i és per a eliminar el caràcter '\n' produït a l'hora de fer scanf() del fitxer "stdio" del sistema; 
si no col·loquéssim aquesta funció, entraríem en un bucle on se'ns farien impressions infinites de tots els caràcters de l'stdio
anteriors per error.

Hi ha altres errors que són propis de l'apartat d'Introduir Un Nou Usuari. Aquí tractem amb strings i fem vàries
validacions per cada atribut que introduïm segons unes condicions que hem especificat (explicades a l'apartat d'Arquitectura del sistema). 
Podrien no ser-hi les condicions i no ens donaria cap error el programa, però les hem col·locat perquè sigui més interessant el programa.

Altres errors que validem són sobretot en els apartats del programa que necessiten accedir a un usuari de la llista, per 
exemple a Operar Users, Manage Requests, CEO Utils, etc. Aquestes funcions sempre necessiten usuaris que estiguin 
prèviament a la llista i per a això s'apliquen algoritmes de cerca (lineals o binaris). En cas contrari, notifiquen que no han trobat l'usuari.

La lectura del fitxer CSV se suposa que és correcta, ja que el fitxer sempre estarà estructurat amb una primera fila 
que són els 9 títols dels atributs de les dades i una files consegüents (tantes com siguin) amb també 9 atributs. 
Cada atribut també se suposa que està ja separat per comes. Un únic error que ens pot donar el fitxer és quan té linies 
a sota buides. Aquest error no el vam menysprear, ja que podia passar si editaves directament el fitxer. 


### Disseny del Model de Dades

<img src="Diagrama_de_la_Xarxa_Social.jpg">

En aquest programa hem utilitzat estructures de dades homogènies, on els seus aributs són arrays dinàmiques d'un sol tipus
de dada que van acompanyades d'un quantificador de la seva mida (un enter). Això ens ha permès
tractar llistes dedicades per a propòsits diferents de la mateixa manera pel que fa a la seva inicialització, ordenació,
impressió per pantalla i altres funcionalitats.

La gran majoria d'aquestes arrays que utilitzem són llistes de cadenes de caràcters o strings, les quals, en realitat, són matrius de caràcters.
Aquesta idea se'ns va ocórrer al cap de poc temps de començar amb el projecte, quan estàvem desenvolupant els primers objectius, 
els d'afegir un nou usuari a la llista, enllistar-los i llegir dades d'un fitxer. El que ens vam fixar és que les dades de l'usuari,
és a dir, els atributs continguts dins del Data de l'estructura d'User, es podien simplificar totes amb una sola llista de strings. 
Com a resultat, en comptes de fer servir etiquetes per a accedir a cadascuna d'elles, que seria fer user->data->name, 
ens va proporcionar el garn avantatge de fer servir índexs, que seria user->data[NAME], la qual cosa era molt més eficient 
iterar per a les posicions de l'estructura d'usuaris en els bucles FOR i WHILE.

Les estructures de dades les declarem en el fitxer de capçalera network_data_control.h, on també hi ha les funcions respectives
que tracten amb elles i la majoria de constants que s'utilitzaran en la resta de fitxers (vegeu l'apartat de les constants).

User:
- data: Llista que conté els atributs de l'usuari. Té una mida fixada de 9 elements. Es declara com a matriu dinàmica de caràcters
- request: Cua que conté els usuris que li han enviat licitud a un usuari.
- size_requests: Quantitat de sol·licituds.
- friends: Llista que conté els nostres amics, que són els usuaris els quals els hi hem acceptat la sol·licitud.
- size_requests: Quantitat d'amics.
- post: Llista que conté les publicions d'un usuari (format de text).
- size_requests: Quantitat de publicacions.

Element:
- key: Llista extreta de les publicacions dels usuaris.
- value: Quantitat de repeticions de la paraula en totes les publicaions.

Dictionary (inclou Element):
- element: Llista d'elements diccionari (parell clau/valor). Té mida fixada de 10 elements.
- current_elements: Quantitat d'elements del diccionari.

Network (inclou Dict i Usuari):
- user: Llista dinàmica dels usuaris.
- size_users: Quantitat d'usuaris.
- order_users: La forma d'ordenació de la llista (per nom, edat, correu, etc.).
- dictionary: Diccionari que compta de el Top 10 de paraules.
- banned_user: Array els noms dels usuaris banejats.
- size_banned_users: Quantitat de banejats.

RandomUsers:
- stack: Pila amb els índexs de tres usuaris aleatoris. Té mida màxima de 3 elements.
- top: Quantitat actual d'usuaris aleatoris a la pila.

S'ha de dir que la cua ha estat l'única estructura de dades que no ens caldria haver fet, però com que era un objectiu obligatori l'hem hagut d'implementar.

### Descripció i Processament del Conjunt de Dades

Els processaments de les dades es troben als fitxxers network_data_control.c i a network_file_control.c.

Inicialització de dades de la Xarxa: initString, initStringArray, initUser; initDictionary initNetwork ();

Expansió de dades: expandUsers, expandStringArray.

Eliminació de dades concretes de llistes: delete_String_In_StringArray

Neteja de dades de la xarxa: clearUsers, clearNetwork.

Còpia de dades: copyString, copyStringArray, copyUser.

Lectura de dades per consola: readString.

Lectura de dades d'un fitxer CSV: Read Users File, Read Users Lines.

Escriptura de dades d'un fitxer CSV: Apend Users File.

## ALTRES INFORMACIONS

Aquestes són les constants més importants que hem utilitzat.

- SIZE_DATA: Quanitat de dades d'un usuari.
- MAX_DICTIONARY_ELEMENTS: Elements màxims del diccionari
- NAME, AGE, EMAIL, (...): Són els índex per a accedir als atributs de les dades de l'usuari.
- NULL_SIZE: Mida d'una stack buida (0).
- ONE_SIZE: Mida d'una stack amb un element (1).
- INCREMENT_SIZE, DECREMENT_SIZE: Incrementar o decrementar la mida d'una stack.
- MULTIPLICATIVE_FACTOR: Per a incrementar una stack en varis element.
- NOT_ORDERED: La llista no té cap tipus d'ordenació.
- BUFFER_SIZE: Un nombre molt gran, per a un buffer de caràcters (2^10 bytes)
- END_CHARACTER: Per a aturar una string llegida per consola.
- RESET: Per a tornar a 0 una variable.
- SET_ZERO: Inicialitzar una variable a 0.
- LESSTHAN, GREATHERTHAN, EQUAL: Per a la comparació d'strings.
- ACCEPT, DENY: Per a acceptar o denegar sol·licituds.

## REFERÈNCIES

Don't Write Comments, from CodeAesthetic - https://youtu.be/Bf7vDBBOBUA

Why You Shouldm't Nest Your Code, from CodeAesthetic - https://youtu.be/CFRhGnuXG-4