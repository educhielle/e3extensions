bin="../bin"
obj="../obj"
src="../src"

obj_unumber="$obj/unumber"
src_treat="$src/treat"

./unumber.sh
# ./sensitive_information.sh

echo -n "Compiling Treat..."
g++ -Wall -O2 -std=c++14 -fno-strict-aliasing  $src_treat/treat.cpp \
$obj_unumber/unumberg.o $obj_unumber/cunmber_4096_m.o \
$obj_unumber/ma_invert_m.o \
-o $bin/treat
echo "done"
