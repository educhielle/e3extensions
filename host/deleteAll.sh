declare -a arr=("bsort" "fact" "fib" "isort" "mm" "soe")
k=1024
b=8
for i in "${arr[@]}"
do
    cd $i
    rm $i.log
    rm $i-K$k-B$b.*
    rm CS.txt
    cd ..
done
