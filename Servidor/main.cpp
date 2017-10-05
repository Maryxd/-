#include <iostream>
#include "rmRef_H.h"
#include "Lista.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
int servidor();
string& bufferToString(char* buffer, int bufflen, string& str);

int tamano = 15;
char memory[15];//Memoria del systema
char* indicador; //apunta donde hay espacio vacio
Lista listaControl=Lista();//Se guardan los valores para llevar un control llave-valor




string reservar_mem(rmRef_H * estructura){//Reserva memoria para almacenar
 bool var1=true;//variable auxiliar
 int i=0;
 while(var1){//Recorre cada espacio de la memoria revisando si se encuentra libre para almacenar

    if(memory[i]==0){// si es 0 entonces está disponible el espacio
        cout << "LALALALALALA: "<< i << endl;
        bool var=true;
        int j=0;
        while((memory[i+j]==0) & var & (j< estructura->tamano) & ((i+j)<tamano)){//si el espacio de memoria está disponible y además j no es el el tamaño total del valor a almacenar entonces entra
            cout << "JOJOJOJO: "<< j << "___" << estructura->tamano << endl;
            if(j==estructura->tamano-1){//si j es igual al tamaño-1 entonces se comienza a reservar el bloque de memoria solicitado
                for (int K=0; K<j+1;K++){//para reservar, en cada espacio de memoria guarda el valor a reservar


                *(memory+(i+K))=estructura->valor;
                }
                estructura->ptr=&memory[i];//el puntero referencia la posición de memoria dónde se encuentra
                cout << "llll"<< *(estructura->ptr) << endl;

                listaControl.insert(estructura);//además añade a la lista de control la nueva estructura con el valor almacenado

            var=false;//se sale de los bucles ya que encontró espacio para almacenar y debe serguir buscando
            var1=false;
            }
            j++;//si aún no se recorren los espacios de memoria vacio necesarios se le suma 1 a j para seguir recorriendo
        }
    if(i==tamano){//si llega al final del bloque de memoria es porque no encontró espacio
        var1=false;//detiene todo el bucle
        cout << "No hay espacio disponible, por favor libere espacio" << endl;
        return "No hay espacio disponible, por favor libere espacio";
    }





    }
    i++;
    //cout << i << endl;
 }
 return "ALMACENADO";
}

rmRef_H* get(char* key){
    for (int i=0; i<listaControl.getSize();i++){
        if(listaControl.getValue(i)->llave==*key){
            (listaControl.getValue(i)->contador)++;
            return listaControl.getValue(i);
        }

    }

}

int promedio(){
    int aux=0;
     for (int i=0; i<listaControl.getSize();i++){
        cout << "PROMEDIOCCCC"  <<   listaControl.getValue(i)->contador << endl;
       aux=aux+listaControl.getValue(i)->contador;
     }
     return aux/listaControl.getSize();
}

void recolector(){//elimina la memoria que no está siendo referenciada
    int aux=promedio();
    for (int i=0; i<listaControl.getSize();i++){
        if((listaControl.getValue(i)->contador)<aux){
            for(int j=0; j<listaControl.getValue(i)->tamano; j++){
                *(listaControl.getValue(i)->ptr+j)=0;
                cout << "BORRANDO"  << i << endl;

            }
            listaControl.eliminarElemento(i);
            i=0;
        }
    }

}



