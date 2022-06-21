#!/bin/bash

echo -n "Which module? "
read m

module=cpp-module-0${m}
git checkout -b ${module}
mkdir ${module}
cd ${module}

curl https://raw.githubusercontent.com/mlanca-c/cpp-piscine/main/README.tmp.md > README.md
curl https://raw.githubusercontent.com/mlanca-c/cpp-piscine/main/Makefile > Makefile

echo -n "How many exercises? "
read nu

i=0
big=ex
small=ex0


while [ $i -lt 100 ]
do

	if [ $i -eq ${nu} ]
	then
		break
	elif [ $i -lt 10 ]
	then
		exercise=${small}$i
	else
		exercise=${big}$i
	fi

	mkdir ${exercise}
	cd ${exercise}
	cp -rf ../Makefile ./
	make .init
	cd ../

	i=$((i+1))
done

date > .init
git add .init
make .init
git commit -m "init"
rm -rf Makefile
cd ../
rm -rf cpp-module-start.sh
rm -rf README.tmp.md
rm -rf Makefile
