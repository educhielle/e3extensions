declare -a arr=("bsort" "fact" "fib" "isort" "mm" "soe")
k=1024
b=8
cd ..
for i in "${arr[@]}"
do
    make preprocess IN=host/$i/$i.cpp OUT=host/$i/$i-K$k-B$b.cpp KEY_SIZE=$k BETA=$b
    make compile-all IN=host/$i/$i-K$k-B$b.cpp OUT=host/$i/$i-K$k-B$b.elf FAST_RANDOM=1 GMP=1 STATIC_LIBG=1 STATIC_LIBGCC=1 STATIC_LIBSTDCPP=1 STATIC=1
done
cd host
