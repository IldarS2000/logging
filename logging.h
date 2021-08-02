#include <stdio.h>
#include <time.h>

#ifndef HEADER_H
#define HEADER_H

//#if __STDC_VERSION__ < 199901L
//# if __GNUC__ >= 2
//#  define __func__ __FUNCTION__
//# else
//#  define __func__ "<unknown function>"
//# endif
//#endif

#ifdef DEBUG 
#define log(...) do { \
  char buffer[20]; \
  time_t now = time(0); \
  struct tm* sTm = gmtime(&now); \
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", sTm); \
  printf("[%s:%d %s]: ", __FILE__, __LINE__, __func__); \
  printf(##__VA_ARGS__); \
} while (0);
#else
#define log(...) do { \
} while (0);
#endif // DEBUG

#endif // HEADER_H