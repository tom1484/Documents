if [ ! -d $1 ]; then
	mkdir $1
fi

cp template.cpp $1/$1.cpp

sed -i "s/TASK:\ /TASK:\ ${1}/g" $1/$1.cpp
sed -i "s/\.in/${1}.in/g" $1/$1.cpp
sed -i "s/\.out/${1}.out/g" $1/$1.cpp

touch $1/$1.in
