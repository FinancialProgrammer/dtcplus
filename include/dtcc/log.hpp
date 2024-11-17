#pragma once
#include <cstdio>
#ifndef LOG
  #define LOG(msg, ...) std::printf(msg "\n", ##__VA_ARGS__)
#endif

#ifndef WARN
  #define WARN(msg, ...) std::printf(msg "\n", ##__VA_ARGS__)
#endif

#ifndef ERR
  #define ERR(msg, ...) std::fprintf(stderr, msg "\n", ##__VA_ARGS__)
#endif