// https://github.com/lattera/glibc/blob/master/bits/sockaddr.h
/* POSIX.1g specifies this type name for the `sa_family' member.  */
typedef unsigned short int sa_family_t;

#define __SOCKADDR_COMMON(sa_prefix) sa_family_t sa_prefix##family

// https://github.com/lattera/glibc/blob/master/bits/socket.h

struct sockaddr {
  __SOCKADDR_COMMON(sa_); /* Common data: address family and length.  */
  char sa_data[14];       /* Address data.  */
};

// https://github.com/lattera/glibc/blob/master/inet/netinet/in.h
struct sockaddr_in {
  __SOCKADDR_COMMON(sin_);
  in_port_t sin_port;      /* Port number.  */
  struct in_addr sin_addr; /* Internet address.  */

  /* Pad to size of `struct sockaddr'.  */
  unsigned char sin_zero[sizeof(struct sockaddr) - __SOCKADDR_COMMON_SIZE -
                         sizeof(in_port_t) - sizeof(struct in_addr)];
};

typedef uint32_t in_addr_t;
struct in_addr {
  in_addr_t s_addr;
};

/* Address to accept any incoming messages.  */
#define INADDR_ANY ((in_addr_t)0x00000000)
/* Address to send to all hosts.  */
#define INADDR_BROADCAST ((in_addr_t)0xffffffff)
/* Address indicating an error return.  */
#define INADDR_NONE ((in_addr_t)0xffffffff)

/* Network number for local host loopback.  */
#define IN_LOOPBACKNET 127
/* Address to loopback in software to local host.  */
#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK ((in_addr_t)0x7f000001) /* Inet 127.0.0.1.  */
#endif
