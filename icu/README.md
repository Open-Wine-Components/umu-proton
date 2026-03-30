International Components for Unicode
------------------------------------

**Project URL:** https://github.com/unicode-org/icu

**License:** https://github.com/unicode-org/icu/blob/main/LICENSE

**Source:** https://github.com/unicode-org/icu/tree/release-68-2

**Release:** https://github.com/unicode-org/icu/releases/tag/release-68-2

```
icu4c-68_2-Win64-MSVC2019.zip
icu4c-68_2-Win32-MSVC2019.zip
```

Only the needed DLLs are repackaged to save space.


SHA256 Checksums
----------------

```
fb652b4d18e452fae886f8fed404d6b430587e744a117ffaa32e05e73e839a97  icu-6.8.2-x86/icudt68.dll
c7b8d528589f8e95e77ee42fe360b7d0be604bdb5ff2658d6ce15be2bec31d37  icu-6.8.2-x86/icuin68.dll
720c5009b6cc4ea641fc5bc803db9b425807989e8312512fc65b563268f284df  icu-6.8.2-x86/icuuc68.dll
cf4479a3f39d95c77058f39c5f49d104ec4f6d43e365aa13a2312066d2f5b024  icu-6.8.2-x86_64/icudt68.dll
87956cf4f8f8eb9e1860628fc5ce31e762d85ad3cfddad0824f0d45aaa4d5d78  icu-6.8.2-x86_64/icuin68.dll
c85a5848628cc5e17253e894bbea98868b76766714fe72673bd6ffefa0521f52  icu-6.8.2-x86_64/icuuc68.dll
```


Compilation
-----------

The DLLs export C++ symbols which means the build currently requires either MSVC
or clang on Windows. Because of that it's not feasible to build it along with
Proton. We are using pre-built versions redistributed by The Unicode Consortium
instead.
