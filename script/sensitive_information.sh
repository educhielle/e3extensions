obj="../obj"
src="../src"

obj_treat="$obj/treat"
src_treat="$src/treat"

if ! [ -d "$obj_treat" ]; then
	mkdir $obj_treat
fi

./unumber.sh
echo -n "Compiling SensitiveInformation..."
g++ -c -Wall -O2 -std=c++14 -fno-strict-aliasing  -fPIC $src_treat/sensitive_information.h -o $obj_treat/sensitive_information.o
echo "done"
