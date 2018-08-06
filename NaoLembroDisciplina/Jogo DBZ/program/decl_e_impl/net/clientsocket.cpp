#include "clientsocket.h"
#include "socketexception.h"

ClientSocket::ClientSocket ( std::string host, int port )
{
   if ( ! Socket::create() )
   {
      throw SocketException ( "Não foi possível criar socket cliente." );
   }

   if ( ! Socket::connect ( host, port ) )
   {
      throw SocketException ( "Não foi possível vincular à porta." );
   }
}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
   if ( ! Socket::send ( s ) )
   {
      throw SocketException ( "Não foi possível gravar socket." );
   }

   return *this;

}


const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
   if ( ! Socket::recv ( s ) )
   {
      throw SocketException ( "Impossível ler socket." );
   }

   return *this;
}
