FinalBinary=dist_linux

Compiler_Linux=g++
LIBRARRYS=-lGL -ldl -lglfw

compile_execute:
	$(Compiler_Linux) source/*.cpp source/*/*.cpp source/*/*/*.cpp source/include/*.c -o build/$(FinalBinary) $(LIBRARRYS)
	build/$(FinalBinary)

compile:
	$(Compiler_Linux) source/*.cpp -o build/$(FinalBinary) $(LIBRARRYS)

execute:
	build/$(FinalBinary)

monitor:
	top -p `pidof $(FinalBinary)`

gpuInfo:
	watch -n 0.5 nvidia-smi
