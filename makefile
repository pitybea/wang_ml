GXX=g++
layer.o : model/nn/layer.cpp
	$(GXX) -std=c++11 -o layer.o -c model/nn/layer.cpp
