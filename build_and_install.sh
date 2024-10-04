#!/usr/bin/env bash
set -e

# Compile mupdf
cd mupdf
make USE_SYSTEM_HARFBUZZ=yes
cd ..

# Compile sioyek
if [ -f "/usr/bin/qmake-qt5" ]; 
then
	QMAKE="/usr/bin/qmake-qt5"
elif [ -f "/usr/bin/qmake" ]; 
then
	QMAKE="/usr/bin/qmake"
else
	QMAKE="qmake"
fi

$QMAKE pdf_viewer_build_config.pro
# $QMAKE "CONFIG+=linux_app_image" pdf_viewer_build_config.pro
make
sudo make install
