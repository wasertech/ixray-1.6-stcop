---
applyTo: '**'
---
We just implemented Vulkan support in IX-Ray, we need to switch all cpp and header files for cross-compilation.
My current system is arch based but it should work for windows too. I have write some scripts to help you.
```
# Syntax check using the system
util/arch/test-pkgbuild.sh

# this will take a while, be patient
# it will generate ./build.log

# find the next file to fix
util/arch/parse-build-log.sh
# this will create ./debug.err.log and ./debug.warn.log
# debug.err.log is the most important one
```
Then (after waiting a bit) you can read the debug file output `./debug.err.log`.
I've generated two log files already. This takes a while, don't remove the logs. Just focus on fixing the next file.
When modifying a file, always use english comments and front-facing messages. Never write in french.