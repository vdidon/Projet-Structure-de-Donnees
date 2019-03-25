cmake_minimum_required(VERSION 3.12)
project(Projet-Structure-de-Donnees)

#find_package(Boost REQUIRED COMPONENTS unit_test_framework)
#include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet-Structure-de-Donnees main.cpp contact.cpp contact.h listContact.cpp listContact.h jour.cpp jour.h agenda.cpp agenda.h rdv.cpp rdv.h listJour.cpp listJour.h temps.cpp temps.h date.h date.cpp vectorLite.h test.h)
#add_executable(Projet-Structure-de-Donnees main.cpp) #Pout les tests