int main()
{
    cout << "SIZE: "<< listaControl.getValue(0)<< endl;
    for(int i=0;  i<tamano; i++){
        memory[i]=0;
    }

    char d= '8';
    char d1= 'l';
    char d2= 'j';
    char d3= 'm';
    char d4= '9';
    int b= 5;

    rmRef_H j= rmRef_H(d,b,3);
    rmRef_H j1= rmRef_H(d1,8,3);
    rmRef_H j2= rmRef_H(d2,9,3);
    rmRef_H j3= rmRef_H(d3,12,3);
    rmRef_H j4= rmRef_H(d4,99,3);

    reservar_mem(&j);
    reservar_mem(&j1);
    reservar_mem(&j2);
    reservar_mem(&j3);






    //j.ptr=&memory[0];
    //for(int i=0;  i<tamano; i++){
    //cout << "Hello world!"  <<   (int)memory[i] << endl;
    //}

    char v= '7';
    int z= 6;

    rmRef_H y= rmRef_H(v,z,1);

    reservar_mem(&y);
cout << "TAMAAAÑOOOOOOOOOOOOOOO"  <<   listaControl.getSize() << endl;
    reservar_mem(&j4);

    int p = get(&v)->contador;
    int u = get(&d3)->contador;
    int p1 = get(&d3)->contador;
    int r = get(&d)->contador;
    int r1 = get(&d)->contador;
    int r2 = get(&d)->contador;
    int r3 = get(&d)->contador;
    int r4 = get(&d)->contador;
    int n = get(&d1)->contador;
    int w = get(&d2)->contador;
    recolector();



    cout << "CHAR"  <<   u << endl;
     //cout << "PROMEDIO"  <<   promedio() << endl;
     cout << "PROMEDIO"  <<   listaControl.getSize() << endl;
    cout << "ttttttttttttt"  <<   j.valor<< endl;
    cout << "JHGFD"  <<   listaControl.getValue(0)->valor<< endl;

    for(int i=0;  i<tamano; i++){
    cout << "BLOQUE" << i << ": "   <<   (int)memory[i] << endl;
    }

    //listaControl.eliminarElemento(1);

for(int l=0;  l<listaControl.getSize(); l++){
    cout << "KKKlKK"  <<   (int)*listaControl.getValue(l)->ptr << endl;
    }



servidor();

return 0;

}

