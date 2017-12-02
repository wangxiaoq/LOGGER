#ifndef LOGGER_H

#define LOGGER_H
#include <stdio.h>

enum {
    DEBUG_LEVEL,
    INFO_LEVEL,
    ERROR_LEVEL
};

extern FILE *log_fp;
extern int global_log_level;

int logger_set_conf_file(const char *conf);

void logger_set_log_level(int log_level);

#define write_log_file(format, args...) \
{ \
    fprintf(log_fp, "[%s %s] ", __DATE__, __TIME__); \
    fprintf(log_fp, "[file: %s, line: %d, function: %s] ", __FILE__, __LINE__, __FUNCTION__); \
    fprintf(log_fp, format, args); \
    fprintf(log_fp, "\n"); \
    fflush(log_fp); \
} 

#define logger_debug_log(format, args...) \
{ \
    if (global_log_level == DEBUG_LEVEL) { \
        fprintf(log_fp, "[DEBUG] "); \
        write_log_file(format, args); \
    } \
}

#define logger_info_log(format, args...) \
{ \
    if (global_log_level <= INFO_LEVEL) { \
        fprintf(log_fp, "[INFO]  "); \
        write_log_file(format, args); \
    } \
}

#define logger_err_log(format, args...) \
{ \
    if (global_log_level <= ERROR_LEVEL) { \
        fprintf(log_fp, "[ERROR] "); \
        write_log_file(format, args); \
    } \
}

#endif
