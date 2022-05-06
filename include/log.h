#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <unistd.h>
#include <sys/file.h>
#include <stdio.h>

#ifndef TY_NO_LOG
#define LOG(...) do { \
                        flockfile(stderr), \
                        fprintf(stderr, "(%d) ", getpid()), \
                        fprintf(stderr, __VA_ARGS__), \
                        fprintf(stderr, "\n"), \
                        funlockfile(stderr); \
                } while (0)
#else
#define LOG(...) ;
#endif

#define TID ((unsigned long long)pthread_self())

#if 0
  #define GCLOG(fmt, ...) fprintf(stderr, "(%14llu): " fmt "\n", TID, __VA_ARGS__)
#else
  #define GCLOG LOG
#endif

#endif
