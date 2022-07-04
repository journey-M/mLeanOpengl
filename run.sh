echo $#

if [[ $# -gt 0 && $1 -eq 'clean' ]];
then rm build -rf
fi

if [ ! -d build ];
then mkdir build;
fi


cd build 
cmake ../CMakeLists.txt
make -j6
./glrun
