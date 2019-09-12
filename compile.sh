cd build
echo ---------------- Compiling ----------------
cmake .. || exit 1
make || exit 1
echo ------------ build successfull ------------
cd ..
build/SAH_Engine
