
TABLE_GENERATOR_PATH = ./Generators/Table
TABLE_GENERATOR_NAME = tableGen

DATABASE_GENERATOR_PATH = ./Generators/Database
DATABASE_GENERATOR_NAME = databaseGen

DB_PATH = /usr/lib/mydatabase/

TABLE_GEN_SRC = $(wildcard $(TABLE_GENERATOR_PATH)/*.cpp)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror 

VARS = -DDB_PATH=$(DB_PATH)

compile_generators:

	