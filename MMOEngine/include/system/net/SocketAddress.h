/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef SOCKETADDRESS_H_
#define SOCKETADDRESS_H_

#include "../platform.h"

#ifndef PLATFORM_WIN
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#else
#include <winsock2.h>
#endif

using namespace std;

namespace sys {
  namespace net {

	class SocketAddress {
		struct sockaddr_in addr;
	
	public:
		SocketAddress();
		SocketAddress(int port);
		SocketAddress(const string& host, int port);
	
		void clear();
	
		int compareTo(SocketAddress* addr);
	
		struct sockaddr* getAddress();
		
	    string getIPAddress();
	
	    uint16 getPort();
	    
	    string getFullIPAddress();
	
	    string getFullPrintableIPAddress();
	
		uint64 getNetworkID();
	
		uint32 getIPID();
	    
		inline int getAddressSize() {
			return sizeof(addr);
		}
		
	};

  } // namespace net
} // namespace sys

using namespace sys::net;

#endif /*SOCKETADDRESS_H_*/
