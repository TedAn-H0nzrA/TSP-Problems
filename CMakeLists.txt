cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(TSP_Problems)

# Utilisation de C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Définition des dossiers
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/out)
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)
set(FONTS_DIR ${ASSETS_DIR}/fonts)
set(MUSICS_DIR ${ASSETS_DIR}/music)

# Ajout récursif des fichiers sources (limité à Ant et Environment)
file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/core/*.cpp"
    "${SRC_DIR}/entity/*.cpp"
    "${SRC_DIR}/utils/*.cpp"
)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Inclusion des headers (limité à Ant et Environment)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDE_DIR}
    ${INCLUDE_DIR}/core
    ${INCLUDE_DIR}/entity
    ${INCLUDE_DIR}/utils
)

# Définition des macros accessibles dans tout le projet
target_compile_definitions(${PROJECT_NAME} PRIVATE
    ASSETS_DIR="${ASSETS_DIR}"
    FONTS_DIR="${FONTS_DIR}"
    MUSICS_DIR="${MUSICS_DIR}"
)

# Lien avec SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

# Copie des assets dans le dossier de build
file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Définir le dossier de sortie de l'exécutable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
)