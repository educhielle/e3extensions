declare -a arr=("bsort" "fact" "fib" "isort" "mm" "soe")
k=1024
b=8
for i in "${arr[@]}"
do
    cd $i
    { time ./$i-K$k-B$b.elf 1; } 2> $i.log
    cd ..
done
