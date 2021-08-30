#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef LOGGING_H
#define LOGGING_H

#define DEBUG
#ifdef DEBUG

#ifdef _WIN32
#define __SHORT_FILE__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __SHORT_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define LOG_HELPER(format, loglevel, ...) \
do { \
  char message[1024] = {0}; \
  char bufferTime[20] = {0}; \
  time_t now = time(0); \
  struct tm* sTm = gmtime(&now); \
  strftime(bufferTime, sizeof(bufferTime), "%Y-%m-%d %H:%M:%S", sTm); \
  sprintf_s(message, 1024, "%s [%s] [%s] [%s:%d] %s", \
            bufferTime, loglevel, __func__, __SHORT_FILE__, __LINE__, format, ##__VA_ARGS__); \
  printf(message); \
} while (0);
#else
#define LOG_HELPER(...)
#endif // DEBUG

#define LOG_DEBUG(format, ...) LOG_HELPER(format, "DEBUG", ## __VA_ARGS__)
#define LOG_INFO(format, ...) LOG_HELPER(format, "INFO", ## __VA_ARGS__)
#define LOG_WARN(format, ...) LOG_HELPER(format, "WARN", ## __VA_ARGS__)
#define LOG_ERROR(format, ...) LOG_HELPER(format, "ERROR", ## __VA_ARGS__)

#endif // LOGGING_H
