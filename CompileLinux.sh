#!/bin/bash
op="$1"
binary_name="linux-out"
linux_dir=linux
if [ "$op" = "clean" ]; then
	rm -rf $linux_dir/*.o
	rm -rf $linux_dir/*.a
	rm -rf $binary_name
	exit 0;
fi

g++ -c linux-socket-connection.cpp -o $linux_dir/linux-socket-connection.o --std=c++11 
ar cr $linux_dir/liblinuxsocket.a $linux_dir/linux-socket-connection.o
g++ server.cpp -o $binary_name -L$linux_dir -I$linux_dir -llinuxsocket --std=c++11
