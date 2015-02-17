#!/bin/bash

#SE COMPRUEBA SI EL NOMBRE DEL ZIP SIGUE EL FORMATO
RES=`echo "$1" | grep -E '^ssoo_p1(_100[[:digit:]]{6}){1,2}.zip$'`
if [ "$RES" = "" ] ;then
	echo "ZIP name/format ERROR"
	exit 1
fi
echo "ZIP name/format OK"

#SE COMPRUEBA SI EL FICHERO EXISTE
if [ ! -f "$1" ] ;then
	echo "ZIP does not exist"
	exit 1
fi

#SE DESCOMPRIME EL ZIP EN UNA CARPETA SEPARADA PARA LAS PRUEBAS
unzip $1 -d unzip
cd unzip

#SE COMPRUEBA QUE EL ZIP CONTIENE LOS FICHEROS myls.c y Makefile
if [ -f "myls.c" ]
then
	echo -e "myls.c OK"
else
	echo -e "myls.c ERROR"
	exit 1
fi
if [ -f "Makefile" ]
then
	echo -e "Makefile OK"
else
	echo -e "Makefile ERROR"
	exit 1
fi

#SE COMPRUEBA SI EL PROGRAMA myls COMPILA
make myls &> compile_myls
if [ -f myls ]
then
	echo -e "LS Compilation OK"
else
	echo -e "LS Compilation ERROR"
	exit 1
fi

#SE COMPRUEBA SI EL PROGRAMA myls COMPILA SIN WARNINGS
W=`cat compile_myls | grep warning | wc -l`
if [ $W -eq 0 ]
then
	echo -e "LS Warnings OK"
else
	echo -e "LS Warnings ERROR"
fi

#SE PREPARA CONTENIDO ADICIONAL PARA EL TEST
mkdir testdir1
touch testdir1/fich1
touch testdir1/fich2
mkdir testdir1/testdir2

#SE COMPARA LA SALIDA DEL PROGRAMA myls CON LA DEL COMANDO EQUIVALENTE
timeout 2 ./myls testdir1 > tmp 
TIME=$?
ls -1f testdir1 > tmp2
DIFF=`diff tmp tmp2 | wc -l`

if [ $DIFF -eq 0 ] && [ $TIME -eq 0 ];
then
	echo -e "LS OK"
else
	echo -e "LS ERROR"
fi

#SE ELIMINA LA CARPETA DE PRUEBAS
cd ..
rm -rf unzip
