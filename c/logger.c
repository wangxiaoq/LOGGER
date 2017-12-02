#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "logger.h"

#define DEFAULT_LOG_LEVEL INFO_LEVEL

FILE *log_fp = NULL;
int global_log_level = DEFAULT_LOG_LEVEL;

int logger_set_conf_file(const char *conf)
{
    int ret = 0;
    struct stat conf_info;
    memset(&conf_info, 0, sizeof(conf_info));

    ret = stat(conf, &conf_info);
    if (ret == 0) {
        if (S_ISREG(conf_info.st_mode)) {
            log_fp = fopen(conf, "a+");
            if (log_fp == NULL) {
                fprintf(stderr, "logger: open file %s error!\n", conf);
                return -1;
            }
        }else {
            fprintf(stderr, "logger: %s is not a regular file. Log file must be a regular file!\n", conf);
            return -1;
        }
    } else if (ret < 0){
        if (errno == ENOENT) {
            log_fp = fopen(conf, "a+");
            if (log_fp == NULL) {
                fprintf(stderr, "logger: open file %s error! Make sure it's a regular file!\n", conf);
                return -1;
            }
        } else {
            perror("stat");
            return -1;
        }
    }

    return 0;
}

void logger_set_log_level(int log_level)
{
    if (log_level < DEBUG_LEVEL) {
        global_log_level = DEBUG_LEVEL;
    } else if (log_level > ERROR_LEVEL) {
        global_log_level = ERROR_LEVEL;
    } else {
        global_log_level = log_level;
    }
}
