if [ $# -gt 0 ] && [ $1 -gt 0 ]; then
  export F=all && export D=host/$F && export R=$D/$F && export export K=1024 && export B=8 && make compile-all IN=$R-K$K-B$B.cpp OUT=$R-K$K-B$B-CoPHEE-${1}.elf FAST_RANDOM=1 GMP=1 STATIC_LIBG=1 STATIC_LIBGCC=1 STATIC_LIBSTDCPP=1 STATIC=1 COPHEE=${1}
  # export F=all && export D=host/$F && export R=$D/$F && export export K=1024 && export B=8 && make compile-all IN=$R-K$K-B$B.cpp OUT=$R-K$K-B$B-CoPHEE-2.elf FAST_RANDOM=1 GMP=1 STATIC_LIBG=1 STATIC_LIBGCC=1 STATIC_LIBSTDCPP=1 STATIC=1 COPHEE=2
else
  export F=all && export D=host/$F && export R=$D/$F && export export K=1024 && export B=8 && make compile-all IN=$R-K$K-B$B.cpp OUT=$R-K$K-B$B.elf FAST_RANDOM=1 GMP=1 STATIC_LIBG=1 STATIC_LIBGCC=1 STATIC_LIBSTDCPP=1 STATIC=1
fi
