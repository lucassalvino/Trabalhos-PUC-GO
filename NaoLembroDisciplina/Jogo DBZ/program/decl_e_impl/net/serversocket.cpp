#include "serversocket.h"
#include "socketexception.h"

ServerSocket::ServerSocket ( int port )
{
   if ( ! Socket::create() )
   {
      throw SocketException ( "Não foi possível criar socket do servidor." );
   }

   if ( ! Socket::bind ( port ) )
   {
      throw SocketException ( "Não foi possível vincular à porta." );
   }

   if ( ! Socket::listen() )
   {
      throw SocketException ( "Não foi possível ouvir ao socket." );
   }

}

ServerSocket::~ServerSocket()
{

}

const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
   if ( ! Socket::send ( s ) )
   {
      throw SocketException ( "Não foi possível gravar socket." );
   }

   return *this;
}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
   if ( ! Socket::recv ( s ) )
   {
      throw SocketException ( "Não foi possível ler socket." );
   }

   return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
   if ( ! Socket::accept ( sock ) )
   {
      throw SocketException ( "Não podia aceitar socket." );
   }
}
