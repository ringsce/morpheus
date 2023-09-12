cmake_minimum_required(VERSION 3.16)
project(neon LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

qt_add_executable(neon
    addtorrentdialog.cpp addtorrentdialog.h
    addtorrentform.ui
    bencodeparser.cpp bencodeparser.h
    connectionmanager.cpp connectionmanager.h
    filemanager.cpp filemanager.h
    main.cpp
    mainwindow.cpp mainwindow.h
    metainfo.cpp metainfo.h
    peerwireclient.cpp peerwireclient.h
    ratecontroller.cpp ratecontroller.h
    torrentclient.cpp torrentclient.h
    torrentserver.cpp torrentserver.h
    trackerclient.cpp trackerclient.h
)

set_target_properties(neon PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(neon PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Widgets
)

# Resources:
set(icons_resource_files
    "icons/1downarrow.png"
    "icons/1uparrow.png"
    "icons/bottom.png"
    "icons/exit.png"
    "icons/peertopeer.png"
    "icons/player_pause.png"
    "icons/player_play.png"
    "icons/player_stop.png"
)

qt_add_resources(neon "icons"
    PREFIX
        "/"
    FILES
        ${icons_resource_files}
)

