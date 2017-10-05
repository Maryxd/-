#ifndef RMLIB_H
#define RMLIB_H
#include "rmRef_H.h"

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <thread>

using namespace std;

int portNum = 1500; // NOTE that the port number is same for both client and server
int portNum2= 8080;

int cliente()
{
    /* ---------- INITIALIZING VARIABLES ---------- */

    /*
       1. client is a file descriptor to store the values
       returned by the socket system call and the accept
       system call.

       2. portNum is for storing port number on which
       the accepts connections

       3. isExit is bool variable which will be used to
       end the loop

       4. The client reads characters from the socket
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

    */

    int client;

    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

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

    cout << "\n=> Socket client has been created..." << endl;

    /*
        The variable serv_addr is a structure of sockaddr_in.
        sin_family contains a code for the address family.
        It should always be set to AF_INET.

        htons() converts the port number from host byte order
        to a port number in network byte order.

    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    // this function returns returns 1 if the IP is valid
    // and 0 if invalid
    // inet_pton converts IP to packets
    // inet_ntoa converts back packets to IP
    //inet_pton(AF_INET, ip, &server_addr.sin_addr);

    /*if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server " << inet_ntoa(server_addr.sin_addr) << " with port number: " << portNum << endl;*/


    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    /*
        The connect function is called by the client to
        establish a connection to the server. It takes
        three arguments, the socket file descriptor, the
        address of the host to which it wants to connect
        (including the port number), and the size of this
        address.

        This function returns 0 on success and -1
        if it fails.

        Note that the client needs to know the port number of
        the server but not its own port number.
    */

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    cout << "            DIGITE LA OPCION DESEADA EN EL FORMATO INDICADO: " << endl;
    cout << "+NEW,key,valor,tamaño" << endl;
    cout << "-DELETE,key" << endl;
    cout << "$GET,key" << endl;
    // Once it reaches here, the client can send a message first.

    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

            if(*buffer=='+'){

            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);

    /* ---------------- CLOSE CALL ------------- */
    /* ----------------- close() --------------- */

    /*
        Once the server presses # to end the connection,
        the loop will break and it will close the server
        socket connection and the client connection.
    */

    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(client);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cliente2()
{
    /* ---------- INITIALIZING VARIABLES ---------- */

    /*
       1. client is a file descriptor to store the values
       returned by the socket system call and the accept
       system call.

       2. portNum is for storing port number on which
       the accepts connections

       3. isExit is bool variable which will be used to
       end the loop

       4. The client reads characters from the socket
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

    */

    int client;

    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

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

    cout << "\n=> Socket client has been created..." << endl;

    /*
        The variable serv_addr is a structure of sockaddr_in.
        sin_family contains a code for the address family.
        It should always be set to AF_INET.

        htons() converts the port number from host byte order
        to a port number in network byte order.

    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum2);

    // this function returns returns 1 if the IP is valid
    // and 0 if invalid
    // inet_pton converts IP to packets
    // inet_ntoa converts back packets to IP
    //inet_pton(AF_INET, ip, &server_addr.sin_addr);

    /*if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server " << inet_ntoa(server_addr.sin_addr) << " with port number: " << portNum << endl;*/


    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum2 << endl;

    /*
        The connect function is called by the client to
        establish a connection to the server. It takes
        three arguments, the socket file descriptor, the
        address of the host to which it wants to connect
        (including the port number), and the size of this
        address.

        This function returns 0 on success and -1
        if it fails.

        Note that the client needs to know the port number of
        the server but not its own port number.
    */

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Once it reaches here, the client can send a message first.

    do {
        cout << "Client: " << endl;
        cout << "            DIGITE LA OPCION DESEADA EN EL FORMATO INDICADO: " << endl;
        cout << "+ NEW,key,valor,tamaño" << endl;
        cout << "- DELETE,key" << endl;
        cout << "$ GET,key" << endl;
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }
            if(*buffer=='$'){

            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);

    /* ---------------- CLOSE CALL ------------- */
    /* ----------------- close() --------------- */

    /*
        Once the server presses # to end the connection,
        the loop will break and it will close the server
        socket connection and the client connection.
    */

    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(client);
    return 0;
}

void rm_init(char* ip,int port,char* ipHA,int portHA){
    portNum=port;
    portNum2=portHA;
    thread t1(cliente); // para conectarse con el server activo
    //thread t2(cliente2); //para conectarse al server pasivo
    t1.join();
    //t2.join();


}

void rm_new(char* key, int* value, int value_size){
    rmRef_H elemento= rmRef_H(key, value, value_size);
}

rmRef_H rm_get(char* key){


}

void rm_delete(rmRef_H* handler){

}

#endif // RMLIB_H
