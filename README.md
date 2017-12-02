# LOGGER

LOGGER是一个Linux下通用的日志记录器，记录程序在执行过程中打印的信息，便于用户调试。为了方便用户使用提供了以下几个接口：

## C使用方法及接口

1. 将仓库克隆到本地，然后将仓库源代码拷贝到你的项目所在的目录下：

    `git clone https://github.com/wangxiaoq/LOGGER`

    `cd LOGGER/c`

    `cp logger.c logger.h /PATH/TO/YOUR/PROJECT`

2. 在你的源代码中包含以下头文件：

    `#include "logger.h"`

3. 在你的源代码中使用下面的接口进行初始化：

    `int logger_set_conf_file(const char *conf);`

   logger_set_conf_file函数用来设置日志文件，参数@conf为路径名和日志文件名字，可以使用绝对路径和相对路径，例如：“/var/log/mylog”或者“./mylog”，对于参数@conf有以下三种情况：

   * @conf指定的日志文件在系统中已经存在 - 若@conf已经指定到日志文件，则打开文件后每次在文件末尾追加日志，例如/var/log/mylog；若@conf仅指定了目录，没有指定日志文件，则报错；

   * @conf指定的日志文件路径不存在，但是路径是合法的，会直接创建这个日志文件；

   * @conf指定的日志文件路径不存在，且路径非法，函数出错返回；

   返回值：创建日志文件成功，返回0；否则返回-1；

4. 使用下面的函数设置日志级别：

    `void logger_set_log_level(int log_level);`

   日志有三种级别：

    DEBUG_LEVEL - 打印5中三个宏写入的所有信息；

    INFO_LEVEL - 只打印由logger_info_log和logger_err_log写入的信息；

    ERROR_LEVEL - 只打印由logger_err_log写入的信息；

5. 使用下面的宏保存日志信息到日志文件中：

    `logger_debug_log(char *format, ...);`

    `logger_info_log(char *format, ...);`

    `logger_err_log(char *format, ...);`

   上面三个函数依次分别是打印调试信息、日常信息和错误信息。

6. 使用例子

   在仓库的c/example目录下有使用例子，这个目录下有三个文件longer.c、longer.h和test.c，其中前两个文件是从LOGGER/c目录下拷贝过来的，tester.c才是真正的例子，tester.c文件的内容如下：

```
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
```
   这个程序会在可执行文件运行的目录下创建一个日志文件test-log，因为日志的级别是DEBUG_LEVEL，所以日志文件中会写入三条日志信息。使用方法如下：

    `gcc test.c logger.c -o test`

    `./test`

    `cat ./test-log`

   显示信息如下：

   ```
[DEBUG] [Dec  2 2017 19:39:31] [file: test.c, line: 7, function: main] debug log
[INFO] [Dec  2 2017 19:39:31] [file: test.c, line: 8, function: main] info log
[ERROR] [Dec  2 2017 19:39:31] [file: test.c, line: 9, function: main] error log
   ```


## C++使用方法及接口（TODO）

## python使用方法及接口（TODO）

## JAVA使用方法及接口（TODO）
