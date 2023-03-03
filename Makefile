CPUS=$(shell nproc)

all:
	mkdir -p build
	cd build && cmake ..
	cd build && make -j$(CPUS)

packge-deb: all
	cd build && cmake -DPACKAGE_DEB=ON ..
	cd build && make package