#include "logger.h"

int main(void)
{
    int ret = logger_set_conf_file("./test-log");
    logger_set_log_level(DEBUG_LEVEL);
    logger_debug_log("%s", "debug log");
    logger_info_log("%s", "info log");
    logger_err_log("%s", "error log");

    return 0;
}