int servidor(){
    /* ---------- INITIALIZING VARIABLES ---------- */

    /*
       1. client/server are two file descriptors
       These two variables store the values returned
       by the socket system call and the accept system call.

       2. portNum is for storing port number on which
       the accepts connections

       3. isExit is bool variable which will be used to
       end the loop

       4. The server reads characters from the socket
       connection into a dynamic variable (buffer).

       5. A sockaddr_in is a structure containing an internet
       address. This structure is already defined in netinet/in.h, so
       we don't need to declare it again.

        DEFINITION:

        struct sockaddr_in
        {
          short   sin_family;
          u_short sin_port;
          struct  in_addr sin_addr;
          char    sin_zero[8];
        };

        6. serv_addr will contain the address of the server

        7. socklen_t  is an intr type of width of at least 32 bits


    */
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    /*
        The socket() function creates a new socket.
        It takes 3 arguments,

            a. AF_INET: address domain of the socket.
            b. SOCK_STREAM: Type of socket. a stream socket in
            which characters are read in a continuous stream (TCP)
            c. Third is a protocol argument: should always be 0. The
            OS will choose the most appropiate protocol.

            This will return a small integer and is used for all
            references to this socket. If the socket call fails,
            it returns -1.

    */

    cout << "\n=> Socket server has been created..." << endl;

    /*
        The variable serv_addr is a structure of sockaddr_in.
        sin_family contains a code for the address family.
        It should always be set to AF_INET.

        INADDR_ANY contains the IP address of the host. For
        server code, this will always be the IP address of
        the machine on which the server is running.

        htons() converts the port number from host byte order
        to a port number in network byte order.

    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    /* ---------- BINDING THE SOCKET ---------- */
    /* ---------------- bind() ---------------- */


    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    /*
        The bind() system call binds a socket to an address,
        in this case the address of the current host and port number
        on which the server will run. It takes three arguments,
        the socket file descriptor. The second argument is a pointer
        to a structure of type sockaddr, this must be cast to
        the correct type.
    */

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

    /* ------------- LISTENING CALL ------------- */
    /* ---------------- listen() ---------------- */

    listen(client, 1);

    /*
        The listen system call allows the process to listen
        on the socket for connections.

        The program will be stay idle here if there are no
        incomming connections.

        The first argument is the socket file descriptor,
        and the second is the size for the number of clients
        i.e the number of connections that the server can
        handle while the process is handling a particular
        connection. The maximum size permitted by most
        systems is 5.

    */

    /* ------------- ACCEPTING CLIENTS  ------------- */
    /* ----------------- listen() ------------------- */

    /*
        The accept() system call causes the process to block
        until a client connects to the server. Thus, it wakes
        up the process when a connection from a client has been
        successfully established. It returns a new file descriptor,
        and all communication on this connection should be done
        using the new file descriptor. The second argument is a
        reference pointer to the address of the client on the other
        end of the connection, and the third argument is the size
        of this structure.
    */

    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server < 0)
        cout << "=> Error on accepting..." << endl;

    while (server > 0)
    {
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
        cout << "\n=> Enter # to end the connection\n" << endl;

        /*
            Note that we would only get to this point after a
            client has successfully connected to our server.
            This reads from the socket. Note that the read()
            will block until there is something for it to read
            in the socket, i.e. after the client has executed a
            the send().

            It will read either the total number of characters
            in the socket or 1024
        */

        cout << "Client: ";
        do {
            recv(server, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }


        } while (*buffer != '*');

        do {
            cout << "\nServer: ";
            do {
                //cin >> buffer;
                send(server, buffer, bufsize, 0);
                if (*buffer == '#') {
                    send(server, buffer, bufsize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');

            cout << "Client: ";
            do {
                recv(server, buffer, bufsize, 0);
                cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    isExit = true;
                }

                if(*buffer=='+'){
                string temp;
                string dato;
                string caracter;
                string caracter2;
                string llave;
                string valor;
                string tamano1;
                int variable=5;
                int contador=0;
                bufferToString(buffer,1024,dato);
                caracter=dato[variable];
                cout << dato << "\n";
                while(contador < 3){
                    temp+=caracter;
                    caracter2=dato[(variable+1)];

                    if(caracter2==","){
                        if(contador==0){
                            llave=temp;
                            temp="";
                            variable++;

                        }
                        if(contador==1){
                            valor=temp;
                            temp="";
                            variable++;

                        }
                        if(contador==2){
                            tamano1=temp;
                            temp="";
                            variable++;

                        }
                        contador++;


                    }

                    variable++;
                    caracter=dato[variable];



                }

                cout << "LLAVE: " << llave << endl;
                cout << "VALOR: " << valor << endl;
                cout << "TAMAÑO: " << tamano1 << endl;

                char *cstr = new char[llave.length() + 1];
                strcpy(cstr, llave.c_str());
                int valor1=atoi(valor.c_str());
                int tamano12=atoi(tamano1.c_str());
                rmRef_H* estructura1;
                estructura1= new rmRef_H(*cstr,valor1,tamano12);

                strcpy(buffer, reservar_mem(estructura1).c_str());
                send(server, buffer, bufsize, 0);

                for(int i=0;  i<tamano; i++){
    cout << "BLOQUE" << i << ": "   <<   (int)memory[i] << endl;
    }

                for(int l=0;  l<listaControl.getSize(); l++){
    cout << "KKKlKK"  <<   (int)*listaControl.getValue(l)->ptr << endl;
    }

                }
            } while (*buffer != '*');
        } while (!isExit);

        /*
            Once a connection has been established, both ends
            can both read and write to the connection. Naturally,
            everything written by the client will be read by the
            server, and everything written by the server will be
            read by the client.
        */

        /* ---------------- CLOSE CALL ------------- */
        /* ----------------- close() --------------- */

        /*
            Once the server presses # to end the connection,
            the loop will break and it will close the server
            socket connection and the client connection.
        */

        // inet_ntoa converts packet data to IP, which was taken from client
        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        isExit = false;
        exit(1);
    }

    close(client);

    }


    string& bufferToString(char* buffer, int bufflen, string& str){
        char temp[bufflen];
        memset(temp, '\0', bufflen + 1);
        strncpy(temp, buffer, bufflen);
        return (str.assign(temp));
    }

