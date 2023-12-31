#############################################################################
# Makefile for building: morpheus.app/Contents/MacOS/morpheus
# Generated by qmake (3.1) (Qt 5.9.7)
# Project:  morpheus.pro
# Template: app
# Command: /Users/pedro/opt/anaconda3/bin/qmake -o morpheus.xcodeproj/project.pbxproj morpheus.pro -spec macx-xcode
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/pedro/opt/anaconda3/bin/moc
UIC       = /Users/pedro/opt/anaconda3/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_DISABLE_DEPRECATED_BEFORE=0x040000 -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I../../../../opt/anaconda3/include/qt -I../../../../opt/anaconda3/include/qt/QtWidgets -I../../../../opt/anaconda3/include/qt/QtGui -I../../../../opt/anaconda3/include/qt/QtCore -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I../../../../opt/anaconda3/mkspecs/macx-clang
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: qrc_resources.cpp moc_predefs.h moc_mainwindow.cpp ui_mainwindow.h
compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		../../../../opt/anaconda3/bin/rcc \
		RINGSCE_v2.png
	/Users/pedro/opt/anaconda3/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: ../../../../opt/anaconda3/mkspecs/features/data/dummy.cpp
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -pipe -stdlib=libc++ -O2 -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h ../../../../opt/anaconda3/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: ../../../../opt/anaconda3/include/qt/QtWidgets/QMainWindow \
		src/mainwindow.h \
		moc_predefs.h \
		../../../../opt/anaconda3/bin/moc
	/Users/pedro/opt/anaconda3/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/pedro/opt/anaconda3/mkspecs/macx-clang -I/Users/pedro/Documents/Projects/ringsce-morpheus/morpheus -I/Users/pedro/opt/anaconda3/include/qt -I/Users/pedro/opt/anaconda3/include/qt/QtWidgets -I/Users/pedro/opt/anaconda3/include/qt/QtGui -I/Users/pedro/opt/anaconda3/include/qt/QtCore -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include src/mainwindow.h -o moc_mainwindow.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: src/mainwindow.ui \
		../../../../opt/anaconda3/bin/uic
	/Users/pedro/opt/anaconda3/bin/uic src/mainwindow.ui -o ui_mainwindow.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

