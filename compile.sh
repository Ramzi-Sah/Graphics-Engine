cd bin/build/standaloan

echo ---------------- Compiling ----------------
cmake ../../.. || exit 1
make || exit 1
echo ------------ build successfull ------------

cd ../../..
bin/build/standaloan/SAHEB_Engine
