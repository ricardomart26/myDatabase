
TABLE_GENERATOR_PATH = ./Generators/Table
TABLE_GENERATOR_NAME = tableGen

DATABASE_GENERATOR_PATH = ./Generators/Database
DATABASE_GENERATOR_NAME = databaseGen

TABLE_GEN_SRC = $(wildcard $(TABLE_GENERATOR_PATH)/*.cpp)

CXX = 


compile_generators:

	